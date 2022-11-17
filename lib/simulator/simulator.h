#ifndef simulator_H
#define simulator_H

#include "../queue/prioqueue.h"
#include "../waktu/waktu.h"
#include "../etc/boolean.h"
#include "../mesin_kata/mesin_kata.h"
#include "../point/point.h"
#include "../mesin_kata/mesin_kata.h"
#include "../tree/tree.h"
#include "../list_statik/list_statik.h"
#include "../notif/notif.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    Word namaPengguna;
    POINT currentLoc;
    PrioQueue Inventory;
    PrioQueue Delivery;
    List_Link Notifikasi;

} Simulator;

#define LOC(S) (S).currentLoc
#define INV(S) (S).Inventory
#define DLV(S) (S).Delivery
#define NAME(S) (S).namaPengguna
#define NOTIF(S) (S).Notifikasi

void createSimulator(Simulator *S);
//inisialisasi

void addMakanan(Simulator *S, makanan m);
// menambahkan makanan ke inventory

boolean checkMakanan(Simulator s, int idMakanan);
// mengecek apakah makanan ada di inventory

int findMakanan(Simulator S, int idMakanan);
//mencari index makanan di inventory

void deleteMakanan(Simulator *S, int idMakanan);
//menghilangkan makanan di prioqueue

void buyMakanan(Simulator *S, makanan m);
//menambahkan makanan ke delivery

void moveMakanan(Simulator *s);
//memindahkan makanan dari delivery list ke inventory

void makeFood(Simulator *S, list_statik l, int idx, char category);
//bikin makanan untuk main

void printNotif(Notif N);
/*I.S. Notif terdefinisi*/
/*F.S. Jika kasus delivery ('d'), akan menampilkan "{item} sudah diterima oleh {Username}!\n".
        Jika kasus expired ('e'), akan menampilkan "{item} kadaluarsa.. :("
*/

void printAllNotif(List_Link *L);
/*  I.S. Notif terdefinisi
    F.S. Notif bisa kosong, jika kosong menampilkan Notifikasi: - 
    Jika tidak kosong, akan ditampilkan "Notifikasi:
                                        1. {Notif 1} ....
                                        .................
                                        k. {Notif k} ....
    Diakhir prosedur, List L akan kosong*/

void rekomendasiMakanan(list_statik catalog, Simulator BNMO);

boolean lengkapBahan(makanan makanan, Simulator BNMO, list_statik catalog);

#endif