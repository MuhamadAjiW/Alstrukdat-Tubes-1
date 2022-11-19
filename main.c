#include "lib/etc/boolean.h"
#include "lib/list_statik/list_statik.c"
#include "lib/makanan/makanan.c"
#include "lib/map/map.c"
#include "lib/matriks/matriks.c"
#include "lib/mesin_karakter/mesin_karakter.c"
#include "lib/mesin_kata/mesin_kata.c"
#include "lib/notif/notif.c"
#include "lib/point/point.c"
#include "lib/queue/prioqueue.c"
#include "lib/simulator/simulator.c"
#include "lib/stack/stack.c"
#include "lib/tree/tree.c"
#include "lib/waktu/waktu.c"
#include "lib/waktu/mekanismewaktu.c"

#include <stdio.h>
#include <stdlib.h>

int main(){
    /*KAMUS*/
    boolean endProgram;
    int counter;
    int counter2;
    int cacheMax;
    int runningSignal;
    int inputSignal;
    int inputSignal2;
    int inputSignal3;
    int redo; // buat nandain bisa redo atau ngga
    int proses; // buat nandain proses apa yang dilakukan

    int FryTime = 5;
    int ChopTime = 4;
    int mixTime = 3;
    int BoilTime = 15;
    int BuyTime = 1;

    Map m;
    list_statik catalog;
    List_Link notifPasser;
    waktu curTime;
    waktu wait;
    waktu cacheTime;
    Simulator BNMO;

    Stack Undo,Redo;
    StrukturUndo temp;

    /*ALGORITMA*/
    runningSignal = 0;

    while (runningSignal != 1 && runningSignal != -1){
        printASCII1();
        input();

        runningSignal = initDetection(currentWord);

        ADVWORD_I();
        if (currentWord.Length > 0){
            ignoreUntilEnter();
            runningSignal = 0;
        }

        switch (runningSignal)
        {
        case 1:
            create_map(&m);
            load_map(&m, "config/petaconf.txt");
            create_list_statik(&catalog);
            load_list_statik(&catalog, "config/makananconf.txt", "config/resepconf.txt");

            createTime(&curTime);
            createTime(&cacheTime);
            createSimulator(&BNMO);
            
            //inisialisasi stack undo dan redo
            createListLink(&notifPasser);
            CreateEmptyStack(&Undo);
            CreateEmptyStack(&Redo);
            while (runningSignal == 1){
                printf("BNMO di posisi: ");
                WritePOINT(S(m));
                printf("\n");

                printf("Waktu: ");
                writeHHMM(curTime);            
                printf("\n");

                // print notif di sini
                printAllNotif(&NOTIF(BNMO));
                
                printMap(m);
                printf("Enter Command: ");

                input();
                inputSignal = baseDetection(currentWord);
                inputSignal2 = -1;
                inputSignal3 = -1;
                counter = 0;
                switch (inputSignal)
                {
                case 1:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        if (isNear(m, 'M')){
                            printf("======================\n");
                            printf("=        MIX         =\n");
                            printf("======================\n");
                            printf("List Bahan Makanan yang Bisa Dibuat:\n");
                            for (int i = 0; i < listLength(catalog); i++){
                                if (locationELMT(catalog, i) == 'M'){
                                    counter++;
                                    printf("   %d. %s\n", counter, namaELMT(catalog, i));
                                }
                            }
                            cacheMax = counter;
                            printf("\nKirim 0 untuk exit.\n");
                            while (inputSignal == 1){
                                printf("\nEnter Command: ");
                                input();

                                counter = 0;
                                inputSignal2 = TransformInt(currentWord);

                                ADVWORD_I();
                                if (currentWord.Length > 0){
                                    printf("Input berlebihan\n");
                                    ignoreUntilEnter();
                                    inputSignal2 = -1;
                                }
                                else{
                                    if (inputSignal2 == 0){
                                        inputSignal = 0;
                                    }
                                    else if (inputSignal2 > cacheMax || inputSignal2 < 0){
                                        printf("Input tidak valid.\n");
                                    }
                                    else{
                                        counter2 = 0;
                                        while (counter < inputSignal2){
                                            if (locationELMT(catalog, counter2) == 'M'){
                                                counter++;
                                            }
                                            counter2++;
                                        }
                                        counter2--;
                                        PushStack(&Undo, BNMO, curTime, '1', counter2);
                                        
                                        makeFood(&BNMO, catalog, counter2, 'm');
                                        passTime(&BNMO, mixTime, &curTime);
                                        inventoryDeliveryMechanism(&BNMO, &Undo);;
                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area mixing!\n");
                        }
                    }
                    Top(Redo)=-1; // tidak bisa redo
                    break;
                case 2:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        if (isNear(m, 'C')){
                            printf("======================\n");
                            printf("=        CHOP        =\n");
                            printf("======================\n");
                            printf("List Bahan Makanan yang Bisa Dibuat:\n");
                            for (int i = 0; i < listLength(catalog); i++){
                                if (locationELMT(catalog, i) == 'C'){
                                    counter++;
                                    printf("   %d. %s\n", counter, namaELMT(catalog, i));
                                }
                            }
                            cacheMax = counter;
                            printf("\nKirim 0 untuk exit.\n");
                            while (inputSignal == 2){
                                printf("\nEnter Command: ");
                                input();

                                counter = 0;
                                inputSignal2 = TransformInt(currentWord);

                                ADVWORD_I();
                                if (currentWord.Length > 0){
                                    printf("Input berlebihan\n");
                                    ignoreUntilEnter();
                                    inputSignal2 = -1;
                                }
                                else{
                                    if (inputSignal2 == 0){
                                        inputSignal = 0;
                                    }
                                    else if (inputSignal2 > cacheMax || inputSignal2 < 0){
                                        printf("Input tidak valid.\n");
                                    }
                                    else{
                                        counter2 = 0;
                                        while (counter < inputSignal2){
                                            if (locationELMT(catalog, counter2) == 'C'){
                                                counter++;
                                            }
                                            counter2++;
                                        }
                                        counter2--;
                                        PushStack(&Undo, BNMO, curTime, '2', counter2);

                                        makeFood(&BNMO, catalog, counter2, 'c');
                                        passTime(&BNMO, ChopTime, &curTime);
                                        inventoryDeliveryMechanism(&BNMO, &Undo);
                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area memotong!\n");
                        }
                    }

                    Top(Redo)=-1; // tidak bisa redo
                    break;
                case 3:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        if (isNear(m, 'F')){
                            printf("======================\n");
                            printf("=        FRY         =\n");
                            printf("======================\n");
                            printf("List Bahan Makanan yang Bisa Dibuat:\n");
                            for (int i = 0; i < listLength(catalog); i++){
                                if (locationELMT(catalog, i) == 'F'){
                                    counter++;
                                    printf("   %d. %s\n", counter, namaELMT(catalog, i));
                                }
                            }
                            cacheMax = counter;
                            printf("\nKirim 0 untuk exit.\n");
                            while (inputSignal == 3){
                                printf("\nEnter Command: ");
                                input();

                                counter = 0;
                                inputSignal2 = TransformInt(currentWord);

                                ADVWORD_I();
                                if (currentWord.Length > 0){
                                    printf("Input berlebihan\n");
                                    ignoreUntilEnter();
                                    inputSignal2 = -1;
                                }
                                else{
                                    if (inputSignal2 == 0){
                                        inputSignal = 0;
                                    }
                                    else if (inputSignal2 > cacheMax || inputSignal2 < 0){
                                        printf("Input tidak valid.\n");
                                    }
                                    else{
                                        counter2 = 0;
                                        while (counter < inputSignal2){
                                            if (locationELMT(catalog, counter2) == 'F'){
                                                counter++;
                                            }
                                            counter2++;
                                        }
                                        counter2--;
                                        PushStack(&Undo, BNMO, curTime, '3', counter2);

                                        makeFood(&BNMO, catalog, counter2, 'f');
                                        passTime(&BNMO, FryTime, &curTime);
                                        inventoryDeliveryMechanism(&BNMO, &Undo);;
                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area penggorengan!\n");
                        }
                    }
                    Top(Redo)=-1; // tidak bisa redo
                    break;
                case 4:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        if (isNear(m, 'B')){
                            printf("======================\n");
                            printf("=        BOIL        =\n");
                            printf("======================\n");
                            printf("List Bahan Makanan yang Bisa Dibuat:\n");
                            for (int i = 0; i < listLength(catalog); i++){
                                if (locationELMT(catalog, i) == 'B'){
                                    counter++;
                                    printf("   %d. %s\n", counter, namaELMT(catalog, i));
                                }
                            }
                            cacheMax = counter;
                            printf("\nKirim 0 untuk exit.\n");
                            while (inputSignal == 4){
                                printf("\nEnter Command: ");
                                input();

                                counter = 0;
                                inputSignal2 = TransformInt(currentWord);

                                ADVWORD_I();
                                if (currentWord.Length > 0){
                                    printf("Input berlebihan\n");
                                    ignoreUntilEnter();
                                    inputSignal2 = -1;
                                }
                                else{
                                    if (inputSignal2 == 0){
                                        inputSignal = 0;
                                    }
                                    else if (inputSignal2 > cacheMax || inputSignal2 < 0){
                                        printf("Input tidak valid.\n");
                                    }
                                    else{
                                        counter2 = 0;
                                        while (counter < inputSignal2){
                                            if (locationELMT(catalog, counter2) == 'B'){
                                                counter++;
                                            }
                                            counter2++;
                                        }
                                        counter2--;
                                        PushStack(&Undo, BNMO, curTime, '4', counter2);

                                        makeFood(&BNMO, catalog, counter2, 'b');
                                        passTime(&BNMO, BoilTime, &curTime);
                                        inventoryDeliveryMechanism(&BNMO, &Undo);
                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area merebus!\n");
                        }
                    }
                    Top(Redo)=-1; // tidak bisa redo
                    break;
                case 5:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        if (isNear(m, 'T')){
                            printf("======================\n");
                            printf("=        BUY         =\n");
                            printf("======================\n");
                            printf("List Bahan Makanan:\n");
                            for (int i = 0; i < listLength(catalog); i++){
                                if (locationELMT(catalog, i) == 'T'){
                                    counter++;
                                    printf("   %d. %s\n", counter, namaELMT(catalog, i));
                                }
                            }
                            cacheMax = counter;
                            printf("\nKirim 0 untuk exit.\n");
                            while (inputSignal == 5){
                                printf("\nEnter Command: ");
                                input();

                                counter = 0;
                                inputSignal2 = TransformInt(currentWord);

                                ADVWORD_I();
                                if (currentWord.Length > 0){
                                    printf("Input berlebihan\n");
                                    ignoreUntilEnter();
                                    inputSignal2 = -1;
                                }
                                else{
                                    if (inputSignal2 == 0){
                                        inputSignal = 0;
                                    }
                                    else if (inputSignal2 > cacheMax || inputSignal2 < 0){
                                        printf("Input tidak valid.\n");
                                    }
                                    else{
                                        counter2 = 0;
                                        while (counter < inputSignal2){
                                            if (locationELMT(catalog, counter2) == 'T'){
                                                counter++;
                                            }
                                            counter2++;
                                        }
                                        counter2--;
                                        printf("Berhasil memesan %s. %s akan diantar dalam ", namaELMT(catalog, counter2), namaELMT(catalog, counter2));
                                        if (Hari(deliverTimeELMT(catalog, counter2)) > 0){
                                            printf("%d hari",Hari(deliverTimeELMT(catalog, counter2)));
                                        }
                                        if (Jam(deliverTimeELMT(catalog, counter2)) > 0){
                                            if (Hari(deliverTimeELMT(catalog, counter2)) > 0){
                                            printf(" ");
                                            }
                                            printf("%d jam",Jam(deliverTimeELMT(catalog, counter2)));
                                        }
                                        if (Menit(deliverTimeELMT(catalog, counter2)) > 0){
                                            if (Jam(deliverTimeELMT(catalog, counter2)) > 0){
                                            printf(" ");
                                            }
                                            printf("%d menit",Menit(deliverTimeELMT(catalog, counter2)));
                                        }
                                        printf("\n");
                                        //fungsi buy masuk sini
                                        PushStack(&Undo, BNMO, curTime, '5', counter2);

                                        buyMakanan(&BNMO,ELMT(catalog, counter2));
                                        passTime(&BNMO, BuyTime, &curTime);
                                        inventoryDeliveryMechanism(&BNMO, &Undo);
                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area telepon!\n");
                        }
                    }
                    Top(Redo)=-1; // tidak bisa redo
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
                            if(moveDir(&m, 'w')){
                                PushStack(&Undo, BNMO, curTime, 'w', 0);
                                passTime(&BNMO, 1, &curTime);
                                inventoryDeliveryMechanism(&BNMO, &Undo);
                            }
                            else{
                                printf("Tidak bisa bergerak ke utara\n");
                            }

                        }
                        break;
                    case 2:
                        ADVWORD_I();
                        if (currentWord.Length > 0){
                            printf("Input berlebihan\n");
                            ignoreUntilEnter();
                        }
                        else{
                            if (moveDir(&m, 's')){
                                PushStack(&Undo, BNMO, curTime, 's', 0);
                                passTime(&BNMO, 1, &curTime);
                                inventoryDeliveryMechanism(&BNMO, &Undo);
                            }
                            else{
                                printf("Tidak bisa bergerak ke selatan\n");
                            }
                        }
                        break;
                    case 3:
                        ADVWORD_I();
                        if (currentWord.Length > 0){
                            printf("Input berlebihan\n");
                            ignoreUntilEnter();
                        }
                        else{
                            if (moveDir(&m, 'd')){
                                PushStack(&Undo, BNMO, curTime, 'd', 0);
                                passTime(&BNMO, 1, &curTime);
                                inventoryDeliveryMechanism(&BNMO, &Undo);
                            }
                            else{
                                printf("Tidak bisa bergerak ke timur\n");
                            }
                        }
                        break;
                    case 4:
                        ADVWORD_I();
                        if (currentWord.Length > 0){
                            printf("Input berlebihan\n");
                            ignoreUntilEnter();
                        }
                        else{
                            if (moveDir(&m, 'a')){
                                PushStack(&Undo, BNMO, curTime, 'a', 0);
                                passTime(&BNMO, 1, &curTime);
                                inventoryDeliveryMechanism(&BNMO, &Undo);
                            }
                            else{
                                printf("Tidak bisa bergerak ke barat\n");
                            }
                        }
                        break;
                    
                    default:
                    printf("Arah tidak valid\n");
                        break;
                    }
                    Top(Redo) = -1; // tidak bisa redo
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
                            else{
                                if (inputSignal3 >= 0){
                                    if (inputSignal2 == 0 && inputSignal3 == 0){
                                        printf("Waktu tidak valid\n");
                                    }
                                    else{
                                        PushStack(&Undo, BNMO, curTime, '6', 0);

                                        printf("Menunggu untuk %d jam, %d menit\n", inputSignal2, inputSignal3);
                                        CreateTimeDirect(&wait, 0,inputSignal2, inputSignal3);
                                        long plusMinute = TIMEToMenit(wait);
                                        passTime(&BNMO, plusMinute, &curTime);
                                        inventoryDeliveryMechanism(&BNMO, &Undo);

                                        Top(Redo)=-1; // tidak bisa redo
                                    }
                                }
                                else{
                                    printf("Waktu tidak valid\n");
                                }
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
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else printCatalog(catalog);
                    break;
                case 9:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else PrintInventory(INV(BNMO));
                    break;
                case 10:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else PrintDelivery(DLV(BNMO));
                    break;
                case 11:
                    //undo
                    /*Undo ketika stack undo berisi*/
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        if (Top(Undo)>=0){
                            if(((Undo).T[Top(Undo)].proses) != -1){
                                if ((Undo).T[(Undo).TOP].movement == 'w'){
                                    PushStack(&Redo, BNMO, curTime, 's', (Undo).T[(Undo).TOP].proses);
                                }
                                else if ((Undo).T[(Undo).TOP].movement == 's'){
                                    PushStack(&Redo, BNMO, curTime, 'w', (Undo).T[(Undo).TOP].proses);
                                }
                                else if ((Undo).T[(Undo).TOP].movement == 'd'){
                                    PushStack(&Redo, BNMO, curTime, 'a', (Undo).T[(Undo).TOP].proses);
                                }
                                else if ((Undo).T[(Undo).TOP].movement == 'a'){
                                    PushStack(&Redo, BNMO, curTime, 'd', (Undo).T[(Undo).TOP].proses);
                                }

                                else if ((Undo).T[(Undo).TOP].movement == '1'){
                                    PushStack(&Redo, BNMO, curTime, 'p', (Undo).T[(Undo).TOP].proses);
                                }
                                else if ((Undo).T[(Undo).TOP].movement == '2'){
                                    PushStack(&Redo, BNMO, curTime, 'o', (Undo).T[(Undo).TOP].proses);
                                }
                                else if ((Undo).T[(Undo).TOP].movement == '3'){
                                    PushStack(&Redo, BNMO, curTime, 'i', (Undo).T[(Undo).TOP].proses);
                                }
                                else if ((Undo).T[(Undo).TOP].movement == '4'){
                                    PushStack(&Redo, BNMO, curTime, 'u', (Undo).T[(Undo).TOP].proses);
                                }
                                else if ((Undo).T[(Undo).TOP].movement == '5'){
                                    PushStack(&Redo, BNMO, curTime, 'y', (Undo).T[(Undo).TOP].proses);
                                }
                                else if ((Undo).T[(Undo).TOP].movement == '6'){
                                    PushStack(&Redo, BNMO, curTime, 't', (Undo).T[(Undo).TOP].proses);
                                }

                                else{
                                    PushStack(&Redo, BNMO, curTime, (Undo).T[(Undo).TOP].movement, (Undo).T[(Undo).TOP].proses);
                                }
                                concatNotDel(NotifPrev(Undo), &notifPasser);
                                concatDel(&notifPasser, &NotifPrev(Redo));
                                convertUR(&NotifPrev(Redo), 1);
                                PopStack(&Undo, &BNMO, &m, &curTime, catalog);
                            }
                            else{
                                printf("Undo tidak bisa dilakukan\n");
                                PopStack(&Undo, &BNMO, &m, &curTime, catalog);
                            }
                        }
                        else{
                            printf("Undo tidak bisa dilakukan\n");
                        }
                    }
                    break;
                case 12:
                    //redo
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        if (Top(Redo)>=0){
                            if(((Redo).T[Top(Redo)].proses) != -1){
                                if ((Redo).T[(Redo).TOP].movement == 'w'){
                                    PushStack(&Undo, BNMO, curTime, 's', (Redo).T[(Redo).TOP].proses);
                                }
                                else if ((Redo).T[(Redo).TOP].movement == 's'){
                                    PushStack(&Undo, BNMO, curTime, 'w', (Redo).T[(Redo).TOP].proses);
                                }
                                else if ((Redo).T[(Redo).TOP].movement == 'd'){
                                    PushStack(&Undo, BNMO, curTime, 'a', (Redo).T[(Redo).TOP].proses);
                                }
                                else if ((Redo).T[(Redo).TOP].movement == 'a'){
                                    PushStack(&Undo, BNMO, curTime, 'd', (Redo).T[(Redo).TOP].proses);
                                }

                                else if ((Redo).T[(Redo).TOP].movement == 'p'){
                                    PushStack(&Undo, BNMO, curTime, '1', (Redo).T[(Redo).TOP].proses);
                                }
                                else if ((Redo).T[(Redo).TOP].movement == 'o'){
                                    PushStack(&Undo, BNMO, curTime, '2', (Redo).T[(Redo).TOP].proses);
                                }
                                else if ((Redo).T[(Redo).TOP].movement == 'i'){
                                    PushStack(&Undo, BNMO, curTime, '3', (Redo).T[(Redo).TOP].proses);
                                }
                                else if ((Redo).T[(Redo).TOP].movement == 'u'){
                                    PushStack(&Undo, BNMO, curTime, '4', (Redo).T[(Redo).TOP].proses);
                                }
                                else if ((Redo).T[(Redo).TOP].movement == 'y'){
                                    PushStack(&Undo, BNMO, curTime, '5', (Redo).T[(Redo).TOP].proses);
                                }
                                else if ((Redo).T[(Redo).TOP].movement == 't'){
                                    PushStack(&Undo, BNMO, curTime, '6', (Redo).T[(Redo).TOP].proses);
                                }

                                else{
                                    PushStack(&Undo, BNMO, curTime, (Redo).T[(Redo).TOP].movement, (Redo).T[(Redo).TOP].proses);
                                }
                                concatNotDel(NotifPrev(Redo), &notifPasser);
                                concatDel(&notifPasser, &NotifPrev(Undo));
                                convertUR(&NotifPrev(Undo), 2);
                                PopStack(&Redo, &BNMO, &m, &curTime, catalog);
                            }
                            else{
                                printf("Redo tidak bisa dilakukan\n");
                                PopStack(&Redo, &BNMO, &m, &curTime, catalog);
                            }
                        }
                        else{
                            printf("Redo tidak bisa dilakukan\n");
                        }
                    }
                    break;
                case 13:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else printCookBook(catalog);
                    break;

                case 14:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else rekomendasiMakanan(catalog, BNMO);
                    break;


                case -1:
                    ADVWORD_I();
                    if (currentWord.Length > 0){
                        printf("Input berlebihan\n");
                        ignoreUntilEnter();
                    }
                    else{
                        runningSignal = 0;
                        unload_list_statik(&catalog);
                        
                        printf("Keluar dari program...\n");
                    }
                    break;
                default:
                    printf("Input tidak valid\n");
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
    return 0;
}