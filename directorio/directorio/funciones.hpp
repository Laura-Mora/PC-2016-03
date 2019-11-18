//
//  funciones.hpp
//  directorio
//
//  Created by Laura Juliana Mora on 11/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef funciones_hpp
#define funciones_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
struct direc{
    char letra;
    int cant;
    string *apellido;
};
void leer(direc *vec, int n);
void imprimir(direc *vec, int n);
void buscar(direc *vec, string pal, int n);
#endif /* funciones_hpp */
