//
//  main.cpp
//  taller 3 listas 2.0
//
//  Created by Laura Juliana Mora on 2/10/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "Funciones.hpp"
using namespace std;
int main() {
    Lista *con1, *con2, *un, *in, *dif;
    int op;
    con1=crearlista();
    con2=crearlista();
    dif=crearlista();
    do{
        op=menu();
        switch (op) {
            case 1:
                int con;
                cout<<"En cual conjunto desea agregar datos: (conjunto 1 o conjunto 2) ";
                cin>>con;
                if(con==1){
                    int num;
                    cout<<"Digite el numero que desea ingresar ";
                    cin>>num;
                    if(esta(con1, num)){
                        cout<<"Este dato ya se encuentra en el conjunto\n";
                    }else{
                        insertar(con1, num);
                    }
                }else if(con==2){
                    int num;
                    cout<<"Digite el numero que desea ingresar ";
                    cin>>num;
                    if(esta(con2, num)){
                        cout<<"Este dato ya se encuentra en el conjunto\n";
                    }else{
                        insertar(con2, num);
                    }
                }
                break;
            case 2:
                int conju;
                
                cout<<"En cual conjunto desea eliminar datos: (conjunto 1 o conjunto 2) ";
                cin>>conju;
                if(conju==1){
                    int num;
                    cout<<"Digite el numero que desea eliminar ";
                    cin>>num;
                    if(esta(con1, num)){
                        elim(con1, num);
                    }else{
                        cout<<"El dato no se encuntra en el conjunto \n";
                    }
                }else if(conju==2){
                    int num;
                    cout<<"Digite el numero que desea eliminar ";
                    cin>>num;
                    if(esta(con2, num)){
                        elim(con2, num);
                    }else{
                        cout<<"El dato no se encuntra en el conjunto\n";
                    }
                }
                break;
            case 3:
                int conj;
                cout<<"En cual conjunto desea imprimir datos: (conjunto 1 o conjunto 2) ";
                cin>>conj;
                if(conj==1){
                    imprimir(con1);
                }else if(conj==2){
                    imprimir(con2);
                }
                break;
            case 4:
                un=crearlista();
                uni(con1, con2, un);
                imprimir(un);
                break;
            case 5:
                in=crearlista();
                inter(con1, con2, in);
                imprimir(in);
                break;
            case 6:
                dif=crearlista();
                int opi;
                cout<<"1.Conjunto 1 - Conjunto 2\n 2. Conjunto 2- Conjunto 1\n Digite la opcion que desea ejecutar ";
                cin>>opi;
                if(opi==1){
                    diferencia(con1, con2, dif);
                    imprimir(dif);
                }else if(opi==2){
                    diferencia(con2, con1, dif);
                    imprimir(dif);
                }
                break;
            default:
                break;
        }
    }while (op!=0);
    return 0;
}
