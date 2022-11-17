#include "list_statik.h"
/*dependent packages:
#include "../makanan/makanan.c"
#include "../waktu/waktu.c"
#include "../tree/tree.c"
#include "../mesin_kata/mesin_kata.c"
#include "../mesin_karakter/mesin_karakter.c"
*/
#include <stdio.h>
#include <stdlib.h>


//loader
void create_list_statik(list_statik *l){
   for (int i = 0; i < CAPACITY; i++){
      createmakanan(&ELMT(*l, i));
   }
}
/* I.S. l sembarang */
/* F.S. Membuat list kosong*/
/* Proses: Mengisi semua elemen list dengan definisi list kosong*/

void load_list_statik(list_statik *l, char* makananconf, char* resepconf){
   int N;
   int cache;
   int mul;
   int counter;

   Word Mix;
   Mix.Length = 3;
   Mix.TabWord[0] = 'M';
   Mix.TabWord[1] = 'i';
   Mix.TabWord[2] = 'x';
   

   Word Chop;
   Chop.Length = 4;
   Chop.TabWord[0] = 'C';
   Chop.TabWord[1] = 'h';
   Chop.TabWord[2] = 'o';
   Chop.TabWord[3] = 'p';
   
   
   Word Fry;
   Fry.Length = 3;
   Fry.TabWord[0] = 'F';
   Fry.TabWord[1] = 'r';
   Fry.TabWord[2] = 'y';

   Word Boil;
   Boil.Length = 4;
   Boil.TabWord[0] = 'B';
   Boil.TabWord[1] = 'o';
   Boil.TabWord[2] = 'i';
   Boil.TabWord[3] = 'l';

   Word Buy;
   Buy.Length = 3;
   Buy.TabWord[0] = 'B';
   Buy.TabWord[1] = 'u';
   Buy.TabWord[2] = 'y';



   STARTWORD(makananconf);


   cache = 0;
   mul = 1;
   for(int j = currentWord.Length-1; j >= 0; j--){
      cache += mul*( ((int) (currentWord.TabWord[j])) - 48);
      mul *= 10;
   }
   N = cache;
   SkipLines();

   for (int i = 0; i < N; i++){
      counter = 0;

      //id
      ADVWORD();
      cache = 0;
      mul = 1;
      for(int j = currentWord.Length-1; j >= 0; j--){
         cache += mul*( ((int) (currentWord.TabWord[j])) - 48);
         mul *= 10;
      }
      idELMT(*l, i) = cache;

      SkipLines();

      //nama
      ADVWORD();
      counter = 0;
      while (currentChar != ENTER){
         for(int j = 0; j < currentWord.Length; j++){
            namaELMT(*l, i)[counter] = currentWord.TabWord[j];
            counter += 1;
         }
         if (currentChar != ENTER){
            namaELMT(*l, i)[counter] = BLANK;
            counter += 1;
            ADVWORD();
         }
      }
      for(int j = 0; j < currentWord.Length; j++){
         namaELMT(*l, i)[counter] = currentWord.TabWord[j];
         counter += 1;
      }
      namaELMT(*l, i)[counter] = '\0';

      SkipLines();      

      //expiretime
      ADVWORD();
      cache = 0;
      mul = 1;
      for(int j = currentWord.Length-1; j >= 0; j--){
         cache += mul*( (int) (currentWord.TabWord[j]) - 48);
         mul *= 10;
      }
      Hari(expireTimeELMT(*l, i)) = cache;

      ADVWORD();
      cache = 0;
      mul = 1;
      for(int j = currentWord.Length-1; j >= 0; j--){
         cache += mul*( (int) (currentWord.TabWord[j]) - 48);
         mul *= 10;
      }
      Jam(expireTimeELMT(*l, i)) = cache;

      ADVWORD();
      cache = 0;
      mul = 1;
      for(int j = currentWord.Length-1; j >= 0; j--){
         cache += mul*( (int) (currentWord.TabWord[j]) - 48);
         mul *= 10;
      }
      Menit(expireTimeELMT(*l, i)) = cache;

      SkipLines();

      //delivertime
      ADVWORD();
      cache = 0;
      mul = 1;
      for(int j = currentWord.Length-1; j >= 0; j--){
         cache += mul*( (int) (currentWord.TabWord[j]) - 48);
         mul *= 10;
      }
      Hari(deliverTimeELMT(*l, i)) = cache;

      ADVWORD();
      cache = 0;
      mul = 1;
      for(int j = currentWord.Length-1; j >= 0; j--){
         cache += mul*( (int) (currentWord.TabWord[j]) - 48);
         mul *= 10;
      }
      Jam(deliverTimeELMT(*l, i)) = cache;

      ADVWORD();
      cache = 0;
      mul = 1;
      for(int j = currentWord.Length-1; j >= 0; j--){
         cache += mul*( (int) (currentWord.TabWord[j]) - 48);
         mul *= 10;
      }
      Menit(deliverTimeELMT(*l, i)) = cache;

      SkipLines();


      //aksi
      ADVWORD();
      for(int j = 0; j < currentWord.Length; j++){
         actionELMT(*l, i)[j] = currentWord.TabWord[j];
      }

      //lokasi
      if (kataSama(currentWord, Mix)){
         locationELMT(*l, i) = 'M';
      }
      else if (kataSama(currentWord, Chop)){
         locationELMT(*l, i) = 'C';
      }
      else if (kataSama(currentWord, Fry)){
         locationELMT(*l, i) = 'F';
      }
      else if (kataSama(currentWord, Boil)){
         locationELMT(*l, i) = 'B';
      }
      else if (kataSama(currentWord, Buy)){
         locationELMT(*l, i) = 'T';
      }

      actionELMT(*l, i)[currentWord.Length] = '\0';

      SkipLines();
   }

   //baca resep
   STARTWORD(resepconf);
   cache = 0;
   mul = 1;
   for(int j = currentWord.Length-1; j >= 0; j--){
      cache += mul*( ((int) (currentWord.TabWord[j])) - 48);
      mul *= 10;
   }
   N = cache;
   SkipLines();

   int currentidx = 0;
   boolean ada = false;
   address p;
   
   for (int i = 0; i < N; i++){
      currentidx = 0;
      ADVWORD();
      cache = 0;
      mul = 1;
      for(int j = currentWord.Length-1; j >= 0; j--){
         cache += mul*( ((int) (currentWord.TabWord[j])) - 48);
         mul *= 10;
      }
      currentidx = indexOf(*l, cache);
      setTreeElmt(&resepELMT(*l, currentidx), cache);

      
      ADVWORD();
      while (currentChar != ENTER){
         ADVWORD();
         if (currentChar != ENTER){
            cache = 0;
            mul = 1;
            for(int j = currentWord.Length-1; j >= 0; j--){
               cache += mul*( ((int) (currentWord.TabWord[j])) - 48);
               mul *= 10;
            }
            counter = 0;
            ada = false;
            while ( !ada && counter < listLength(*l)){
               if (treeVal(resepELMT(*l, counter)) == cache){
                  ada = true;
               }
               else{
                  counter += 1;
               }
            }
            if (ada){
               address copier;
               copier = copyTree(resepELMT(*l, counter));
               AssignBranch(&resepELMT(*l, currentidx), &copier);
            }
            else{
               p = CreateNode(cache);
               AssignBranch(&resepELMT(*l, currentidx), &p);
            }
         }
      }


      cache = 0;
      mul = 1;
      for(int j = currentWord.Length-1; j >= 0; j--){
         cache += mul*( ((int) (currentWord.TabWord[j])) - 48);
         mul *= 10;
      }
      counter = 0;
      ada = false;
      while ( !ada && counter < listLength(*l)){
         if (treeVal(resepELMT(*l, counter)) == cache){
            ada = true;
         }
         else{
            counter += 1;
         }
      }
      if (ada){
         AssignBranch(&resepELMT(*l, currentidx), &resepELMT(*l, counter));
      }
      else{
         p = CreateNode(cache);
         AssignBranch(&resepELMT(*l, currentidx), &p);
      }

      SkipLines();
   }
}
/* I.S. l terinisialisasi, file config tidak kosong */
/* F.S. Membuat list berisikan data makanan*/
/* Proses: Membaca file configmakanan*/

void unload_list_statik(list_statik *l){
   
   //Masih banyak leak, belom beres

   for (int i = listLength(*l); i < CAPACITY; i++){
      DeleteNode(&(resepELMT(*l, i)));
   }

}


boolean isEmpty(list_statik l) {
   return idELMT(l, 0) == NIL;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */

boolean isFull(list_statik l) {
   return idELMT(l, CAPACITY-1) != NIL;
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

boolean isIdxValid(list_statik l, IdxType i) {
   return ( (i < CAPACITY) && (i >= 0) );
}

/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(list_statik l, IdxType i) {
   return ( (i < listLength(l) ) && (i >= 0) );
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

int listLength(list_statik l) {
   int length = 0;
   if (isFull(l)) {
      length = CAPACITY;
   }
   else {
      while (idELMT(l, length) != NIL) {
      length += 1;
      }
   }
   return length;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

int indexOf(list_statik l, int idval){
   int indeks = 0;
   boolean ada = false;
   while ( (indeks < listLength(l)) && (!ada) ) {
      if (idELMT(l, indeks) == idval) {
         ada = true;
      }
      else{
         indeks += 1;
      }
   }
   if (!ada){
      indeks = IDX_UNDEF;
   }
   return indeks;
}
// searching dengan id, kalo gaada return idx undef


void printList(list_statik l){
   for(int i =0; i < listLength(l); i++){
      printf("---------------------------------------\n");
      printmakanan(ELMT(l, i));
      printf("\n");
   }
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

void printCatalog(list_statik l){
   printf("List Makanan\n");
   printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
   for(int i =0; i < listLength(l); i++){
      printf("   %d. ", i+1);
      printf("%s - ", namaELMT(l, i));
      if (Hari(expireTimeELMT(l, i)) > 0){
         printf("%d hari",Hari(expireTimeELMT(l, i)));
      }
      if (Jam(expireTimeELMT(l, i)) > 0){
         if (Hari(expireTimeELMT(l, i)) > 0){
            printf(" ");
         }
         printf("%d jam",Jam(expireTimeELMT(l, i)));
      }
      if (Menit(expireTimeELMT(l, i)) > 0){
         if (Jam(expireTimeELMT(l, i)) > 0){
            printf(" ");
         }
         printf("%d menit",Menit(expireTimeELMT(l, i)));
      }
      printf(" - ");
      printf("%s - ", actionELMT(l,i));

      if (locationELMT(l,i) != 'T'){
         printf("0");
      }
      else{
         if (Hari(deliverTimeELMT(l, i)) > 0){
            printf("%d hari",Hari(deliverTimeELMT(l, i)));
         }
         if (Jam(deliverTimeELMT(l, i)) > 0){
            if (Hari(deliverTimeELMT(l, i)) > 0){
               printf(" ");
            }
            printf("%d jam",Jam(deliverTimeELMT(l, i)));
         }
         if (Menit(deliverTimeELMT(l, i)) > 0){
            if (Jam(deliverTimeELMT(l, i)) > 0){
               printf(" ");
            }
            printf("%d menit",Menit(deliverTimeELMT(l, i)));
         }
      }
      printf("\n");
   }
}

void printCookBook(list_statik l){
   int counter = 0;
   int cacheCounter;
   int cacheIdx;

   printf("List Resep\n");
   printf("(aksi yang diperlukan - bahan)\n");
   for(int i =0; i < listLength(l); i++){
      if (locationELMT(l, i) != 'T'){
         counter++;
         printf("   %d. %s\n", counter, namaELMT(l,i));
         printf("     ");
         cacheCounter = counter;
         while (cacheCounter > 0){
            printf(" ");
            cacheCounter = cacheCounter/10;
         }
         printf("%s - ", actionELMT(l,i));

         for (int j = 0; j <= subMaxIdx(resepELMT(l,i)); j++){
            cacheIdx = indexOf(l, treeVal(treeSub(resepELMT(l,i), j)));
            printf("%s", namaELMT(l, cacheIdx));
            if (j != subMaxIdx(resepELMT(l,i))){
               printf(" - ");
            }
         }
         printf("\n");
      }
   }
}


