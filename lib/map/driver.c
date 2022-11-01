#include <stdio.h>
#include <stdlib.h>
#include "map.c"

int main(){
    Map m;
    create_map(&m);
    load_map(&m, "../../config/petaconf.txt");
    printMap(m);
    Word w;
    w.Length=4;
    w.TabWord[0]='E';
    w.TabWord[1]='A';
    w.TabWord[2]='S';
    w.TabWord[3]='T';
    move_map(&m,w);
    move_map(&m,w);
    printMap(m);
    return 0;

}
// gcc driver.c map.c ../matrix/matrix.c ../point/point.c ../mesin_kata/mesin_kata.c ../mesin_karakter/mesin_karakter.c -o mp