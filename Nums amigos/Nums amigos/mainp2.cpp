//
//  main.cpp
//  Nums amigos
//
//  Created by Laura Juliana Mora on 1/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include "FuncionesNumerosAmigos.hpp"
using namespace std;
int main() {
    int numer, cont=1,acu=0,acu2=0;
    cin>>numer;
    acu=num(numer, acu, cont);
    cout<<acu<<"\n";
    cont=1;
    acu2=num(acu, acu2, cont);
    cout<<acu2<<"\n";
    if(acu2==numer)
        cout<<numer<<" es amigo de "<<acu<<"\n";
    else
        cout<<numer<<" no es amigo de "<<acu<<"\n";
    return 0;
}
