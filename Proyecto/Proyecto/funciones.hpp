//
//  funciones.hpp
//  Proyecto
//
//  Created by Laura Juliana Mora on 6/11/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#ifndef funciones_hpp
#define funciones_hpp

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <stdio.h>
using namespace std;
struct cliente{
    char *nombre;
    long nit;
    char *direccion;
};

struct presentacion{
    char *tipo;//tamanio 20
    int existencias;
    float costo;
    presentacion *sig;
};

struct producto{
    presentacion * cabeza;
    char* nombre;// tamanio 20
    int existenciastotales;
};
struct sucursal{
    producto*cabeza;
    char * nombre;
    sucursal* sig;
};
struct compra{
    char *nombreprod;
    char *presentacion;
    int cant;
    int precio;
    float precioiva;
    int codigo;
    compra *nex;
};
struct listcompra{
    compra *cabe;
    int cantprod;
};
producto presentacionproducto(producto nuevo);
bool buscarproducto(char* nombre,char*tienda);
void imprimirproductos(char* sucursal);
char *seleccionarsucursal();
void menu();
void compra();
void ingresarprod(char* sucursal);
void modificarproductos(char* sucursal);
void venta(char *sucursal);
void registrarcliente();
bool buscarcliente(char *nombre, char *archivo);
void infoclientes();
void modificarcliente(char *nombre);
int cantidadproductototaltienda(char* sucursal,char* nombreprod);
int cantidadproductototal (char* nombreprod);
void cantidadproductosportienda(char* sucursal);
void ordenpedidostiendas();
void infoclientes();
void modificarinfo();
int menuclien();
void clientes(char *sucursal);
void infoclienteespe();
void productos(char* sucursal);
int menuventa();
void ven(char * sucursal);
char *rev(char*frase);
void consultafacturas();
void consultarfacclien(char *clien);
listcompra *crear();
bool vacia(listcompra * lista);
void insertar(listcompra * lista, struct compra infoNueva);
cliente obtinfo(char *nombre);
int preciouni(char *prod, char *pres, char*sucur);
float precioconIVA(int preuni, int cant);
void carrito(listcompra *lista, cliente datos, char *fecha);
void registrarproductocodigo(char *producto, long codigo);
int obtenercodigo(char *producto);
#endif /* funciones_hpp */
