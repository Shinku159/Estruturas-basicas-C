// ------------------
// Created by shinku 
// on 14/02/2020.
// -----------------

#ifndef LinkList_LinkList_H
#define LinkList_LinkList_H

//Nome das estruturas
typedef struct No No;
typedef struct List List;

List* CriaLista(int id); //função que inicializa uma nova lista.

void AdicionaDado(List *lista, int d); //função para adicionar um dado a lista.

void RemoveDado(List *lista, int d); //função que elimina o primeiro nó com o dado d cadastrado.

void DeletaLista(List *lista); //função que desaloca completamente uma lista.

void Concatena(List *lista1, List *lista2); //Função que concatena a lista 2 na lista 1.

void PercorreLista(List *lista); //função que percorre imprimindo os itens da lista.

void InverteLista(List *lista); //função que inverte a posição dos valoes da lista.

#endif //LinkList_LinkList_H