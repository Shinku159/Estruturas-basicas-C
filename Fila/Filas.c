#include <stdio.h>
    #include <stdlib.h>
#include "Queue.h"

int main(int argc, char *argv[]){
    Queue *fila = CriaFila(1, 10);
    Item i;
    //if(fila){
    //    printf("OK!, fila criada\n %d", fila->capacidade);
    //}
    AdicionaItem(fila, 0, 1);
    AdicionaItem(fila, 1, 0);
    AdicionaItem(fila, 2, 3);
    AdicionaItem(fila, 3, 2);
    AdicionaItem(fila, 4, 0);
    AdicionaItem(fila, 5, 8);
    AdicionaItem(fila, 6, 0);
    AdicionaItem(fila, 7, 0);
    AdicionaItem(fila, 8, 6);
    AdicionaItem(fila, 9, 0);
    //printf("%d ", fila->itens[3].dado);
    i = ExtraiItem(fila);
    printf("%d ", i.dado);
    DestroiFila(fila);
    return 0;
}