/* Definisi type boolean */

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

void CreateTimeTest (waktu * T, int DD, int HH, int MM);
//buat test aja

long TIMEToMenit (waktu T);
//dipake di TLT & TGT

waktu MenitToTIME (long N); 

//buat sort makanan
boolean TLT (waktu T1, waktu T2);
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (waktu T1, waktu T2);
/* Mengirimkan true jika T1>T2, false jika tidak */

#endif