#include "waktu.h"
/*dependent packages:
None
*/
#include <stdio.h>
#include <stdlib.h>

void createTime(waktu *t)
{
    Hari(*t) = 0;
    Jam(*t) = 0;
    Menit(*t) = 0;
}
// Inisiasi time
// 0 0 0

void printTime(waktu t)
{
    printf("%d ", Hari(t));
    printf("%d ", Jam(t));
    printf("%d", Menit(t));
}
// Print time
// Format 0 0 0, tanpa enter

boolean IsTIMEValid (int D, int H, int M)
{
    // Dipakai di createTime
    if (D >= 0 && H >= 0 && H <= 23 && M >= 0 && M <= 59)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CreateTimeDirect (waktu * T, int DD, int HH, int MM) 
{
    // Membuat time dengan input manual
    Hari(*T) = DD;
    Jam(*T) = HH;
    Menit(*T) = MM;
}

long TIMEToMenit (waktu T) 
{
    // Dipakai di TLT & TGT
    return (24 * 60 * Hari(T) + 60 * Jam(T) + Menit(T));
}

waktu MenitToTIME (long N)
{
    // Mengubah nilai dari menit kembali ke time
    waktu time;
    int N1, hr, min;
    N1 = N / (24 * 60);
    hr = (N % (24 * 60)) / 60;
    min = (N % (24 * 60)) % 60;
    CreateTimeDirect(&time, N1, hr, min);
    return time;
} 

boolean TLT (waktu T1, waktu T2) 
{
    // True jika T1 < T2, false jika tidak
    if (TIMEToMenit(T1) < TIMEToMenit(T2)) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

boolean TGT (waktu T1, waktu T2)
{
    // True jika T1 > T2, false jika tidak
    if (TIMEToMenit(T1) > TIMEToMenit(T2)) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void writeHHMM(waktu t)
{
    // Menuliskan waktu dalam format HH.MM
    printf("%d.", Jam(t));
    printf("%d", Menit(t));
}

void nextMinute(waktu * T)
{
    // Mengubah T menjadi waktu setelah 1 menit
    long menit = TIMEToMenit(*T);
    *T = MenitToTIME(menit + 1);
}

void nextTime(waktu * T, int givenMinute)
{
    // Mengubah T menjadi waktu setelah (givenMinute) menit
    long menit = TIMEToMenit(*T);
    *T = MenitToTIME(menit + givenMinute);
}

void copyTime(waktu input, waktu *output)
{
    // Menyalin waktu di tempat lain
    Hari(*output) = Hari(input);
    Jam(*output) = Jam(input);
    Menit(*output) = Menit(input);
}