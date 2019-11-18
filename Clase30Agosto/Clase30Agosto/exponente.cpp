//
//  exponente.cpp
//  Clase30Agosto
//
//  Created by Laura Juliana Mora on 30/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int expo(int num, int ex);
int main(){
    int num, ex;
    cin>>num;
    cin>>ex;
    cout<<expo(num, ex);
    return 0;
}
int expo(int num, int ex){
    if(ex==0)
        return 1;
    else
        return num*expo(num,ex-1);
}