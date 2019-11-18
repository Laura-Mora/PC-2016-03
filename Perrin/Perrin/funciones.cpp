//
//  funciones.cpp
//  Perrin
//
//  Created by Laura Juliana Mora on 3/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//
#include <iostream>
#include "funciones.hpp"
using namespace std;

void datos(int *p,int c){
    for(int i=3;i<c;i++){
        *(p+i)=*(p+(i-2))+*(p+(i-3));
    }
}
void imprimir(int *p,int n){
    for(int i=0;i<n;i++){
        cout<<*(p+i)<<" ";
    }
    cout<<"\n";
}
void imprimir2(int **p,int n){
    for(int i=0;i<n;i++){
        if(*(p+i)==NULL)
            cout<<"NULL"<<" ";
        else
            cout<<**(p+i)<<" ";
    }
    cout<<"\n";
}
int primos(int *p,int n){
    int  **apuntadorprimos, cant=0;
    apuntadorprimos=new int *[n];
    for(int i=2;i<n;i++){
        if(*(p+i)%i==0){
            *(apuntadorprimos+cant)=p+i;
            cant++;
        }
    }
    for(int i=cant;i<n;i++){
        *(apuntadorprimos+i)=NULL;
    }
    imprimir2(apuntadorprimos, n);
    delete apuntadorprimos;
    return cant;
}
int menu(){
    int op;
    do{
        cout<<"1. Vector numeros"<<"\n"<<"2. Vector autoprimos con NULL"<<"\n"<<"3. Vector autoprimos"<<"\n"<<"4.Salir"<<"\n"<<"Digite una opcion: ";
        cin>>op;
    }while (op>4||op<1);
    return op;
}
void primos2(int *p,int n,int cant){
    int  **apuntadorprimos, j=0;
    apuntadorprimos=new int *[cant];
    for(int i=2;i<n;i++){
        if(*(p+i)%i==0){
            *(apuntadorprimos+j)=p+i;
            j++;
        }
    }
    for(int i=0;i<cant;i++){
        cout<<**(apuntadorprimos+i)<<" ";
    }
    cout<<"\n";
    delete apuntadorprimos;
}