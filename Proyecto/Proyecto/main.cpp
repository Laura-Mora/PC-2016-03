//
//  main.cpp
//  Proyecto
//
//  Created by Laura Juliana Mora on 6/11/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include "funciones.hpp"
using namespace std;

int main()
{
    fstream entrada;
    entrada.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/sucursales.txt", ios::in);
    //entrada.open("sucursales.txt",ios::in);
    
    if (!entrada){
        cout<<"error: archivo no encontrado\n";
        //		exit(1);
    }
    entrada.close();
    menu();
    
    return 0;
}
