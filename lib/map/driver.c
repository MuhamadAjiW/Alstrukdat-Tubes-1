#include "map.c"
#include "../mesin_karakter/mesin_karakter.c"
#include "../mesin_kata/mesin_kata.c"

#include <stdio.h>
#include <stdlib.h>

int main(){
    Map m;
    create_map(&m);
    load_map(&m, "../../config/petaconf.txt");
    printMap(m);
    Word w;
    w.Length=4;
    printMap(m);
    return 0;

}
// gcc driver.c map.c ../matrix/matrix.c ../point/point.c ../mesin_kata/mesin_kata.c ../mesin_karakter/mesin_karakter.c -o mp