#include "list_statik.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int confirmDone = 0;
    list_statik testlist;
    //header program

    //tulis program di tengah sini
    create_list_statik(&testlist);
    printList(testlist);
    printf("compile success!\n");

    deallocateList(&testlist);
    //akhir program
    printf("Done!");    
    scanf("%d", &confirmDone);
    return 0;
}