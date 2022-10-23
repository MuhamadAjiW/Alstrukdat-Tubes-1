//ADT List dari praktikum, list rapat kiri

#include "makanan.h"
#include <stdio.h>
#include <stdlib.h>

void createmakanan(makanan *a){
   id(*a) = NIL;
   nama(*a) = (char*) malloc (PANJANGNAMA* sizeof(char));
   nama(*a) = "";
   createTime(&expireTime(*a));
   createTime(&deliverTime(*a));
   action(*a) = (char*) malloc (PANJANGACTIONANDLOCATION* sizeof(char));
   action(*a) = "";
   createResep(&resep(*a));
}
//membuat ADT makanan

void createResep(recipe *r){
   for (int i = 0; i < PANJANGRESEP; i++){
      ELMT(*r, i) = 0;
   }
}
//membuat ADT recipe

void printmakanan(makanan a){
   printf("id = %d\n", id(a));
   printf("nama = %s\n", nama(a));
   printf("waktu sampai expired = ");
   printTime(expireTime(a));
   printf("\n");
   printf("waktu pengantaran = ");
   printTime(deliverTime(a));
   printf("\n");
   printf("aksi untuk mendapatkan = %s\n", action(a));
   printf("data resep = ");
   printResep(resep(a));
}
//print makanan

void printResep(recipe r){
   for (int i = 0; i < PANJANGRESEP; i++){
      printf("%d", ELMT(r, i));
      if (i != PANJANGRESEP - 1){
         printf(" ");
      }
   }
}
//print makanan

