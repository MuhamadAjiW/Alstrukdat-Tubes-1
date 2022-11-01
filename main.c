#include "lib/etc/boolean.h"
#include "lib/list_statik/list_statik.c"
#include "lib/queue/prioqueue.c"
#include "lib/simulator/simulator.c"
#include "lib/stack/stack.c"
#include "lib/tree/tree.c"
#include "lib/map/map.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
    /*KAMUS*/
    boolean endProgram;
    int runningSignal;
    int inputSignal;
    Map m;
    list_statik catalog;

    /*ALGORITMA*/
    runningSignal = 0;

    while (runningSignal != 1 && runningSignal != -1){
        printASCII1();
        input();

        runningSignal = initDetection(currentWord);
        switch (runningSignal)
        {
        case 1:
            create_map(&m);
            load_map(&m, "config/petaconf.txt");
            create_list_statik(&catalog);
            load_list_statik(&catalog, "config/makananconf.txt", "config/resepconf.txt");
            
            while (runningSignal == 1){
                input();
                runningSignal = initDetection(currentWord);
            }

            break;

        case -1:
            printf("Quitting!\n");
            break;
        
        default:
            printf("Invalid Input!\n");
            break;
        }
    }
    


    printf("\nDone!\n");

    return 0;
}