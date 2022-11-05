#include <stdio.h>
#include "../map/map.c"
#include "../waktu/waktu.c"

int main(){
    Word command;

    Word MOVE,BUY,WAIT,BOIL,CHOP,FRY,MIX,CATALOG,COOKBOOK,INVENTORY,DELIVERY,UNDO,REDO,EXIT;
    MOVE.Length=4;
    MOVE.TabWord[0]='M';
    MOVE.TabWord[1]='O';
    MOVE.TabWord[2]='V';
    MOVE.TabWord[3]='E';

    BUY.Length=3;
    BUY.TabWord[0]='B';
    BUY.TabWord[1]='U';
    BUY.TabWord[2]='Y';

    WAIT.Length=4;
    WAIT.TabWord[0]='W';
    WAIT.TabWord[1]='A';
    WAIT.TabWord[2]='I';
    WAIT.TabWord[3]='T';

    BOIL.Length=4;
    BOIL.TabWord[0]='B';
    BOIL.TabWord[1]='O';
    BOIL.TabWord[2]='I';
    BOIL.TabWord[3]='L';

    CHOP.Length=4;
    CHOP.TabWord[0]='C';
    CHOP.TabWord[1]='H';
    CHOP.TabWord[2]='O';
    CHOP.TabWord[3]='P';

    FRY.Length=3;
    FRY.TabWord[0]='F';
    FRY.TabWord[1]='R';
    FRY.TabWord[2]='Y';

    MIX.Length=3;
    MIX.TabWord[0]='M';
    MIX.TabWord[1]='I';
    MIX.TabWord[2]='X';

    CATALOG.Length=7;
    CATALOG.TabWord[0]='C';
    CATALOG.TabWord[1]='A';
    CATALOG.TabWord[2]='T';
    CATALOG.TabWord[3]='A';
    CATALOG.TabWord[4]='L';
    CATALOG.TabWord[5]='O';
    CATALOG.TabWord[6]='G';

    INVENTORY.Length=9;
    INVENTORY.TabWord[0]='I';
    INVENTORY.TabWord[1]='N';
    INVENTORY.TabWord[2]='V';
    INVENTORY.TabWord[3]='E';
    INVENTORY.TabWord[4]='N';
    INVENTORY.TabWord[5]='T';
    INVENTORY.TabWord[6]='O';
    INVENTORY.TabWord[7]='R';
    INVENTORY.TabWord[8]='Y';

    DELIVERY.Length=8;
    DELIVERY.TabWord[0]='D';
    DELIVERY.TabWord[1]='E';
    DELIVERY.TabWord[2]='L';
    DELIVERY.TabWord[3]='I';
    DELIVERY.TabWord[4]='V';
    DELIVERY.TabWord[5]='E';
    DELIVERY.TabWord[6]='R';
    DELIVERY.TabWord[7]='Y';

    UNDO.Length=4;
    UNDO.TabWord[0]='U';
    UNDO.TabWord[1]='N';
    UNDO.TabWord[2]='D';
    UNDO.TabWord[3]='O';

    REDO.Length=4;
    REDO.TabWord[0]='R';
    REDO.TabWord[1]='E';
    REDO.TabWord[2]='D';
    REDO.TabWord[3]='O';

    EXIT.Length=4;
    EXIT.TabWord[0]='E';
    EXIT.TabWord[1]='X';
    EXIT.TabWord[2]='I';
    EXIT.TabWord[3]='T';

    Map m;
    create_map(&m);
    load_map(&m, "../../config/petaconf.txt");

    waktu curTime;
    createTime(&curTime);

    boolean run=true;
    //Main loop
    while(run){
        printf("BNMO di posisi: ");
        WritePOINT(S(m));
        printf("\n");
        printf("Waktu: ");
        writeHHMM(curTime);
        printf("\n");
        printf("Notifikasi: ");
        //check delivery & expired here

        //
        printf("\n\n");
        printMap(m);
        printf("\n\n");
        printf("Enter Command: ");
        
        input();
        if(kataSama(currentWord,MOVE)){
            ADVWORD_I();
            move_map(&m,currentWord);
            nextMinute(&curTime);
            printf("\n\n");
        }

        else if(kataSama(currentWord,WAIT)){
            Word HR,MNT;
            ADVinput(&HR);
            ADVinput(&MNT);
            int hr,mnt;
            hr=TransformInt(HR);
            mnt=TransformInt(MNT);
            //tunggu fungsi waktu abyan
            printf("\n\n");
        }

        else if(kataSama(currentWord,BUY)){
            if(isNear(m,'T')){
                printf("======================\n");
                printf("=        BUY         =\n");
                printf("======================\n");
                printf("List Bahan Makanan:\n");
                //print list makanan disini

                //
                printf("Kirim 0 untuk exit.\n\n");
                printf("Enter command: ");
                ADVWORD_I();
                if (TransformInt(currentWord)!=0){
                    //beli makanan
                }
                else printf("test\n");

            }   
            else{
                printf("BNMO tidak berada di area telepon!\n");
            }
            printf("\n\n");
        }

        else if(kataSama(currentWord,BOIL)){
            if(isNear(m,'B')){
                printf("======================\n");
                printf("=        BOIL        =\n");
                printf("======================\n");
                printf("List Bahan Makanan yang Bisa Dibuat:\n");
                //print list makanan yang bisa direbus disini

                //
                printf("Kirim 0 untuk exit.\n\n");
                printf("Enter command: ");
                ADVWORD_I();
                if (TransformInt(currentWord)!=0){
                    //olah makanan
                }
                else printf("test\n");

            }   
            else{
                printf("BNMO tidak berada di area merebus!\n");
            }
            printf("\n\n");
        }

        else if(kataSama(currentWord,CHOP)){
            if(isNear(m,'C')){
                printf("======================\n");
                printf("=        CHOP        =\n");
                printf("======================\n");
                printf("List Bahan Makanan yang Bisa Dibuat:\n");
                //print list makanan yang bisa dipotong disini

                //
                printf("Kirim 0 untuk exit.\n\n");
                printf("Enter command: ");
                ADVWORD_I();
                if (TransformInt(currentWord)!=0){
                    //olah makanan
                }
                else printf("test\n");

            }   
            else{
                printf("BNMO tidak berada di area memotong!\n");
            }
            printf("\n\n");
        }

        else if(kataSama(currentWord,FRY)){
            if(isNear(m,'F')){
                printf("======================\n");
                printf("=        FRY         =\n");
                printf("======================\n");
                printf("List Bahan Makanan yang Bisa Dibuat:\n");
                //print list makanan yang bisa digoreng disini

                //
                printf("Kirim 0 untuk exit.\n\n");
                printf("Enter command: ");
                ADVWORD_I();
                if (TransformInt(currentWord)!=0){
                    //olah makanan
                }
                else printf("test\n");

            }   
            else{
                printf("BNMO tidak berada di area penggorengan!\n");
            }
            printf("\n\n");
        }

        else if(kataSama(currentWord,MIX)){
            if(isNear(m,'M')){
                printf("======================\n");
                printf("=        MIX         =\n");
                printf("======================\n");
                printf("List Bahan Makanan yang Bisa Dibuat:\n");
                //print list makanan yang bisa dicampur disini

                //
                printf("Kirim 0 untuk exit.\n\n");
                printf("Enter command: ");
                ADVWORD_I();
                if (TransformInt(currentWord)!=0){
                    //olah makanan
                }
                else printf("test\n");

            }   
            else{
                printf("BNMO tidak berada di area mixing!\n");
            }
            printf("\n\n");
        }


        else if(kataSama(currentWord,CATALOG)){
            printf("List Makanan\n");
            printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
            //Print list makanan disini

            //
            printf("\n\n");
        }

        else if(kataSama(currentWord,COOKBOOK)){
            printf("List Resep\n");
            printf("(aksi yang diperlukan - bahan...)\n");
            //Print list resep disini

            //
            printf("\n\n");
        }
        else if(kataSama(currentWord,INVENTORY)){
            printf("List Makanan di Inventory\n");
            printf("(nama - waktu sisa kedaluwarsa)\n");
            //Print list inventory disini

            //
            printf("\n\n");
        }

        else if(kataSama(currentWord,DELIVERY)){
            printf("List Makanan di Perjalanan\n");
            printf("(nama - waktu sisa delivery)\n");
            //Print list inventory disini

            //
            printf("\n\n");
        }

        else if(kataSama(currentWord,UNDO)){
            //undo algo disini

            //
        }
        else if(kataSama(currentWord,REDO)){
            //redo algo disini

            //
        }

        else if(kataSama(currentWord,EXIT)){
            run=false;
        }

        else{
            printf("Command tidak tersedia! Mohon ulangi lagi.\n\n");
        }
    }

    return 0;
}