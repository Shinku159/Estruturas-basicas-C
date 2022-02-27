#include <stdio.h>
    #include <stdlib.h>
#include "Stack.h"

//estrutura de um nó na pilha
struct No{
    int dado;
    struct No *prox;
};

//estrutura da pilha
struct Stack{
    struct No *sentinela;
    int id;
};

Stack* CriaPilha(int id){
    
    //Aloca espaço para a nova pilha
    Stack *novo = (Stack*) malloc(sizeof(Stack));
    if(!novo){
        printf("Erro ao alocar memoria");
        exit(-1);
    }

    //Aloca espaço para a sentinela da pilha
    novo->sentinela = (No*) malloc(sizeof(No));
    if(!novo->sentinela){
        printf("Erro ao alocar memoria");
        exit(-1);
    }

    //cria a nova pilha com o id inserido. 
    novo->id = id;
    novo->sentinela->dado = -100000;
    novo->sentinela->prox = NULL;
    return novo;
}

void Push(Stack *pilha, int d){

    //caso se envie uma pilha não inicializada
    if(pilha == NULL){
        printf("Essa pilha ainda nao foi inicializada");
        return;
    }

    //Aloca espaço para o novo nó(Item)
    No* novo = (No*) malloc(sizeof(No));
    if(!novo){
        printf("Erro na alocacao de memoria");
        exit(-1);
    }

    //cria e adiciona novo a pilha;
    novo->dado = d;
    novo->prox = pilha->sentinela->prox;
    pilha->sentinela->prox = novo;
}

int Pull(Stack *pilha){

    //caso se envie uma pilha não inicializada
    if(pilha == NULL){
        printf("Essa pilha ainda nao foi inicializada");
        return -1;
    }

    //pega o item no topo da pilha.
    No* aux = pilha->sentinela->prox;
    
    //se a pilha estiver vazia
    if(aux == NULL){
        printf("Essa pilha esta vazia");
        return -1;
    }

    //desempilha o item.
    pilha->sentinela->prox = aux->prox;
    int d = aux->dado;
    free(aux);
    return d;
}

void DeletaPilha(Stack *pilha){
    if(pilha->sentinela->prox != NULL){
        int d = Pull(pilha);
        while(d != -1){
            d = Pull(pilha);
        }   
    }
    free(pilha->sentinela);
    free(pilha); 
}



