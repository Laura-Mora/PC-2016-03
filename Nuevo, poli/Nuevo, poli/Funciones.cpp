//
//  Funciones.cpp
//  Nuevo, poli
//  Polinomios sin Templates
//  Created by Laura Juliana Mora on 16/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//
#include <iostream>
#include <math.h>
#include "Funciones.hpp"
using namespace std;
Lista *crearlista(){
    Lista *lista = new Lista;
    lista->tam=0;
    lista->cab=NULL;
    return lista;
}
void insertar(Lista *lista, int infonueva, int exponente){
    Nodo *nuevo;
    nuevo= new Nodo;
    nuevo->info.num=infonueva;
    nuevo->info.expo=exponente;
    nuevo->sig=NULL;
    if(lista->tam==0){
        lista->cab=nuevo;
        lista->tam++;
    }
    else{
        Nodo *aux;
        aux=lista->cab;
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
        Nodo *aux;
        aux=lista->cab;
        int pos=1;
        while(aux!=NULL){
            cout<<aux->info.num<<"x^"<<aux->info.expo;
            if(aux->sig!=NULL)
                cout<<" + ";
            aux=aux->sig;
            pos++;
        }
    }
    cout<<"\n";
}
int obtenerDato(Lista * lista, int pos)
{
    Nodo * aux;
    aux = lista->cab;
    
    while(aux != NULL)
    {
        if(pos == aux->info.expo)
        {
            return aux->info.num;
        }
        aux = aux->sig;
    }
    return 0;
}
bool esta(Lista *lista, int nume){
    Nodo *aux;
    aux=lista->cab;
    while(aux!=NULL){
        if(aux->info.expo==nume)
            return true;
        else
            aux=aux->sig;
    }
    return false;
}
void sumar(Lista *lista, Lista *lista2, Lista *listafinal){
    Nodo *aux1,*aux2;
    int num=0,sum=0;
    aux1=lista->cab;
    aux2=lista2->cab;
    while(aux1 != NULL){
        num=obtenerDato(lista2, aux1->info.expo);
        sum=num+aux1->info.num;
        if(sum!=0)
            insertar(listafinal, sum, aux1->info.expo);
        aux1=aux1->sig;
    }
    while(aux2 != NULL){
        if(esta(listafinal,aux2->info.expo))
            aux2=aux2->sig;
        else{
            num=obtenerDato(lista, aux2->info.expo);
            sum=num+aux2->info.num;
            if(sum!=0)
                insertar(listafinal, sum, aux2->info.expo);
            aux2=aux2->sig;
        }
    }
    cout<<"Suma de Polinomios (Polinomio Final):\n";
    imprimir(listafinal);
}
int solucion(Lista *lista, int x){
    int sum=0,n=0;
    Nodo *aux;
    aux=lista->cab;
    while(aux!=NULL){
        n=aux->info.num*pow(x, aux->info.expo);
        sum=sum+n;
        aux=aux->sig;
    }
    return sum;
}
