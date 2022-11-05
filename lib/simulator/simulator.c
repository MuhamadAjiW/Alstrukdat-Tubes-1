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
}

void addMakanan(Simulator *S, makanan m){
// menambahkan makanan ke inventory
    Enqueue(&INV(*S),m);
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
        Dequeue(&INV(*S),&m);
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

void passTime(Simulator *S, int pass){
// melewatkan waktu selama menit yang ditentukan
// makanan dengan waktu penyimpanan <0 artinya sudah expired
    addressQ idx;
    if(!queueIsEmpty(INV(*S))){
    int menit;

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