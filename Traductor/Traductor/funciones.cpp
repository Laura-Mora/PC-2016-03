//
//  funciones.cpp
//  Traductor
//
//  Created by Laura Juliana Mora on 29/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "funciones.hpp"
#include <iostream>
#include <string.h>
using namespace std;
void crear(dic *info,int tam){
    cout<<"\n";
    for(int i=0;i<tam;i++){
        (info+i)->pal= new char [20];
        cout<<"Digite la palabra del diccionario: ";
        cin.getline((info+i)->pal, 20, '\n');
        cout<<"Digite la el codigo de la palabra digitada: ";
        cin>>(info+i)->codigo;
        cin.ignore();
    }
}
void imprimir(dic *info,int tam){
    for(int i=0;i<tam;i++){
        cout<<(info+i)->pal<<" "<<(info+i)->codigo;
        cout<<"\n";
    }
}
void traducir(dic *infoes, int tames, dic *infoin, int tamin, char *frase, char *ingles){
    char *palab;
    int num=0,tampi=0;
    palab=strtok(frase, " ");
    num=esta(palab,infoes,tames);
    while(palab!=NULL){
        //num=esta(palab, infoes, tames);
        if(est(palab, infoes, tames)){
            strcat(ingles, pala(num,infoin,tamin));
            tampi=strlen(ingles);
            *(ingles+tampi)=' ';
        }else{
            strcat(ingles, palab);
            tampi=strlen(ingles);
            *(ingles+tampi)=' ';
        }
        palab=strtok(NULL, " ");
        if(palab!=NULL)
            num=esta(palab, infoes, tames);
    }
}
int esta (char *palab, dic *esp, int tam){
    int numi=0;
    for(int i=0;i<tam;i++){
        if(strcmp(palab,(esp+i)->pal)==0){
            numi = (esp+i)->codigo;
            break;
        }
    }
    return numi;
}
char *pala(int cod, dic *ing, int tam){
    char *pali;
    for(int i=0;i<tam;i++)
        if(cod== (ing+i)->codigo){
            pali =(ing+i)->pal;
            break;
        }
    return pali;
}
bool est(char *palab, dic *esp, int tam){
    for(int i=0;i<tam;i++){
        if(strcmp(palab,(esp+i)->pal)==0){
            return true;
        }
    }
    return false;
}
