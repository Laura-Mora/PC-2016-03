//
//  Funciones_caracteres.cpp
//  Cadenas caracteres
//
//  Created by Laura Juliana Mora on 25/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Funciones_caracteresp2.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
void invertir(char *pal){
    int tam, tam2, pos;
    char *pal2, *aux;
    tam=strlen(pal);
    tam++;
    pos=tam-1;
    aux = new char[tam];
    pal2=strtok(pal," ");
    while (pal2!=NULL)
    {
        tam2= strlen(pal2);
        tam2++;
        for(int i=tam2-2;i>=0;i--){
            *(aux+pos)=*(pal2+i);
            pos--;
        }
        *(aux+pos)=' ';
        pos--;
        pal2=strtok(NULL, " ");
        //*(aux+pos)=' ';
    }
    cout<<aux<<endl;
}