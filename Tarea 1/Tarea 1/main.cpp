//
//  main.cpp
//  Tarea 1
//
//  Created by Laura Juliana Mora on 30/07/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#define MAX 11
using namespace std;
void ordenar(int *ptr, int tam);
void leer(int n, int m, int tam, int *ptra, int *ptrb, int *ptr);
void imprimir(int *ptr, int tam);
int main() {
    int a[MAX], b[MAX], c[22],m,n,tam;
    int *ptr, *ptra,*ptrb ;
    do{
        cout<<"Tamaño vector a: ";
        cin>>m;
    }while(m>10);
    do{
        cout<<"Tamaño vector b: ";
        cin>>n;
    }while(n>10);
    tam=n+m;
    ptra=&a[0];
    ptrb=&b[0];
    ptr=&c[0];
    leer(n,  m,  tam,  ptra,  ptrb, ptr);
    return 0;
}
void leer(int n, int m, int tam, int *ptra, int *ptrb, int *ptr){
    int i=0,pa=0, pb=0, tam1=0, **bum;

    bum=&ptr;
    while(i<tam){
            if(pa<m){
            *(ptra+pa)=(1+rand() %  9);
            //cout<<"Dato a: "<<*(ptra+i)<<"\n";
            *(ptr+i)=*(ptra+pa);
            i++;
            pa++;

          tam1++;
        }


            ordenar(ptr,tam1);

        if(pb<n){
            *(ptrb+pb)=(1+rand() %  9);
            //cout<<"Dato b: "<<*(ptrb+i)<<"\n";
            *(ptr+i)=*(ptrb+pb);

            i++;
            pb++;

    tam1++;
        }


    ordenar(ptr,tam1);

    }
    cout<<"Vector a: ";
    imprimir(ptra,m);
    cout<<"\n";
    cout<<"Vector b: ";
    imprimir(ptrb,n);
    cout<<"\n";
    cout<<"Vector c: ";
    imprimir(ptr,tam);
}
void ordenar(int *ptr, int tam){

    int i,j;
    int aux;
    for(i=0;i<tam-1;i++)
    {

        for(j=i+1;j<tam;j++)
        {

            if(*(ptr+i)>*(ptr+j))
            {

                aux=*(ptr+i);
                *(ptr+i)=*(ptr+j);
                *(ptr+j)=aux;
            }

        }
    }

}
void imprimir(int *ptr, int tam){
    for(int i=0;i<tam;i++){
        cout<<" "<<*(ptr+i);
    }
}
