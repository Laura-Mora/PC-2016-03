//
//  main1.cpp
//  Parcial p2
//
//  Created by Laura Juliana Mora on 19/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Funciones1.hpp"
#include <iostream>
using namespace std;
int main() {
    cancion  *arreglocanciones, *indice, *autor;
    
    int canti=0,*cant;
    cant=&canti;
    agregar(arreglocanciones, indice, cant,  autor);
    return 0;
}
