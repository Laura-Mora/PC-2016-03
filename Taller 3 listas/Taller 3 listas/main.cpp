//
//  main.cpp
//  Taller 3 listas
//
//  Created by Laura Juliana Mora on 29/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "funciones.cpp"
using namespace std;
int main() {
    Lista <int> *lista;
    char continuar;
    int nume=0;
    lista=crearlista<int>();
    cout<<"Polinomio 1: \n";
    do{
        cout<<"Digite un numero: ";
        cin>>nume;
        insertar(lista, nume);
        cout<<"¿Desea ingresar mas numeros? (S=si, N=no)";
        cin>>continuar;
    }while (continuar=='s'||continuar=='S');
    imprimir(lista);
    return 0;
}
