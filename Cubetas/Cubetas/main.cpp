//
//  main.cpp
//  Cubetas
//
//  Created by Laura Juliana Mora on 6/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "funciones.hpp"
using namespace std;
int main() {
    int N, digitos, **m, *p;
    cout<<"Cantidad de de numeros en el vector: ";
    cin>>N;
    cout<<"Cantidad de digitos maximo en los numeros: ";
    cin>>digitos;
    p=new int[N];
    crearvector(p,N, digitos);
    ordenar(p, N, digitos,m);
    delete p;
    cout<<"\n";
    return 0;
}
