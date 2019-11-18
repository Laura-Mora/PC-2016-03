//
//  funciones.cpp
//  Proyecto
//
//  Created by Laura Juliana Mora on 6/11/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include <stack>
#include "funciones.hpp"
using namespace std;
void menu()
{
    char *sucursal, *suqui;
    sucursal=new char[15];
    suqui=new char[20000];
    strcpy(suqui, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/");
    do
    {
        sucursal=seleccionarsucursal();
    }while(strcmp(sucursal,"no")==0);
    
    system("cls");
    int all=-1;
    strcat(sucursal,".txt");
    while(all!=0)
    {
        cout<<sucursal<<endl<<"---------------------"<<endl;
        cout<<"1.productos\n2.clientes\n3.orden pedidos tiendas\n4.cambiar sucursal"<<endl;
        cin>>all;
        strcat(suqui, sucursal);
        
        switch(all)
        {
            case 1:
                productos(sucursal);
                //productos(sucursal);
                break;
            case 2:
                clientes(suqui) ;
                //clientes(sucursal);
                break;
            case 3:
                ordenpedidostiendas();
                break;
            case 4:
                sucursal=seleccionarsucursal();
                break;
        }
        
        system("pause");
        system("cls");
    }
    
}

//en caso de que un producto baje de 100 enviara una orden
void ordenpedidostiendas()
{
    fstream sucursales;
    
    sucursales.open("sucursales.txt",ios::in);
    
    char* suc;
    suc=new char[70];
    
    int cantidad=0;
    
    while (!sucursales.eof())
    {
        sucursales.getline(suc,70,'\n');
        cantidadproductosportienda(strcat(suc,".txt"));
        
    }
    
    cout<<"archivos generados"<<endl;
}

void cantidadproductosportienda(char* sucursal)//----------------------------------------------------------------------
{
    char *temp,*token,*blah;
    blah=new char[20];
    temp=new char[20];
    fstream almacen,pedido;
    stack<producto> orden;
    producto product;
    char *pedid,*nomb;
    nomb=new char[20];
    pedid=new char [20];
    strcpy(pedid,"orden para ");
    strcat(pedid,sucursal);
    bool prim=false,nproducto=false;
    
    pedido.open(pedid,ios::out);//esto esta molestando, y no tengo claro el por que-----------------------------------
    almacen.open(sucursal,ios::in|ios::out|ios::app);
    int cant=0;
    bool ya=false;
    
    
    if (!pedido)
    {
        
    }
    if (!almacen)
    {
        cout<<"no se ha encontrado el archivo"<<endl;
        
    }
    else
    {
        while (!almacen.eof()&&ya==false)
        {
            
            almacen.getline(temp,20,';');
            
            strcpy(blah,temp);
            ya=false;
            //			token=strtok(blah,";");
            
            if(token==NULL||strlen(blah)==0)
            {
                token=strtok(NULL,"\n");
                if(token==NULL)
                {
                    ya=true;
                }
                
                
                
            }
            else
            {
                if (blah[0]=='\n'||prim==false)
                {
                    prim=true;
                    nproducto=false;
                    if (blah[0]=='\n')
                    {
                        temp=strtok(temp,"\n");
                        if (temp!=NULL)
                        {
                            strcpy(blah,temp);
                        }
                        
                    }
                }
            }
            if (strlen(blah)>0&&ya==false&&temp!=NULL)
            {
                
                blah=rev(blah);
                token=strtok(blah,",");
                blah=rev(token);
                cant=atoi(token);
                strcpy(blah,temp);
                nomb=strtok(blah,",");
                
                if(cant<100)
                {
                    
                    if(nproducto==false)
                    {
                        cout<<nomb<<" "<<cant<<endl<<"	presentaciones:"<<endl;
                        
                        pedido<<nomb<<" "<<cant<<endl<<"	presentaciones:"<<endl;
                    }
                    else
                    {
                        cout<<"	"<<nomb<<" "<<cant<<"  son necesarios:"<<100-cant<<endl;
                        
                        pedido<<"	"<<nomb<<" "<<cant<<"  son necesarios:"<<100-cant<<endl;
                    }
                    
                    
                    
                    nproducto=true;
                    /*	strcpy(blah,temp);
                     pedido<<strtok(blah,",")<<", cantidad total :"<<cant<<endl<<"	se necesita:"<<endl;
                     strcpy(blah,temp);
                     
                     strcpy(token,blah);
                     strtok(token,";");
                     
                     while (token!=NULL)
                     {
                     strtok(token,";");
                     cout<<token<<endl;
                     }*/
                    
                }
            }
            
        }
        
        
        
        
    }
    
    
}

//cantidad de un producto especifico en todas las tiendas
int cantidadproductototal (char* nombreprod)
{
    fstream sucursales;
    
    
    sucursales.open("sucursales.txt",ios::in);
    
    char* suc;
    suc=new char[70];
    
    int cantidad=0;
    
    while (!sucursales.eof())
    {
        sucursales.getline(suc,70,'\n');
        cantidad+=cantidadproductototaltienda(strcat(suc,".txt"),nombreprod);
        
    }
    
    cout<<cantidad<<endl;
    return cantidad;
}

//la cantidad de un producto dado en una tienda especifica
int cantidadproductototaltienda(char* sucursal,char* nombreprod)
{
    char *temp,*token,*blah;
    blah=new char[20];
    temp=new char[20];
    fstream almacen;
    almacen.open(sucursal,ios::in);
    bool ya=false;
    int cant=0;
    
    if (!almacen)
    {
        cout<<"no se ha encontrado el archivo"<<endl;
        return 0;
    }
    else
    {
        while (!almacen.eof()&&ya==false)
        {
            
            almacen.getline(temp,20,';');
            strcpy(blah,temp);
            if (blah[0]=='\n')
            {
                blah=strtok(blah,"\n");		
            }
            
            if (blah!=NULL)
            {
                if (strstr(blah,nombreprod))
                {
                    blah=rev(blah);
                    token=strtok(blah,",");
                    blah=rev(token);
                    cant=atoi(token);
                    //				cout<<cant<<endl;
                    ya=true;
                }
            }
            
        }
        return cant;
    }
    
    
}

//realizar compra
void compra()
{
    fstream sucursales;
    sucursales.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/sucursales.txt", ios::in|ios::out);
    //sucursales.open("sucursales.txt",ios::in|ios::out);
    int cont=0;
    if (!sucursales)
    {
        cout<<"error: archivo no encontrado";
        exit(1);
    }
    char *mander;
    
    mander=new char[50];
    
    while(!sucursales.eof())
    {
        sucursales.getline(mander,50,'\n');
        if (mander[0]=='[')
        {
            cout<<mander<<endl;
        }
        
    }
    
    sucursales.close();
     sucursales.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/sucursales.txt", ios::in|ios::out);
    //sucursales.open("sucursales.txt",ios::in|ios::out);
    cout<<"sucursal mas cercana: "<<endl;
    cin>>cont;
    char *temp;
    temp=new char[50];
    while(!sucursales.eof())
    {
        sucursales.getline(mander,50,'\n');
        
        if (mander[1]-'0'==cont &&mander[0]=='[')
        {
            sucursales.getline(mander,50,'\n');
            while(!sucursales.eof()&&mander[0]!='[')
            {
                if (mander[0]=='*')
                {
                    cout<<mander<<endl;
                }
                sucursales.getline(mander,50,'\n');
                
            }
            
            break;
        }
        
    }
    
    
    system("break");
}

char *seleccionarsucursal()
{
    fstream sucursales;
    sucursales.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/sucursales.txt", ios::in);
    //sucursales.open("sucursales.txt",ios::in);
    
    if(!sucursales)
    {
        cout<<"no se ha encontrado archivo sucursales"<<endl;
        exit(1);
    }
    char*mander, *aux;
    int tam=0;
    mander =new char[20];
    aux=new char[20];
    while (!sucursales.eof())
    {
        sucursales.getline(mander,20,'\n');
        cout<<mander<<endl;
    }
    int suc=0;
    cout<<"seleccionar sucursal: ";
    cin>>suc;
    
    suc;
    sucursales.close();
    sucursales.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/sucursales.txt", ios::in);
    //sucursales.open("sucursales.txt",ios::in);
    
    bool ya=false;
    while (!sucursales.eof())
    {
        sucursales.getline(mander,20,'\n');
        //	cout<<mander<<endl;
        if (mander[1]-'0'==suc)
        {
            ya =true;
            //			cout<<mander<<endl;
            cout<<mander;
            break;
        }
    }
    
    if (ya==false)
    {
        cout<<"sucursal no encontrada"<<endl;
        strcpy(mander,"no");
    }
    //inicio pequeño cambio
    tam=strlen(mander);
    int num=0;
    for(int i=4;i<tam-1;i++){
        if(*(mander+i)!='\n'){
        *(aux+num)=*(mander+i);
        }
        num++;
    }
    return aux;
    //fin pequeño cambio =D
    //return mander;
}


//esta funcion ingresa nuevos productos a una tienda seleccionada por el usuario
void ingresarprod(char* sucursal)
{
    
    //	char*mander;
    //	mander =new char[20];
    //	mander=seleccionarsucursal();
    
    fstream tienda;
    
    //	strcat(mander,".txt");
    
    //	cout<<mander<<endl;
    tienda.open(sucursal,ios::in|ios::out|ios::app);
    
    producto nuevo;
    nuevo.nombre=new char[20];
    
    nuevo.existenciastotales=0;
    
    cin.ignore();
    cout<<"nombre : ";
    cin.getline(nuevo.nombre,20,'\n');
    
    bool ya =false;
    
    
    if (tienda)
    {
        ya=buscarproducto(nuevo.nombre,strcat(sucursal,".txt"));
        
        if (ya)
        {
            cout<<"este producto ya esta en el inventario"<<endl;
            
        }
    }
    else
    {
        cout<<"no hay archivo de "<<sucursal<<endl;
    }
    
    if (ya==false)
    {
        long codigo;
        cout<<"Digite el codigo del producto: ";
        cin>>codigo;
        cin.ignore();
        registrarproductocodigo(nuevo.nombre, codigo);
        presentacion *aux;
        nuevo.cabeza=new presentacion;
        char*temp;
        temp=new char[20];
        strcpy(temp,nuevo.nombre);
        
        nuevo=presentacionproducto(nuevo);
        strcpy(nuevo.nombre,temp);
        tienda.close();
        tienda.open(sucursal,ios::out|ios::app);
        
        
        cout<<nuevo.nombre<<","<<nuevo.existenciastotales<<";";
        tienda<<nuevo.nombre<<","<<nuevo.existenciastotales<<";";
        aux=nuevo.cabeza;
        
        while (aux!=NULL)
        {
            
            cout<<aux->tipo<<","<<aux->costo<<","<<aux->existencias<<";";
            tienda<<aux->tipo<<","<<aux->costo<<","<<aux->existencias<<";";
            
            aux=aux->sig;
        }
        
        cout<<endl;
        tienda<<endl;
        
    }
    
    
    
}
//ingresa presentaciones de un producto especifico
producto presentacionproducto(producto nuevo)
{
    presentacion *aux;
    aux=new presentacion;
    nuevo.cabeza=aux;
    int existtot=0;
    char continuar='s';
    int cont=0;
    while(continuar=='s'||continuar=='S')
    {
        aux->tipo=new char[20];
        
        cout<<"descripcion : ";//ej: piedra negra, piedra gris, piedra cafe
        cin>>aux->tipo;
        
        cout<<"existencias : ";
        cin>>aux->existencias;
        
        existtot+=aux->existencias;
        
        cout<<"costo : ";
        cin>>aux->costo;
        
        
        cout<<"ingresar otra presentacion? (s/n)"<<endl;
        cin>>continuar;
        if (continuar=='s'||continuar=='S')
        {
            aux->sig=new presentacion;
            aux=aux->sig;
            
        }
        else
        {
            aux->sig=NULL;
        }
        
    }
    
    nuevo.existenciastotales=existtot;
    
    return nuevo;
}

void imprimirproductos(char* sucursal)
{
    char *product,*token,*prod, *archivo;
    fstream tienda;
    prod =new char[20];
    product=new char[300];
    int cont=0;
    
    if (tienda)
    {
        tienda.close();
    }
    tienda.open(sucursal,ios::in);
    
    if (!tienda)
    {
        cout<<"no se ha encontrado el archivo"<<endl;
    }
    else
    {
        while(!tienda.eof())
        {
            tienda.getline(product,300,'\n');
            
            token=strtok(product,";");
            cont=0;
            while(token!=NULL)
            {
                if(cont>=1)
                {
                    if(cont==1)
                    {
                        cout<<"		"<<"presentacion,valor,cantidad"<<endl;	
                    }
                    cout<<"		";
                }
                cout<<token<<endl;
                cont++;
                token=strtok(NULL,";");
            }
            
        }
    }
}
//en caso de ser encontrado, retorna verdadero
bool buscarproducto(char* nombre,char*tienda)
{
    char *temp,*token,*blah;
    blah=new char[20];
    temp=new char[20];
    fstream almacen;
    almacen.open(tienda,ios::in|ios::out|ios::app);
    bool ya=false;
    
    while (!almacen.eof())
    {
        almacen.getline(temp,20,';');
        strcpy(blah,temp);
        
        
        if (token!=NULL)
        {
            if (blah[0]=='\n')
            {
                token=strtok(blah,"\n");
                token=strtok(token,",");
            }
            else
            {
                token=strtok(blah,",");
            }
            if (/*!token=='\n'&&*/strcmp(token,nombre)==0)
            {
                almacen.close();
                return true;
                
            }
        }
        
    }
    almacen.close();
    cout<<"no se ha encontrado el producto"<<endl;
    return false;
}

void modificarproductos(char* sucursal)
{
    fstream tienda,temp;
    //    char*suc;
    //    sucursal =new char[1000];
    //    suc2=new char [20];
    //    suc2=seleccionarsucursal();
    //    sucursal=seleccionarsucursal();
    producto nuevo;
    //    strcat(sucursal,".txt");
    //    strcat(suc2,".txt");
    //cout<<sucursal<<endl;
    //    strcpy(sucursal , "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/");
    //    strcat(sucursal, suc2);
    char *prod;
    prod=new char [20];
    char* paso,*token,*otro;
    paso=new char[200];
    otro=new char[50];
    cin.ignore();
    cout<<"producto a modificar:";
    cin.getline(prod,20,'\n');
    
    if (buscarproducto(prod,sucursal))
    {
        tienda.open(sucursal,ios::in|ios::out|ios::app);
        //        temp.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/temp.txt",ios::in|ios::out);
        temp.open("temp.txt",ios::out);
        
        if(!temp)
        {
            
        }
        nuevo.nombre=new char[20];
        strcpy(nuevo.nombre,prod);
        nuevo=presentacionproducto(nuevo);
        strcpy(nuevo.nombre,prod);
        
        while (!tienda.eof())
        {
            tienda.getline(paso,200,'\n');
            strcpy(otro,paso);
            token=strtok(otro,",");
            if(strlen(paso)>0)
            {
                if (strcmp(token,nuevo.nombre)==0)
                {
                    presentacion *aux;
                    temp<<nuevo.nombre<<","<<nuevo.existenciastotales<<";";
                    aux=nuevo.cabeza;
                    
                    while (aux!=NULL)
                    {
                        //					cout<<aux->tipo;
                        
                        //					cout<<aux->tipo<<","<<aux->costo<<","<<aux->existencias<<";";
                        temp<<aux->tipo<<","<<aux->costo<<","<<aux->existencias<<";";
                        
                        aux=aux->sig;
                    }
                    
                    temp<<endl;
                }
                else
                {
                    cout<<paso<<endl;
                    temp<<paso<<endl;
                }
            }
            
        }
        
        
        tienda.close();
        temp.close();
        
        tienda.open(sucursal,ios::in|ios::out);
        temp.open("temp.txt",ios::in|ios::out);
        //        temp.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/temp.txt",ios::in|ios::out);
        while(!temp.eof())
        {
            temp.getline(paso,200,'\n');
            
            tienda<<paso<<endl;
            
        }
        
    }
    
    remove("temp.txt");
}

void venta(char *sucursal){
    char *fecha;
    fecha=new char[20];
    cout<<"Digite la fecha de cuando esta realizando la compra";
    cin.getline(fecha, 20,'\n');
    fstream formato;
    fstream clientes;
    fstream ventas;
    char*client, continu = '\0', *aux, *auxi, *auxi2;
    client=new char[20];
    aux=new char[20];
    //    suqui=new char[20000];
    auxi=new char [20];
    auxi2=new char [20];
    strcpy(client,"clientes.txt");
    //formato.open("formato.txt", ios::in);
    formato.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/formatp.txt",ios::in);
    //clientes.open("clientes.txt",ios::in|ios::out);
       clientes.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt",ios::in);
    char *clien, continuar;
    clien= new char[20];
    cin.ignore();
    cout<<"Nombre del cliente que desea realizar la compra ";
    cin.getline(clien, 20, '\n');
    //if(!buscarcliente(clien, client)){
    if(!buscarcliente(clien, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt")){
        cout<<"Este cliente no existe \n ¿Desea registarlo ?(s->si)";
        cin>>continuar;
        if(continuar=='s'||continuar=='S'){
            registrarcliente();
        }
    }
    //    strcat(suqui, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/");
    //    auxi=seleccionarsucursal();
    //    cin.ignore();
    //    strcat(auxi, ".txt");
    //    strcat(suqui, auxi);
    imprimirproductos(sucursal);
    listcompra *lista;
    lista=crear();
    int cant=0;
    do{
        cout<<"Cual producto desea comprar? ";
        cin.getline(aux, 20,'\n');
        if(buscarproducto(aux, sucursal)){
            struct compra nuevo;
            nuevo.nombreprod=new char[20];
            nuevo.presentacion=new char[20];
            strcpy(nuevo.nombreprod,aux);
            cout<<"¿Cual presentacion desea comprar? ";
            cin.getline(auxi2, 20, '\n');
            if(buscarproducto(auxi2, sucursal)){
                strcpy(nuevo.presentacion, auxi2);
                cout<<"¿Cantidad que desea? ";
                cin>>cant;
                cin.ignore();
                if(cant<=cantidadproductototaltienda(sucursal, nuevo.nombreprod)){
                    nuevo.cant=cant;
                    nuevo.precio=preciouni(nuevo.nombreprod, nuevo.presentacion, sucursal);
                    nuevo.precioiva=precioconIVA(nuevo.precio, nuevo.cant);
                    nuevo.codigo=obtenercodigo(nuevo.nombreprod);
                    insertar(lista, nuevo);
                    modificarproductos(sucursal,nuevo.nombreprod,nuevo.presentacion,nuevo.cant);
                }
            }
        }else{
            cout<<"El producto no existe\nDesea comprar otro producto? (S-->si)";
            cin>>continu;
        }
    }while(continu=='S'||continu=='s');
    cliente dat;
    dat=obtinfo(clien);
    carrito(lista, dat,fecha);
    formato.close();
    clientes.close();
}

//registra un cliente para poder realizar la compra
void registrarcliente(){
    fstream clientes;
    char*client;
    client=new char[15];
    strcpy(client,"clientes.txt");
    //clientes.open("clientes.txt",ios::in|ios::out);
    clientes.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt",ios::in|ios::out|ios::app);
    if(!clientes){
        cout<<"No se pudo abrir el archivo clientes.txt";
        exit(1);
    }
    cliente nuevo;
    nuevo.nombre= new char[20];
    nuevo.direccion= new char [20];
    
    cout<<"Digite el nombre del cliente que desea registrar ";
    cin.getline(nuevo.nombre, 20, '\n');
    
    if(buscarcliente(nuevo.nombre, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt")){
    //if(buscarcliente(nuevo.nombre, client)){
        cout<<"El cliente ya existe \n";
    }else{
        clientes.seekp(0,ios::end);
        clientes<<nuevo.nombre<<'\n';
        cout<<"Digite el NIT del cliente que desea registar ";
        cin>>nuevo.nit;
        clientes<<nuevo.nit<<'\n';
        cin.ignore();
        cout<<"Digite la direccion del ususario que desea registar ";
        cin.getline(nuevo.direccion, 20, '\n');
        clientes<<nuevo.direccion<<'\n';
    }
    clientes.close();
}
//en caso de que encuentre al cliente retorna verdadero
bool buscarcliente(char *nombre, char *archivo){
    fstream bus;
    bus.open(archivo,ios::in);
    int cant=1;
    char *aux;
    aux=new char[20];
    bool es=false;
    while (!bus.eof()&&es==false){
        bus.getline(aux, 20, '\n');
        cout<<aux<<"\n";
        if(cant==1){
            if(strcmp(aux,nombre)==0){
                es= true;
            }
        }else if (cant==3){
            cant=1;
        }else{
        cant++;
        }
    }
    return es;
}
void infoclientes(){
    fstream clientes;
    char*client;
    client=new char[15];
    strcpy(client,"clientes.txt");
    //clientes.open("clientes.txt",ios::in);
    clientes.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt",ios::in);
    cliente datos;
    datos.direccion= new char [20];
    datos.nombre = new char [20];
    char *aux;
    aux=new char[20];
    int cant=1;
    while(!clientes.eof()){
        if(cant==1){
            clientes.getline(datos.nombre, 20, '\n');
            if(datos.nombre!=" ")
                cout<<"Nombre: "<<datos.nombre<<"\n";
            cant++;
        }else if(cant==2){
            clientes.getline(aux, 20, '\n');
            datos.nit=atoi(aux);
            cout<<"NIT: "<<datos.nit<<"\n";
            cant++;
        }else if(cant==3){
            clientes.getline(datos.direccion, 20,'\n');
            cout<<"Direccion: "<<datos.direccion<<"\n";
            cant=1;
        }
    }
}
void modificarinfo(){
    fstream clientes, temp;
    clientes.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt",ios::in|ios::out|ios::app);
    temp.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/tem.txt",ios::in|ios::out|ios::app);
    cliente mod;
    mod.direccion= new char[20];
    mod.nombre=new char [20];
    char *aux;
    aux=new char [20];
    cout<<"Digite el nombre del cliente que desea modificar: ";
    cin.getline(mod.nombre, 20, '\n');
    if(buscarcliente(mod.nombre, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt")){
        cout<<"Digite la nueva direccion del cliente "<<mod.nombre<<" ";
        cin.getline(mod.direccion, 20, '\n');
        int cant=0;
        clientes.seekg(0);
        //clientes.getline(aux, 20,'\n');
        while(!clientes.eof()){
            clientes.getline(aux, 20,'\n');
            //cout<<aux<<"\n";
            if(strcmp(aux, mod.nombre)==0){
                temp<<aux<<'\n';
                clientes.getline(aux, 20,'\n');
                temp<<aux<<'\n';
                temp<<mod.direccion<<'\n';
                clientes.getline(aux, 20,'\n');
            }else{
                temp<<aux<<'\n';
            }
        }
    }else{
        cout<<"Este cliente no existe\n";
        exit(1);
    }
    clientes.close();
    clientes.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt",ios::out);
    temp.seekp(0);
    aux=new char[20];
    while (!temp.eof()) {
        temp.getline(aux, 20, '\n');
        cout<<aux<<"\n";
        if(aux!=" "){
           clientes<<aux<<'\n';
        }
    }
    temp.close();
    clientes.close();
}
int menuclien(){
    int opci=0;
    do{
        cout<<"1.Consultar informacion de todos los clientes\n 2.Consultar informacion de un cliente en especifico\n3.Modificar informacion (direccion) de un cliente\n 4.Opciones de compras \n 5. Registrar cliente\n¿Cual opcion desea realizar? ";
        cin>>opci;
        cin.ignore();
    }while(opci<1||opci>5);
    return opci;
}
void clientes(char *suqui){
    int opci=0;
    opci=menuclien();
    switch (opci) {
        case 1:
            infoclientes();
            break;
        case 2:
            infoclienteespe();
            break;
        case 3:
            modificarinfo();
            break;
        case 4:
            ven(suqui);
            break;
        case 5:
            registrarcliente();
            break;
    }
}
void infoclienteespe(){
    fstream clientes;
    char*client;
    client=new char[15];
    strcpy(client,"clientes.txt");
    //clientes.open("clientes.txt",ios::in);
    clientes.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt",ios::in);
    cliente datos;
    datos.direccion= new char [20];
    datos.nombre = new char [20];
    char *aux, *name;
    aux=new char[20];
    name=new char [20];
    cout<<"Digite el nombre del cliente del cual quiere conocer sus datos ";
    cin.getline(name, 20, '\n');
    while(!clientes.eof()){
        clientes.getline(aux, 20,'\n');
        if(strcmp(aux, name)==0){
            cout<<"Nombre: "<<aux<<"\n";
            clientes.getline(aux, 20,'\n');
            cout<<"NIT: "<<aux<<"\n";
            clientes.getline(aux, 20,'\n');
            cout<<"Direccion: "<<aux<<"\n";
        }
    }
    clientes.close();
}
//enviar a hamilton
int menuventa(){
    int opc=0;
    do{
        cout<<"0.Volver\n1.Realizar compra\n2.Consultar Todas las facturas\n 3.Consultar las facturas de un cliente especifico\nDigite la opcion que desea realizar ";
        cin>>opc;
    }while(opc<0||opc>3);
    return opc;
}
//enviar a hamilton
void ven(char * sucursal){
    int opc=0;
    system("cls");
    do{
        opc=menuventa();
        switch (opc) {
            case 1:
                venta(sucursal);
                break;
            case 2:
                consultafacturas();
                break;
            case 3:
                char *nombre;
                nombre =new char[20];
                cout<<"Digite el nombre del cliente del cual quiere conocer sus facturas ";
                cin.getline(nombre, 20, '\n');
                if(buscarcliente(nombre, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/clientes.txt")){
                    consultarfacclien(nombre);
                }else{
                    cout<<"El cliente no exite \n";
                }
                break;
            default:
                break;
        }
        
        system("pause");
        system("cls");
    }while(opc>0);
}
char *rev(char*frase)
{
    int tam=0;
    tam=strlen(frase);
    char* inv;
    inv=new char[tam];
    for (int a=0;a<=tam;a++)
    {
        inv[a]=frase[tam-(a+1)];
        //strcat(inv[a],frase[tam-(a+1)]);
    }
    
    return inv;
    
}

void productos(char* sucursal)
{
    int all=-1;
    char *nombreprod;
    nombreprod=new char [20];
    while(all!=0)
    {
        system("cls");
        
        cout<<"0.volver\n1.ingreso productos\n2.imprimir productos\n3.modificar productos\n4.cantidad de un producto\n5.cantidad total de un producto especifico"<<endl;
        cin>>all;
        
        
        switch(all)
        {
            case 1:
                ingresarprod(sucursal);
                break;
            case 2:
                imprimirproductos(sucursal);
                break;
            case 3:
                modificarproductos(sucursal);
                break;
            case 4:
                cout<<"producto: ";
                cin>>nombreprod;
                cout<<(cantidadproductototaltienda( sucursal,nombreprod))<<endl;
                break;
            case 5:
                char* producto;
                producto=new char[20];
                cin.ignore();
                cout<<"producto : ";
                cin.getline(producto,20,'\n');
                
                cantidadproductototal (producto);
                break;
                
        }
        if (all!=0)
        {
            
            system("pause");
        }
        
    }
}
void consultafacturas(){
    fstream total;
    total.open("facturas.txt",ios::in);
    char *ubi,*aux, *factura;
    ubi= new char[50];
    aux=new char[500];
    //strcpy(aux, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/");
    while (!total.eof()) {
        ubi= new char[50];
        aux=new char[500];
        //strcpy(aux, "/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/");
        total.getline(ubi, 50, '\n');
        strcat(ubi, ".txt");
        //strcat(aux, ubi);
        fstream factu;
        factu.open(ubi,ios::in);
        char *lineafactu;
        lineafactu=new char[500];
        while (!factu.eof()) {
            factu.getline(lineafactu, 500, '\n');
            cout<<lineafactu<<"\n";
        }
        factu.close();
    }
    total.close();
}
void consultarfacclien(char *clien){
    fstream facturas;
    facturas.open("facturas.txt",ios::in);
    char *aux,*token,*auxcpy, *fac;
    aux=new char[20];
    token=new char[20];
    auxcpy=new char [20];
    fac=new char[500];
    while(!facturas.eof()){
        facturas.getline(aux, 20, '\n');
        strcpy(auxcpy, aux);
        token=strtok(aux, "_");
        if(strcmp(clien, aux)==0){
            strcat(auxcpy, ".txt");
            fstream cuenta;
            cuenta.open(auxcpy,ios::in);
            fac=new char[500];
            while (!cuenta.eof()) {
                cuenta.getline(fac, 500, '\n');
                cout<<fac<<"\n";
            }
            cuenta.close();
        }
    }
    facturas.close();
}
listcompra *crear(){
    listcompra *nueva =new listcompra;
    nueva->cantprod=0;
    nueva->cabe=NULL;
    return nueva;
}
bool vacia(listcompra * lista){
    if(lista->cantprod == 0)
        return true;
    else
        return false;
}
void insertar(listcompra * lista, struct compra infoNueva){
    struct compra * nuevo;
    nuevo = new struct compra;
    nuevo->nombreprod=new char[20];
    nuevo->presentacion=new char[20];
    strcpy(nuevo->nombreprod, infoNueva.nombreprod);
    strcpy(nuevo->presentacion, infoNueva.presentacion);
    nuevo->nex = NULL;
    if(lista->cantprod == 0)
    {
        lista->cabe = nuevo;
        lista->cantprod++;
    }
    else
    {
        struct compra * aux;
        aux = lista->cabe;
        while(aux->nex != NULL)
        {
            aux = aux->nex;
        }
        aux->nex = nuevo;
        lista->cantprod++;
    }
}
cliente obtinfo(char *nombre){
    cliente dat;
    dat.nombre=new char [20];
    dat.direccion=new char [20];
    char *aux=new char[20];
    int cont=0;
    fstream clien;
    clien.open("clientes.txt",ios::in);
    while(!clien.eof()&&cont!=1){
        clien.getline(aux, 20, '\n');
        if(strcmp(aux, nombre)==0){
            strcpy(dat.nombre, aux);
            clien.getline(aux, 20, '\n');
            dat.nit=atoi(aux);
            clien.getline(aux, 20, '\n');
            strcpy(dat.direccion, aux);
            cont++;
        }
    }
    clien.close();
    return dat;
}
int preciouni(char *prod, char *pres, char*sucur){
    int precio = 0;
    char *aux=new char [30], *token =new char[20];
    fstream buscar;
    buscar.open(sucur,ios::in);
    while (!buscar.eof()) {
        buscar.getline(aux, 30, ';');
        token=strtok(aux, ",");
        if(strcmp(token, prod)==0){
            while(strcmp(token, pres)!=0){
                buscar.getline(aux, 30, ';');
                token=strtok(aux, ",");
            }
            token=strtok(aux, ",");
            precio=atoi(token);
        }
    }
    buscar.close();
    return precio;
}
float precioconIVA(int preuni, int cant){
    float preci;
    int prec=0;
    prec=preuni*cant;
    preci=prec*0.14;
    return preci;
}
void carrito(listcompra *lista, cliente datos, char *fecha){
    fstream formato,factura;
    //formato.open("formato.txt", ios::in);
    formato.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/formato.txt",ios::in);
    factura.open("facturas.txt",ios::out|ios::app);
    fstream crear;
    char *archivonom;
    strcat(archivonom, datos.nombre);
    strcat(archivonom,"_");
    strcat(archivonom, lista->cabe->nombreprod);
    factura<<archivonom<<"\n";
    strcat(archivonom, ".txt");
    crear.open(archivonom,ios::out);
    formato.seekg(0,ios::beg);
    char *form;
    form=new char[100];
    float totalcad, totalfinal=0, totaliva=0;
    while(!formato.eof()){
        formato.getline(form, 100,'<');
        crear.write(form, 100);
        formato.getline(form, 100,'>');
        strcat(fecha, "\n");
        crear.write(fecha,30);
        formato.getline(form, 100,'<');
        crear.write(form, 100);
        formato.getline(form, 100,'>');
        strcat(datos.nombre, "\n");
        crear.write(datos.nombre,30);
        formato.getline(form, 100,'<');
        crear.write(form, 100);
        formato.getline(form, 100,'>');
        crear<<datos.nit<<"\n";
        formato.getline(form, 100,'<');
        crear.write(form, 100);
        formato.getline(form, 100,'>');
        strcat(datos.direccion, "\n");
        crear.write(datos.direccion,30);
        formato.getline(form, 100, '\n');
        crear<<form<<"\n";
        struct compra *aux;
        aux=lista->cabe;
        while(aux!=NULL){
            totalcad=aux->precio+aux->precioiva;
            crear<<aux->codigo<<"  "<<aux->nombreprod<<"  "<<aux->presentacion<<"  "<<aux->cant<<"  "<<aux->precio*aux->cant<<"  "<<aux->precioiva<<"   "<<totalcad<<"\n";
            totalfinal+=totalcad;
            totaliva+=aux->precioiva;
            aux=aux->nex;
        }
        crear<<"Total IVA: $"<<totaliva<<"\n"<<"Total Factura: $"<<totalfinal<<"\n";
    }
    formato.close();
    crear.close();
}
void registrarproductocodigo(char *producto, long codigo){
    fstream codigos;
    codigos.open("codigos.txt",ios::out|ios::app);
    codigos<<producto<<" "<<codigo<<"\n",
    codigos.close();
}
int obtenercodigo(char *producto){
    fstream codigos;
    codigos.open("codigos.txt",ios::in);
    char *aux=new char [20],*token=new  char [20];
    while(!codigos.eof()){
        codigos.getline(aux, 20,'\n');
        token=strtok(aux, " ");
        if(strcmp(aux,producto)==0){
            token=strtok(NULL, "\n");
            return atoi(token);
        }
    }
    codigos.close();
    return 0;
}
