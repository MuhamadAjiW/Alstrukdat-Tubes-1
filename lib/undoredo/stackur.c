#include "stackur.h"
#include <stdio.h>
#include <stdlib.h>

void CreateEmptyStackur(Stackur *S){
    Topur(*S) = Nil;
}

boolean IsEmptyStackur(Stackur S){
    return Topur(S) == Nil;
}

void PushStackur(Stackur *S, StrukturUndo X){
    if(Topur(*S)==Nil){
        Topur(*S)=0;
    }
    else{
        Topur(*S)++;
    }
    copyAll(&InfoTopur(*S),X);
}

void PopStackur(Stackur *S){
    if(Topur(*S)==Nil){
        printf("Stack kosong");
    }else{
        Topur(*S)--;
    }
}

void PrintTopUR(Stackur *S){
    printf("a");
    if(Topur(*S)==Nil){
        printf("Stack kosong");
    }else{
        printf("Top: %d\n",Topur(*S));
        printf("MapTopur: \n");
        printMap(MapTopur(*S));
        printf("WaktuTopur: \n");
        printTime(WaktuTopur(*S));
        printf("SimulatorTopur: \n");
        // printSimulator(SimulatorTopur(*S));
    }
}
void copyAll(StrukturUndo *Sout,StrukturUndo Sin){
    *Sout = Sin;
}

void subsStrukturUR(StrukturUndo *Sout,Map m,waktu w,Simulator s,int proses){
    (*Sout).M = m;
    (*Sout).W = w;
    (*Sout).S = s;
    (*Sout).proses = proses;
}

void subsElementUR(StrukturUndo Sout,Map *m,waktu *w,Simulator *s,int *proses){
    *m = Sout.M;
    *w = Sout.W;
    *s = Sout.S;
    *proses = Sout.proses;
}

