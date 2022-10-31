#include <stdio.h>
#include "prioqueue.c"

int main(){
    int confirmDone = 0;
    PrioQueue q1, q2;
    makanan m1, m2, m3, m4, dump;
    //header program
    MakeEmpty(&q1, 5);
    MakeEmpty(&q2, 5);

    //angka di parameter editMakananTest itu waktu, ganti aja kalo mau
    //buat dan nambah makanan ke queue
    createmakanan(&m1);
    editMakananTest(&m1, 15);
    Enqueue(&q1, m1);

    createmakanan(&m2);
    editMakananTest(&m2, 20);
    Enqueue(&q1, m2);

    createmakanan(&m3);
    editMakananTest(&m3, 17);
    Enqueue(&q1, m3);

    //print isi queue sementara
    PrintPrioQueue(q1);
    printf("\n");

    createmakanan(&m4);
    editMakananTest(&m4, 16);
    Enqueue(&q1, m4);

    PrintPrioQueue(q1);
    printf("\n");
    
    //pop head dari queue
    Dequeue(&q1, &dump);
    Dequeue(&q1, &dump);

    PrintPrioQueue(q1);
    printf("\n");

    editMakananTest(&m1, 22);
    Enqueue(&q1, m1);

    PrintPrioQueue(q1);
    printf("\n");

    editMakananTest(&m1, 19);
    Enqueue(&q1, m1);

    PrintPrioQueue(q1);
    printf("\n");

    printf("Other priority queue\n");
    int i = 19;
    while (!IsFull(q2)) {
        Enqueue(&q2, m1);
        i += 1;
        editMakananTest(&m1, i);
    }
    PrintPrioQueue(q2);
    if (IsFull(q2)) {
        printf("Queue is full\n");
    }
    printf("\n");

    Enqueue(&q2, m1);
    Enqueue(&q2, m1);    

    PrintPrioQueue(q2);
    if (!(IsFull(q2))) {
        printf("Queue is not full anymore\n");
    }


    //akhir program
    printf("Done!");
    scanf("%d", &confirmDone);
    return 0;
}