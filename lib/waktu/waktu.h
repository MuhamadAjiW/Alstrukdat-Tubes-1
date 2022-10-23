/* Definisi type boolean */

#ifndef _waktu_h
#define _waktu_h

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

#endif