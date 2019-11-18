//
//  vertical.cpp
//  Clase30Agosto
//
//  Created by Laura Juliana Mora on 30/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
void vertical(int n);
int main(){
    int num;
    cin>>num;
    vertical(num);
    return 0;
}
void vertical(int n){
    if(n!=0){
        vertical(n/10);
        cout<<endl<<n%10;
    }
}