#include "map.h"
#include <stdio.h>
#include <stdlib.h>

void create_map(Map *map){
    ROW_Map(*map)=IDX_UNDEF;
    COL_Map(*map)=IDX_UNDEF;
    int i,j;

    for(i=0;i<=CAPACITYMP;i++){
        for(j=0;j<=CAPACITYMP;j++){
            ELMT_Map(*map,i,j)='*';
        }
    }
    // POINT temp;
    // temp=S(*map);
    // CreatePoint(&temp);
    // CreatePoint(&S(*map));
    Absis(S(*map))=IDX_UNDEF;
    Ordinat(S(*map))=IDX_UNDEF;
}
void load_map(Map *map, char* mapconf){
    char *location;

    START(mapconf);
    int i,j,ii,jj;
    i=1;
    j=1;
    ii = 0;
    jj = 0;
    int spasi;
    spasi=0;
    while((currentChar>='0' && currentChar<='9') || currentChar==' '){
        if(spasi==0){
            if(currentChar>='0' && currentChar<='9'){
                ii=ii*10+(currentChar-'0');
            }
            else{
                spasi=1;
            }
        }
        else{
            if(currentChar>='0' && currentChar<='9'){
                jj=jj*10+(currentChar-'0');
            }
        }
        ADV();
    }

    i = 1;
    while (i <= ii){
        j = 1;
        while (j <= jj){
            if(currentChar=='\n' || currentChar =='\r'){
                ADV();
            }
            else{
                if(currentChar=='S'){
                    Absis(S(*map))=i;
                    Ordinat(S(*map))=j;
                }
                ELMT_Map(*map,i,j)=currentChar;
                ADV();
                j++;
            }
        }
        i++;
    }
    
    
    ROW_Map(*map)=ii;
    COL_Map(*map)=jj;
}

boolean isEmptyMP(Map map){
    return (ROW_Map(map)==IDX_UNDEF && COL_Map(map)==IDX_UNDEF);
}
boolean isIdxValidMP(int i,int j){
    return (i>IDX_MIN && i<=CAPACITYMP && j>IDX_MIN && j<=CAPACITYMP);
}
boolean isIdxEffMP(Map map,int i,int j){
    return (i>IDX_MIN && i<=ROW_Map(map) && j>IDX_MIN && j<=COL_Map(map));
}
void printMap(Map map){
    int i,j;

    for(i=0;i<=ROW_Map(map)+1;i++){
        for(j=0;j<=COL_Map(map)+1;j++){
            if(j!=0){
                printf(" ");
            }
            if(ELMT_Map(map,i,j)=='#'){
                printf(" ");
            }
            else{
                printf("%c",ELMT_Map(map,i,j));
            }
        }
        printf("\n");
    }
}
boolean isNear(Map map,char ch){

    if (Absis(S(map)) != 0){
        if(ELMT_Map(map,Absis(S(map))-1,Ordinat(S(map)))==ch){
            return true;
        }
    }
    
    if (Absis(S(map)) != ROW_Map(map)-1){
        if(ELMT_Map(map,Absis(S(map))+1,Ordinat(S(map)))==ch){
            return true;
        }
    };

    if (Ordinat(S(map)) != 0){
        if(ELMT_Map(map,Absis(S(map)),Ordinat(S(map))-1)==ch){
            return true;
        }
    }

    if (Ordinat(S(map)) != COL_Map(map)-1){
        if(ELMT_Map(map,Absis(S(map)),Ordinat(S(map))+1)==ch){
            return true;
        }
    }  
    
    return false;
}

void move_map(Map *map,Word arah){
    Word NORTH,SOUTH,EAST,WEST;
    NORTH.Length=5;
    NORTH.TabWord[0]='N';
    NORTH.TabWord[1]='O';
    NORTH.TabWord[2]='R';
    NORTH.TabWord[3]='T';
    NORTH.TabWord[4]='H';
    SOUTH.Length=5;
    SOUTH.TabWord[0]='S';
    SOUTH.TabWord[1]='O';
    SOUTH.TabWord[2]='U';
    SOUTH.TabWord[3]='T';
    SOUTH.TabWord[4]='H';
    EAST.Length=4;
    EAST.TabWord[0]='E';
    EAST.TabWord[1]='A';
    EAST.TabWord[2]='S';
    EAST.TabWord[3]='T';
    WEST.Length=4;
    WEST.TabWord[0]='W';
    WEST.TabWord[1]='E';
    WEST.TabWord[2]='S';
    WEST.TabWord[3]='T';

    if(kataSama(arah,NORTH)){
        if(ELMT_Map(*map,Absis(S(*map))-1,Ordinat(S(*map)))=='#'){
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map)))='#';
            ELMT_Map(*map,Absis(S(*map))-1,Ordinat(S(*map)))='S';

            Absis(S(*map))--;
        }
    }
    else if(kataSama(arah,SOUTH)){
        if(ELMT_Map(*map,Absis(S(*map))+1,Ordinat(S(*map)))=='#'){
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map)))='#';
            ELMT_Map(*map,Absis(S(*map))+1,Ordinat(S(*map)))='S';

            Absis(S(*map))++;
        }
    }
    else if(kataSama(arah,EAST)){
        if(ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map))+1)=='#'){
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map)))='#';
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map))+1)='S';

            Ordinat(S(*map))++;
        }
    }
    else if(kataSama(arah,WEST)){
        if(ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map))-1)=='#'){
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map)))='#';
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map))-1)='S';
            
            Ordinat(S(*map))--;
        }
    }
}
/* I.S. map terdefinisi*/
/* F.S. Posisi S pindah sesuai arah*/

void moveDir(Map *map,char arah){
    /*pake wasd yes*/
    if(arah == 'w'){
        if(ELMT_Map(*map,Absis(S(*map))-1,Ordinat(S(*map)))=='#'){
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map)))='#';
            ELMT_Map(*map,Absis(S(*map))-1,Ordinat(S(*map)))='S';

            Absis(S(*map))--;
        }
    }
    else if(arah == 's'){
        if(ELMT_Map(*map,Absis(S(*map))+1,Ordinat(S(*map)))=='#'){
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map)))='#';
            ELMT_Map(*map,Absis(S(*map))+1,Ordinat(S(*map)))='S';

            Absis(S(*map))++;
        }
    }
    else if(arah == 'd'){
        if(ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map))+1)=='#'){
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map)))='#';
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map))+1)='S';

            Ordinat(S(*map))++;
        }
    }
    else if(arah == 'a'){
        if(ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map))-1)=='#'){
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map)))='#';
            ELMT_Map(*map,Absis(S(*map)),Ordinat(S(*map))-1)='S';
            
            Ordinat(S(*map))--;
        }
    }
}