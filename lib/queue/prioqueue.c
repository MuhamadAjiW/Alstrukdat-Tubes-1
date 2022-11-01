#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"
#include "../makanan/makanan.c"
#include "../waktu/waktu.c"

boolean IsEmpty (PrioQueue Q) {
    return (Head(Q) == NIL && Tail(Q) == NIL);
}

boolean IsFull (PrioQueue Q) {
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueue Q) {
    if (IsEmpty(Q)) {
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

void CopyQueue(PrioQueue * Q, PrioQueue * targetQ) {
    int nelmt = NBElmt(*Q);
    makanan temp;
    for (int i = 0; i < nelmt; i++) {
        Dequeue(Q, &temp);
        Enqueue(targetQ, temp);
    }
}

void Enqueue (PrioQueue * Q, makanan X) {
    PrioQueue q;

    if (IsFull(*Q)){
        (*Q).T = (makanan *) realloc((*Q).T , (MaxEl(*Q)*2) * sizeof(makanan));
        if ((*Q).T != NULL) {
            MaxEl(*Q) = MaxEl(*Q)*2;
        }
        else {
            MaxEl(*Q) = 0;
        }
    }


    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else {
        if (IsFull(*Q)) {
            MakeEmpty(&q, MaxEl(*Q)*2);
            CopyQueue(Q, &q);
            ExpandQueue(Q);
            CopyQueue(&q, Q);
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
    while (i != Head(*Q) && TLT(Time(*Q, i), Time(*Q, j))) {
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

void Dequeue (PrioQueue * Q, makanan * X) {

    if (MaxEl(*Q) >= 4 && NBElmt(*Q)-1 <= MaxEl(*Q)/4){
        (*Q).T = (makanan *) realloc((*Q).T , (MaxEl(*Q)/2) * sizeof(makanan));
        if ((*Q).T != NULL) {
            MaxEl(*Q) = MaxEl(*Q)/2;
        }
        else {
            MaxEl(*Q) = 0;
        }
    } 

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

    if ((NBElmt(*Q) < MaxEl(*Q)/4) && !IsEmpty(*Q)) {
        PrioQueue q;
        MakeEmpty(&q, MaxEl(*Q)*2);
        CopyQueue(Q, &q);
        CompressQueue(Q);
        CopyQueue(&q, Q);
        DeAlokasi(&q);
    }
}

void PrintPrioQueue (PrioQueue Q) {

    int i = 0;
    int j = Head(Q);
    while (i < NBElmt(Q)) {
        printf("%s", Name(Q, j));
        printTime(Time(Q, j));
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
        printf("    %s - ", Name(Q, j));
        if (Hari(Time(Q, j)) > 0){
            printf("%d hari", Hari(Time(Q, j)));
        }
        else if (Jam(Time(Q, j)) > 0){
            printf("%d jam", Jam(Time(Q, j)));
        }
        else if (Menit(Time(Q, j)) > 0){
            printf("%d menit", Menit(Time(Q, j)));
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