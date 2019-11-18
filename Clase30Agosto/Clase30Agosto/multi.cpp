//
//  multi.cpp
//  Clase30Agosto
//
//  Created by Laura Juliana Mora on 30/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int multi(int a, int b);
int main(){
    int a, b;
    cin>>a;
    cin>>b;
    cout<<multi(a, b);
    return 0;
}
int multi(int a, int b){
    int c=0;
    if(b==0)
        return 0;
    else{
        c=a+multi(a, (b-1));
        return c;
    }
}