//
//  main.cpp
//  Pilas & Colas
//
//  Created by Laura Juliana Mora on 3/11/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include "funciones.hpp"
using namespace std;
int main() {
    char *ecuacion;
    ecuacion=new char[50];
    compo priori[8], dataux, var,*aux;
    prio(priori);
    stack<compo> operadores;
    queue<char> salida;
    int tam=0, tamp=0, tamc=0;
    cout<<"Digite la ecuacion: ";
    cin.getline(ecuacion, 50, '\n');
    tam=strlen(ecuacion);
    //cout<<tam;
    aux= new compo [tam];
    for(int i=0;i<tam;i++){
        tamp=0;
        if(*(ecuacion+i)>=65&&*(ecuacion+i)<=90){
            salida.push(*(ecuacion+i));
            cout<<salida.back();
        }else{
            dataux.vari=*(ecuacion+i);
            for(int j=0;j<8;j++){
                if(dataux.vari==priori[j].vari){
                    dataux.prio=priori[j].prio;
                    break;
                }
            }
            if(dataux.vari=='('){
                operadores.push(dataux);
                var=operadores.top();
                cout<<"\n";
            }else if(dataux.vari==')'){
                tamp=0;
                if(!operadores.empty()){
                do{
                    *(aux+tamp)=operadores.top();
                    if((aux+tamp)->vari!='('){
                        salida.push((aux+tamp)->vari);
                        cout<<salida.back();
                    }
                    tamp++;
                    operadores.pop();
                }while((aux+(tamp-1))->vari!='('||!operadores.empty());
                }
            }else{
                tamp=0;
                if(!operadores.empty()){
                    do{
                        *(aux+tamp)=operadores.top();
                        if((aux+tamp)->prio>=dataux.prio){
                            salida.push((aux+tamp)->vari);
                            cout<<salida.back();
                            operadores.pop();
                        }
                        tamp++;
                        //tamc=tamp-1;
                    }while((aux+(tamp-1))->prio>=dataux.prio&&!operadores.empty());
                    operadores.push(dataux);
                }else{
                    operadores.push(dataux);
                }
                
            }
        }
    }
    while(!operadores.empty()){
        *aux=operadores.top();
        salida.push(aux->vari);
        cout<<salida.back();
        operadores.pop();
    }
    cout<<"\n";
    return 0;
}

