/* Definisi type boolean */

#include "waktu.h"
#include <stdio.h>
#include <stdlib.h>

void createTime(waktu *t){
    Hari(*t) = 0;
    Jam(*t) = 0;
    Menit(*t) = 0;
}
//inisiasi time
//isinya 0 0 0

void printTime(waktu t){
    printf("%d ", Hari(t));
    printf("%d ", Jam(t));
    printf("%d", Menit(t));
}
//print time
//format 0 0 0, tanpa enter