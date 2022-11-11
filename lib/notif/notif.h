#ifndef NOTIF_H
#define NOTIF_H


#include "../etc/boolean.h"
#include "../makanan/makanan.h"
/*Notifikasi Menggunakan List Linked*/

typedef struct { 
	char kasus; 
	char item[PANJANGNAMA]; 
} Notif;

typedef Notif ElTypeL;
typedef struct node* Address;
typedef struct node {
    ElTypeL info;
    Address next;
} NodeList;

/***SELEKTOR***/
#define KASUS(n) (n).kasus
#define ITEM(n) (n).item
#define ELMT_ITEM(n,i) (n).item[i] 

#define INFO(p) (p)->info
#define NEXT(p) (p)->next




/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef Address List_Link;

#define FIRST(l) (l)


/*********************************************/
/********************Notif********************/
/*********************************************/

Notif createNotif(char kasus, makanan item);
/* Membentuk sebuah Notif dari komponen-komponennya */

/***************************************************/
/********************Linked List********************/
/***************************************************/


void createListLink(List_Link *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

boolean isEmptyListLink(List_Link L);
//mengembalikan true jika listlink kosong

void insertFirst(List_Link *L, char kasus, makanan item);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Notif N jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. dan menampilkan "Allocation Error"*/

void deleteFirst(List_Link *L, ElTypeL *N);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Notif disimpan pada N */
/*      dan alamat elemen pertama di-dealokasi */

void concatDel(List_Link *Lbawah, List_Link *Latas);
//lbawah bakal habis masuk ke Latas
#endif