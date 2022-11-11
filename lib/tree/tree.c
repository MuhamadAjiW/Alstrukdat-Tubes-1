#include "tree.h"
/*dependent packages:
None
*/
#include <stdio.h>
#include <stdlib.h>

address CreateNode(infotype val){
    address p = (address) malloc (sizeof(Node));
    if (p != NULL){
        treeVal(p) = val;
        parent(p) = NULL;
        subMaxIdx(p) = -1;
    }
    else{
        printf("alokasi gagal.\n");
    }
    return p;
}


void setTreeElmt(Tree *P, infotype X){
    treeVal(*P) = X;
}

void AssignBranch(Tree *Main, Tree *Branch){
    if (subMaxIdx(*Main) == -1){
        subStorage(*Main) = (address*) malloc (1*(sizeof(Node)));
    }
    else{
        subStorage(*Main) = (address*) realloc (subStorage(*Main), (subMaxIdx(*Main)+2)*(sizeof(Node)));
    }

    
    treeSub(*Main, (subMaxIdx(*Main)+1)) = *Branch;
    subMaxIdx(*Main)++;
    parent(*Branch) = *Main;
    
}

void PrintTree(Tree T){
    printf("%d", treeVal(T));
    if (subMaxIdx(T) >= 0){
        printf(", branch = (");
        for (int i = 0; i <= subMaxIdx(T); i++){
            PrintTree(treeSub(T, i));
            if (i != subMaxIdx(T)){
                printf(", ");
            }
        }
        printf(")");
    }
}
/*cetak tree*/

void DeleteNode(Tree *P){
    for (int i = 0; i <= subMaxIdx(*P); i++){
        DeleteNode(&treeSub(*P, i));
    }
    //printf("test");
    if (parent(*P) != NULL){
        int a=subMaxIdx(parent(*P))+1;
        subStorage(parent(*P)) = (address*) realloc (subStorage(parent(*P)), (a)*(sizeof(Node)));
        subMaxIdx(parent(*P))--;
    }
    //printf("test2");
    //free(subStorage(*P));
    free(*P);
    //printf("test3");
}
/*dealokasi tree*/
