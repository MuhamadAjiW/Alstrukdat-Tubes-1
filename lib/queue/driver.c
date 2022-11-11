#include "prioqueue.c"
#include "../makanan/makanan.c"
#include "../tree/tree.c"
#include "../waktu/waktu.c"


#include <stdio.h>
#include <stdlib.h>

#include "../list_statik/list_statik.c"
#include "../mesin_kata/mesin_kata.c"
#include "../mesin_karakter/mesin_karakter.c"

int main(){
    int confirmDone = 0;
    PrioQueue q1, q2, q3;
    makanan m1, m2, m3, m4, dump;
    list_statik testlist;
    create_list_statik(&testlist);
    load_list_statik(&testlist, "../../config/makananconf.txt", "../../config/resepconf.txt");
    //header program
    
    //angka di parameter editMakananTest itu waktu, ganti aja kalo mau
    //buat dan nambah makanan ke queue

    MakeEmpty(&q1, 1);
    Enqueue(&q1, ELMT(testlist, 0), 2);
    Enqueue(&q1, ELMT(testlist, 0), 2);
    Enqueue(&q1, ELMT(testlist, 0), 2);
    Enqueue(&q1, ELMT(testlist, 0), 2);
    Enqueue(&q1, ELMT(testlist, 1), 2);
    Enqueue(&q1, ELMT(testlist, 1), 2);
    Enqueue(&q1, ELMT(testlist, 1), 2);
    Enqueue(&q1, ELMT(testlist, 2), 2);
    Enqueue(&q1, ELMT(testlist, 2), 2);
    Enqueue(&q1, ELMT(testlist, 2), 2);
    Enqueue(&q1, ELMT(testlist, 2), 2);
    Enqueue(&q1, ELMT(testlist, 2), 2);


    PrintDelivery(q1);
    printf("\n");

    MakeEmpty(&q2, 5);
    Enqueue(&q2, ELMT(testlist, 0), 2);
    Enqueue(&q2, ELMT(testlist, 0), 2);
    Enqueue(&q2, ELMT(testlist, 0), 2);
    Enqueue(&q2, ELMT(testlist, 1), 2);
    Enqueue(&q2, ELMT(testlist, 1), 2);
    Enqueue(&q2, ELMT(testlist, 2), 2);
    
    PrintDelivery(q2);
    printf("\n");

    unload_list_statik(&testlist);
    DeAlokasi(&q1);
    //akhir program
    printf("Done!");
    scanf("%d", &confirmDone);
    return 0;
}