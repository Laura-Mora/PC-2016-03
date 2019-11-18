//
//  FuncionesNumerosAmigos.cpp
//  Nums amigos
//
//  Created by Laura Juliana Mora on 1/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "FuncionesNumerosAmigos.hpp"
#include <iostream>
using namespace std;
int num(int numer, int acu, int cont){
    if(cont==numer)
        return acu;
    else{
        if((numer%cont)==0){
            acu+=cont;
            acu=num(numer,acu,cont+1);
            return acu;
        }else{
            acu=num(numer,acu,cont+1);
            return acu;
        }
    }
}