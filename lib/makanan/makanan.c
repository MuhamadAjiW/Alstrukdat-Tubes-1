//ADT List dari praktikum, list rapat kiri

#include "makanan.h"
#include <stdio.h>
#include <stdlib.h>

void createmakanan(makanan *a){
   id(*a) = NIL;
   nama(*a)[0] = '\0';
   createTime(&expireTime(*a));
   createTime(&deliverTime(*a));
   action(*a)[0] = '\0';
   location(*a) = '\0';
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
   printf("aksi untuk mendapatkan = %s (lokasi: %c)\n", action(a), location(a));
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

