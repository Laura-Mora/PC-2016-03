//
//  Funciones p1.cpp
//  Suma nums
//
//  Created by Laura Juliana Mora on 1/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Funciones p1.hpp"
#include <iostream>
using namespace std;
void sum(int num, int num2){
    if(num==num2||num-num2==1)
        cout<<num<<"+"<<num2<<"\n";
    else{
        cout<<num<<"+"<<num2<<"\n";
        sum(num-1,num2+1);
    }   
}