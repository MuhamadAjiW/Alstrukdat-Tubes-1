/* File: mesinkata.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../etc/boolean.h"
#include "../mesin_karakter/mesin_karakter.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'
#define CARRIAGERETURN '\r'

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean endWord;
extern Word currentWord;

void printCurrentKata();

boolean kataSama(Word target, Word asal);

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void SkipLines();
/*proses enter*/

void STARTWORD(char* location);
/* I.S. : CC sembarang
   F.S. : EndWord = true, dan CC = MARK;
          atau EndWord = false, CWord adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CWord adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam CWord
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CWord berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void IgnoreBlanks_I();
    /*Ignore Blanks untuk input*/
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = ENTER */


void ignoreUntilEnter();
//Mengabaikan seluruh input hingga ENTER
/*I.S.  currentChar Sembarang */
/*F.S.  currentChar = ENTER */


void CopyWord_I();
    /*CopyWord untuk input*/
    /*Mengakuisisi kata, menyimpan dalam w
       I.S. :  currentChar adalah karakter pertama dari kata;
               w sembarang
       F.S. :  input berisi kata yang sudah diakuisisi;
               currentChar = BLANK atau currentChar = ENTER;
               currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
               Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */


void LowerCase(Word *kata);
/* I.S. kata terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */





void input();
/* I.S.  w sembarang 
   F.S.  w menyimpan kata pertama dari input;
         Jika currentChara adalah ENTER, maka endWord = true;
         

   Catatan: 
   - Iringkan dengan ignoreUntilEnter dan cek endword untuk validasi input
   - fry halo akan dibaca fry,

    */

int TransformInt(Word w);
/*  I.S. w terdefinisi
    F.S. Word diubah menjadi int
        Jika gagal, length diubah menjadi 0
        Tidak bisa handle overflow
        Tidak menerima bilangan negatif
        Jika input tidak valid, mengembalikan -1*/





void displayWord(Word w);
/* I.S. w terdefinisi
   F.S. Menampilkan kata w pada layar terminal
   Tidak ada karakter tambah baik di depan atau di akhir kata.*/

void printASCII1();

#endif
