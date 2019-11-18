//
//  main.cpp
//  Funciones listas
//
//  Created by Laura Juliana Mora on 11/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "FuncionesL.hpp"
using namespace std;
int main() {
    int op, num;
    Lista *lista,*pares;
    lista=crearlista();
    do{
    op=menu();
    switch (op) {
        case 1:
            cout<<"Digite un  numero: ";
            cin>>num;
            insertar(lista, num);
            break;
        case 2:
            cout<<"Digite un  numero: ";
            cin>>num;
            insertarInicio(lista, num);
            break;
        case 3:
            
            break;
        case 4:
            cout<<"Borrar ultimo nodo\n";
            borrarfinal(lista);
            break;
        case 5:
            pares=listapares(lista);
            cout<<"Lista con pares: \n";
            imprimir(pares);
            break;
        case 6:
            imprimir(lista);
            break;
        default:
            break;
    }
    }while(op!=0);
    return 0;
}
