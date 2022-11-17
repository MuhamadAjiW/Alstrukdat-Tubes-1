/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef _list_statik_H
#define _list_statik_H

#include "../makanan/makanan.h"
#include "../etc/boolean.h"
#include "../waktu/waktu.h"
#include "../tree/tree.h"
#include "../mesin_kata/mesin_kata.h"
#include "../mesin_karakter/mesin_karakter.h"

/*  Kamus Umum */
#define CAPACITY 50
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/


/* Definisi elemen dan koleksi objek */
typedef int IdxType;
typedef struct {
   makanan contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} list_statik;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* cara akses bisa lihat di selektor
/* List kosong:
   untuk semua index
   id = -1
   nama = ""
   expireTime = 0 0 0
   deliverTime = 0 0 0
   action = ""
   location = ""
   resep = 0 0 0 0 0 0 0 0 0 0

/* ********** SELEKTOR ********** */
//Selektor list
#define ELMT(l, i) (l).contents[(i)]
#define idELMT(l, i) id(ELMT(l, i))
#define namaELMT(l, i) nama(ELMT(l, i))
#define expireTimeELMT(l, i) expireTime(ELMT(l, i))
#define deliverTimeELMT(l, i) deliverTime(ELMT(l, i))
#define locationELMT(l, i) location(ELMT(l, i))
#define actionELMT(l, i) action(ELMT(l, i))
#define resepELMT(l, i) resep(ELMT(l, i))


//loader
void create_list_statik(list_statik *l);
/* I.S. l sembarang */
/* F.S. Membuat list kosong*/
/* Proses: Mengisi semua elemen list dengan definisi list kosong*/

void load_list_statik(list_statik *l, char* makananconf, char* resepconf);
/* I.S. l sembarang */
/* F.S. Membuat list berisikan data makanan*/
/* Proses: Membaca file configmakanan*/


//fungsi yang bisa dipake//
boolean isEmpty(list_statik l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

boolean isFull(list_statik l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

boolean isIdxValid(list_statik l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean isIdxEff(list_statik l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

int listLength(list_statik l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

int indexOf(list_statik l, int idval);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

void printList(list_statik l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

#endif