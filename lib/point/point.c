#include <stdio.h>
#include "point.h"
       
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT CreatePOINT (int X, int Y){
/* Membentuk sebuah POINT dari komponen-komponennya */
    POINT p;

    Absis(p)=X;
    Ordinat(p)=Y;
    return p;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void ReadPOINT (POINT * P){
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
    int x,y;

    scanf("%d %d",&x,&y);
    *P=CreatePOINT(x,y);
}

void WritePOINT (POINT P){
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                
    printf("(%d,%d)",Absis(P)-1,Ordinat(P)-1);
}

/* *** OPERASI TERHADAP TYPE *** */                           
void Drag (POINT *P, int deltaX, int deltaY){
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    POINT pnew;
    Absis(pnew)=Absis(*P)+deltaX;
    Ordinat(pnew)=Ordinat(*P)+deltaY;
    *P=pnew;
}

void MoveSouth(POINT *P){
/* I.S. P terdefinisi */
/* F.S. Absis P ditambah 1 */
    Drag(P,1,0);
}

void MoveEast(POINT *P){
/* I.S. P terdefinisi */
/* F.S. Ordinat P ditambah 1 */
    Drag(P,0,1);
}

void MoveNorth(POINT *P){
/* I.S. P terdefinisi */
/* F.S. Absis P dikurang 1 */
    Drag(P,-1,0);
}

void MoveWest(POINT *P){
/* I.S. P terdefinisi */
/* F.S. Ordinat P dikurang 1 */
    Drag(P,0,-1);
}