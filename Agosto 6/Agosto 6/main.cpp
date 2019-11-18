//
//  main.cpp
//  Agosto 6
//
//  Created by Laura Juliana Mora on 8/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "Funciones.hpp"
using namespace std;
int main() {
    Lista *lista;
    char continuar;
    lista=crearlista();
    int num=0;
    do{
        cout<<"Digite un numero: ";
        cin>>num;
        insertar(lista, num);
        cout<<"¿Desea ingresar mas numeros? (S=si, N=no)";
        cin>>continuar;
    }while (continuar=='s'||continuar=='S');
    imprimir(lista);
    reversa(lista);
    imprimir(lista);
    return 0;
}
