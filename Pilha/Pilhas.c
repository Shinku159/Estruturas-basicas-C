#include <stdio.h>
    #include <stdlib.h>
#include "Stack.h"

int main(int argc, char *argv[]){
    Stack* pilha = CriaPilha(1);
    int d;
    Push(pilha, 1);
    Push(pilha, 2);
    Push(pilha, 3);
    d = Pull(pilha);
    while(d != -1){
        printf("%d ", d);
        d = Pull(pilha);
    }
    printf("\n");
    Push(pilha, 1);
    Push(pilha, 2);
    Push(pilha, 3);
    DeletaPilha(pilha);    
    d = Pull(pilha);
    return 0;
}