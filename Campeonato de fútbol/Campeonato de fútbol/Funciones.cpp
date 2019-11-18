//
//  Funciones.cpp
//  Campeonato de fútbol
//
//  Created by Laura Juliana Mora on 15/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Funciones.hpp"
#include <iostream>
using namespace std;
Campeonato *crearCampeonato(int N){
    Campeonato *ap;
    ap = new  Campeonato;
    ap->equipos= new Equipo[N];
    for(int i=0;i<N;i++){
        (ap)->equipos[i].partidos=new int *[N];
        for(int j=0;j<N;j++)
            (ap)->equipos[i].partidos[j]=new int [2];
    }
    return ap;
}
void leer(Campeonato *ap, int N){
    int k=0;

    while(k<N){
        cout<<"Nombre del equipo "<<k+1<<": ";
        cin>>(ap)->equipos[k].nombre;
        cout<<"Posicion del equipo: ";
        cin>>(ap)->equipos[k].posicion;
        for(int i=0;i<N;i++){
                cout<<"Puntos del partido "<<i+1<<": ";
                cin>>ap->equipos[k].partidos[i][1];
                ap->equipos[k].partidos[i][0]=i+1;
            
        }
        k++;
    }
    k=0;
    while(k<N){
        cout<<"Nombre del equipo: "<<(*ap).equipos[k].nombre<<"\n";
        cout<<"Posicion del equipo: "<<(*ap).equipos[k].posicion<<"\n";
        for(int i=0;i<N;i++){
            for(int j=1;j<2;j++){
                cout<<"Puntos del partido "<<i+1<<": "<<(*ap).equipos[k].partidos[i][j]<<"\n";
            }
        }
        k++;
    }
}
int promedio(Campeonato *ap, int N,string nom){
    int pro=0;
    bool es=false;
    
    for(int i=0;i<N && es==false;i++){
        if(nom==ap->equipos[i].nombre){
            es=true;
            for(int j=0;j<N;j++)
                pro=pro+ap->equipos[i].partidos[j][1];
        }
    }
    if(es==true){
        pro=pro/N;
        cout<<"Promedio del equipo "<<nom<<": "<<pro<<"\n";
    }else
        cout<<"El equipo no existe "<<"\n";
    return pro;
}
int menu(){
    int op;
    do{
        cout<<"1.Promedio"<<"\n"<<"2.Campeon (Solo funciona si usas antes el promedio)"<<"\n"<<"3.Salir"<<"\n"<<"¿Cual opcion desea ejecutar? ";
        cin>>op;
    }while(op>3||op<1);
    return op;
}
void ganador(Campeonato *ap, int N){
    Equipo ganador;
    int prom, prom2;
    ganador=(ap)->equipos[0];
    for (int i=1;i<N;i++){
        prom=promedio(ap, N, ap->equipos[i].nombre);
        prom2=promedio(ap,N, ganador.nombre);
        if(prom>prom2){
            ganador=(ap)->equipos[i];
        }
    }
    cout<<"Ganador: "<<ganador.nombre<<"\n";
}
