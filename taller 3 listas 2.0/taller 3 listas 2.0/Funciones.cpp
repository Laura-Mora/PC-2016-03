//
//  Funciones.cpp
//  taller 3 listas 2.0
//
//  Created by Laura Juliana Mora on 2/10/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Funciones.hpp"
#include <iostream>
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
bool eliminar(Lista *lista, int pos){
    if(lista->tam>pos&&pos!=-1){
        if(pos==0){
            Nodo *temp;
            temp=lista->cabe;
            lista->cabe=temp->sig;
            temp->sig=NULL;
            delete temp;
            lista->tam--;
            return true;
        }else{
            Nodo *aux;
            aux=lista->cabe;
            for(int i=0;i<pos-1;i++)
                aux=aux->sig;
            Nodo *temp;
            temp=aux->sig;
            aux->sig=temp->sig;
            temp->sig=NULL;
            delete temp;
            lista->tam--;
            return true;
        }
    }else{
        return false;
    }
}
int obtenerpoa(Lista *lista, int num){
    if(vacia(lista)==false){
        int cont=0;
        Nodo *aux;
        aux=lista->cabe;
        while(aux!=NULL){
            if(aux->info==num)
                break;
            aux=aux->sig;
            cont++;
        }
        return cont;
    }else{
        cout<<"El dato no existe \n";
        return -1;
    }
}
void elim(Lista *lista, int num){
    bool si;
    si=eliminar(lista, obtenerpoa(lista, num));
    if(si==true){
        cout<<"El dato ha sido eliminado \n";
    }else{
        cout<<"El dato no pudo ser eliminado \n";
    }
}
void inter(Lista *lista1, Lista *lista2, Lista *in){
    if(lista1->tam>lista2->tam){
        Nodo *aux;
        aux=lista1->cabe;
        while(aux!=NULL){
            if(esta(lista2, aux->info)){
                insertar(in, aux->info);
            }
            aux=aux->sig;
        }
    }else{
        Nodo *aux;
        aux=lista2->cabe;
        while(aux!=NULL){
            if(esta(lista1, aux->info)){
                insertar(in, aux->info);
            }
            aux=aux->sig;
        }
    }
}
bool esta(Lista *lista, int num){
    Nodo *aux;
    aux=lista->cabe;
    while(aux!=NULL){
        if(num==aux->info)
            return true;
        aux=aux->sig;
    }
    return false;
}
int menu(){
    int op;
    do{
        cout<<"Menu \n 0. Salir\n 1.Insertar elemento al conjunto\n 2.Eliminar un elemento\n 3.Imprimir conjunto\n 4. Union de conjuntos\n 5.Interseccion de conjuntos\n 6.Diferencia de conjuntos\n Digite la opcion que desea ejecutar";
        cin>>op;
    }while(op>6||op<0);
    return op;
}
void uni(Lista *lista1, Lista *lista2, Lista *un){
    Nodo *aux;
    aux=lista1->cabe;
    while (aux!=NULL) {
        insertar(un, aux->info);
        aux=aux->sig;
    }
    aux=lista2->cabe;
    while(aux!=NULL){
        if(esta(un, aux->info)==false){
            insertar(un, aux->info);
        }
        aux=aux->sig;
    }
}
void diferencia(Lista *lista1, Lista *lista2, Lista *dif){
    Nodo *aux;
    aux=lista1->cabe;
    while (aux!=NULL) {
        if(esta(lista2, aux->info)==false){
            insertar(dif, aux->info);
        }
        aux=aux->sig;
    }
}
