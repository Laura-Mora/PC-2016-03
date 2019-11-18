//
//  Funciones.hpp
//  Campeonato de fútbol
//
//  Created by Laura Juliana Mora on 15/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef Funciones_hpp
#define Funciones_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
struct Equipo{
    string nombre;
    int posicion;
    int **partidos;
};
struct Campeonato{
    Equipo *equipos;
    unsigned int tam;
};
Campeonato *crearCampeonato( int N);
void leer(Campeonato *ap, int N);
int menu();
int promedio(Campeonato *ap, int N,string nom);
void ganador(Campeonato *ap, int N);
#endif /* Funciones_hpp */
