//
//  main.cpp
//  Hoja de calculo
//
//  Created by Laura Juliana Mora on 21/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "Funcioneshoja.hpp"
using namespace std;
int main() {
    char ***hojaInicial;
    int nfilas, ncolumnas, **hojaFinal;
    cout<<"¿Cantidad de filas? ";
    cin>>nfilas;
    cout<<"¿Cantidad de columnas? ";
    cin>>ncolumnas;
    hojaInicial = new char **[ncolumnas];
    for(int i=0;i<ncolumnas;i++)
        *(hojaInicial+i)= new char *[nfilas];
    for(int i=0;i<ncolumnas;i++)
        for(int j=0;j<nfilas;j++)
            *(*(hojaInicial+i)+j)=new char [20];
    cin.ignore();
    crear(hojaInicial, nfilas, ncolumnas);
    hojaFinal = new int *[ncolumnas];
    for(int i=0;i<ncolumnas;i++)
        *(hojaFinal+i)= new int[nfilas];
    CalcularHoja(hojaInicial, nfilas, ncolumnas, hojaFinal);
    
    for(int i=0;i<ncolumnas;i++)
        for(int j=0;j<nfilas;j++)
            delete *(*(hojaInicial+i)+j);
    for(int i=0;i<ncolumnas;i++)
        delete *(hojaInicial+i);
    delete hojaInicial;
    
    return 0;
}
