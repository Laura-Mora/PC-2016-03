//
//  funciones.hpp
//  Traductor
//
//  Created by Laura Juliana Mora on 29/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef funciones_hpp
#define funciones_hpp

#include <stdio.h>
#include <iostream>
struct dic{
    char *pal;
    int codigo;
};
void crear(dic *info,int tam);
void imprimir(dic *info,int tam);
void traducir(dic *infoes, int tames, dic *infoin, int tamin, char *frase, char *ingles);
int esta (char *pal, dic *esp, int tam);
char *pala(int cod, dic *ing, int tam);
bool est(char *palab, dic *esp, int tam);
#endif /* funciones_hpp */
