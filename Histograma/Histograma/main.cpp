//
//  main.cpp
//  Histograma
//
//  Created by Laura Juliana Mora on 11/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "Funciones.hpp"
using namespace std;
int main() {
    int *vec, tam;
    char **matriz;
    cout<<"Tamaño del vector: ";
    cin>>tam;
    vec=new int[tam];
    crearvector(vec, tam);
    crearmatriz(vec, tam, matriz);
    delete vec;
    return 0;
}
