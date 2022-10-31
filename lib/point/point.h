/* File: point.h */

#ifndef POINT_H
#define POINT_H

#include "../etc/boolean.h"

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

/* *** Notasi Akses: Selektor POINT *** */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
        
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT CreatePOINT (int X, int Y);
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void ReadPOINT (POINT * P); 
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void WritePOINT (POINT P);
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** OPERASI TERHADAP TYPE *** */                           
void Drag (POINT *P, int deltaX, int deltaY);
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */

void MoveSouth(POINT *P);
/* I.S. P terdefinisi */
/* F.S. Absis P ditambah 1 */

void MoveEast(POINT *P);
/* I.S. P terdefinisi */
/* F.S. Ordinat P ditambah 1 */

void MoveNorth(POINT *P);
/* I.S. P terdefinisi */
/* F.S. Absis P dikurang 1 */

void MoveWest(POINT *P);
/* I.S. P terdefinisi */
/* F.S. Ordinat P dikurang 1 */

#endif