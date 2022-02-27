// ------------------
// Created by shinku 
// on 16/02/2020.
// -----------------

#ifndef Queue_Queue_H
#define Queue_Queue_H

//estrutura de um nó da fila
struct Item{
    int prioridade;
    int dado;
};

//estrutura da fila
struct Queue{
    struct Item *itens;
    int capacidade, ini, fim, tamanho;
    int id;
};

//nomes das estruturas
typedef struct Item Item;
typedef struct Queue Queue;

Queue* CriaFila(int id, int capacidade); //função que cria uma nova fila.

void DestroiFila(Queue *fila); //função que destroi por completo uma fila.

int isFull(Queue *fila); //função retorna verdadeiro caso a fila esteja cheia.

int isEmpty(Queue* fila); //função retorna verdadeiro caso a fila esteja vazia.

void AdicionaItem(Queue *fila, int d, int chave); //função que adiciona um item a fila.

Item ExtraiItem(Queue *fila); //função que extrai um item da fila.

//Item ExtraiItemPref(Queue *fila);

#endif //Queue_Queue_H