//fungsinya buat mapping fungsi di main
//intinya buat ngesplit split list statik tanpa bikin list baru tapi akses indeksnya biar gampang di main

#ifndef _minilist_H
#define _minilist_H

#include "list_statik.h"
#include "../etc/boolean.h"

#define CAPACITYMLST 20

typedef int IdxType;

typedef struct {
   int contents[CAPACITYMLST]; /* memori tempat penyimpan elemen (container) */
} minilist;

#define mlELMT(ml,i) (ml).contents[(i)]

void createMiniList(minilist *ml);
void load_miniList(list_statik l, minilist *ml, char category);
boolean isMlEmpty(minilist l);
boolean isMlFull(minilist l);
boolean isMlIdxValid(minilist l, IdxType i);
boolean isMlIdxEff(minilist l, IdxType i);
int minilistLength(minilist l);
int mlIndexOf(minilist l, int idval);
void printMiniList(list_statik l, minilist ml);

#endif