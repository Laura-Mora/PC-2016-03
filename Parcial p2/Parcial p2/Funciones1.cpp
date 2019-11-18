//
//  Funciones1.cpp
//  Parcial p2
//
//  Created by Laura Juliana Mora on 19/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Funciones1.hpp"
#include <iostream>
using namespace std;

void agregar(cancion *arreglocanciones, cancion *indice, int *cant,  cancion *autor){
    cancion *auxar, *auxin, *auxau, sraux, nueva;
    char conti;

    do{
        cout<<"Nombre cancion nueva: ";
        cin>>nueva.titulo;
        cout<<"Nombre del autor de la cancion "<<nueva.titulo<<" ";
        cin>>nueva.autor;
        cout<<"Cantidad de minutos que dura la cancion "<<nueva.titulo<<" ";
        cin>>nueva.tiempo;
        *cant=(*cant)+1;
        auxar= new cancion [*cant];
        auxin= new cancion [*cant];
        auxau= new cancion [*cant];
        for(int i=0;i<(*cant)-1;i++){
            *(auxar+i)=*(arreglocanciones+i);
            *(auxin+i)=*(indice+i);
            *(auxau+i)=*(autor+i);
        }
        arreglocanciones=new cancion[*cant];
        indice=new cancion [*cant];
        autor=new cancion [*cant];
        *(auxar+(*cant)-1)=nueva;
        *(auxin+(*cant)-1)=nueva;
        *(auxau+(*cant)-1)=nueva;
        cout<<(auxau+(*cant)-1)->tiempo;
        for(int i=0;i<(*cant);i++){
            *(arreglocanciones+i)=*(auxar+i);
            *(indice+i)=*(auxin+i);
            *(autor+i)=*(auxau+i);
        }
        cout<<(arreglocanciones+(*cant)-1)->tiempo;
        for(int i=0;i<(*cant)-1;i++)
            for(int j=i+1;j<(*cant);j++)
                if((indice+i)->titulo > (indice+j)->titulo){
                    sraux=*(indice+i);
                    *(indice+i)=*(indice+j);
                    *(indice+j)=sraux;
                }
        for(int i=0;i<(*cant)-1;i++)
            for(int j=i+1;j<(*cant);j++)
                if((autor+i)->autor > (autor+j)->autor){
                    sraux=*(autor+i);
                    *(autor+i)=*(autor+j);
                    *(autor+j)=sraux;
                }
        cout<<"Desea continuar (S->si/N->no)";
        cin>>conti;
    }while (conti=='S'||conti=='s');
       for(int i=0;i<*cant;i++){
        cout<<"Nombre: "<<(arreglocanciones+i)->titulo<<"\n";
        cout<<"Autor: "<<(arreglocanciones+i)->autor<<"\n";
        cout<<"Tiempo: "<<(arreglocanciones+i)->tiempo<<"\n";
    }
    cout<<"\n"<<"Arreglo ordenado por titulos: "<<"\n";
    for(int i=0;i<*cant;i++){
        cout<<"Nombre: "<<(indice+i)->titulo<<"\n";
        cout<<"Autor: "<<(indice+i)->autor<<"\n";
        cout<<"Tiempo: "<<(indice+i)->tiempo<<"\n";
    }
    cout<<"\n"<<"Arreglo ordenado por autores: "<<"\n";
    for(int i=0;i<*cant;i++){
        cout<<"Nombre: "<<(autor+i)->titulo<<"\n";
        cout<<"Autor: "<<(autor+i)->autor<<"\n";
        cout<<"Tiempo: "<<(autor+i)->tiempo<<"\n";
    }
    //delete auxar;
    //delete auxin;
    //delete auxau;
}