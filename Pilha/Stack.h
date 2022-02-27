// ------------------
// Created by shinku 
// on 14/02/2020.
// -----------------

#ifndef Stack_Stack_H
#define Stack_Stack_H

//nome das estruturas
typedef struct No No;
typedef struct Stack Stack;

Stack* CriaPilha(int id);//função que inicializa uma nova pilha.

void Push(Stack *pilha, int d); //função que empilha um novo item na pilha.

int Pull(Stack *pilha); //função que desempilha o ultimo item inserido.

void DeletaPilha(Stack *pilha); //Deleta uma pilhaa e seu conteudo caso tenha.

#endif //Stack_Stack_H