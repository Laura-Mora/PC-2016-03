//
//  funciones.cpp
//  Cubetas
//
//  Created by Laura Juliana Mora on 6/08/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "funciones.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void crearvector(int *p, int cantidad,int dig){
    int num=1, cont=0;
    while(cont<dig){
        num=num*10;
        cont++;
    }
    num--;
    for(int i=0;i<cantidad;i++){
        *(p+i)=(1+rand()%num);
        cout<<*(p+i)<<" ";
    }
    cout<<"\n";
}
void ordenar(int *p, int cantidad, int dig, int **m){
    int cont=0, numm=10, div=1, *cantr, posvec=0, posi=0, pos=0;
    while(cont<dig){
        posvec=0;
        m=new int*[10];
        cantr=new int[10];
        for(int i=0;i<10;i++)
            m[i]=new int[cantidad];
        for(int i=0;i<10;i++){
            *(cantr+i)=0;
            //cout<<*(cantr+i)<<" ";
        }
        //cout<<"\n";
        //cout<<"\n";
        
        for(int i=0;i<10;i++){
            for(int j=0;j<cantidad;j++){
                *(*(m+i)+j)=0;
                //cout<< *(*(m+i)+j)<<" ";
            }
            //cout<<"\n";
        }
        cout<<"\n";
        for(int i=0;i<cantidad;i++){
            pos= *(p+i)%numm;
            posi=pos/div;
            
            *(*(m+ posi)+ *(cantr+posi))=*(p+i);
            *(cantr+posi)= *(cantr+posi)+1;
        }
        
        for(int i=0;i<10;i++){
            for(int j=0;j<*(cantr+i);j++){
                if(*(*(m+i)+j)>0){
                    *(p+posvec)=*(*(m+i)+j);
                    posvec++;
                }
            }
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<cantidad;j++){
                cout<< *(*(m+i)+j)<<" ";
            }
            cout<<"\n";
        }
        for(int i=0;i<cantidad;i++)
            cout<<*(p+i)<<" ";
        cout<<"\n";
        
        for(int i=0;i<10;i++)
            delete m[i];
        delete m;
        delete cantr;
        numm=numm*10;
        div=div*10;
        cont++;
        
    }
    cout<<"Vector final (ordenado): ";
    for(int i=0;i<cantidad;i++)
        cout<<*(p+i)<<" ";
    
    
}

