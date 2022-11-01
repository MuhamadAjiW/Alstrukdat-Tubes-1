#include <stdio.h>
#include "stack.c"
#include "../mesin_kata/mesin_kata.c"
#include "../etc/boolean.h"

int main(){
    int confirmDone = 0;
    Stack s;
    Word popped;
    //header program

    CreateEmpty(&s);

    //test dengan test.txt, boleh diedit isinya
    STARTWORD("test.txt");
    while (!endWord) {
        printCurrentKata();
        printf("\n");
        Push(&s, currentWord);
        ADVWORD();
    }

    //print isi stack
    while (!IsEmpty(s)) {
        Pop(&s, &popped);
        printf("%s", popped.TabWord);
    }
    printf("\n");

    //akhir program
    printf("Done!");
    scanf("%d", &confirmDone);
    return 0;
}