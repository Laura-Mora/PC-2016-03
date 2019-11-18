//
//  funciones.cpp
//  Parcial p1
//
//  Created by Laura Juliana Mora on 19/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "funciones.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void CrearV(int *V,int MAX){
    for(int i=0;i<MAX;i++)
        *(V+i)=(1+rand()%100);
    for(int i=0;i<MAX;i++)
        cout<<*(V+i)<<" ";
    cout<<"\n";
}
bool esta(int *num,int cant, int nume){
    bool es=false;
    for(int i=0;i<cant&&es==false;i++)
        if(nume==*(num+i))
            es=true;
    return es;
}
int cant(int *V, int MAX, int num){
    int cant=0;
    for(int i=0;i<MAX;i++)
        if(*(V+i)==num)
            cant++;
    return cant;
}
void Crearnums(int *V, int MAX, int *numero, int *numero_ocurrencias, int ***pos){
    int cantnums=1, veces=0,*aux, mayor=0, pez=0;
    bool es=true;
    aux=new int [MAX];
    for(int i=0;i<MAX;i++)
        *(aux+i)=0;
    for(int i=0;i<MAX;i++){
        es=esta(aux,cantnums,*(V+i));
        if(es==false){
            *(aux+cantnums-1)=*(V+i);
            cantnums++;
        }
    }
    cantnums--;
    numero=new int [cantnums];
    for(int i=0;i<cantnums;i++)
        *(numero+i)=*(aux+i);
    delete aux;
    
    cout<<"\nNumeros: ";
    for(int i=0;i<cantnums;i++)
        cout<<*(numero+i)<<" ";
    
    numero_ocurrencias=new int[cantnums];
    for(int j=0;j<cantnums;j++){
        veces=cant(V,MAX,*(numero+j));
        *(numero_ocurrencias+j)=veces;
        if(veces>mayor)
            mayor=veces;
    }
    cout<<"\nNumeros ocurrencias: ";
    for(int i=0;i<cantnums;i++)
        cout<<*(numero_ocurrencias+i)<<" ";
    cout<<"\n";
    
    pos=new int **[mayor];
    for(int i=0;i<mayor;i++)
        pos[i]=new int *[cantnums];
    for(int i=0;i<cantnums;i++){
            pez=0;
            for(int k=0;k<MAX;k++){
                if(*(V+k)==*(numero+i)){
                    *(*(pos+pez)+i)=(V+k);
                    pez++;
                }
            }
    }
    for(int i=0;i<cantnums;i++){
        for(int j=0;j<*(numero_ocurrencias+i);j++)
            cout<<*(*(pos+j)+i)<<" ";
        cout<<"\n";
    }
    for(int i=0;i<cantnums;i++){
        for(int j=0;j<*(numero_ocurrencias+i);j++)
            cout<<*(*(*(pos+j)+i))<<" ";
        cout<<"\n";
    }
    ordenar(V, MAX, numero, numero_ocurrencias,cantnums,pos);
    
}
void ordenar(int *V, int MAX, int *numero, int *numero_ocurrencias,int cantnums, int ***pos){
    int menor=0, *aux, *auxnums, posi=0, cont=0, num=0;
    bool  ya=false;
    aux=new int [MAX];
    for(int i=0;i<MAX;i++)
        *(aux+i)=0;
    auxnums=new int[cantnums];
    for(int i=0;i<cantnums;i++)
        *(auxnums+i)=*(numero+i);
    
    while(cont<MAX){
        ya=false;
        for(int i=0;i<cantnums&&ya==false;i++)
            if(*(auxnums+i)!=0){
                menor=*(auxnums+i);
                ya=true;
                posi=*(numero_ocurrencias+i);
                num=i;
            }
        for(int i=0;i<cantnums;i++)
            if((*(auxnums+i)!=0)&& (*(auxnums+i))<menor){
                menor=*(auxnums+i);
                posi=*(numero_ocurrencias+i);
                num=i;
            }
        for(int i=0;i<posi;i++){
            *(aux+cont)=*(*(*(pos+i)+num));
            //*(aux+cont)=*pos[num][i];
            cont++;
        }
        *(auxnums+num)=0;
    }
    for(int i=0;i<MAX;i++)
        *(V+i)=*(aux+i);
    cout<<"Vector ordenado: \n";
    for(int i=0;i<MAX;i++)
        cout<<*(V+i)<<" ";
}