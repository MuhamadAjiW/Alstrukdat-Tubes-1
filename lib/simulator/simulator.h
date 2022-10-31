
#include "../queue/prioqueue.h"
#include "../waktu/waktu.h"
#include "../etc/boolean.h"
#include "../mesin_karakter/mesin_karakter.h"
#include "../mesin_kata/mesin_kata.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    Word namaPengguna;
    int currentLoc;
    PrioQueue Inventory;
    
} Simulator;
