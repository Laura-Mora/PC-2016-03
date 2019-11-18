//
//  funciones.cpp
//  Taller 3 listas
//
//  Created by Laura Juliana Mora on 29/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "funciones.hpp"
#include <iostream>
using namespace std;
template <typename T>
Lista <T> *crearlista(){
    Lista <T> *lista = new Lista <T>;
    lista->tam=0;
    lista->cab=NULL;
    return lista;
}
template <typename T>
void insertar(Lista <T> *lista, int infonueva){
    Nodo <T> *nuevo;
    nuevo= new Nodo <T>;
    nuevo->info=infonueva;
    nuevo->sig=NULL;
    if(esta<int>(lista, infonueva)){
    if(lista->tam==0){
        lista->cab=nuevo;
        lista->tam++;
    }
    else{
        Nodo <T> *aux;
        aux=lista->cab;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
        lista->tam++;
    }
    }else
        cout<<"El numero que digito ya esta en el conjunto"<<"\n";
}
template <typename T>
bool vacia (Lista <T> *lista){
    if(lista->tam==0)
        return true;
    else
        return false;
}
template <typename T>
void imprimir(Lista <T> *lista){
    if(vacia(lista))
        cout<<"La lista no tiene información"<<"\n";
    else{
        Nodo <T> *aux;
        aux=lista->cab;
        cout<<"La informacion de la lista es: \n";
        int pos=1;
        while(aux!=NULL){
            cout<<aux->info<<" ";
            aux=aux->sig;
            pos++;
        }
    }
    cout<<"\n";
}
template <typename T>
bool esta(Lista <T> *lista,int infonueva){
    return true;
}
