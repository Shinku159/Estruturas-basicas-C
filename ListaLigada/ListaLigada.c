#include <stdio.h>
    #include <stdlib.h>
#include "LinkList.h"

int main(int argc, char *argv[]){
    List *lista = CriaLista(1);
    AdicionaDado(lista, 0);
    AdicionaDado(lista, 1);
    AdicionaDado(lista, 2);
    AdicionaDado(lista, 3);
    AdicionaDado(lista, 4);
    AdicionaDado(lista, 5);
    AdicionaDado(lista, 6);
    AdicionaDado(lista, 7);
    AdicionaDado(lista, 8);
    AdicionaDado(lista, 9);
    PercorreLista(lista);
    printf("\n");
    RemoveDado(lista, 3);
    RemoveDado(lista, 7);
    RemoveDado(lista, 9);
    PercorreLista(lista);
    printf("\n");
    List *lista2 = CriaLista(2);
    AdicionaDado(lista2, 10);
    AdicionaDado(lista2, 11);
    AdicionaDado(lista2, 12);
    AdicionaDado(lista2, 13);
    AdicionaDado(lista2, 14);
    AdicionaDado(lista2, 15);
    PercorreLista(lista2);
    printf("\n");
    Concatena(lista2, lista);
    PercorreLista(lista2);
    printf("\n");
    InverteLista(lista2);
    PercorreLista(lista2);
    DeletaLista(lista);
    DeletaLista(lista2);
    return 0;
}