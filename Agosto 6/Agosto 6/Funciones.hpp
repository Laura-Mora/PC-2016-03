//
//  Funciones.hpp
//  Agosto 6
//
//  Created by Laura Juliana Mora on 8/09/16.
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
void reversa(Lista *lista);

#endif /* Funciones_hpp */
