//
//  main.cpp
//  Subcadena
//


#include <iostream>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#include "Funciones subcadena.hpp"
using namespace std;
int main() {
    char *frase1, *segunda;
    int tam1=0, tam2=0;
    bool esta=true;
    frase1= new char [MAX];
    segunda=new char [MAX];
    cout<<"Digite frase 1: ";
    cin.getline(frase1, MAX, '\n');
    tam1=frasetam(frase1);
    cout<<"Tamaño: "<<tam1<<"\n";
    cout<<"Digite frase 2: ";
    cin.getline(segunda, MAX);
    tam2=frasetam(segunda);
    cout<<"Tamaño: "<<tam2<<"\n";
    esta=subcadena(frase1, segunda);
    if(esta==true)
        cout<<"La frase 2 "<<segunda<<" contiene a la frase 1 "<<frase1<<"\n";
    else
        cout<<"La frase 2 "<<segunda<<" no contiene a la frase 1 "<<frase1<<"\n";
    delete frase1;
    delete segunda;
    return 0;
}
