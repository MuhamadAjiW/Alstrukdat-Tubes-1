#include "tree.c"

#include <stdio.h>
#include <stdlib.h>

int main(){
    int confirmDone = 0;
    //header program
    address a = CreateNode(1);
    address b = CreateNode(2);
    address c = CreateNode(3);
    address d = CreateNode(4);    
    
    AssignBranch(&a, &b);
    AssignBranch(&b, &c);

    setTreeElmt(&a, 3);

    PrintTree(a);
    printf("\n\n");

    d = copyTree(a);
    PrintTree(d);
    printf("\nPass\n");

    DeleteNode(&a);
    DeleteNode(&d);
    //akhir program
    printf("\nCompile Success!\n");
    scanf("%d", &confirmDone);
    return 0;
}