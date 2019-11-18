//
//  main.cpp
//  Cadenas caracteres
//
//  Created by Laura Juliana Mora on 25/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "Funciones_caracteresp2.hpp"
using namespace std;
int main() {
    char *palabras1;
    cout<<"Digite la frase: ";
    cin.getline(palabras1, 100, '\n');
    invertir(palabras1);
    return 0;
}
