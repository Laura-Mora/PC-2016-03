//
//  palabras.cpp
//  Recursión 29Sept
//
//  Created by Laura Juliana Mora on 29/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
bool palindromo(int cont, char *cad, int tam);
int main(){
    bool es;
    char *cad;
    int tam=0, cont=0;
    cin.getline(cad, 50,'\n');
    tam=strlen(cad);
    es=palindromo(cont,cad,tam);
    cout<<es;
    return 0;
}
bool palindromo(int cont, char *cad, int tam){
    if(cont==tam){
        if(*(cad+cont)==*(cad+tam))
            return true;
        else
            return false;
    }else{
        return palindromo(cont+1,cad,tam);
    }
}
