#include "list_statik.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int confirmDone = 0;
    //header program
    
    list_statik testlist;
    create_list_statik(&testlist);

    load_list_statik(&testlist);
    printList(testlist);

    printf("\ncompile success!\n");

    //akhir program
    printf("Done!");    
    scanf("%d", &confirmDone);
    return 0;
}