//
//  Listas.hpp
//  Punto3 parcial
//
//  Created by Laura Juliana Mora on 14/10/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef Listas_hpp
#define Listas_hpp

#include <stdio.h>
#include <iostream>
struct numbin{
    int info;
    numbin *sig;
};
struct numhex{
    char info;
    numhex *sig;
};
struct nums{
    int tamb;
    int tamh;
    int info;
    numbin *ini;
    numhex *inic;
    nums *sig;
};
struct Lista{
    nums *cab;
    int tam;
};
Lista *crear();
void ins(Lista *lista, nums *nuevo);
void imprimir(Lista *lista);
void insertarbi(nums *val, int infonueva);
void insertarhex(nums *val, char infonueva);
void insertarEnUnaPosicion (Lista * lista, nums *infoNueva, int pos);
#endif /* Listas_hpp */
