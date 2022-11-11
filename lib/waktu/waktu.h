#ifndef _waktu_h
#define _waktu_h

#include "../etc/boolean.h"

typedef struct{
   int contents[3]; /* memori tempat penyimpan elemen (container) */
} waktu;

#define Hari(time) (time).contents[(0)]
#define Jam(time) (time).contents[(1)]
#define Menit(time) (time).contents[(2)]

void createTime(waktu *t);
//inisiasi time
//isinya 0 0 0 

void printTime(waktu t);
//print time
//format 0 0 0, tanpa enter

boolean IsTIMEValid (int D, int H, int M);
//dipake di createtime

void CreateTimeDirect(waktu * T, int DD, int HH, int MM);
//membuat time dengan input manual

long TIMEToMenit (waktu T);
//dipake di TLT & TGT

waktu MenitToTIME (long N); 
//mengubah nilai dari menit kembali ke time

//buat sort makanan
boolean TLT (waktu T1, waktu T2);
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (waktu T1, waktu T2);
/* Mengirimkan true jika T1>T2, false jika tidak */

void writeHHMM(waktu t);
//Menuliskan waktu dalam format HH.MM

void nextMinute(waktu * T);
// mengubah T menjadi waktu setelah 1 menit

void nextTime(waktu * T, int givenMinute);
// mengubah T menjadi waktu setelah (givenMinute) menit

void copyTime(waktu input, waktu *output);
// menyalin waktu di tempat lain

#endif