//
//  punto 2.cpp
//  Tarea 1
//
//  Created by Laura Juliana Mora on 31/07/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//


#include <iostream>
#define MAX 10
#define MAX2 20
using namespace std;
int *menu();
void uninir(int *ap[],int *bp[],int *cp[],int tam, int m, int n);
bool esta(int *num, int *bp, int n);
void igual(int *ap[],int *bp[],int *dp[],int m, int n);
void diferente(int *ap[],int *bp[],int *ep[],int m, int n);
int main(){
    int *opmenu;
    int a[MAX], b[MAX],c[MAX],m,n,tam;
    int *ap[MAX], *bp[MAX], *cp[MAX2], *dp[MAX2],*ep[MAX2];
    do{
        cout<<"Tamano vector a: ";
        cin>>m;
    }while(m>10);
    do{
        cout<<"Tamano vector b: ";
        cin>>n;
    }while(n>10);
    cout<<"Datos vector a:";
    for(int i=0;i<m;i++)
        cin>>*(a+i);
    for(int i=0;i<m;i++){
        *(ap+i)=&*(a+i);
        //cout<<*(*ap+i);
    }
    cout<<"Datos vector b:";
    for(int i=0;i<n;i++)
        cin>>*(b+i);
    for(int i=0;i<n;i++){
        *(bp+i)=&*(b+i);
        cout<<*(*bp+i);
    }
    tam=m+n;
    for(int i=0;i<tam;i++)
        *(cp+i)=&*(c+i);
    opmenu=menu();
    switch (*opmenu) {
        case 1:
            uninir(ap, bp, cp, tam,  m,  n);
            break;
        case 2:
            igual(ap,bp,dp, m,  n);
            break;
        case 3:
            diferente(ap,bp,ep, m,  n);
            break;
    }
    return 0;
}
int *menu(){
    int *op,opc;
    do{
        cout<<"1.Union"<<"\n"<<"2.Interseccion"<<"\n"<<"3.Diferencia"<<"\n"<<"Cual opcion desea ejecutar?";
        cin>>opc;
    }while(opc>2||opc<1);
    op=&opc;
    return op;
}
void uninir(int *ap[],int *bp[],int *cp[],int tam, int m, int n){
    int i=0, j=0;
    for(j=0;j<m;j++)
        *(cp+j)=*(ap+j);
    
    for( i=0;i<n;i++){
        *(cp+j)=*(bp+i);
        j++;
    }
    for( i=0;i<tam;i++)
        cout<<*(*cp+i)<<" ";
}
bool esta(int *num, int *bp, int n){
 bool es=false;
 int p;
 for( p=0;p<n&&es==false;p++){
 if(*num==*(bp+p))
 es=true;
 
 }
 
 return es;
 }
void igual(int *ap[],int *bp[],int *dp[],int m, int n){
 bool es;
 int pos=0;
 for(int i=0;i<m;i++){
 
 es=esta(*(ap+i),*bp,n);
 if(es==true){
 *(dp+i)=*(ap+i);
 pos++;
 }
 }
 for(int i=0;i<pos;i++)
 cout<<*(*dp+i)<<" ";
 }
void diferente(int *ap[],int *bp[],int *ep[],int m, int n){
    bool es;
    int pos=0;
    for(int i=0;i<m;i++){
        
        es=esta(*(ap+i),*bp,n);
        if(es==false){
            *(ep+i)=*(ap+i);
            pos++;
        }
    }
    for(int i=0;i<pos;i++)
        cout<<*(*ep+i)<<" ";
}
