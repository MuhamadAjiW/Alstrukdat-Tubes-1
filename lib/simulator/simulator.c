#include "simulator.h"
/*dependent packages:
#include "../waktu/waktu.c"
#include "../notif/notif.c"
#include "../queue/prioqueue.c"
#include "../list_statik/list_statik.c"
#include "../makanan/makanan.c"
#include "../tree/tree.c"
#include "../mesin_kata/mesin_kata.c"
#include "../mesin_karakter/mesin_karakter.c"
*/
#include <stdio.h>
#include <stdlib.h>

void createSimulator(Simulator *S){
//inisialisasi
    NAME(*S).Length=4;
    NAME(*S).TabWord[0]='B';
    NAME(*S).TabWord[1]='N';
    NAME(*S).TabWord[2]='M';
    NAME(*S).TabWord[3]='O';
    //nama default BNMO

    Absis(LOC(*S))=0;
    Ordinat(LOC(*S))=0;
    //lokasi default 0,0

    MakeEmpty(&INV(*S),1);
    MakeEmpty(&DLV(*S),1);

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
//mencari index makanan di inventory
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

void buyMakanan(Simulator *S, makanan m) {
//menambahkan makanan ke delivery
    Enqueue(&DLV(*S), m, 2);
}

void moveMakanan(Simulator *S) {
//memindahkan makanan dari delivery list ke inventory
    makanan temp;
    Dequeue(&DLV(*S), &temp, 2);
    Enqueue(&INV(*S), temp, 1);
}

void makeFood(Simulator *S, list_statik l, int idx, char category){
//bikin makanan untuk main
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
        printf("%s kadaluwarsa ", ITEM(N));
    }
    
    else if(KASUS(N) == '1'){
        printf("Pencampuran %s digagalkan ", ITEM(N));
    }else if(KASUS(N) == '2'){
        printf("Pemotongan %s digagalkan", ITEM(N));
    }else if(KASUS(N) == '3'){
        printf("Penggorengan %s digagalkan ", ITEM(N));
    }else if(KASUS(N) == '4'){
        printf("Perebusan %s digagalkan ", ITEM(N));
    }else if(KASUS(N) == '5'){
        printf("Pembelian %s digagalkan", ITEM(N));
    }else if(KASUS(N) == '6'){
        printf("%s tidak jadi sampai ", ITEM(N));
    }else if(KASUS(N) == '7'){
        printf("%s tidak jadi kadaluwarsa ", ITEM(N));
    }
    
    else if(KASUS(N) == 'p'){
        printf("%s kembali dicampurkan ", ITEM(N));
    }else if(KASUS(N) == 'o'){
        printf("%s kembali dipotongkan ", ITEM(N));
    }else if(KASUS(N) == 'i'){
        printf("%s kembali digorengkan ", ITEM(N));
    }else if(KASUS(N) == 'u'){
        printf("%s kembali direbuskan ", ITEM(N));
    }else if(KASUS(N) == 'y'){
        printf("%s kembali dibeli ", ITEM(N));
    }else if(KASUS(N) == 't'){
        printf("%s kembali sampai ", ITEM(N));
    }else if(KASUS(N) == 'r'){
        printf("%s kembali kadaluwarsa ", ITEM(N));
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
            i++;
        }
    }
    printf("\n");
}

void rekomendasiMakanan(list_statik catalog, Simulator BNMO){
    int counter = 0;

    for (int i = 0; i < listLength(catalog); i++){
        if (!(locationELMT(catalog, i) == 'T')){
            if (lengkapBahan(ELMT(catalog, i), BNMO, catalog)){
                if (counter == 0){
                    printf("Makanan yang dapat dibuat adalah: \n");
                }
                counter++;
                printf("    %d. %s\n", counter, namaELMT(catalog, i));
            }
        }
    }
    if (counter == 0){
        printf("Tidak ada makanan yang dapat dibuat\n");
    }
}

boolean lengkapBahan(makanan makanan, Simulator BNMO, list_statik catalog){
    if (treeVal(resep(makanan)) == -1){
        if (checkMakanan(BNMO, id(makanan))){
            return true;
        }
        else return false;
    }
    else{
        boolean lengkap = 1;
        int idx;
        for (int i = 0; i <= subMaxIdx(resep(makanan)); i++)
        {
            idx = indexOf(catalog, treeVal(treeSub(resep(makanan), i)));
            if (checkMakanan(BNMO, treeVal(treeSub(resep(makanan), i)) )){
                lengkap = lengkap && 1;
            }
            else{
                lengkap = lengkap && lengkapBahan(ELMT(catalog, idx), BNMO, catalog);
            }
        }
        return lengkap;
    }
}