#include "notif.h"
/*dependent packages:
None
*/
#include <stdlib.h>
#include <stdio.h>


/*********************************************/
/********************Notif********************/
/*********************************************/

Notif createNotif(char kasus, makanan val){
/* Membentuk sebuah Notif dari komponen-komponennya */
Notif N;
int i;

KASUS(N) = kasus;
for(i=0;i<PANJANGNAMA;i++){
    ELMT_ITEM(N, i) = val.nama[i];
}
return N;
}





/***************************************************/
/********************Linked List********************/
/***************************************************/

/***Create new node***/
Address newNode(ElTypeL N){
    Address p = (Address)malloc(sizeof(NodeList));
    if(p!= NULL){
        INFO(p) = N;
        NEXT(p) = NULL;
    }
    return p;
}


void createListLink(List_Link *L){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*L) = NULL;
}
boolean isEmptyListLink(List_Link L){
    return FIRST(L) == NULL;
}
void insertFirst(List_Link *L,  char kasus, makanan item){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Notif N jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. dan menampilkan "Allocation Error"*/
    /*KAMUS LOKAL*/
    Address p; 
    Notif N;
    /*ALGORITMA*/
    N = createNotif(kasus, item);
    p = newNode(N);
    if(p!=NULL){
        NEXT(p) = FIRST(*L);
        FIRST(*L) = p;
}
}
void deleteFirst(List_Link *L, ElTypeL *N){
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Notif disimpan pada N */
/*      dan alamat elemen pertama di-dealokasi */
    /*KAMUS LOKAL*/
    Address p;
    /*ALGORITMA*/
    p=FIRST(*L);
    *N = INFO(p);
    FIRST(*L)=NEXT(p);
    free(p);
}


void insertFirstNotif(List_Link *L,  Notif N){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Notif N jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. dan menampilkan "Allocation Error"*/
    /*KAMUS LOKAL*/
    Address p;
    /*ALGORITMA*/
    p = newNode(N);
    if(p!=NULL){
        NEXT(p) = FIRST(*L);
        FIRST(*L) = p;
    }
}

void concatDel(List_Link *Lbawah, List_Link *Latas){
    Notif temp;
    while (!isEmptyListLink(*Lbawah))
    {
        insertFirstNotif(Latas, INFO(FIRST(*Lbawah)) );
        deleteFirst(Lbawah, &temp);
    }
}

void concatNotDel(List_Link Lbawah, List_Link *Latas){
    Address p;
    p = FIRST(Lbawah);
    
    while (p != NULL)
    {
        insertFirstNotif(Latas, INFO(p) );
        p = NEXT(p);
    }
}

