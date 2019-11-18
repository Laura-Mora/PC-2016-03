//
//  main.cpp
//  Punto3 parcial
//
//  Created by Laura Juliana Mora on 14/10/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "Listas.hpp"
using namespace std;
int main() {
    Lista *lista;
    lista=crear();
    nums *nuevo;
    char cont, *hex;
    hex=new char[50];
    int bi, tam=0, conta=0;
    do{
        nuevo= new nums;
        nuevo->tamb=0;
        nuevo->tamh=0;
        nuevo->ini=NULL;
        nuevo->inic=NULL;
        nuevo->sig=NULL;
        cout<<"Digite el numero: ";
        cin>>nuevo->info;
        cout<<"Digite el numero en binario: ";
        cin>>bi;
        while(bi>0){
            insertarbi(nuevo, bi%10);
            bi=bi/10;
        }
        cin.ignore();
        cout<<"Numero en Hexadecimal: ";
        cin.getline(hex, 49, '\n');
        tam=strlen(hex);
        conta=0;
        while(conta<tam){
            insertarhex(nuevo, *(hex+conta));
            conta++;
        }
        ins(lista, nuevo);
        cout<<"Desea agregar mas datos? (S=si, N=no)";
        cin>>cont;
    }while(cont=='s'||cont=='S');
    imprimir(lista);
    return 0;
}
