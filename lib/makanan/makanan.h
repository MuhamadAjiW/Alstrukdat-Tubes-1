/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef _makanan_H
#define _makanan_H

#include "../etc/boolean.h"
#include "../waktu/waktu.c"
#include "../tree/tree.c"

/*  Kamus Umum */
#define PANJANGNAMA 25
/* kapasitas maksimum nama */
#define PANJANGACTION 5
/* kapasitas maksimum kata aksi */
#define NIL -1
/* Nil */

/* Definisi elemen dan koleksi objek */
typedef Tree recipe;

typedef struct{
   int id;
   char nama[PANJANGNAMA];
   waktu expireTime;
   waktu deliverTime;
   char action[PANJANGACTION];
   char location;
   recipe resep;
} makanan;  /* type elemen List */

/* ********** SELEKTOR ********** */
//Selektor tipe data
#define ELMT(l, i) (l).contents[(i)]
#define id(tipedata) (tipedata).id
#define nama(tipedata) (tipedata).nama
#define expireTime(tipedata) (tipedata).expireTime
#define deliverTime(tipedata) (tipedata).deliverTime
#define action(tipedata) (tipedata).action
#define location(tipedata) (tipedata).location
#define resep(tipedata) (tipedata).resep

void createmakanan(makanan *a);
//membuat ADT makanan

void createResep(recipe *r);
//membuat ADT resep

void printmakanan(makanan a);
//print makanan

void printResep(recipe r);
//print makanan

#endif