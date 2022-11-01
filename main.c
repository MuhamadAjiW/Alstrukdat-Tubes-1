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
    int inputSignal2;
    int inputSignal3;
    
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
                printf("BNMO di posisi: ");
                WritePOINT(S(m));
                printf("\n");

                printf("Waktu: ");
                printf("\n");

                printf("Notifikasi: ");
                printf("\n");
                
                printMap(m);
                input();
                inputSignal = baseDetection(currentWord);
                inputSignal2 = 0;
                switch (inputSignal)
                {
                case 1:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }

                    if (isNear(m, 'M')){
                        printf("Mix\n");
                        //fungsi mix masuk sini
                    }
                    else{
                        printf("Tidak dapat melakukan aksi.\n");
                    }
                    break;
                case 2:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }

                    if (isNear(m, 'C')){
                        printf("Chop\n");
                        //fungsi chop masuk sini
                    }
                    else{
                        printf("Tidak dapat melakukan aksi.\n");
                    }
                    break;
                case 3:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }

                    if (isNear(m, 'F')){
                        printf("Fry\n");
                        //fungsi fry masuk sini
                    }
                    else{
                        printf("Tidak dapat melakukan aksi.\n");
                    }
                    break;
                case 4:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }

                    if (isNear(m, 'B')){
                        printf("Boil\n");
                        //fungsi boil masuk sini
                    }
                    else{
                        printf("Tidak dapat melakukan aksi.\n");
                    }
                    break;
                case 5:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }

                    if (isNear(m, 'T')){
                        printf("Buy\n");
                        //fungsi buy masuk sini
                    }
                    else{
                        printf("Tidak dapat melakukan aksi.\n");
                    }
                    break;
                case 6:
                    ADVWORD_I();
                    inputSignal2 = moveDetection(currentWord);

                    switch (inputSignal2)
                    {
                    case 1:
                        ADVWORD_I();
                        if (currentWord.Length > 0){
                            printf("Input berlebihan\n");
                            ignoreUntilEnter();
                        }
                        else{
                            moveDir(&m, 'w');
                        }
                        break;
                    case 2:
                        ADVWORD_I();
                        if (currentWord.Length > 0){
                            printf("Input berlebihan\n");
                            ignoreUntilEnter();
                        }
                        else{
                            moveDir(&m, 's');
                        }
                        break;
                    case 3:
                        ADVWORD_I();
                        if (currentWord.Length > 0){
                            printf("Input berlebihan\n");
                            ignoreUntilEnter();
                        }
                        else{
                            moveDir(&m, 'd');
                        }
                        break;
                    case 4:
                        ADVWORD_I();
                        if (currentWord.Length > 0){
                            printf("Input berlebihan\n");
                            ignoreUntilEnter();
                        }
                        else{
                            moveDir(&m, 'a');
                        }
                        break;
                    
                    default:
                    printf("Arah tidak valid\n");
                        break;
                    }
                    break;
                case 7:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        inputSignal2 = TransformInt(currentWord);
                        ADVWORD_I();
                        if (currentWord.Length > 0 && inputSignal2 >= 0){
                            inputSignal3 = TransformInt(currentWord);

                            ADVWORD_I();
                            if (currentWord.Length > 0){
                                printf("Input berlebihan\n");
                                ignoreUntilEnter();
                            }
                            else if (inputSignal3 >= 0){
                                printf("Menunggu untuk %d jam, %d menit\n", inputSignal2, inputSignal3);
                                //Masuk command wait di sini
                            }
                            else{
                                printf("Waktu tidak valid\n");
                            }
                        }
                        else{
                            printf("Waktu tidak valid\n");
                        }
                    }
                    else{
                        printf("Waktu tidak valid\n");
                    }
                    break;

                case 8:
                    printList(catalog);
                    break;
                case -1:
                    runningSignal = 0;
                    printf("Keluar dari program...\n");
                    break;

                
                default:
                    break;
                }
            }
            break;

        case -1:
            printf("\nTerima kasih sudah menggunakan BNMO!\n");
            break;
        
        default:
            printf("\nInvalid Input!\n");
            break;
        }
    }
    


    printf("\nDone!\n");

    return 0;
}