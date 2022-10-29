//skema intinya mirip linked list cuman linkednya ke banyak list diakses dari contents


#ifndef _tree_H
#define _tree_H

#include "../etc/boolean.h"

/*Selektor*/
#define treeVal(p) (p)->treeVal
#define parent(p) (p)->parent
#define subStorage(p) (p)->contents
#define subMaxIdx(p) (p)->capacity
#define treeSub(p, i) (p)->contents[(i)]

typedef int infotype;

typedef struct tNode *address;
typedef struct tNode {
    infotype treeVal;
    address parent;
    address *contents;
    int capacity;
} Node;
typedef address Tree;

address CreateNode(infotype X);
/*inisiasi node untuk tree*/

void AssignBranch(Tree *Main, Tree *Branch);
/*nambahin branch*/

void PrintTree(Tree T);
/*cetak tree*/

void DeleteNode(Tree *P);
/*dealokasi tree*/

#endif