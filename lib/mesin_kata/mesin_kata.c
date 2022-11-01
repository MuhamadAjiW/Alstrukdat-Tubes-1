#include <stdio.h>
#include "mesin_kata.h"

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
    while (currentChar == ENTER)
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
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
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
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        endWord = true;
    }
    else
    {
        CopyWord_I();
        ignoreUntilEnter();
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
    printf("Ya welkam lah pokoknya.\n");
    printf("(START/EXIT)\n");
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
