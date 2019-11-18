//
//  Funciones.cpp
//  Histograma
//
//  Created by Laura Juliana Mora on 11/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Funciones.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void crearvector(int *vec, int n){
    for(int i=0;i<n;i++)
        *(vec+i)=(1+rand()%9);
    for(int i=0;i<n;i++)
        cout<<*(vec+i)<<" ";
    cout<<"\n";
}
void crearmatriz(int *vec, int n, char **m){
    int mayor;
    mayor=*(vec+0);
    for(int i=0;i<n;i++)
        if(mayor<*(vec+i))
            mayor=*(vec+i);
    m=new char *[mayor];
    for(int i=0;i<mayor;i++)
        m[i]=new char[n];
    for(int i=0;i<mayor;i++)
        for(int j=0;j<n;j++)
            *(*(m+i)+j)=' ';
    /*for(int i=0;i<mayor;i++){
        for(int j=0;j<n;j++)
            cout<<*(*(m+i)+j)<<" ";
        cout<<"\n";
    }
    cout<<"\n";*/
    for(int i=0;i<mayor;i++){
        for(int j=0;j<n;j++){
            if(*(vec+j)==(mayor-i)){
                *(*(m+i)+j)='x';
                *(vec+j)=*(vec+j)-1;
            }
        }
    }
    for(int i=0;i<mayor;i++){
        for(int j=0;j<n;j++)
            cout<<*(*(m+i)+j)<<" ";
        cout<<"\n";
    }
    for(int i=0;i<mayor;i++)
        delete m[i];
    delete m;

}