//
//  main.cpp
//  Recursión 29Sept
//
//  Created by Laura Juliana Mora on 29/09/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void llenar(int nums[50][50],int x, int y);
int vector(int nums[][50],int x, int y, int numv[],int i,int *pez);
int primo(int num, int cant, int i);
int correr (int nums[][50], int y,int pos,int cont, int numv[],int *pez);
int main() {
    int nums[50][50],numv[50];
    int tamx=0, tamy=0,tam,*pez=new int,i=0;
    *pez=0;
    cout<<"cantidad de filas ";
    cin>>tamx;
    cout<<"cantidad de columnas ";
    cin>>tamy;
    llenar(nums, tamx, tamy);
    cout<<"ban";
    tam=vector(nums, tamx, tamy, numv,i,pez);
    cout<<"Numeros primos de la matriz: \n";
    cout<<*pez;
    for(int i=0;i<*pez;i++)
        cout<<numv[i]<<" ";
    cout<<"\n";
    return 0;
}
void llenar(int nums[50][50],int x, int y){
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++){
            nums[i][j]=(1+rand()%100);
            
        }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}
int vector(int nums[][50],int x, int y, int numv[],int i,int *pez){
    int cont=0;
    if(i==x){
        return 0;
    }else{
        i=correr(nums,y,i,cont,numv,pez);
        return vector(nums,x,y,numv,i,pez);
    }
    
}

bool insertar(int num,int numv[],int *p){
    int res=0;
    res=primo(num,0,1);
    if(res<=2){
        numv[*p]=num;
        return true;
    }else{
        return false;
    }
}
int correr (int nums[][50], int y,int pos,int cont, int numv[],int *pez){
    if(cont==y){
        return pos+1;
    }else{
        if(insertar(nums[pos][cont], numv, pez)){
            *pez+=1;
            return correr(nums, y, pos, cont+1, numv,pez);
        }else{
            return correr(nums, y, pos, cont+1, numv,pez);
        }
    }
}
int primo(int num, int cant, int i){
    if(num==i||cant>2){
        return cant+1;
    }else{
        if(num%i==0){
            return primo(num,cant+1,i+1);
        }else{
            return primo(num,cant,i+1);
        }
    }
}
