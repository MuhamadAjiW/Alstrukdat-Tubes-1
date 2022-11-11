#include "simulator.c"
#include "../waktu/waktu.c"
#include "../notif/notif.c"
#include "../queue/prioqueue.c"
#include "../list_statik/list_statik.c"
#include "../makanan/makanan.c"
#include "../tree/tree.c"
#include "../mesin_kata/mesin_kata.c"
#include "../mesin_karakter/mesin_karakter.c"

#include <stdio.h>
#include <stdlib.h>

#include "../waktu/mekanismewaktu.c"

int main(){
    Simulator S;
    createSimulator(&S);

    list_statik testlist;
    create_list_statik(&testlist);
    load_list_statik(&testlist, "../../config/makananconf.txt", "../../config/resepconf.txt");

    addMakanan(&S,ELMT(testlist, 0));
    addMakanan(&S,ELMT(testlist, 1));
    addMakanan(&S,ELMT(testlist, 2));

    PrintInventory(INV(S));
    printf("\n");
    //makanan temp;
    //Dequeue(&INV(S),&temp);
    makanan m=ELMT(testlist,0);

    //mengecek makanan apakah di inventory
    if(checkMakanan(S,m.id)){
        printf("%s ada di Inventory\n",m.nama);
    }

    //menunggu sebanyak 10 menit
    waktu t;
    passTime(&S,10,&t);
    PrintInventory(INV(S));
    printf("\n");
    PrintPrioQueue(INV(S));
    printf("\n");
    
    //mencari index makanan di inventory
    int find;
    find=findMakanan(S,m.id);
    printf("%s ada di index %d\n",m.nama,find);

    //mengeluarkan makanan dari inventory
    
    deleteMakanan(&S,m.id);
    PrintInventory(INV(S));
    printf("\n");
    PrintPrioQueue(INV(S));
    printf("\n");

    return 0;
}