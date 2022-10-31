#include "matriks.h"
/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
    ROW_EFF(*m)=nRows;
    COL_EFF(*m)=nCols;
    int i,j;
    for(i=0;i<nRows;i++){
        for(j=0;j<nCols;j++){
            ELMT_Matrix(*m,i,j)='.';
        }
    }
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

void readMatrix(Matrix *m, int nRow, int nCol){
    createMatrix(nRow,nCol,m);
    int i,j;
    for(i=0;i<nRow;i++){
        for(j=0;j<nCol;j++){
            scanf("%c",&ELMT_Matrix(*m,i,j));
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
    int i,j;
    for(i=0;i<ROW_EFF(m);i++){
        for(j=0;j<COL_EFF(m);j++){
            printf("%c",ELMT_Matrix(m,i,j));
        }
        printf("\n");
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
    return (i>=0 && j>=0);
}


/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
