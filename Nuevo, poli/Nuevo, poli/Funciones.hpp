//
//  Funciones.hpp
//  Nuevo, poli
//  Polinomios sin Templates
//  Created by Laura Juliana Mora on 16/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef Funciones_hpp
#define Funciones_hpp

#include <stdio.h>
#include <math.h>
struct infor{
    int num;
    int expo;
};
struct Nodo{
    Nodo *sig;
    infor info;
};
struct Lista{
    Nodo *cab;
    int tam;
};
Lista *crearlista();
void insertar(Lista *lista, int infonueva, int exponente);
bool vacia (Lista *lista);
void imprimir(Lista *lista);
void sumar(Lista *lista, Lista *lista2, Lista *listafinal);
int obtenerDato(Lista * lista, int pos);
bool esta(Lista *lista, int nume);
int solucion(Lista *lista, int x);
#endif /* Funciones_hpp */
