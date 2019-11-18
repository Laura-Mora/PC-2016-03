//
//  main.cpp
//  PC
//
//  Created by Laura Juliana Mora on 20/07/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
using namespace std;

void suma(int *num1, int *num2, int *num3);
void prueba(int *p[]);
int main() {
    /*int a=3, b=4, c=5;
    int *pa, *pb,*pc1;
    pa=&a;
    pb=&b;
    pc1=&c;
    suma(pa,pb,pc1);*/
    int nums[5];
    int *ap[5];
    for(int i=0;i<5;i++){
        cout<<"Digite un numero ";
        cin>>nums[i];
    }
    for(int i=0;i<5;i++){
        ap[i]=&nums[i];
    }
    prueba(ap);
    return 0;
}
void suma(int *num1, int *num2, int *num3){
    int aux=0;
    aux=*num1+*num2;
    cout<<"Suma "<<*num1<<"+"<<*num2<<"="<<aux<<"\n";
    cout<<"Posiciones "<<num1<<" "<<num2<<" "<<num3<<"\n";
}
void prueba(int *p[]){
    for(int i=0;i<5;i++){
        cout<<*p[i]<<" "<<p[i]<<"\n";
    }
}