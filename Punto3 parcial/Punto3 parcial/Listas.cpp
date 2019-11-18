//
//  Listas.cpp
//  Punto3 parcial
//
//  Created by Laura Juliana Mora on 14/10/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Listas.hpp"
#include <iostream>
using namespace std;
void imprimir(Lista *lista){
    if(lista->tam==0)
        cout<<"La lista no tiene informacion \n";
    else{
        cout<<"La informacion de la lista es: \n";
        nums *aux;
        aux=lista->cab;
        while(aux!=NULL){
            cout<<aux->info<<" Bin: ";
            numbin *aux2;
            aux2=aux->ini;
            while(aux2!=NULL){
                cout<<aux2->info;
                aux2=aux2->sig;
            }
            cout<<" Hex: ";
            numhex *aux3;
            aux3=aux->inic;
            while (aux3!=NULL) {
                cout<<aux3->info;
                aux3=aux3->sig;
            }
            cout<<"\n";
            aux=aux->sig;
        }
    }
}
Lista *crear(){
    Lista *lista=new Lista;
    lista->tam=0;
    lista->cab=NULL;
    return lista;
}
void insertarbi(nums *val, int infonueva){
    numbin *nuevo;
    nuevo = new numbin;
    nuevo->info=infonueva;
    nuevo->sig=NULL;
    
    nuevo->sig=val->ini;
    val->ini=nuevo;
    val->tamb+=1;
    
}

void insertarhex(nums *val, char infonueva){
    numhex *nuevo;
    nuevo = new numhex;
    nuevo->info=infonueva;
    nuevo->sig=NULL;
    if(val->tamh==0){
        val->inic=nuevo;
        val->tamh++;
    }
    else{
        numhex *aux;
        aux=val->inic;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
        val->tamh+=1;
    }
}
void ins(Lista *lista, nums *nuevo){
    nums *aux;
    aux=lista->cab;
    int pos=0;
    if(lista->tam==0){
        insertarEnUnaPosicion(lista, nuevo, pos);
    }else{
    while (aux!=NULL){
        if(nuevo->info<aux->info){
            insertarEnUnaPosicion(lista, nuevo, pos);
            break;
        }else{
            pos++;
            if(aux->sig==NULL){
                insertarEnUnaPosicion(lista, nuevo, pos);
                aux=aux->sig;
            }
            aux=aux->sig;
        }
    }
    }
}
void insertarEnUnaPosicion (Lista * lista, nums *infoNueva, int pos){
    nums * aux;
    aux = lista->cab;
    int p = 0;
    if(lista->tam==0){
        lista->cab=infoNueva;
        lista->tam+=1;
    }else{
        if(pos==0){
            infoNueva->sig=aux;
            lista->cab=infoNueva;
            lista->tam+=1;
        }else{
            while(aux->sig != NULL)
            {
                if(pos-1==p)
                {
                    infoNueva->sig=aux->sig;
                    aux->sig=infoNueva;
                    lista->tam+=1;
                    p++;
                    break;
                }else{
                        aux = aux->sig;
                        p++;
                }
            }
            aux->sig=infoNueva;
            lista->tam+=1;
        }
    }
}
