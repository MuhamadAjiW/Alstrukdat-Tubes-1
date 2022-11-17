#include "list_statik.c"
#include "../makanan/makanan.c"
#include "../waktu/waktu.c"
#include "../tree/tree.c"
#include "../mesin_kata/mesin_kata.c"
#include "../mesin_karakter/mesin_karakter.c"

#include <stdio.h>
#include <stdlib.h>

int main(){
    int confirmDone = 0;
    //header program
    list_statik l;

    create_list_statik(&l);
    printf("\nhere!\n");
    load_list_statik(&l, "../../config/makananconf.txt", "../../config/resepconf.txt");
    printList(l);
    unload_list_statik(&l);
    
    //akhir program
    printf("\ncompile success!\n");
    
    //akhir program
    printf("Done!");    
    scanf("%d", &confirmDone);
    return 0;
}