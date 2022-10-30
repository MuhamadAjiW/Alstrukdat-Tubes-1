/* Definisi type boolean */

#include "../etc/boolean.h"
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

boolean IsTIMEValid (int D, int H, int M) {
    if (D >= 0 && H >= 0 && H <= 23 && M >= 0 && M <= 59) {
        return true;
    }
    else {
        return false;
    }
}

void CreateTimeTest (waktu * T, int DD, int HH, int MM) {
    if (IsTIMEValid(DD, HH, MM)) {
        Hari(*T) = DD;
        Jam(*T) = HH;
        Menit(*T) = MM;
    }
}

long TIMEToMenit (waktu T) {
    return (24*60*Hari(T) + 60*Jam(T) + Menit(T));
}

waktu MenitToTIME (long N) {
    waktu time;
    int N1, hr, min;
    N1 = N / (24*60);
    hr = (N % (24*60)) / 60;
    min = (N % (24*60)) % 60;
    CreateTimeTest(&time, N1, hr, min);
    return time;
} 

boolean TLT (waktu T1, waktu T2) {
    if (TIMEToMenit(T1) < TIMEToMenit(T2)) {
        return true;
    }
    else {
        return false;
    }
}

boolean TGT (waktu T1, waktu T2){
    if (TIMEToMenit(T1) > TIMEToMenit(T2)) {
        return true;
    }
    else {
        return false;
    }
}

