
#include <stdio.h>
#include "stack.h"
#include "../mesin_kata/mesin_kata.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S) {
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean stackIsEmpty(Stack S) {
    return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean stackIsFull(Stack S) {
    return Top(S) == (MaxElStck-1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, Word X) {
    Top(*S) += 1;
    TopWord(*S) = X;
    
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, Word* X) {
    *X = TopWord(*S);
    Top(*S) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */