#ifndef simulator_H
#define simulator_H

#include "../queue/prioqueue.c"
#include "../waktu/waktu.h"
#include "../etc/boolean.h"
#include "../mesin_kata/mesin_kata.h"
#include "../point/point.h"
#include "../mesin_kata/mesin_kata.h"
#include "../tree/tree.h"
#include "../list_statik/list_statik.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    Word namaPengguna;
    POINT currentLoc;
    PrioQueue Inventory;
    
} Simulator;

#define LOC(S) (S).currentLoc
#define INV(S) (S).Inventory
#define NAME(S) (S).namaPengguna

void createSimulator(Simulator *S);

void addMakanan(Simulator *S, makanan m);
// menambahkan makanan ke inventory

boolean checkMakanan(Simulator s, int idMakanan);
// mengecek apakah makanan ada di inventory

int findMakanan(Simulator S, int idMakanan);
//mencari index makanan di inventory

void deleteMakanan(Simulator *S, int idMakanan);
//menghilangkan makanan di prioqueue

void passTime(Simulator *s, int minute);
// melewatkan waktu selama menit yang ditentukan
// makanan dengan waktu penyimpanan <0 artinya sudah expired

void makeFood(Simulator *S, list_statik l, int idx, char category);
//bikin makanan
//untuk main

#endif