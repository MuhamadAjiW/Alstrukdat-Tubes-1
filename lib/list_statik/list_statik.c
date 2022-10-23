//ADT List dari praktikum, list rapat kiri

#include "list_statik.h"
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

void load_list_statik(list_statik *l){
   /*
   FILE* makananconf;
   FILE* resepconf;
   char stringParser[PANJANGNAMA];
   char tempReader;
   int makananLength;
   int resepLength;
   int id;

   char contentmakanan[1500];

   makananconf = fopen("../../config/makananconf.txt", "r");
   makananLength = (int)(fgets(contentmakanan, 1500, makananconf));
   for(int i = 0; i < makananLength; i++){
      fgets(contentmakanan, 1500, makananconf)
      while 
   }

   char contentresep[1500];
   resepconf = fopen("../../config/resepconf.txt", "r");
   fgets(contentresep, 1500, resepconf);


   fclose(makananconf);
   fclose(resepconf);
   */
}
/* I.S. l terinisialisasi */
/* F.S. Membuat list berisikan data makanan*/
/* Proses: Membaca file configmakanan*/

void deallocateList(list_statik *l){
   for (int i = 0; i < CAPACITY; i++){
      free(namaELMT(*l, i));
      free(actionELMT(*l, i));
   }
}
//free malloc di tiap list

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

int indexOf(list_statik l, int idval) {
   int indeks = 0;
   boolean ada = false;
   while ( (indeks < listLength(l)) && (!ada) ) {
      if (idELMT(l, indeks) == idval) {
         ada = true;
         indeks -= 1;
      }
      indeks += 1;
   }
   if (!ada){
      indeks = IDX_UNDEF;
   }
   return indeks;
}
// searching dengan id, kalo gaada return idx undef


void printList(list_statik l) {
   for(int i =0; i < listLength(l); i++){
      printf("----------------------------------\n");
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