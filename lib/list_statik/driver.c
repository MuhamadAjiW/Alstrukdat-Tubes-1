#include "list_statik.c"
#include "../makanan/makanan.c"
#include "../waktu/waktu.c"
#include "../tree/tree.c"
#include "../mesin_kata/mesin_kata.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int confirmDone = 0;
    //header program
    
    list_statik testlist;
    create_list_statik(&testlist);
 
    load_list_statik(&testlist, "../../config/makananconf.txt", "../../config/resepconf.txt");

    //akhir program
    printf("\ncompile success!\n");
    printf("Done!");    
    scanf("%d", &confirmDone);
    return 0;
}