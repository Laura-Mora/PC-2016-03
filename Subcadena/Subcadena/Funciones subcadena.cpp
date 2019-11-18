//
//  Funciones subcadena.cpp
//  Subcadena
//
//  Created by Laura Juliana Mora on 27/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Funciones subcadena.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int frasetam(char *frase){
    int cont=0,i=0;
    while(*(frase+i)!=NULL){
        //cout<<*(frase+i)<<" ";
        cont++;
        i++;
    }
    return cont;
}
bool subcadena (char *pal1, char *pal2){
    bool es=true;
    int cont=0, tam1=0, tam2=0;
    tam1=frasetam(pal1);
    tam2=frasetam(pal2);
    for(int i=0;i<tam2;i++){
        if(*(pal2+i)==*(pal1+0)){
            es=true;
            cont=0;
            for(int j=0;j<tam1&&es==true;j++)
                if(*(pal2+(i+j))==*(pal1+j))
                    cont++;
                else
                    es=false;
        }
    }
    if(cont<tam1){
        es=false;
    }
    return es;
}