//
//  Funciones.hpp
//  taller 3 listas 2.0
//
//  Created by Laura Juliana Mora on 2/10/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef Funciones_hpp
#define Funciones_hpp

#include <stdio.h>
struct Nodo{
    int info;
    Nodo *sig;
};
struct Lista{
    Nodo *cabe;
    int tam;
};
Lista *crearlista();
void insertar(Lista *lista, int infonueva);
bool vacia (Lista *lista);
void imprimir(Lista *lista);
bool eliminar(Lista *lista, int pos);
int obtenerpoa(Lista *lista, int num);
void elim(Lista *lista, int num);
bool esta(Lista *lista, int num);
void inter(Lista *lista1, Lista *lista2, Lista *un);
int menu();
void uni(Lista *lista1, Lista *lista2, Lista *un);
void diferencia(Lista *lista1, Lista *lista2, Lista *dif);
#endif /* Funciones_hpp */
