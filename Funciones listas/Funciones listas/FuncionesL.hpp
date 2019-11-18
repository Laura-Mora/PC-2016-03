//
//  FuncionesL.hpp
//  Funciones listas
//
//  Created by Laura Juliana Mora on 11/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef FuncionesL_hpp
#define FuncionesL_hpp

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
void insertarInicio(Lista *lista, int infonueva);
int menu();
void borrarfinal(Lista *lista);
Lista *listapares(Lista *lista);
void ordenar(Lista *lista);
bool esta(Lista *lista, int num);
#endif /* FuncionesL_hpp */
