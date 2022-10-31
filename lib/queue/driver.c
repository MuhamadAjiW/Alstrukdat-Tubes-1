#include <stdio.h>
#include "prioqueue.c"
#include "../list_statik/list_statik.c"
#include "../tree/tree.c"
#include "../mesin_kata/mesin_kata.c"
#include "../mesin_karakter/mesin_karakter.c"
#include "../makanan/makanan.c"
#include "../waktu/waktu.c"


int main(){
    int confirmDone = 0;
    PrioQueue q1;
    makanan dump;
    list_statik testlist;
    create_list_statik(&testlist);
    load_list_statik(&testlist);
    //header program
    

    //angka di parameter editMakananTest itu waktu, ganti aja kalo mau
    //buat dan nambah makanan ke queue

    MakeEmpty(&q1, 1);

    Enqueue(&q1, ELMT(testlist, 0));

    Enqueue(&q1, ELMT(testlist, 1));

    Enqueue(&q1, ELMT(testlist, 2));

    //print isi queue sementara 
    printf("max = %d\n", MaxEl(q1));

    PrintInventory(q1);
    printf("\n");

    Enqueue(&q1, ELMT(testlist, 3));

    PrintInventory(q1);
    printf("\n");

    //pop head dari queue
    Dequeue(&q1, &dump);
    Dequeue(&q1, &dump);
    Dequeue(&q1, &dump);

    printf("max = %d\n", MaxEl(q1));
    PrintInventory(q1);
    printf("\n");

    unload_list_statik(&testlist);
    DeAlokasi(&q1);
    //akhir program
    printf("Done!");
    scanf("%d", &confirmDone);
    return 0;
}