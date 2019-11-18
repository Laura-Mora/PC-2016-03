//
//  pez.cpp
//  Tarea 1
//
//  Created by Laura Juliana Mora on 1/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
void unir(int m, int n, int *ap, int *ab, int tam, int *ac);
void leer(int m, int n, int *ap, int *ab);
void igual(int m, int n, int *ap, int *ab, int tam, int *ac);
bool esta(int*ab,int n,int *num);
void diferente(int m, int n, int *ap, int *ab, int tam, int *ac);
int menu();
int main(){
    int m,n,a[10],b[10],c[20],d[20],e[20],tam, men;
    int *ap,*ab,*ac;
    cout<<"tamaño vector a";
    cin>>m;
    cout<<"tamaño vector b";
    cin>>n;
    tam=m+n;
    ap=&a[0];
    ab=&b[0];
    leer(m,n,ap,ab);
    men=menu();
    switch (men){
        case 1:
            ac=&c[0];

           unir(m,n,ap,ab,tam,ac);
        break;
        case 2:
            ac=&d[0];
            tam=0;
            igual(m,n,ap,ab,tam,ac);
        break;
        case 3:
            ac=&d[0];
            tam=0;
            diferente(m,n,ap,ab,tam,ac);
        break;
    }

    return 0;
}
int menu(){
    int opc;
    do{
        cout<<"\n"<<"1.Union"<<"\n"<<"2.Interseccion"<<"\n"<<"3.Diferencia (a-b)"<<"\n"<<"Cual opcion desea ejecutar?";
        cin>>opc;
    }while(opc>3||opc<1);
    return opc;
}
void leer(int m, int n, int *ap, int *ab){
    cout<<"Vector a: ";
    for(int i=0;i<m;i++){
        cin>>*(ap+i);
    }
    cout<<"Vector b: ";
    for(int i=0;i<n;i++){
        cin>>*(ab+i);
    }
    cout<<"Vector a: ";
    for(int i=0;i<m;i++){
        cout<<*(ap+i)<<" ";
    }
    cout<<"\n"<<"Vector b:";
    for(int i=0;i<n;i++){
        cout<<*(ab+i)<<" ";
    }

}
void unir(int m, int n, int *ap, int *ab, int tam, int *ac){
    int j=0;
    for(int i=0;i<m;i++){
        *(ac+i)=*(ap+i);
    }
    for(int i=m;i<tam;i++){
        *(ac+i)=*(ab+j);
        j++;
    }
    cout<<"Vector c: ";
    for(int i=0;i<tam;i++){
        cout<<*(ac+i)<<" ";
    }
    cout<<"\n";
}
void igual(int m, int n, int *ap, int *ab, int tam, int *ac){
    bool es=false;
    for(int i=0;i<m;i++){
        es=false;
        es=esta(ab,n,(ap+i));
        if(es==true){
            *(ac+i)=*(ap+i);
            tam++;
        }
    }
    cout<<"Vector d: ";
    for(int i=0;i<tam;i++){
        cout<<*(ac+i);
    }
    cout<<"\n";
}
bool esta(int*ab,int n,int *num){
    bool es=false;
    for(int i=0;i<n&&es==false;i++){
        if(*num==*(ab+i)){
            es=true;
        }
    }
    return es;
}
void diferente(int m, int n, int *ap, int *ab, int tam, int *ac){
    bool es=false;
    for(int i=0;i<m;i++){
        es=false;
        es=esta(ab,n,(ap+i));
        if(es==false){
            *(ac+i)=*(ap+i);
            tam++;
        }
    }
    cout<<"Vector e: ";
    for(int i=0;i<tam;i++){
        cout<<*(ac+i);
    }
    cout<<"\n";
}
