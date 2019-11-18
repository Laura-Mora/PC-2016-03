//
//  main.cpp
//  Parcial p1
//
//  Created by Laura Juliana Mora on 19/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "funciones.hpp"
using namespace std;
int main() {
    int *V, MAX,*numero,*numero_ocurrencias,***pos;
    cout<<"Digite el tamaño del vector: ";
    cin>>MAX;
    V=new int[MAX];
    CrearV(V, MAX);
   /*for(int i=0;i<MAX;i++)
        cout<<*(V+i)<<" ";
    cout<<"\n";*/
    Crearnums(V, MAX, numero, numero_ocurrencias, pos);
    return 0;
}
