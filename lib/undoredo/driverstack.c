#include "stackur.c"

int main(){
    // printf("aman");
    Stackur S;
    StrukturUndo X;
    Simulator S1;
    Map M;
    waktu W;
    int proses;
    CreateEmptyStackur(&S);
    createSimulator(&S1);
    create_map(&M);
    load_map(&M, "../../config/petaconf.txt");
    createTime(&W);
    proses=12;
    subsStrukturUR(&X,M,W,S1,proses);
    PushStackur(&S,X);
    PrintTopUR(&S);
    printf("\n");

    nextMinute(&W);
    moveDir(&M,'e');
    proses=13;
    subsStrukturUR(&X,M,W,S1,proses);
    PushStackur(&S,X);
    PrintTopUR(&S);

    int i=0;
    for(i=0;i<10;i++){
        nextMinute(&W);
    }
    moveDir(&M,'d');
    proses=13;
    subsStrukturUR(&X,M,W,S1,proses);
    PushStackur(&S,X);
    PrintTopUR(&S);
    printf("\n");

    PopStackur(&S);
    PrintTopUR(&S);

    return 0;
}