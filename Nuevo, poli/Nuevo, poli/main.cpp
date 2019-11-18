//
//  main.cpp
//  Nuevo, poli
//  Polinomios sin Templates
//  Created by Laura Juliana Mora on 16/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//


#include <iostream>
#include <math.h>
#include "Funciones.hpp"
using namespace std;
int main() {
    Lista *lista,*lista2,*listafinal;
    char continuar;
    int nume=0,expone=0,resul=0;
    lista=crearlista();
    cout<<"Polinomio 1: \n";
    do{
        cout<<"Digite un numero: ";
        cin>>nume;
        cout<<"Digite un exponente: ";
        cin>>expone;
        insertar(lista, nume,expone);
        cout<<"¿Desea ingresar mas numeros? (S=si, N=no)";
        cin>>continuar;
    }while (continuar=='s'||continuar=='S');
    cout<<"Info polinomio 1 \n";
    imprimir(lista);
    lista2=crearlista();
    cout<<"Polinomio 2: \n";
    do{
        cout<<"Digite un numero: ";
        cin>>nume;
        cout<<"Digite un exponente: ";
        cin>>expone;
        insertar(lista2, nume,expone);
        cout<<"¿Desea ingresar mas numeros? (S=si, N=no)";
        cin>>continuar;
    }while (continuar=='s'||continuar=='S');
    cout<<"Info polinomio 2 \n";
    imprimir(lista2);
    listafinal=crearlista();
    sumar(lista, lista2, listafinal);
    cout<<"Digite un numero para remplazar la x: ";
    cin>>nume;
    resul=solucion(listafinal, nume);
    cout<<"El resultado del polinomio remplazando a x por "<<nume<<": "<<resul<<"\n";
    return 0;
}
