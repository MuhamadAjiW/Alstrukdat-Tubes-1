//fungsinya buat mapping fungsi di main
//intinya buat ngesplit split list statik tanpa bikin list baru tapi akses indeksnya biar gampang di main

#include <stdio.h>
#include <stdlib.h>
#include "minilist.h"
#include "../etc/boolean.h"

void createMiniList(minilist *ml){
    for (int i = 0; i < CAPACITYMLST; i++){
        mlELMT(*ml,i) = -1;
    }
}

void load_miniList(list_statik l, minilist *ml, char category){
    /*
    category
    'm' = mix
    'c' = chop
    'f' = fry
    'b' = boil
    't' = buy
    */


    int counter = 0;
    if (category == 'm'){
        for(int i = 0; i < listLength(l); i++){
            if (locationELMT(l, i) == 'M'){
                mlELMT(*ml,counter) = idELMT(l,i);
                counter++;
            }
        }
    }
    else if (category == 'c'){
        for(int i = 0; i < listLength(l); i++){
            if (locationELMT(l, i) == 'C'){
                mlELMT(*ml,counter) = idELMT(l,i);
                counter++;
            }
        }
    }
    else if (category == 'f'){
        for(int i = 0; i < listLength(l); i++){
            if (locationELMT(l, i) == 'F'){
                mlELMT(*ml,counter) = idELMT(l,i);
                counter++;
            }
        }
    }
    else if (category == 'b'){
        for(int i = 0; i < listLength(l); i++){
            if (locationELMT(l, i) == 'B'){
                mlELMT(*ml,counter) = idELMT(l,i);
                counter++;
            }
        }
    }
    else if (category == 't'){
        for(int i = 0; i < listLength(l); i++){
            if (locationELMT(l, i) == 'T'){
                mlELMT(*ml,counter) = idELMT(l,i);
                counter++;
            }
        }
    }

}

boolean isMlEmpty(minilist ml){
    return mlELMT(ml,0) = -1 == -1;
}

boolean isMlFull(minilist ml){
    return mlELMT(ml, CAPACITYMLST-1) != -1;
}

boolean isMlIdxValid(minilist ml, IdxType i){
    return (i >= 0 && i < CAPACITYMLST);
}

boolean isMlIdxEff(minilist ml, IdxType i){
    return (i >= 0 && i < minilistLength(ml));
}

int minilistLength(minilist ml){
    int counter;
    counter = 0;
    if (isMlFull(ml)){
        counter = CAPACITYMLST;
    }
    else{
        while (mlELMT(ml, counter) != -1){
            counter++;
        }
    }
    return counter;
}

int mlIndexOf(minilist l, int idval){
    int indeks = 0;
    boolean ada = false;
    while ( (indeks < minilistLength(l)) && (!ada) ) {
        if (mlELMT(l, indeks) == idval) {
           ada = true;
        }
        else{
           indeks += 1;
        }
    }
    if (!ada){
        indeks = -1;
    }
    return indeks;
}

void printMiniList(list_statik l, minilist ml){
    for (int i = 0; i < minilistLength(ml); i++){
        printf("%d, ", mlELMT(ml, i));
    }
    printf("\n");
}