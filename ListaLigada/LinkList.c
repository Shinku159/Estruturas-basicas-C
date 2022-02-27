#include <stdio.h>
    #include <stdlib.h>
#include "LinkList.h"

//Estrutura de um Nó
struct No{
    int dado;
    struct No* prox;
};

//Estrutura da Lista(cabeça)
struct List{
    struct No* sentinela;
    int id;
};

List* CriaLista(int id){

    //Aloca espaço para a lista
    List *novo = (List*) malloc(sizeof(List));
    if(!novo){
        printf("Erro na alocacao de memoria");
        exit(-1);
    }

    //Aloca espaço para a cabeça da lista  
    novo->sentinela = (No*) malloc(sizeof(No));
    if(!novo->sentinela){
        printf("Erro na alocacao de memoria");
        exit(-1);
    }

    //cria a lista
    novo->id = id;
    novo->sentinela->dado = -100000;
    novo->sentinela->prox = NULL;

    return novo;
}

void AdicionaDado(List *lista, int d){

    //caso se envie uma lista não inicializada
    if(lista == NULL){
        printf("Essa lista ainda nao foi criada");
        return;
    }

    //Aloca espaço para o novo nó
    No* novo = (No*) malloc(sizeof(No));
    if(!novo){
        printf("Erro na alocacao de memoria");
        exit(-1);
    }

    //cria e adiciona novo ao inicio da lista;
    //ATT: ESSA VERSÃO FAZ INSERÇÃO APENAS NO INICIO DA LISTA
    novo->dado = d;
    novo->prox = lista->sentinela->prox;
    lista->sentinela->prox = novo;
}

void PercorreLista(List* lista){

    //caso se envie uma lista não inicializada
    if(lista == NULL){
        printf("Essa lista ainda nao foi criada");
        return;
    }
 
    //inicializa um auxiliar que percorrera a lista
    No* aux = lista->sentinela->prox; 
    
    //caso a lista esteja vazia
    if(aux == NULL){
        printf("lista vazia");
        return;
    }
    
    //percorre a lista
    while(aux != NULL){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
}

void RemoveDado(List *lista, int d){

    //inicializa os auxiliares para a busca
    No *pred = lista->sentinela;
    No *aux = lista->sentinela->prox;

    //encontra o dado a ser eliminado na lista
    while(aux != NULL && aux->dado != d){
        pred = aux;
        aux = aux->prox;
    }

    //caso não se tenha encontrado o dado d na lista
    if(aux == NULL){
        printf("Dado nao encontra");
        return;
    }

    //faz a remoção
    pred->prox = aux->prox;
    free(aux);
}

void DeletaNos(No* noAtual){
    //recursão para apagar desde o ultimo item até o primeiro
    if(noAtual != NULL){
        DeletaNos(noAtual->prox);
        free(noAtual);
    }
}

void DeletaLista(List *lista){
    //caso a lista não esteja vazia, delete os nós
    if(lista->sentinela->prox != NULL)
        DeletaNos(lista->sentinela->prox);

    //apague a sentinela e depois a si mesma
    free(lista->sentinela);
    free(lista);
}

void Concatena(List *lista1, List *lista2){
    //caso uma das listas não tenham sido inicializadas.
    if(lista1 == NULL || lista2 == NULL){
        printf("Atencao, uma das listas pode nao ter sido inicializada ainda");
        return;
    }

    //caso a lista a ser concatenada em 1 esteja vazia
    if(lista2->sentinela->prox == NULL){
        return;
    }

    //caso 1 esteja vazia
    if(lista1->sentinela->prox == NULL){
        lista1->sentinela->prox = lista2->sentinela->prox;
        return;
    }

    //encontra o final da lista 1
    No* aux = lista1->sentinela->prox;
    while(aux->prox != NULL){
        aux =  aux->prox;
    }

    //concatena
    aux->prox = lista2->sentinela->prox;
}

No* Invertido(No* noAtual, No* novo_ultimo){
    if(noAtual == NULL){
        return NULL;
    }

    if(noAtual->prox == NULL){
        noAtual->prox = novo_ultimo;
        return noAtual;
    }

    No* nova_cabeca = Invertido(noAtual->prox, noAtual);
    noAtual->prox = novo_ultimo;

    return nova_cabeca;
}

void InverteLista(List *lista){
    //caso se envie uma lista não inicializada
    if(lista == NULL){
        printf("Essa lista ainda nao foi criada");
        return;
    }

    //caso a lista esteja vazia
    if(lista->sentinela->prox == NULL){
        printf("Lista vazia, nenhuma alteracao feita");
        return;
    }

    ///inverte a lista.  
    lista->sentinela->prox = Invertido(lista->sentinela->prox, NULL);
}
