#include "mesin_kata.h"
/*dependent packages:
#include "../mesin_karakter/mesin_karakter.c"
*/
#include <stdio.h>

boolean endWord;
Word currentWord;

void printCurrentKata(){
    for(int i = 0; i < currentWord.Length; i++){
        printf("%c", currentWord.TabWord[i]);
    }
}

boolean kataSama(Word target, Word asal){
    boolean sama = true;

    if (target.Length != asal.Length){
        sama = false;
    }
    else{
        int i = 0;
        while (i < target.Length && sama){
            if (target.TabWord[i] != asal.TabWord[i]){
                sama = false;
            }
            i++;
        }
    }

    return sama;
}

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void SkipLines()
{
    while (currentChar == ENTER || currentChar == CARRIAGERETURN)
    {
        ADV();
    }
}

void STARTWORD(char* location)
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = MARK;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START(location);
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        endWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;
    while (currentChar != BLANK && currentChar != MARK && currentChar != ENTER)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            if (currentChar != CARRIAGERETURN){
                currentWord.TabWord[currentWord.Length] = currentChar;
                currentWord.Length++;
                ADV();
            }
            else{
                ADV();
            }
        }
        else
            break;
    }
}


/***********/
/***INPUT***/
/***********/

/*Untuk input, mark diganti enter*/



void IgnoreBlanks_I()
{
    /*Ignore Blanks untuk input*/
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = ENTER */
    while (currentChar == BLANK)
    {
        ADV_I();
    }
}


void ignoreUntilEnter(){
/*I.S.  currentChar Sembarang*/
/*F.S.  Membaca seluruh input hingga '\n', kemudian mengembalikan pesan
        "Input salah"*/
    while(currentChar!=ENTER){
        ADV_I();
    }
}

void CopyWord_I()
{
    /*CopyWord untuk input*/
    /*Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = ENTER;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    currentWord.Length = 0;;
    while (currentChar != BLANK  && currentChar != ENTER)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV_I();
        }
        else{ //input overflow
            ignoreUntilEnter();
    }
}
}

void ADVWORD_I()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks_I();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        CopyWord_I();
        IgnoreBlanks();
    }
}

void LowerCase(Word *kata){
/* I.S. kata terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */
    int i;
    i = 0;
    if(kata->Length>0){
        while (i<kata->Length){
            if((kata->TabWord[i]>=65)&& (kata->TabWord[i]<=90)){
                kata->TabWord[i] += 32;
            }
        i+=1;
        }
    }
}

void Uppercase(Word* kata){
    int i;
    i = 0;
    if(kata->Length>0){
        while (i<kata->Length){
            if((kata->TabWord[i]>=97)&& (kata->TabWord[i]<=122)){
                kata->TabWord[i] -= 32;
            }
        i+=1;
        }
    }
}




void input(){
/* I.S.  w sembarang 
   F.S.  w menyimpan kata pertama dari input;
         Jika currentChara adalah ENTER, maka endWord = true;
         

   Catatan: 
   - Iringkan dengan ignoreUntilEnter dan cek endword untuk validasi input
   - fry halo akan dibaca fry,

    */
   /*ALGORITMA*/
    START_I();
    IgnoreBlanks();
    if(currentChar==ENTER){
        endWord=true;
    }else{
        CopyWord_I();
        endWord = false;
    }
}


int TransformInt(Word w){
/*  I.S. w terdefinisi
    F.S. Word diubah menjadi int
        Jika gagal, length diubah menjadi 0
        Tidak bisa handle overflow
        Tidak menerima bilangan negatif
        Jika input tidak valid, mengembalikan -1*/
/*KAMUS LOKAL*/
int i, temp, retval;
boolean valid = true;

/*ALGORITMA*/
retval =0;
i=0;
while(i<(w.Length) && valid){
    if(w.TabWord[i]<=57 && w.TabWord[i]>=48){
        temp = w.TabWord[i];
        retval = (retval)*10 +(temp-48);
        i++;
    }else{
        valid = false;
        retval = -1;
    }
}
if (w.Length == 0)
{
    valid = false;
    retval = -1;
}

return retval;
}

void displayWord(Word w){
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    if(w.Length == 0){
        printf("Input kosong");
    }else{
    for(i=0; i<w.Length; i++){
        printf("%c", w.TabWord[i]);
    }
    }
}

void ADVinput(Word *w){
   /*ALGORITMA*/
    IgnoreBlanks_I();
    if(currentChar!=ENTER){
        CopyWord_I(w);
        if(currentChar==ENTER){
            endWord=true;
        }else{
            endWord = false;
        }
    }else{
        endWord=true;
        w->Length =0; 
    }
}
void printASCII1(){
printf("\n\n\n");
printf("==========================================\n\n");
printf("|| _______  __    _  __   __  _______   ||\n");
printf("|| |  _    ||  |  | ||  |_|  ||       | ||\n");
printf("|| | |_|   ||   |_| ||       ||   _   | ||\n");
printf("|| |       ||       ||       ||  | |  | ||\n");
printf("|| |  _   | |  _    ||       ||  |_|  | ||\n");
printf("|| | |_|   || | |   || ||_|| ||       | ||\n");
printf("|| |_______||_|  |__||_|   |_||_______| ||\n\n");

printf("Ketik:\n");

printf("1. START untuk memulai BNMO\n");
printf(" {\\__/}  \n");
printf("  ( ^-^)  \n");
printf(" // > >)   \n\n");

printf("2. EXIT untuk keluar program\n");
printf(" {\\__/})  \n");
printf(" ('.' )  \n");
printf(" <  <  \\   \n");
}

int initDetection(Word kata){
    int signal = 0;
    Word START,EXIT;
    START.Length=5;
    START.TabWord[0]='S';
    START.TabWord[1]='T';
    START.TabWord[2]='A';
    START.TabWord[3]='R';
    START.TabWord[4]='T';
    EXIT.Length=4;
    EXIT.TabWord[0]='E';
    EXIT.TabWord[1]='X';
    EXIT.TabWord[2]='I';
    EXIT.TabWord[3]='T';

    Uppercase(&kata);

    if (kataSama(kata, START)){
        signal = 1;
    }
    else if (kataSama(kata, EXIT)){
        signal = -1;
    }
    return signal;

}

int baseDetection(Word kata){
    Word mix;
    mix.Length = 3;
    mix.TabWord[0] = 'm';
    mix.TabWord[1] = 'i';
    mix.TabWord[2] = 'x';
    

    Word chop;
    chop.Length = 4;
    chop.TabWord[0] = 'c';
    chop.TabWord[1] = 'h';
    chop.TabWord[2] = 'o';
    chop.TabWord[3] = 'p';
    
    
    Word fry;
    fry.Length = 3;
    fry.TabWord[0] = 'f';
    fry.TabWord[1] = 'r';
    fry.TabWord[2] = 'y';

    Word boil;
    boil.Length = 4;
    boil.TabWord[0] = 'b';
    boil.TabWord[1] = 'o';
    boil.TabWord[2] = 'i';
    boil.TabWord[3] = 'l';

    Word buy;
    buy.Length = 3;
    buy.TabWord[0] = 'b';
    buy.TabWord[1] = 'u';
    buy.TabWord[2] = 'y';

    Word move;
    move.Length = 4;
    move.TabWord[0] = 'm';
    move.TabWord[1] = 'o';
    move.TabWord[2] = 'v';
    move.TabWord[3] = 'e';

    Word exit;
    exit.Length = 4;
    exit.TabWord[0] = 'e';
    exit.TabWord[1] = 'x';
    exit.TabWord[2] = 'i';
    exit.TabWord[3] = 't';

    Word wait;
    wait.Length = 4;
    wait.TabWord[0] = 'w';
    wait.TabWord[1] = 'a';
    wait.TabWord[2] = 'i';
    wait.TabWord[3] = 't';

    Word catalog;
    catalog.Length = 7;
    catalog.TabWord[0] = 'c';
    catalog.TabWord[1] = 'a';
    catalog.TabWord[2] = 't';
    catalog.TabWord[3] = 'a';
    catalog.TabWord[4] = 'l';
    catalog.TabWord[5] = 'o';
    catalog.TabWord[6] = 'g';

    Word inventory;
    inventory.Length=9;
    inventory.TabWord[0]='i';
    inventory.TabWord[1]='n';
    inventory.TabWord[2]='v';
    inventory.TabWord[3]='e';
    inventory.TabWord[4]='n';
    inventory.TabWord[5]='t';
    inventory.TabWord[6]='o';
    inventory.TabWord[7]='r';
    inventory.TabWord[8]='y';

    Word delivery;
    delivery.Length=8;
    delivery.TabWord[0]='d';
    delivery.TabWord[1]='e';
    delivery.TabWord[2]='l';
    delivery.TabWord[3]='i';
    delivery.TabWord[4]='v';
    delivery.TabWord[5]='e';
    delivery.TabWord[6]='r';
    delivery.TabWord[7]='y';

    Word undo;
    undo.Length=4;
    undo.TabWord[0]='u';
    undo.TabWord[1]='n';
    undo.TabWord[2]='d';
    undo.TabWord[3]='o';

    Word redo;
    redo.Length=4;
    redo.TabWord[0]='r';
    redo.TabWord[1]='e';
    redo.TabWord[2]='d';
    redo.TabWord[3]='o';

    Word cookbook;
    cookbook.Length=8;
    cookbook.TabWord[0]='c';
    cookbook.TabWord[1]='o';
    cookbook.TabWord[2]='o';
    cookbook.TabWord[3]='k';
    cookbook.TabWord[4]='b';
    cookbook.TabWord[5]='o';
    cookbook.TabWord[6]='o';
    cookbook.TabWord[7]='k';
    
    
    LowerCase(&currentWord);

    int signal;
    signal = 0;

    printf("\n");
    if (kataSama(currentWord, mix)){
        signal = 1;
    }
    else if (kataSama(currentWord, chop)){
        signal = 2;
    }
    else if (kataSama(currentWord, fry)){
        signal = 3;
    }
    else if (kataSama(currentWord, boil)){
        signal = 4;
    }
    else if (kataSama(currentWord, buy)){
        signal = 5;
    }
    else if (kataSama(currentWord, move)){
        signal = 6;
    }
    else if (kataSama(currentWord, wait)){
        signal = 7;
    }
    else if (kataSama(currentWord, catalog)){
        signal = 8;
    }
    else if (kataSama(currentWord, inventory)){
        signal = 9;
    }
    else if (kataSama(currentWord, delivery)){
        signal = 10;
    }
    else if (kataSama(currentWord, undo)){
        signal = 11;
    }
    else if (kataSama(currentWord, redo)){
        signal = 12;
    }
    else if (kataSama(currentWord, cookbook)){
        signal = 13;
    }
    else if (kataSama(currentWord, exit)){
        signal = -1;
    }

    return signal;
}

int moveDetection(Word kata){
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

    Uppercase(&kata);

    int signal = 0;
    if(kataSama(kata,NORTH)){
        signal = 1;
    }
    else if(kataSama(kata,SOUTH)){
        signal = 2;
    }
    else if(kataSama(kata,EAST)){
        signal = 3;
    }
    else if(kataSama(kata,WEST)){
        signal = 4;
    }
    return signal;
}
