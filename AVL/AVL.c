#include <stdlib.h>
  #include <stdio.h>
#include "AVL.h"

AVL* CriaArvore(int id){

  //Aloca espaço para a nova árvore.
  AVL *nova = (AVL*) malloc(sizeof(AVL));
  if(!nova){
    printf("Falha ao alocar memoria");
    exit(0);
  }

  //Aloca espaço para a sentinela
  nova->sentinela = (No*) malloc(sizeof(No));
  if(!nova){
    printf("Falha ao alocar memoria");
    exit(0);
  }

  //preenche o cabeçalho inicial da árvore
  nova->sentinela->FB = 3;
  nova->sentinela->dado = -1000;
  nova->sentinela->pai = NULL;
  nova->sentinela->esq = NULL;
  nova->sentinela->dir = NULL;
  nova->id = id;

  return nova;
}

void RotateLeft(No *node){
  No *filho = node->dir;
  No *aux = filho->esq;

  //rotaciona
  filho->esq =  node;
  node->dir = aux;

  //troca os pais
  filho->pai = node->pai;
  node->pai = filho;
  if(aux != NULL)
    aux->pai = node;
  
  //troca o filho da esq ou dir do pai da raiz da rotação
  if(filho->pai->esq == node)
    filho->pai->esq = filho;
  else
    filho->pai->dir = filho;

  node->FB = node->FB - 1 - max(filho->FB, 0);
  filho->FB = filho->FB - 1 + min(node->FB, 0);
}

void RotateRight(No *node){
  No *filho = node->esq;
  No *aux = filho->dir;

  //rotaciona
  filho->dir =  node;
  node->esq = aux;

  //troca os pais
  filho->pai = node->pai;
  node->pai = filho;
  if(aux != NULL)
    aux->pai = node;
  
  //troca o filho da esq ou dir do pai da raiz da rotação
  if(filho->pai->esq == node)
    filho->pai->esq = filho;
  else
    filho->pai->dir = filho;

  node->FB = node->FB + 1 - min(node->pai->FB, 0);
  node->pai->FB = node->pai->FB + 1 + max(node->FB, 0);
}

void AtualizaFB(No *node){
  No *aux = node;
  // printf("NODE: %d - pai: %d ", node->dado, node->pai->dado);
  //para cada nó até raiz ou ate q haja rotação 
  while(node->pai->dado != -1000){ 
    node = node->pai;
    if(node->dir == aux)
      node->FB++;
    else
      node->FB--;

    //criterio de parada
    if(node->FB == 0)
      break;

    //rotaciona se necessário
    if(node->FB == 2){
      if(aux->FB == -1)
        RotateRight(aux);
      RotateLeft(node);
      break;
    }
    else if(node->FB ==  -2)
    {
      if(aux->FB == 1)  
        RotateLeft(aux);
      RotateRight(node);
      break;
    }
    aux = node;
  }

}

void AdicionaNo(AVL *arvore, int d){

  //Aloca o no para o novo dado
  No *novo = (No*) malloc(sizeof(No));
  if(!novo){
    printf("Falha ao alocar memoria");
    exit(0);
  }

  //preenche o no com os dados iniciais
  novo->FB = 0;
  novo->dir = NULL;
  novo->esq = NULL;
  novo->dado = d;

  //encontra a posição do novo no na arvore
  No *pai = arvore->sentinela;
  No *aux = arvore->sentinela->dir;
  while(aux != NULL){
    pai = aux;
    if(aux->dado < d)
      aux = aux->dir;
    else
      aux = aux->esq;
  }
  
  //insere o novo no, indicando quem é o pai;
  if(pai->dado < d)
    pai->dir = novo;
  else
    pai->esq = novo;
  novo->pai = pai;

  //atualiza os fatores de balanceamento, balanceando se necessario.
  AtualizaFB(novo);
  // Percorre(arvore->sentinela->dir);
}

void balanceamento(No *pai){
  No *noFilho;

  if (pai->FB == -2)//rotação à direita
  {
    noFilho = pai->esq;
    if(noFilho->FB == 1) //rotação dupla esq-dir
    {
      RotateLeft(noFilho);
      RotateRight(pai);
    }
    else
      RotateRight(pai);
  }
  else
  {
    noFilho = pai->dir;
    if(noFilho->FB == -1)
    {
      RotateRight(noFilho);
      RotateLeft(pai);
    }
    else
      RotateLeft(pai);
  }
  return;  
}

void AtualizaFBRemocao(No* pai, int valor){
  
  if(pai->dado == -1000)
    return;

  if(valor < pai->dado)
    pai->FB = pai->FB+1;
  else
    pai->FB = pai->FB-1;

  while((pai->FB < 1) && (pai->FB > -1) && (pai->pai->dado != -1000))
  {
    pai = pai->pai;
    if(valor < pai->dado)
      pai->FB = pai->FB+1;
    else
      pai->FB = pai->FB-1;
  }

  if(pai->FB==2 || pai->FB == -2)
  {
    balanceamento(pai);
    if(pai->pai->FB == 0)
      AtualizaFBRemocao(pai->pai->pai, valor);
  }
}

void RemoveNo(AVL *arvore, int d){
  No *pai;
  int valor;
  No *aux = arvore->sentinela->dir;

  while(aux->dado != d && aux != NULL){
    if(d > aux->dado)
      aux = aux->dir;
    else
      aux = aux->esq; 
  }

  if(aux == NULL){
    printf("Valor não encontrado!");
    return;
  }

  if(aux->dir != NULL && aux->esq != NULL){
    No *filho = aux->dir;
    while(filho->esq != NULL){
      filho = filho->esq;
    }
    aux->dado = filho->dado;
    aux = filho;
  }

  pai = aux->pai;
  valor = aux->dado;
  if(pai->esq == aux){
    if(aux->esq != NULL){
      pai->esq = aux->esq;
      aux->esq->pai = pai;
    }
    else if (aux->dir != NULL){
      pai->esq = aux->dir;
      aux->dir->pai = pai;
    }
    else
      pai->esq = NULL;
  }
  else{
    if(aux->esq != NULL){
      pai->dir = aux->esq;
      aux->esq->pai = pai;
    }
    else if (aux->dir != NULL){
      pai->dir = aux->dir;
      aux->dir->pai = pai;
    }
    else
      pai->dir = NULL;
  }
  free(aux);

  AtualizaFBRemocao(pai, valor);
}

void Percorre(No *noAtual)
{
    if(noAtual == NULL)
        return;

    Percorre(noAtual->esq);
    printf("%d - FP: %d\n", noAtual->dado, noAtual->FB);
    Percorre(noAtual->dir);
    return;
}

// No* RetornaSentinela(AVL *arvore){
//     return arvore->sentinela->dir;
// }