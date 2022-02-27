#include <stdio.h>
    #include <stdlib.h>
#include "Queue.h"

Queue* CriaFila(int id, int capacidade){

    //Aloca espaço para a fila
    Queue *novo = (Queue*) malloc(sizeof(Queue));
    if(!novo){
        printf("Erro ao alocar memoria");
        exit(-1);
    }

    //Aloca espaço apra os itens da fila
    novo->itens = (Item*) malloc(capacidade * sizeof(Item));
    if(!novo->itens){
        printf("Erro ao alocar memoria");
        exit(-1);
    }

    //cria a fila
    novo->capacidade = capacidade;
    novo->ini = novo->tamanho = 0;
    novo->fim = capacidade - 1;
    novo->id = id;
    return novo;
}

int isFull(Queue *fila){
    return (fila->tamanho == fila->capacidade);
}

int isEmpty(Queue *fila){
    return (fila->tamanho == 0);
}

void DestroiFila(Queue *fila){
    free(fila->itens);
    free(fila);
}

void AdicionaItem(Queue *fila, int d, int chave){

    //caso a fila esteja cheia
    if(isFull(fila)){
        printf("A fila está cheia");
    }

    //cria o item  
    Item i;
    i.dado = d;
    i.prioridade = chave;

    //adiciona o item no fila 
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->itens[fila->fim] = i;
    fila->tamanho++;
}

Item ExtraiItem(Queue *fila){

    Item i;
    //caso a fila esteja vazia
    if(isEmpty(fila)){
        printf("A fila está vazia.");
        return i;
    }

    i = fila->itens[fila->ini];
    fila->ini = (fila->ini + 1) % fila->capacidade;
    fila->tamanho--;
    return i;
}

int Max(Queue *fila){
    int max = fila->ini;
    for(int i = max + 1; i <= fila->fim; i++){
        if(fila->itens[max].prioridade < fila->itens[i].prioridade)
            max = i;
    }
    return max;
}

/*
Item ExtraiItemPref(Queue *fila){

    Item i;
    //caso a fila esteja vazia
    if(isEmpty(fila)){
        printf("A fila está vazia.");
        return i;
    }
}*/