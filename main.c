#include "lib/etc/boolean.h"
// #include "lib/list_statik/list_statik.c"
#include "lib/stack/stack.c"
// #include "lib/tree/tree.c"
#include "lib/undoredo/stackur.c"
// #include "lib/map/map.c"
// #include "lib/queue/prioqueue.c"
#include "lib/waktu/mekanismewaktu.c"
#include <stdio.h>
#include <stdlib.h>
// #include "lib/notif/notif.c"

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
    
    Map m;
    list_statik catalog;
    waktu curTime;
    Simulator BNMO;

    Stackur Undo,Redo;
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
            createSimulator(&BNMO);
            
            //inisialisasi stack undo dan redo
            CreateEmptyStackur(&Undo);
            CreateEmptyStackur(&Redo);
            subsStrukturUR(&temp,m,curTime,BNMO,proses);
            PushStackur(&Undo,temp);
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
                                        makeFood(&BNMO, catalog, counter2, 'm');
                                        mekanismeWaktu(&BNMO, &curTime);
                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area mixing!\n");
                        }
                    }
                    subsStrukturUR(&temp, m, curTime, BNMO, proses);
                    PushStackur(&Undo, temp);
                    Topur(Redo)=-1; // tidak bisa redo
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
                                        makeFood(&BNMO, catalog, counter2, 'c');
                                        mekanismeWaktu(&BNMO, &curTime);
                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area memotong!\n");
                        }
                    }
                    subsStrukturUR(&temp, m, curTime, BNMO, proses);
                    PushStackur(&Undo, temp);
                    Topur(Redo)=-1; // tidak bisa redo
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
                                        makeFood(&BNMO, catalog, counter2, 'f');
                                        mekanismeWaktu(&BNMO, &curTime);
                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area penggorengan!\n");
                        }
                    }
                    subsStrukturUR(&temp, m, curTime, BNMO, proses);
                    PushStackur(&Undo, temp);
                    Topur(Redo)=-1; // tidak bisa redo
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
                                        makeFood(&BNMO, catalog, counter2, 'b');
                                        mekanismeWaktu(&BNMO, &curTime);
                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area merebus!\n");
                        }
                    }
                    subsStrukturUR(&temp, m, curTime, BNMO, proses);
                    PushStackur(&Undo, temp);
                    Topur(Redo)=-1; // tidak bisa redo
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
                                        buyMakanan(&BNMO,ELMT(catalog, counter2));
                                        mekanismeWaktu(&BNMO, &curTime);
                                        //sementara bakalan make add inventory secara instan, tapi janlup ganti yes

                                    }
                                }
                            }
                        }
                        else{
                            printf("BNMO tidak berada di area telepon!\n");
                        }
                    }
                    subsStrukturUR(&temp, m, curTime, BNMO, proses);
                    PushStackur(&Undo, temp);
                    Topur(Redo)=-1; // tidak bisa redo
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
                            mekanismeWaktu(&BNMO, &curTime);
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
                            mekanismeWaktu(&BNMO, &curTime);
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
                            mekanismeWaktu(&BNMO, &curTime);
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
                            mekanismeWaktu(&BNMO, &curTime);
                        }
                        break;
                    
                    default:
                    printf("Arah tidak valid\n");
                        break;
                    }
                    subsStrukturUR(&temp, m, curTime, BNMO, proses);
                    PushStackur(&Undo, temp);
                    Topur(Redo)=-1; // tidak bisa redo
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
                                    printf("Menunggu untuk %d jam, %d menit\n", inputSignal2, inputSignal3);
                                    waktu wait;
                                    CreateTimeTest(&wait, 0,inputSignal2, inputSignal3);
                                    long plusMinute = TIMEToMenit(wait);
                                    passTime(&BNMO, plusMinute, &curTime);
                                    inventoryDeliveryMechanism(&BNMO);
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
                    subsStrukturUR(&temp, m, curTime, BNMO, proses);
                    PushStackur(&Undo, temp);
                    Topur(Redo)=-1; // tidak bisa redo
                    break;

                case 8:
                    printCatalog(catalog);
                    break;
                case 9:
                    PrintInventory(INV(BNMO));
                    break;
                case 10:
                    PrintDelivery(DLV(BNMO));
                    break;
                case 11:
                    //undo
                    /*Undo ketika stack undo berisi*/
                    if(Topur(Undo)>0){
                        temp=InfoTopur(Undo);
                        PopStackur(&Undo);
                        subsElementUR(InfoTopur(Undo), &m,&curTime,&BNMO,&proses);
                        PushStackur(&Redo, temp);

                    }
                    else{
                        printf("Undo tidak bisa dilakukan\n");
                    }
                    break;
                case 12:
                    //redo
                    if(!IsEmptyStackur(Redo)){
                        temp=InfoTopur(Redo);
                        PopStackur(&Redo);
                        subsElementUR(temp, &m,&curTime,&BNMO,&proses);
                        PushStackur(&Undo, temp);

                    }
                    else{
                        printf("Redo tidak bisa dilakukan\n");
                    }
                    break;
                    break;
                case 13:
                    printCookBook(catalog);
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