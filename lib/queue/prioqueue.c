#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"
#include "../makanan/makanan.c"
#include "../waktu/waktu.c"

boolean queueIsEmpty (PrioQueue Q) {
    return (Head(Q) == NIL && Tail(Q) == NIL);
}

boolean queueIsFull (PrioQueue Q) {
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueue Q) {
    if (queueIsEmpty(Q)) {
        return 0;
    }
    else if  (Head(Q) <= Tail(Q)) {
        return Tail(Q) - Head(Q) + 1;
    }
    else {
        return MaxEl(Q) - Head(Q) + Tail(Q) + 1;
    }
}

void MakeEmpty (PrioQueue * Q, int Max) {
    (*Q).T = (makanan *) malloc((Max + 1) * sizeof(makanan));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = NIL;
        Tail(*Q) = NIL;
    }
    else {
        MaxEl(*Q) = 0;
    }
}

void DeAlokasi(PrioQueue * Q) {
    MaxEl(*Q) = 0;
    free((*Q).T);
    
}

void ExpandQueue(PrioQueue * Q) {
    int newCap = MaxEl(*Q)*2;
    DeAlokasi(Q);
    MakeEmpty(Q, newCap);
}

void CompressQueue(PrioQueue * Q) {
    int newCap = MaxEl(*Q)/2;
    DeAlokasi(Q);
    MakeEmpty(Q, newCap);
}

void CopyQueue(PrioQueue * Q, PrioQueue * targetQ, int type) {
    int nelmt = NBElmt(*Q);
    makanan temp;
    for (int i = 0; i < nelmt; i++) {
        Dequeue(Q, &temp, type);
        Enqueue(targetQ, temp, type);
    }
}

void Enqueue (PrioQueue * Q, makanan X, int type) {
    /*Type 1 untuk Expire List, Type 2 untuk Deliver list*/
    PrioQueue q;

    if (queueIsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else {
        if (queueIsFull(*Q)) {
            MakeEmpty(&q, MaxEl(*Q)*2);
            CopyQueue(Q, &q, type);
            ExpandQueue(Q);
            CopyQueue(&q, Q, type);
            DeAlokasi(&q);
        }
        if (Tail(*Q) == MaxEl(*Q)-1) {
            Tail(*Q) = 0;
        }
        else {
            Tail(*Q) += 1;
        }
    }
    InfoTail(*Q) = X;

    int i = Tail(*Q);
    int j;
    if (i == 0) {
        j = MaxEl(*Q) - 1;
    }
    else {
        j = i -1;
    }
    if (type == 1) {
        while (i != Head(*Q) && TLT(Expire(*Q, i), Expire(*Q, j))) {
            makanan temp = Elmt(*Q, i);
            if (i == 0) {
                Elmt(*Q, i) = Elmt(*Q, j);
                Elmt(*Q, j) = temp;
                i = j;
            }
            else {
                Elmt(*Q, i) = Elmt(*Q, i-1);
                Elmt(*Q, i-1) = temp;
                i -= 1;
            }

            if (j == 0) {
                j = MaxEl(*Q) - 1;
            }
            else {
                j -= 1;
            }
        }
    }
    if (type == 2) {
        while (i != Head(*Q) && TLT(Deliver(*Q, i), Deliver(*Q, j))) {
            makanan temp = Elmt(*Q, i);
            if (i == 0) {
                Elmt(*Q, i) = Elmt(*Q, j);
                Elmt(*Q, j) = temp;
                i = j;
            }
            else {
                Elmt(*Q, i) = Elmt(*Q, i-1);
                Elmt(*Q, i-1) = temp;
                i -= 1;
            }

            if (j == 0) {
                j = MaxEl(*Q) - 1;
            }
            else {
                j -= 1;
            }
        }
    }
}

void Dequeue (PrioQueue * Q, makanan * X, int type) {

    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1) {
        Head(*Q) = NIL;
        Tail(*Q) = NIL;
    }
    else {
        if (Head(*Q) == MaxEl(*Q)-1) {
            Head(*Q) = 0;
        }
        else {
            Head(*Q) += 1;
        }
    }

    if ((NBElmt(*Q) < MaxEl(*Q)/4) && !queueIsEmpty(*Q)) {
        PrioQueue q;
        MakeEmpty(&q, MaxEl(*Q));
        CopyQueue(Q, &q, type);
        CompressQueue(Q);
        CopyQueue(&q, Q, type);
        DeAlokasi(&q);
    }
}

void PrintPrioQueue (PrioQueue Q) {

    int i = 0;
    int j = Head(Q);
    while (i < NBElmt(Q)) {
        printmakanan(Elmt(Q, j));
        printf("\n");
        if (j == MaxEl(Q)-1) {
            j = 0;
        }
        else {
            j += 1;
        }
        i += 1;
    }
}

void PrintInventory (PrioQueue Q){
    printf("List makanan di Inventory\n");
    printf("(nama - waktu sisa kedaluwarsa)\n");
    int i = 0;
    int j = Head(Q);
    while (i < NBElmt(Q)) {
        boolean space=false;
        printf("    %s - ", Name(Q, j));
        if (Hari(Expire(Q, j)) > 0){
            printf("%d hari", Hari(Expire(Q, j)));
            space=true;
        }
        if (Jam(Expire(Q, j)) > 0){
            if(space) printf(" ");
            printf("%d jam", Jam(Expire(Q, j)));
            space=true;
        }
        if (Menit(Expire(Q, j)) > 0){
            if(space) printf(" ");
            printf("%d menit", Menit(Expire(Q, j)));
        }

        printf("\n");
        if (j == MaxEl(Q)-1) {
            j = 0;
        }
        else {
            j += 1;
        }
        i += 1;
    }
}

void PrintDelivery (PrioQueue Q){
    printf("List Makanan di Perjalanan\n");
    printf("(nama - waktu sisa delivery)\n");
    int i = 0;
    int j = Head(Q);
    while (i < NBElmt(Q)) {
        printf("    %s - ", Name(Q, j));
        if (Hari(Deliver(Q, j)) > 0){
            printf("%d hari", Hari(Deliver(Q, j)));
        }
        else if (Jam(Deliver(Q, j)) > 0){
            printf("%d jam", Jam(Deliver(Q, j)));
        }
        else if (Menit(Deliver(Q, j)) > 0){
            printf("%d menit", Menit(Deliver(Q, j)));
        }

        printf("\n");
        if (j == MaxEl(Q)-1) {
            j = 0;
        }
        else {
            j += 1;
        }
        i += 1;
    }
}

boolean timeIsZero(PrioQueue Q, int type) {
    if (!queueIsEmpty(Q)) {
        if (type == 1) {
            return TIMEToMenit(Expire(Q, Head(Q))) <= 0;
        }
        if (type == 2) {
            return TIMEToMenit(Deliver(Q, Head(Q))) == 0;
        }
    }
    else return false;
}
