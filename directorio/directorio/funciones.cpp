//
//  funciones.cpp
//  directorio
//
//  Created by Laura Juliana Mora on 11/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "funciones.hpp"
#include <iostream>
using namespace std;

void leer(direc *vec, int n){
    char cont;
    string pal;
    string *aux, aux2;
    bool es=false;
    
    for(int i=0;i<n;i++){
        (*(vec+i)).letra='A'+i;
        cout<<(*(vec+i)).letra<<" ";
        (*(vec+i)).cant=0;
    }
    cout<<"\n";
    do{
        cout<<"Apellido: ";
        cin>>pal;
        es=false;
        for(int i=0;i<n&&es==false;i++){
            if(pal[0]==(*(vec+i)).letra){
                (*(vec+i)).cant++;
                (*(vec+i)).apellido=new string[(*(vec+i)).cant];
                es=true;
                for(int j=0;j<(*(vec+i)).cant-1;j++){
                  *((*(vec+i)).apellido+j)=*(aux+j);
                }
                aux = new string[(*(vec+i)).cant];
                *((*(vec+i)).apellido+((*(vec+i)).cant-1))=pal;
                for(int j=0;j<(*(vec+i)).cant;j++){
                    *(aux+j)=*((*(vec+i)).apellido+j);
                }
               
            }
        }
        imprimir(vec, n);
        cout<<"¿Desea continuar S=si, N=no? ";
        cin>>cont;
    }while(cont=='s'||cont=='S');
    do{
        cout<<"¿Cual palabra desea buscar?";
        cin>>pal;
        buscar(vec, pal,n);
        cout<<"¿Desea continuar S=si, N=no? ";
        cin>>cont;
    }while(cont=='s'||cont=='S');
    /*for(int i=0;i<4;i++)
        delete (*(vec+i)).apellido;
    */
    
}
void imprimir(direc *vec, int n){
    for(int i=0;i<n;i++){
        cout<<(*(vec+i)).letra<<" "<<(*(vec+i)).cant<<"\n";
        if((*(vec+i)).cant>0){
            for(int j=0;j<(*(vec+i)).cant;j++){
                cout<<*((*(vec+i)).apellido+j)<<" ";
            }
        }else{
            cout<<"Aun no hay apellidos en el vector"<<"\n";
        }
        cout<<"\n";
    }
}
void buscar(direc *vec, string pal, int n){
    bool es=false;
    for(int i=0;i<n&&es==false;i++){
        if(pal[0]==(*(vec+i)).letra){
            for(int j=0;j<(*(vec+i)).cant&&es==false;j++){
                if(pal==*((*(vec+i)).apellido+j)){
                    cout<<"El apellido se encuentra en la estructura de la letra "<<(*(vec+i)).letra<<", en la posicion "<<j<<"\n";
                    es=true;
                }
                if(j==(*(vec+i)).cant-1&&es==false){
                    cout<<"El apellido no se encuetra registrado."<<"\n";
                    es=true;
                }
            }
        }
    }
}