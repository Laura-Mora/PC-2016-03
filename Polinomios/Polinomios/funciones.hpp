//
//  funciones.hpp
//  Polinomios
//
//  Created by Laura Juliana Mora on 15/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef Funciones_hpp
#define Funciones_hpp

#include <stdio.h>
#include <math.h>

/*struct infor{
    int num;
    int expo;
};*/
template <typename T>
struct Nodo{
    Nodo <T> *sig;
    //infor info;
    T num;
    T expo;
};
template <typename T>
struct Lista{
    Nodo <T> *cab;
    int tam;
};
template <typename T>
Lista <T> *crearlista();
template <typename T>
void insertar(Lista <T> *lista, int infonueva, int exponente);
template <typename T>
bool vacia (Lista <T> *lista);
template <typename T>
void imprimir(Lista <T> *lista);
template <typename T>
void sumar(Lista <T> *lista, Lista <T> *lista2, Lista <T> *listafinal);
template <typename T>
int obtenerDato(Lista <T > *lista, int pos);
template <typename T>
bool esta(Lista <T> *lista, int nume);
template <typename T>
int solucion(Lista <T> *lista, int x);
#endif /* Funciones_hpp */
