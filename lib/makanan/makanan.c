//ADT List dari praktikum, list rapat kiri

#include "makanan.h"


//dependent package
/*HARUS MAKE INI
#include "../waktu/waktu.c"
#include "../tree/tree.c"
*/
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
   if (treeVal(resep(a)) == -1){
      printf("Tidak memiliki resep\n");
   }
   else{
      printResep(resep(a));
   }
}
//print makanan

void createResep(recipe *r){
   *r = (address) malloc (sizeof(Node));
   if (*r != NULL){
      treeVal(*r) = -1;
      parent(*r) = NULL;
      subMaxIdx(*r) = -1;
   }
   else{
       printf("alokasi gagal.\n");
   }
}
//membuat ADT resep


void printResep(recipe r){
   for (int i = 0; i <= subMaxIdx(r); i++){
      printf("%d", treeVal(treeSub(r, i)) );
      if (i != subMaxIdx(r)){
         printf(", ");
      }
   }
   printf("\n");
}
//print makanan

void editMakananTest(makanan *a, long exTime) {
   expireTime(*a) = MenitToTIME(exTime);
}
