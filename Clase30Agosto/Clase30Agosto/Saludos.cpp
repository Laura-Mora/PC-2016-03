//
//  Saludos.cpp
//  Clase30Agosto
//
//  Created by Laura Juliana Mora on 30/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int cantsaludos(int cant);
int main(){
    int cant;
    cin>>cant;
    cout<<cantsaludos(cant);
    return 0;
}
int cantsaludos(int cant){
    if(cant==1)
        return 0;
    else
        return ((cant-1)+cantsaludos(cant-1));
}