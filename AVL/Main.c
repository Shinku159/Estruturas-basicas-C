#include <stdlib.h>
  #include <stdio.h>
#include "AVL.h"

int main(int argc, char *argv[]){
  
  AVL *arvore = CriaArvore(1);
  AdicionaNo(arvore, 2);
  AdicionaNo(arvore, 3);
  AdicionaNo(arvore, 9);
  AdicionaNo(arvore, 1);
  AdicionaNo(arvore, 6);
  AdicionaNo(arvore, 4);
  AdicionaNo(arvore, 7);
  AdicionaNo(arvore, 8);
  AdicionaNo(arvore, 5);
  Percorre(arvore->sentinela->dir);
  RemoveNo(arvore, 3);
  RemoveNo(arvore, 1);
  RemoveNo(arvore, 7);
  RemoveNo(arvore, 9);
  printf("\n\n");
  Percorre(arvore->sentinela->dir);
  return EXIT_SUCCESS;
}