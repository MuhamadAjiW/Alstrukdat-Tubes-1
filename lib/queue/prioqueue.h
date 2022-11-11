
#ifndef prioqueue_H
#define prioqueue_H

#include "../etc/boolean.h"
#include "../makanan/makanan.h"

#define NIL -1

typedef int addressQ;

typedef struct {
    makanan * T;   /* tabel penyimpan elemen */
    addressQ HEAD;  /* alamat penghapusan */
    addressQ TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} PrioQueue;

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueue, maka akses elemen : */
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define Elmt(Q,i)   (Q).T[(i)]
#define Name(Q,i)   (Q).T[(i)].nama
#define Expire(Q,i)    (Q).T[(i)].expireTime
#define Deliver(Q,i)    (Q).T[(i)].deliverTime

/* ********* Prototype ********* */
boolean queueIsEmpty (PrioQueue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean queueIsFull (PrioQueue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

void ExpandQueue(PrioQueue * Q);
void CompressQueue(PrioQueue * Q);
void CopyQueue(PrioQueue Q, PrioQueue * targetQ, int type);

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueue * Q, makanan X, int type);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
/* Type 1 untuk Expire List, Type 2 untuk Deliver List*/
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueue * Q, makanan * X, int type);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueue (PrioQueue Q);
/* Mencetak isi queue Q ke layar */

void PrintInventory (PrioQueue Q);
/*cetak dengan gaya inventory sesuai spek*/

void PrintDelivery (PrioQueue Q);

boolean timeIsZero(PrioQueue Q, int type);
/*cek waktu head pada queue bernilai 0 atau tidak*/
/* Type 1 untuk Expire List, Type 2 untuk Deliver List*/

#endif
