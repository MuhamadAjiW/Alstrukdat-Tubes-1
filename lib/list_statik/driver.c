#include "list_statik.c"
#include "minilist.c"
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
    minilist listMix;
    minilist listChop;
    minilist listFry;
    minilist listBoil;
    minilist listBuy;
    create_list_statik(&testlist);
    createMiniList(&listMix);
    createMiniList(&listChop);
    createMiniList(&listFry);
    createMiniList(&listBoil);
    createMiniList(&listBuy);
 
    load_list_statik(&testlist, "../../config/makananconf.txt", "../../config/resepconf.txt");
    load_miniList(testlist, &listMix, 'm');
    load_miniList(testlist, &listChop, 'c');
    load_miniList(testlist, &listFry, 'f');
    load_miniList(testlist, &listBoil, 'b');
    load_miniList(testlist, &listBuy, 't');

    printList(testlist);
    printMiniList(testlist, listMix);
    printMiniList(testlist, listChop);
    printMiniList(testlist, listFry);
    printMiniList(testlist, listBoil);
    printMiniList(testlist, listBuy);
    

    unload_list_statik(&testlist);
    //akhir program
    printf("\ncompile success!\n");
    printf("Done!");    
    scanf("%d", &confirmDone);
    return 0;
}