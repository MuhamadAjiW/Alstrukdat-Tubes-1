#include <stdio.h>
#include "prioqueue.c"
#include "../list_statik/list_statik.c"
#include "../tree/tree.c"
#include "../mesin_kata/mesin_kata.c"


int main(){
    int confirmDone = 0;
    PrioQueue q1, q2;
    makanan m1, m2, m3, m4, dump;
    list_statik testlist;
    create_list_statik(&testlist);
    load_list_statik(&testlist, "../../config/makananconf.txt", "../../config/resepconf.txt");
    //header program
    MakeEmpty(&q2, 5);

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

    createmakanan(&m1);
    printf("Other priority queue\n");
    int i = 19;
    while (!queueIsFull(q2)) {
        Enqueue(&q2, m1);
        i += 1;
        editMakananTest(&m1, i);
    }
    PrintPrioQueue(q2);
    if (queueIsFull(q2)) {
        printf("Queue is full\n");
    }
    printf("\n");

    Enqueue(&q2, m1);
    Enqueue(&q2, m1);    

    PrintPrioQueue(q2);
    if (!(queueIsFull(q2))) {
        printf("Queue is not full anymore\n");
    }

    unload_list_statik(&testlist);
    DeAlokasi(&q1);
    //akhir program
    printf("Done!");
    scanf("%d", &confirmDone);
    return 0;
}