#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"


void createSimulator(Simulator *S){
    NAME(*S).Length=4;
    NAME(*S).TabWord[0]='B';
    NAME(*S).TabWord[1]='N';
    NAME(*S).TabWord[2]='M';
    NAME(*S).TabWord[3]='O';
    //nama default BNMO

    Absis(LOC(*S))=0;
    Ordinat(LOC(*S))=0;
    //lokasi default 0,0

    MakeEmpty(&INV(*S),10);
    MakeEmpty(&DLV(*S),10);

    createListLink(&NOTIF(*S));
}

void addMakanan(Simulator *S, makanan m){
// menambahkan makanan ke inventory
    Enqueue(&INV(*S),m, 1);
}


boolean checkMakanan(Simulator S, int idMakanan){
// mengecek apakah makanan ada di inventory
    addressQ idx;
    boolean found;

    if(queueIsEmpty(INV(S)))found=false;
    else{
    idx=Head(INV(S));
    found=false;
    while(idx!=Tail(INV(S))&&!found){
        if(Elmt(INV(S),idx).id==idMakanan)found=true;
        if(idx==MaxEl(INV(S))-1){
            idx=0;
        }
        else idx++;
    }
    if(InfoTail(INV(S)).id==idMakanan)found=true;
    }
    return found;
}

int findMakanan(Simulator S, int idMakanan){
    addressQ idx;
    addressQ foundIDX;
    boolean found;
    found=false;
    foundIDX=-1;
    if(checkMakanan(S,idMakanan)){
        idx=Head(INV(S));
        while(idx!=Tail(INV(S))&&!found){
            if(Elmt(INV(S),idx).id==idMakanan){
                found=true;
                foundIDX=idx;
            }
            if(idx==MaxEl(INV(S))-1){
                idx=0;
            }
            else idx++;
        }
    if(!found && InfoTail(INV(S)).id==idMakanan){
        found=true;
        foundIDX=Tail(INV(S));
    }
    }

    return foundIDX;
}

void deleteMakanan(Simulator *S, int idMakanan){
//menghilangkan makanan di prioqueue
    int foundIDX;
    int idx;
    makanan m,temp,temp2;
    foundIDX=findMakanan(*S,idMakanan);
    if(foundIDX==Head(INV(*S))){
        Dequeue(&INV(*S),&m, 1);
    }
    else if(foundIDX==Tail(INV(*S))){
        if(Tail(INV(*S))==0){
            Tail(INV(*S))=MaxEl(INV(*S))-1;
        }
        else{
            Tail(INV(*S))--;
        }
    }
    else{
        idx=Tail(INV(*S));
        temp=InfoTail(INV(*S));

        if(idx==0){
            idx=MaxEl(INV(*S))-1;
        }
        else{
            idx--;
        }
        
        while(idx!=foundIDX){
            temp2=Elmt(INV(*S),idx);
            Elmt(INV(*S),idx)=temp;
            temp=temp2;

            if(idx==0){
                idx=MaxEl(INV(*S))-1;
            }
            else{
                idx--;
            }
        }
        //idx=foundIDX;
        Elmt(INV(*S),idx)=temp;

        //update tail
        if(Tail(INV(*S))==0){
            Tail(INV(*S))=MaxEl(INV(*S))-1;
        }
        else{
            Tail(INV(*S))--;
        }

    }

}

void passTime(Simulator *S, long pass, waktu *time){
// melewatkan waktu selama menit yang ditentukan
// makanan dengan waktu penyimpanan <0 artinya sudah expired
    addressQ idx;
    long temp = TIMEToMenit(*time);
    *time = MenitToTIME(temp + pass);

    if(!queueIsEmpty(INV(*S))){
        long menit;

        idx=Head(INV(*S));
        while(idx!=Tail(INV(*S))){
            menit=TIMEToMenit(Elmt(INV(*S),idx).expireTime);
            menit-=pass;
            Elmt(INV(*S),idx).expireTime=MenitToTIME(menit);
            if(idx==MaxEl(INV(*S))-1){
                idx=0;
            }
            else idx++;
        }
        menit=TIMEToMenit(InfoTail(INV(*S)).expireTime);
        menit-=pass;
        InfoTail(INV(*S)).expireTime=MenitToTIME(menit);
    }

    if (!queueIsEmpty(DLV(*S))) {
        long tMenit;
        int nDelivery = NBElmt(DLV(*S));
        int i = Head(DLV(*S));
        for (int j = 0; j < nDelivery; j++) {
            tMenit = TIMEToMenit(Deliver(DLV(*S), i));
            if ((tMenit-pass) <= 0) {
                long tempExp = TIMEToMenit(Expire(DLV(*S), i)) + tMenit - pass;
                Expire(DLV(*S), i) = MenitToTIME(tempExp);
                Deliver(DLV(*S), i) = MenitToTIME(0);
            }
            else {
                Deliver(DLV(*S), i) = MenitToTIME(tMenit-pass);
            }

            if (i == MaxEl(DLV(*S))-1) {
                i = 0;
            }
            else {
                i += 1;
            }
        }
    }
}

void buyMakanan(Simulator *S, makanan m) {
    Enqueue(&DLV(*S), m, 2);
}

void moveMakanan(Simulator *S) {
    makanan temp;
    Dequeue(&DLV(*S), &temp, 2);
    Enqueue(&INV(*S), temp, 1);
}

void inventoryDeliveryMechanism(Simulator *S) {
    makanan dump, temp;
    while(timeIsZero(DLV(*S), 2)) {//delivery
        Dequeue(&DLV(*S), &temp, 2);
        Enqueue(&INV(*S), temp, 1);
        //add notif
        insertFirst(&NOTIF(*S), 'd', temp);
    }
    while(timeIsZero(INV(*S), 1)) {//expiration
        Dequeue(&INV(*S), &dump, 1);
        //add notiff
        insertFirst(&NOTIF(*S), 'e', dump);
    }
}

void makeFood(Simulator *S, list_statik l, int idx, char category){
    boolean lengkap = true;
    int id;
    int index;

    int counter;
    int counter2;

    counter = 0;
    while (counter <= subMaxIdx(resepELMT(l,idx)) && lengkap){
        id = treeVal(treeSub(resepELMT(l,idx), counter));
        if (!checkMakanan(*S, id)){
            lengkap = false;
        }
        counter++;
    }
    if (lengkap){
        addMakanan(S, ELMT(l, idx));
        for(counter = 0; counter <= subMaxIdx(resepELMT(l,idx)); counter++){
            deleteMakanan(S, treeVal(treeSub(resepELMT(l,idx), counter)));
        }
        printf("%s selesai dibuat dan sudah masuk ke inventory!\n", namaELMT(l, idx));
    }
    else{
        printf("Gagal ");
        if (category == 'm'){
            printf("mencampurkan");
        }
        else if (category == 'c'){
            printf("memotongkan");
        }
        else if (category == 'f'){
            printf("menggoreng");
        }
        else if (category == 'b'){
            printf("merebus");
        }
        
        printf(" %s karena kamu tidak memiliki bahan berikut:\n", namaELMT(l, idx));
        counter2 = 0;
        for(counter = 0; counter <= subMaxIdx(resepELMT(l,idx)); counter++){
            id = treeVal(treeSub(resepELMT(l,idx), counter));
            if (!checkMakanan(*S, id)){
                counter2++;
                index = indexOf(l, id);
                printf("    %d. %s\n", counter2, namaELMT(l, index));
            }
        }
    }
}

void printNotif(Notif N){
/*I.S. Notif terdefinisi*/
/*F.S. Jika kasus delivery ('d'), akan menampilkan "{item} sudah diterima oleh {Username}!\n".
        Jika kasus expired ('e'), akan menampilkan "{item} kadaluarsa \n".
*/
/*ALGORITMA*/


if(KASUS(N) == 'd'){    
    printf("%s sudah diterima oleh BNMO", ITEM(N));
}else if(KASUS(N) == 'e'){
    printf("%s kadaluarsa ", ITEM(N));
}
}

void printAllNotif(List_Link *L){
/*  I.S. Notif terdefinisi
    F.S. Notif bisa kosong, jika kosong menampilkan Notifikasi: - 
    Jika tidak kosong, akan ditampilkan "Notifikasi:
                                        1. {Notif 1} ....
                                        .................
                                        k. {Notif k} ....""
    Diakhir list notif akan ditampilkan 
    Diakhir prosedur, List L akan kosong*/
    /*KAMUS LOKAL*/
    Notif N;
    int i = 1;
    /*ALGORITMA*/
    printf("Notifikasi:");
    if(isEmptyListLink(*L)){
        printf(" - ");
    }else{
        while(!isEmptyListLink(*L)){
            deleteFirst(L, &N);
            printf("\n%d. ", i);
            printNotif(N);
        }
    }
    printf("\n");
}
