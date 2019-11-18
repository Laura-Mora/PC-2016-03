//
//  main.cpp
//  Taller archivos1
//
//  Created by Laura Juliana Mora on 20/10/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include "funciones.hpp"

using namespace std;
int main() {
    datos dat;
    dat.apellido=new char [20];
    dat.nombre=new char[20];
    dat.celular=new char[20];
    dat.codigo= new char [20];
    char *frase;
    frase=new char [50];
    quemar();
    int men=0;
    do{
       men=menu();
        switch (men) {
            case 1:
                leer();
                break;
            case 2:
                generar();
                break;
            case 3:
                cout<<"Codigo del nuevo empleado ";
                cin.getline(dat.codigo, 20, '\n');
                cout<<"Apellido del nuevo empleado ";
                cin.getline(dat.apellido, 20, '\n');
                cout<<"Nombre del nuevo empleado ";
                cin.getline(dat.nombre, 20, '\n');
                cout<<"Celular del nuevo empleado ";
                cin.getline(dat.celular, 20, '\n');
                agregar(dat);
                leer();
                break;
            case 4:
                cartas();
                break;
            case 5:
                telefonos();
                break;
            default:
                break;
        }
    }while(men!=0);
    return 0;
}
