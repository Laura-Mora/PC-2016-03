//
//  funciones.hpp
//  Parcial p1
//
//  Created by Laura Juliana Mora on 19/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef funciones_hpp
#define funciones_hpp

#include <stdio.h>
void CrearV(int *V,int MAX );
bool esta(int *num,int cant, int nume);
int cant(int *V, int MAX, int num);
void Crearnums(int *V, int MAX, int *numero, int *numero_ocurrencias, int ***pos);
void ordenar(int *V, int MAX, int *numero, int *numero_ocurrencias,int cantnums, int ***pos);
#endif /* funciones_hpp */
