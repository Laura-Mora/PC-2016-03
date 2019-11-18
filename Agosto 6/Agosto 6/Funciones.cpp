//
//  Funciones.cpp
//  Agosto 6
//
//  Created by Laura Juliana Mora on 8/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//
#include <iostream>
#include "Funciones.hpp"
using namespace std;
Lista *crearlista(){
    Lista *lista = new Lista;
    lista->tam=0;
    lista->cabe=NULL;
    return lista;
}
void insertar(Lista *lista, int infonueva){
    Nodo *nuevo;
    nuevo= new Nodo;
    nuevo->info=infonueva;
    nuevo->sig=NULL;
    if(lista->tam==0){
        lista->cabe=nuevo;
        lista->tam++;
    }
    else{
        Nodo *aux;
        aux=lista->cabe;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
        lista->tam++;
    }
}
bool vacia (Lista *lista){
    if(lista->tam==0)
        return true;
    else
        return false;
}
void imprimir(Lista *lista){
    if(vacia(lista))
        cout<<"La lista no tiene información"<<"\n";
    else{
        cout<<"La informacion de la lista es: "<<"\n";
        Nodo *aux;
        aux=lista->cabe;
        int pos=1;
        while(aux!=NULL){
            cout<<"Info "<<pos<<": "<<aux->info<<"\n";
            aux=aux->sig;
            pos++;
        }
    }
}
void reversa(Lista *lista){
    Nodo *aux,*aux2 = nullptr,*sraux = nullptr, *aux3 = nullptr,*aux4;
    int cont=1;
    aux=lista->cabe;
    aux2=aux;
    while (cont<=lista->tam){
        aux3=aux;
        aux4=aux;
        while(aux3->sig!=NULL){
            aux3=aux3->sig;
            if(aux3->sig==NULL){
                aux4->sig=NULL;
            }
            aux4=aux4->sig;
        }
        sraux=aux3;
        if(cont==1){
            aux2=sraux;
            lista->cabe=aux2;
        }else{
            aux2->sig=sraux;
            aux2=aux2->sig;
        }
        cont++;
    }
    aux2->sig=NULL;
}