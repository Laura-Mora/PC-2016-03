//
//  FuncionesL.cpp
//  Funciones listas
//
//  Created by Laura Juliana Mora on 11/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "FuncionesL.hpp"
#include <iostream>
using namespace std;
int menu(){
    int op;
    do{
    cout<<"Menu: \n 0.Salir \n 1.Insertar final \n 2.Insertar inicio \n 3.Ordenar la lista \n 4.Borrar Final \n 5.Nueva lista con los pares \n 6. Imprimir \n";
    cout<<"Digite una opcion: ";
    cin>>op;
    }while (op>6||op<0);
    return op;
}
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
void insertarInicio(Lista *lista, int infonueva){
    Nodo *nuevo;
    nuevo=new Nodo;
    nuevo->info=infonueva;
    nuevo->sig=NULL;
    
    nuevo->sig=lista->cabe;
    lista->cabe=nuevo;
    lista->tam++;
}
void borrarfinal(Lista *lista){
    Nodo *aux, *aux2;
    aux=lista->cabe;
    aux2=aux;
    while(aux->sig!=NULL){
        aux=aux->sig;
        if(aux->sig==NULL)
            aux2->sig=NULL;
        aux2=aux2->sig;
    }
    imprimir(lista);
}
Lista *listapares(Lista *lista){
    Lista *nueva;
    Nodo *aux;
    nueva=crearlista();
    aux=lista->cabe;
    while(aux!=NULL){
        if(aux->info%2==0)
            insertar(nueva, aux->info);
        aux=aux->sig;
    }
    return nueva;
}
bool esta(Lista *lista, int num){
    bool es=false;
    Nodo *aux;
    aux=lista->cabe;
    while(aux!=NULL&&aux->info!=num){
        if(aux->info==num)
            es=true;
        aux=aux->sig;
    }
    return es;
}
void ordenar(Lista *lista){
    Nodo *aux, *menor = nullptr, *aux2, *fijo;
    int cont=0;
    fijo=lista->cabe;
    while (aux!=NULL){
        aux=fijo;
        for(int i=0;i<lista->tam;i++){
            if(aux->info<menor->info)
                menor=aux;
            aux=aux->sig;
        }
        
    }
}
