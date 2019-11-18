//
//  vocales.cpp
//  Recursión 29Sept
//
//  Created by Laura Juliana Mora on 29/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int cantvocales(char *cad, int tam, int pos, int cant);
int main(){
    char *cad;
    int tam, pos=0,cant=0, fin=0;
    cin.getline(cad, 50, '\n');
    tam=strlen(cad);
    fin=cantvocales(cad, tam, pos, cant);
    cout<<fin;
    return 0;
}
int cantvocales(char *cad, int tam, int pos, int cant){
    if(pos==tam){
        return cant;
    }else{
        if(*(cad+pos)=='a'||*(cad+pos)=='e'||*(cad+pos)=='i'||*(cad+pos)=='o'||*(cad+pos)=='u'){
            return cantvocales(cad, tam, pos+1, cant+1);
        }else{
            return cantvocales(cad, tam, pos+1, cant);
        }
    }
}
