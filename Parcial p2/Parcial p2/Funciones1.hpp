//
//  Funciones1.hpp
//  Parcial p2
//
//  Created by Laura Juliana Mora on 19/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef Funciones_hpp
#define Funciones_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
struct cancion{
    string titulo;
    string autor;
    float tiempo;
};
void agregar(cancion *arreglocanciones, cancion *indice, int *cant,  cancion *autor);
#endif /* Funciones_hpp */
