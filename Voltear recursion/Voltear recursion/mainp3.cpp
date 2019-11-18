//
//  main.cpp
//  Voltear recursion
//
//  Created by Laura Juliana Mora on 3/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "FuncionesP3.hpp"
using namespace std;
int main() {
    char *palabra, *aux;
    int tam=0;
    palabra = new char [50];
    cout<<"Cadena: ";
    cin.getline(palabra, 49, '\n');
    tam=strlen(palabra);
    aux=new char[tam+1];
    aux=invertit(palabra);
    cout<<aux<<"\n";
    return 0;
}
