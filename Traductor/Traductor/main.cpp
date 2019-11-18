//
//  main.cpp
//  Traductor
//
//  Created by Laura Juliana Mora on 29/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "funciones.hpp"
using namespace std;
int main() {
    char *cespa, *cing;
    int cantes,cantin;
    dic *espa, *ing;
    cout<<"Cantidad de palabras diccionario español: ";
    cin>>cantes;
    espa=new dic[cantes];
    cout<<"Ingrese palabras del diccionario en español ";
    cin.ignore();
    crear(espa, cantes);
    imprimir(espa, cantes);
    cout<<"Cantidad de palabras diccionario ingles: ";
    cin>>cantin;
    ing=new dic [cantes];
    cout<<"Ingrese palabras del diccionario en ingles ";
    cin.ignore();
    crear(ing, cantin);
    imprimir(ing, cantin);
    cout<<"Digite la frase que desea traducir: ";
    cespa=new char [50];
    cin.getline(cespa, 50,'\n');
    cing=new char[50];
    traducir(espa, cantes, ing, cantin, cespa, cing);
    cout<<cing<<"\n";
    for(int i=0;i<cantes;i++)
        delete (espa+i)->pal;
    for(int i=0;i<cantin;i++)
        delete (ing+i)->pal;
    delete espa;
    delete ing;
    delete cespa;
    delete cing;
    return 0;
}
