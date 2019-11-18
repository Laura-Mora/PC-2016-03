//
//  funciones.hpp
//  Taller archivos1
//
//  Created by Laura Juliana Mora on 20/10/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef funciones_hpp
#define funciones_hpp
#include <iostream>
#include <stdio.h>
#include <fstream>
struct datos{
    char *codigo;
    char *apellido;
    char *nombre;
    char *celular;
};
void quemar();
void leer();
void generar();
void agregar(datos nuevo);
int indice();
void cartas();
int menu();
void telefonos();
#endif /* funciones_hpp */
