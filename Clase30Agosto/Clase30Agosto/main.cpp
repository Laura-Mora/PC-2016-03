//
//  main.cpp
//  Clase30Agosto
//
// Invertir numero
//

#include <iostream>
#include <math.h>
using namespace std;
int invertir(int num, float dig);
int main() {
    int num,num2=0;
    float dig;
    cin>>num;
    cin>>dig;
    num2=invertir(num,dig);
    /*while(num>0){
        num2=num2*10;
        num2=num2+(num%10);
        num=num/10;
    }*/
    cout<<num2;
    return 0;
}
int invertir(int num, float dig){
    if(num<10)
        return num;
    else
        return ((num%10)*pow(10,dig-1)+invertir((num/10),dig-1));
}