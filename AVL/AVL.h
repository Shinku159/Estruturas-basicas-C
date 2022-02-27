// ------------------
// Created by shinku 
// on 16/07/2020.
// -----------------

#ifndef AVL_AVL_H
#define AVL_AVL_H

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

//nomes das structs.
typedef struct No{ //Estutura de um nó na arvore
  int dado;
  int FB;
  struct No* pai;
  struct No* esq;
  struct No* dir;
}No;

typedef struct AVL{ //Estrutura de uma árvore
  struct No* sentinela;
  int id;
}AVL; 

AVL* CriaArvore(int id); //Função que inicializa uma nova árvore.

void AdicionaNo(AVL *arvore, int d); //Função que adiciona o dado 'd' a um novo nó na arvore binaria de pesquisa "arvore". 

void RemoveNo(AVL *arvore, int d); //Função que remove o nó com o dado 'd' da arvore binaria de pesquisa "arvore".

void Percorre(No *noAtual); //percorre imprimindo a árvore em órdem Esq-Raiz-Dir(ERD).

No* RetornaSentinela(AVL *arvore); //Retorna o nó sentinela da árvore para incialização

void RotateLeft(No *node); //rotaciona os nós para a esquerda

void RotateRight(No *node); //rotaciona os nós para a direita

void AtualizaFB(No *node); //atualiza o balanceamento da árvore fazendo rotações se necessário.

void AtualizaFBRemocao(No *pai, int valor);


#endif //AVL_AVL_H