//
//  funciones.cpp
//  Polinomios
//
//  Created by Laura Juliana Mora on 15/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "Funciones.hpp"
using namespace std;
template <typename T>
Lista <T> *crearlista(){
    Lista <T> *lista = new Lista <T>;
    lista->tam=0;
    lista->cab=NULL;
    return lista;
}
template <typename T>
void insertar(Lista <T> *lista, int infonueva, int exponente){
    Nodo <T> *nuevo;
    nuevo= new Nodo <T>;
    nuevo->num=infonueva;
    nuevo->expo=exponente;
    nuevo->sig=NULL;
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
        int pos=1;
        while(aux!=NULL){
            cout<<aux->info.num<<"x^"<<aux->expo;
            if(aux->sig!=NULL)
                cout<<" + ";
            aux=aux->sig;
            pos++;
        }
    }
    cout<<"\n";
}
template <typename T>
int obtenerDato(Lista <T > *lista, int pos)
{
    Nodo <T> * aux;
    aux = lista->cab;
    
    while(aux != NULL)
    {
        if(pos == aux->expo)
        {
            return aux->num;
        }
        aux = aux->sig;
    }
    return 0;
}
template <typename T>
bool esta(Lista <T> *lista, int nume){
    Nodo <T> *aux;
    aux=lista->cab;
    while(aux!=NULL){
        if(aux->info.expo==nume)
            return true;
        else
            aux=aux->sig;
    }
    return false;
}
template <typename T>
void sumar(Lista <T> *lista, Lista <T> *lista2, Lista <T> *listafinal){
    Nodo <T> *aux1,*aux2;
    int num=0,sum=0;
    aux1=lista->cab;
    aux2=lista2->cab;
    while(aux1 != NULL){
        num=obtenerDato(lista2, aux1->expo);
        sum=num+aux1->num;
        if(sum!=0)
            insertar(listafinal, sum, aux1->expo);
        aux1=aux1->sig;
    }
    while(aux2 != NULL){
        if(esta(listafinal,aux2->expo))
            aux2=aux2->sig;
        else{
            num=obtenerDato(lista, aux2->expo);
            sum=num+aux2->info.num;
            if(sum!=0)
                insertar(listafinal, sum, aux2->expo);
            aux2=aux2->sig;
        }
    }
    cout<<"Suma de Polinomios (Polinomio Final):\n";
    imprimir(listafinal);
}
template <typename T>
int solucion(Lista <T> *lista, int x){
    int sum=0,n=0;
    Nodo <T> *aux;
    aux=lista->cab;
    while(aux!=NULL){
        n=aux->info.num*pow(x, aux->expo);
        sum=sum+n;
        aux=aux->sig;
    }
    return sum;
}
