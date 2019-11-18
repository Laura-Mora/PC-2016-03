//
//  Funciones hoja.cpp
//  Hoja de calculo
//
//  Created by Laura Juliana Mora on 21/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Funcioneshoja.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
void crear(char ***hojaInicial, int nfilas, int ncolumnas){
    char letra;
    for(int i=0;i<ncolumnas;i++){
        letra='A';
        for(int j=0;j<nfilas;j++){
            cout<<letra<<i+1<<": ";
            cin.getline(*(*(hojaInicial+i)+j),20,'\n');
            letra++;
        }
    }
    
}
void CalcularHoja (char ***hojaInicial, int nfilas, int ncolumnas, int **hojaFinal){
    char *pez,*aux;
    int k=0, numi=0, sum=0,numi2=0, peje=0, p, cont=0, nums=0;
    for(int i=0;i<ncolumnas;i++){
        for(int j=0;j<nfilas;j++){
            if(*(*(*(hojaInicial+i)+j)+0)!= '='){
                *(*(hojaFinal+i)+j)=atoi(*(*(hojaInicial+i)+j));
            }else{
                pez=strtok(*(*(hojaInicial+i)+j),"=+");
                while(pez!=NULL){
                    if(*(pez+0)<65){
                        k=atoi(pez);
                        sum=sum+k;
                    }else{
                    numi=*(pez+0)-'A';
                    //cout<<numi<<" ";
                    peje=*(pez+1)-'1';
                    //cout<<peje<<" ";
                    numi2=atoi(*(*(hojaInicial+peje)+numi));
                    //cout<<numi2<<" ";
                    sum=sum+numi2;
                        //cout<<sum<<" ";
                    }
                    pez=strtok(NULL,"=+");
                    //cout<<"\n";
                    
                }
                
                p=sum;
                while(p>0){
                    p=p/10;
                    cont++;
                }
                p=sum;
                aux =new char [cont];
                while(cont>=0){
                    nums=p%10;
                    *(aux+(cont-1))=(nums+48);
                    cont--;
                    //cout<< *(*(*(hojaInicial+peje)+numi)+cont)<<" "<<sum<<" ";
                }
                *(*(hojaInicial+i)+j)=aux;
                //cout<< *(*(*(hojaInicial+peje)+numi)+cont)<<" "<<sum<<" ";
                *(*(hojaFinal+i)+j)=sum;
            }
        }
    }
    cout<<"\n";
    for(int i=0;i<ncolumnas;i++){
        for(int j=0;j<nfilas;j++)
            cout<<*(*(hojaFinal+i)+j)<<" ";
        cout<<"\n";
    }
    
}