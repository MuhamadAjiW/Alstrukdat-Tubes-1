#include <stdio.h>
#include "../map/map.c"
#include "../waktu/waktu.c"

int main(){
    Word command;

    Word MOVE;
    MOVE.Length=4;
    MOVE.TabWord[0]='M';
    MOVE.TabWord[1]='O';
    MOVE.TabWord[2]='V';
    MOVE.TabWord[3]='E';

    Map m;
    create_map(&m);
    load_map(&m);

    waktu curTime;
    createTime(&curTime);


    //Main loop
    while(true){
        printf("BNMO di posisi: ");
        WritePOINT(S(m));
        printf("\n");
        printf("Waktu: ");
        writeHHMM(curTime);
        printf("\n");
        printf("Notifikasi: ");
        printf("\n\n");
        printMap(m);
        printf("\n\n");
        printf("Enter Command: ");
        
        input(&command);
        if(kataSama(command,MOVE)){
            ADVinput(&command);
            move_map(&m,command);
            nextMinute(&curTime);
        }
    }

    return 0;
}