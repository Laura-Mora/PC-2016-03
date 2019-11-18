//
//  main.cpp
//  Campeonato de fútbol
//
//  Created by Laura Juliana Mora on 15/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "Funciones.hpp"
using namespace std;
int main() {
    unsigned int N;
    int op, prom;
    Campeonato *cam;
    string nom;
    cout<<"¿Cantidad de equipos? ";
    cin>>N;
    cam=crearCampeonato(N);
    leer(cam, N);
    do{
       op=menu();
        switch (op) {
            case 1:
                cout<<"Nombre del equipo del cual quiere conocer el promedio: ";
                cin>>nom;
                prom=promedio(cam, N, nom);
                break;
            case 2:
                ganador(cam, N);
                break;
            default:
                cout<<"Adios"<<"\n";
                break;
        }
    }while(op<3&&op>0);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
           delete (cam)->equipos[i].partidos[j];
    delete cam;
    return 0;
}
