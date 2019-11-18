//
//  main.cpp
//  Perrin
//
//  Created by Laura Juliana Mora on 3/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "funciones.hpp"
using namespace std;
int main() {
    int n=0, *perrin, opc, cant=0, *c;
    c=&cant;
    cout<<"Cantidad de numeros: ";
    cin>>n;
    perrin=new int [n];
    *(perrin+0)=3;
    *(perrin+1)=0;
    *(perrin+2)=2;
    do{
        opc=menu();
        switch (opc) {
            case 1:
                datos(perrin,n);
                cout<<"Numeros Perrin: ";
                imprimir(perrin, n);
                break;
            case 2:
                cout<<"Primos Perrin (con NULL): ";
                cant=primos(perrin, n);
                break;
            case 3:
                cout<<"Primos Perrin: ";
                primos2(perrin, n, cant);
                break;
                
        }
        
    }while(opc<4);
    delete perrin;
    return 0;
}
