//
//  funciones.cpp
//  Taller archivos1
//
//  Created by Laura Juliana Mora on 20/10/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "funciones.hpp"
#include <fstream>
#include <string.h>
using namespace std;

void leer(){
    char *frase;
    frase=new char [100];
    fstream bina;
    bina.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/pez.bin",ios::binary|ios::in);
    if(!bina){
        cout<<"Hay problemas con el archivo pez.bin \n";
    }
    bina.seekg(0,ios::end);
    int n=bina.tellg()/100;
    bina.seekg(0,ios::beg);
    for(int j=0;j<n;j++){
        bina.read(frase, 100);
        cout<<frase<<"\n";
    }
    bina.close();
    fstream binaind;
    binaind.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/indices.bin",ios::binary|ios::in);
    if(!binaind){
        cout<<"Hay problemas con el archivo indices.bin \n";
    }
    binaind.seekg(0,ios::end);
    int c=binaind.tellg()/50;
    
    binaind.seekg(0,ios::beg);
    for(int j=0;j<c;j++){
        binaind.read(frase, 50);
        cout<<frase<<"\n";
    }
    binaind.close();
    bina.close();
}

void quemar(){
    char *frase;
    frase=new char [100];
    ifstream entrada;
     entrada.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/datostxt.txt",ios::in);
     fstream f;
     f.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/pez.bin",ios::out|ios::binary);
     if(!entrada)
     cout<<"Hay problemas con el archivo datostxt.txt \n";
     while(!entrada.eof()){
     //entrada.read((char*)frase, 50);
     //entrada>>frase;
     
     entrada.getline(frase, 100, '\n');
     cout<<frase<<"\n";
     f.write(frase,100);
     f.seekp(0,ios::end);
     
     }
     entrada.close();
     f.close();
     fstream indi;
     fstream indibin;
     indi.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/1.txt",ios::in);
     if(!indi){
     cout<<"Hay problemas con el archivo pez.bin \n";
     }
     indibin.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/indices.bin",ios::binary|ios::out);
     if(!indibin){
     cout<<"hola \n";
     }
     while(!indi.eof()){
     indi.getline(frase, 50, '\n');
     cout<<frase<<"\n";
     indibin.write(frase,50);
     indibin.seekp(0,ios::end);
         
     }
    indibin.close();
    indi.close();
}

void generar(){
    char *frase,*cont2;
    frase=new char [100];
    cont2=new char[50];
    int cont=0, num=0;
    fstream f;
    f.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/pez.bin",ios::in|ios::binary);
    if(!f)
        cout<<"Hay problemas con el archivo pez.bin";
    fstream en;
    en.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/indices.bin",ios::in|ios::binary);
    if(!en)
        cout<<"Hay problemas con el archivo indices.bin";
    fstream salida;
    salida.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/datos.txt",ios::out);
    if(!salida)
        cout<<"No se pudo crear el archivo datos.txt";
    f.seekg(0,ios::end);
    int c=f.tellg()/100;
    f.seekg(0,ios::beg);
    en.seekg(0,ios::end);
    int n=en.tellg()/50;
    en.seekg(0,ios::beg);
    while(cont<n){
        en.read(cont2, 50);
        num=atoi(cont2);
        for(int j=0;j<c;j++){
            f.read(frase, 100);
            //cout<<frase<<"\n";
            if(j==num){
                //cout<<"ya "<<j<<" "<<num<<" ";
                cout<<frase<<"\n";
                salida.write(frase,100);
                salida<<"\n";
                salida.seekp(0,ios::end);
            }
        }
        cont++;
        f.seekg(0,ios::beg);
    }
    f.close();
    en.close();
    salida.close();
}

void agregar(datos nuevo){
    bool ter=false;
    char *frase,*aux, *token, *aux3, *aux2;
    frase=new char [100];
    
    aux2=new char [50];
    aux3=new char[100];
    int pos=0,cont=0, *indi, aux1=0, auxaux=0;
    fstream entd;
    entd.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/pez.bin",ios::in|ios::binary|ios::out);
    if(!entd)
        cout<<"Hay problemas con el archivo pez.bin";
    fstream entin;
    entin.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/indices.bin",ios::in|ios::binary|ios::out);
    if(!entin)
        cout<<"Hay problemas con el archivo indice.bin";
    entd.seekg(0,ios::end);
    int n=entd.tellg()/100;
    strcat(frase, nuevo.codigo);
    strcat(frase, ",");
    strcat(frase, nuevo.apellido);
    strcat(frase, ",");
    strcat(frase, nuevo.nombre);
    strcat(frase, ",");
    strcat(frase, nuevo.celular);
    //strcat(frase, "\n");
    pos=indice();
    //cout<<frase;
    entd.write(frase, 100);
    entd.seekg(0,ios::beg);
    entin.seekg(0,ios::end);
    int c=entin.tellg()/50;
    indi=new int [c+1];
    //cout<<pos;
    *aux2=pos+48;
    //cout<<aux2;
    entin.write(aux2,50);
    entin.seekg(0,ios::beg);
    aux=new char [50];
    for(int i=0;i<=c;i++){
        entin.read(aux,50);
        *(indi+i)=atoi(aux);
    }
    for(int i=0;i<n&&ter==false;i++){
        entd.seekg(*(indi+i)*100);
        entd.read(aux3,100);
        token=strtok(aux3, ",");
        token=strtok(NULL, ",");
        cout<<token<<"\n";
        if(strcmp(nuevo.apellido,token)<=0){
            ter=true;
        }else{
            cont++;
        }
    }
    //cout<<cont<<"contador\n";
    //cout<<pos;
    if(ter==true){
        for(int i=cont;i<=pos;i++){
            if(i==cont){
                aux1=*(indi+i);
                *(indi+i)=pos;
            }else{
                auxaux=*(indi+i);
                *(indi+i)=aux1;
                aux1=auxaux;
            }
        }
    }
    entin.seekg(0,ios::beg);
    for(int i=0;i<=pos;i++){
        int P=0, nuevocon=0, nums;
        if(*(indi+i)==0){
            *aux=(0+48);
            entin.write(aux,50);
        }else{
        P=*(indi+i);
        while(P>0){
            P=P/10;
            nuevocon++;
        }
        P=*(indi+i);
        aux=new char[50];
        while (nuevocon>=0) {
            nums=P%10;
            *(aux+(nuevocon-1))=(nums+48);
            P=P/10;
            nuevocon--;
        }
        entin.write(aux,50);
        }
    }
    
    entd.close();
    entin.close();
    cout<<"\n";
    
}

int indice(){
    int cont=0;
    fstream entd("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/pez.bin",ios::in|ios::binary);
    if(!entd)
        cout<<"Hay problemas con el archivo pez.bin";
    entd.seekg(0,ios::end);
    cont = entd.tellg()/100;
    entd.close();
    return cont;
}

void cartas(){
    char *superfrase, *pez, *aux, *aux2;
    int cont=1;
    datos info;
    ifstream entradacarta;
    entradacarta.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/formato.txt",ios::in);
    if(!entradacarta){
        cout<<"Hay problemas con el archivo formato.txt";
    }
    ifstream entradadat;
    entradadat.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/pez.bin",ios::in|ios::binary);
    if(!entradadat){
        cout<<"Hay problemas con el archivo datos.txt\n";
    }
    fstream crear;
    crear.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/cartas.txt",ios::out);
    if(!crear){
        cout<<"El archivo cartas.txt no se ha podido crear";
    }
    entradadat.seekg(0,ios::end);
    int tam=entradadat.tellg()/100;
    entradadat.seekg(0,ios::beg);
    //cout<<tam<<"\n";
    for(int i=0;i<tam;i++){
        entradadat.seekg(i*100);
        //crear.seekg(0,ios::end);
        cont=1;
        superfrase=new char [500];
        pez=new char [150];
        aux=new char[100];
        aux2=new char [20];
        info.apellido=new char [30];
        info.nombre=new char [30];
        info.codigo=new char [30];
        info.celular=new char [30];
        entradadat.getline(pez,100,'\0');
        //cout<<pez;
        aux=strtok(pez, ",");
        info.codigo=aux;
        aux=strtok(NULL, ",");
        info.apellido=aux;
        aux=strtok(NULL,",");
        info.nombre=aux;
        aux=strtok(NULL, " ");
        info.celular=aux;
        //cout<<info.codigo<<" "<<info.nombre<<" "<<info.apellido<<" "<<info.celular;
        entradacarta.seekg(0,ios::beg);
        while(!entradacarta.eof()){
            entradacarta.getline(superfrase,500,'<');
            if(cont==1){
                aux2=new char [20];
                entradacarta.getline(aux2,100,'>');
                //cout<<aux;
                strcat(superfrase, info.nombre);
                cont++;
                cout<<superfrase;
                crear.write(superfrase, 500);
            }else if(cont==2){
                aux2=new char [20];
                entradacarta.getline(aux2,100,'>');
                strcat(superfrase, info.apellido);
                cont++;
                cout<<superfrase;
                crear.write(superfrase, 500);
            }else if(cont==3){
                aux2=new char [20];
                entradacarta.getline(aux2,100,'>');
                strcat(superfrase, info.celular);
                cont++;
                cout<<superfrase;
                crear.write(superfrase, 500);
                entradacarta.getline(superfrase,500,'/');
                cout<<superfrase;
                crear.write(superfrase, 500);
            }
        }
        cout<<"\n";
    }
    

}
int menu(){
    int op=0;
    do{
        cout<<"0.Salir\n1.Leer archivos\n2.Generar archivo .txt\n3.Añadir empleado\n4.Generar cartas\n5.Consultar telefonia\nDigite una opcion ";
        cin>>op;
        cin.ignore();
    }while(op<0||op>5);
    return op;
}
void telefonos(){
    char *aux,*pez, *frase, *bina;
    datos info;
    fstream tel;
    
    fstream entd("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/pez.bin",ios::in|ios::binary);
    if(!entd)
        cout<<"Hay problemas con el archivo pez.bin";
    char *direc;
    bina=new char [10000];
    strcpy(bina, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/");
    direc=new char [10000];
    strcpy(direc, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/");
    entd.seekg(0,ios::end);
    int tam=entd.tellg()/100;
    entd.seekg(0,ios::beg);
    //cout<<tam<<"\n";
    for(int i=0;i<tam;i++){
        direc=new char [10000];
        strcpy(direc, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/");
        strcpy(bina, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/archivos1/Taller archivos1/");
        entd.seekg(i*100);
        aux=new char[100];
        pez=new char[100];
        frase=new char[50];
        info.apellido=new char [30];
        info.nombre=new char [30];
        info.codigo=new char [30];
        info.celular=new char [30];
        entd.getline(pez,100,'\0');
        aux=strtok(pez, ",");
        info.codigo=aux;
        aux=strtok(NULL, ",");
        info.apellido=aux;
        aux=strtok(NULL,",");
        info.nombre=aux;
        aux=strtok(NULL, " ");
        info.celular=aux;
        strncat(direc, info.celular, 3);
        strncat(bina, info.celular, 3);
        strcat(direc, "tel.txt");
        strcat(bina, "tel.bin");
        fstream tel;
        tel.open(direc, ios::out|ios::app);
        fstream b;
        b.open(bina,ios::out|ios::app|ios::binary);
        tel<<info.codigo<<" "<<info.nombre<<" "<<info.apellido<<"\n";
        b<<info.codigo<<" "<<info.nombre<<" "<<info.apellido<<"\n";
        tel.close();
        b.close();
    }
}
