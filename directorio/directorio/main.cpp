//
//  main.cpp
//  directorio
//
//  Created by Laura Juliana Mora on 11/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "funciones.hpp"
using namespace std;

int main() {
    direc *ap;
    int n;
    cout<<"Catidad de letras de abecedario en el directorio: ";
    cin>>n;
    ap = new direc [n];
    leer (ap,n);
    delete ap;
    return 0;
}
