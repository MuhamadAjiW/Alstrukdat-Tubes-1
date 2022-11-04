#include <stdio.h>
#include "waktu.c"
#include "../mesin_kata/mesin_kata.c"
#include "..\makanan\makanan.h"
#include <string.h>
#include "../simulator/simulator.c"
#include "../queue/prioqueue.c"

/* int main()
{
    char *str;
    printf("Enter Command: ");

    input();
    Word BUY;
    Word MIX;
    Word CHOP;
    Word FRY;
    Word BOIL;
    Word MOVE;
    BUY.Length = 3;
    MIX.Length = 3;
    CHOP.Length = 4;
    FRY.Length = 3;
    BOIL.Length = 4;
    MOVE.Length = 4;
    BUY.TabWord[0] = 'B';
    BUY.TabWord[1] = 'U';
    BUY.TabWord[2] = 'Y';
    MIX.TabWord[0] = 'M';
    MIX.TabWord[1] = 'I';
    MIX.TabWord[2] = 'X';
    CHOP.TabWord[0] = 'C';
    CHOP.TabWord[1] = 'H';
    CHOP.TabWord[2] = 'O';
    CHOP.TabWord[3] = 'P';
    FRY.TabWord[0] = 'F';
    FRY.TabWord[1] = 'R';
    FRY.TabWord[2] = 'Y';
    BOIL.TabWord[0] = 'B';
    BOIL.TabWord[1] = 'O';
    BOIL.TabWord[2] = 'I';
    BOIL.TabWord[3] = 'L';
    MOVE.TabWord[0] = 'M';
    MOVE.TabWord[1] = 'O';
    MOVE.TabWord[2] = 'V';
    MOVE.TabWord[3] = 'E';
    if ((kataSama(BUY, currentWord)) || (kataSama(MIX, currentWord)) || (kataSama(CHOP, currentWord)) ||
        (kataSama(FRY, currentWord)) || (kataSama(BOIL, currentWord)) || (kataSama(MOVE, currentWord)))
    {
        waktu t;
        createTime(&t);
        CreateTimeTest(&t, 0, 1, 2);
        long int menit = TIMEToMenit(t);
        menit += 1;
        t = MenitToTIME(menit);
        printTime(t);
        printf("\n");

        /* INV(S) ;
        createTime(&expireTime);
        CreateTimeTest(&expireTime, 0, 1, 2);
        menit = TIMEToMenit(expireTime);
        menit -= 1;
        expireTime = MenitToTIME(menit);
        printTime(expireTime);
        printf("\n");
 
        waktu deliverTime;
        createTime(&deliverTime);
        CreateTimeTest(&deliverTime, 0, 1, 2);
        menit = TIMEToMenit(deliverTime);
        menit -= 1;
        deliverTime = MenitToTIME(menit);
        printTime(deliverTime);
        printf("\n");   
    }
} */
void mekanismeWaktu(Simulator * p)
{
    PrioQueue inv = INV(*p);
    int i = 0;
    int j = Head(inv);
    while (i < NBElmt(inv)) {
        waktu temp = Time(inv, j);
        Time(inv, j) = MenitToTIME(TIMEToMenit(temp)-1);
        if (j == MaxEl(inv)-1) {
            j = 0;
        }
        else {
            j += 1;
        }
        i += 1;
    }
}