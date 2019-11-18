//
//  FuncionesP3.cpp
//  Voltear recursion
//
//  Created by Laura Juliana Mora on 3/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "FuncionesP3.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*char *invertir (char *pal, int tam, int numaux, char *aux){
    if(numaux==tam){
        *(aux+numaux)=*(pal+0);
        return aux;
    }

}*/
char *invertit (char *pal){
    char *aux;
    aux=new char[2];
    *(aux+1)=NULL;
    *aux=*pal;
    if(*(pal+1)!=NULL)
        return strcat(invertit(pal+1), aux);
    return pal;
}