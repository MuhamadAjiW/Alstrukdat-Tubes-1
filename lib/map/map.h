#ifndef _map_H
#define _map_H

#include "../etc/boolean.h"
#include "../point/point.c"
#include "../matriks/matriks.c"
// #include "../mesin_karakter/mesin_karakter.c"
#include "../mesin_kata/mesin_kata.c"
#include "../simulator/simulator.c"

/*  Kamus Umum */
#define CAPACITYMP 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/


typedef struct 
{
    Matrix array; /* memori tempat penyimpanan peta elemen*/
    Simulator sim; /* Simulator */
}Map;
/*Map kosong berarti Matrix berisi * sebanyak 100 x 100*/

/* Selektor */
#define ROW_Map(m) (m).array.rowEff
#define COL_Map(m) (m).array.colEff
#define ELMT_Map(m,i,j) ELMT_Matrix((m).array, (i), (j))
#define S(m) (m).sim.currentLoc

// loader
void create_map(Map *map);
/* I.S. map sembarang*/
/* F.S. map terdefinisi memuat Map kosong*/
/* Proses: Mengisi semua elemen array dengan * */
void load_map(Map *map, char* mapconf);
/* I.S. map terdefinisi*/
/* F.S. map terdefinisi memuat Map yang telah di load*/
/* Proses: Membaca file eksternal dan mengisi array map sesuai dengan file eksternal*/

// validator
boolean isEmptyMP(Map map);
/* Mengirimkan true jika map kosong*/
boolean isIdxValidMP(int i,int j);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEffMP(Map map,int i,int j);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
void printMap(Map map);
/* I.S. map terdefinisi*/
/* F.S. map tercetak di layar*/
/*Contoh: */
boolean isNear(Map map,char ch);
/* Mengirimkan true jika ada karakter ch yang berada di sekitar start*/

void move_map(Map *map,Word arah);
/* I.S. map terdefinisi*/
/* F.S. Posisi S pindah sesuai arah*/

#endif