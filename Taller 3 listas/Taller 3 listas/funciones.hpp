//
//  funciones.hpp
//  Taller 3 listas
//
//  Created by Laura Juliana Mora on 29/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef funciones_hpp
#define funciones_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
template <typename T>
struct Nodo{
    Nodo <T> *sig;
    T info;
};

template <typename T>
struct Lista
{
    Nodo <T> *cab;
    int tam;
};
template <typename T>
Lista <T> *crearlista();
template <typename T>
void insertar(Lista <T> *lista, int infonueva);
template <typename T>
bool esta(Lista <T> *lista,int infonueva);
template <typename T>
bool vacia (Lista <T> *lista);
template <typename T>
void imprimir(Lista <T> *lista);
#endif /* funciones_hpp */
