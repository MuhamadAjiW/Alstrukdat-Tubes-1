#include "list_statik.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int confirmDone = 0;
    //header program
    
    list_statik testlist;
    create_list_statik(&testlist);
 
    load_list_statik(&testlist);
    //printList(testlist);


    printf("%d\n", indexOf(testlist, 21));
    printList(testlist);

    unload_list_statik(&testlist);
    //akhir program
    printf("\ncompile success!\n");
    printf("Done!");    
    scanf("%d", &confirmDone);
    return 0;
}