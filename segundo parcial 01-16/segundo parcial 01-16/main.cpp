#include <cstdlib>
#include <iostream>
#include<math.h>
#include "Listas.cpp"

using namespace std;

struct Paquete
{
    char origen[16];
    char destino[16];
    char protocolo[20];
    char dato[980];
    int suma;
};

struct Protocolo
{
    char nombre[20];
    Lista<Paquete> *listaPaquetes;
};

void insertarPaquete(Lista<Protocolo *> *protocolos, Paquete p)
{
    if( p.suma == strlen(p.dato))
    {
        bool inserte = false;
        for( int i = 0; i < tamano(protocolos); i++)
        {
            Protocolo * temp = obtenerDato(protocolos, i);
            if( strcmp(p.protocolo, temp->nombre) == 0)
            {
                insertar(temp->listaPaquetes, p);
                inserte = true;
                break;
            }
        }
        if( !inserte)
        {
            Protocolo *nuevo = new Protocolo;
            strcpy(nuevo->nombre, p.protocolo);
            nuevo->listaPaquetes = crearLista<Paquete>();
            insertar(nuevo->listaPaquetes, p);
            insertar(protocolos, nuevo);
        }
    }
}

Lista<Paquete> *buscarPaquetes (Lista<Protocolo *> *protocolos, char *ip, char *protocolo)
{
    Lista<Paquete> *listaResultado = crearLista<Paquete>();
    for( int i = 0; i < tamano(protocolos); i++)
    {
        Protocolo *temp = obtenerDato(protocolos, i);
        if( strcmp(temp->nombre, protocolo) == 0)
        {
            for( int j = 0; j < tamano(temp->listaPaquetes); j++)
            {
                Paquete aux = obtenerDato(temp->listaPaquetes, j);
                {
                    if( strcmp(ip, aux.origen) == 0 || strcmp(ip, aux.destino)== 0)
                    {
                        insertar(listaResultado, aux);
                    }
                }
            }
        }
    }
    return listaResultado;
}

void cambiarMensajes( Lista<Protocolo *> *protocolos)
{
    for( int i = 0; i < tamano(protocolos); i++)
    {
        Protocolo *temp = obtenerDato(protocolos, i);
        if( strcmp(temp->nombre, "SECRET MESSAGE")== 0)
        {
            Nodo<Paquete> *aux = temp->listaPaquetes->cab;
            while( aux != NULL)
            {
                int tam = strlen(aux->info.dato);
                char *cadena = aux->info.dato;
                for( int j = 0; j < tam; j++)
                {
                    if( cadena[j] == '1')
                    {
                        cadena[j] = 'a';
                    }
                    if( cadena[j] == '2')
                    {
                        cadena[j] = 'e';
                    }
                    if( cadena[j] == '3')
                    {
                        cadena[j] = 'i';
                    }
                    if( cadena[j] == '4')
                    {
                        cadena[j] = 'o';
                    }
                    if( cadena[j] == '5')
                    {
                        cadena[j] = 'u';
                    }
                }
                aux = aux->sig;
            }
        }
    }
}



void quemarDatos(Lista<Protocolo *> *protocolos)
{
    Paquete p;
    strcpy(p.origen, "10.8.1.255");
    strcpy(p.destino, "10.2.36.25");
    strcpy(p.protocolo, "DNS");
    strcpy(p.dato, "34348 www[Sync] Seq=0 Len=0");
    p.suma = 27;
    insertarPaquete(protocolos, p);
    strcpy(p.origen, "192.175.3.21");
    strcpy(p.destino, "19.8.1.111");
    strcpy(p.protocolo, "DNS");
    strcpy(p.dato, "Response Mac Address");
    p.suma = 20;
    insertarPaquete(protocolos, p);
    strcpy(p.origen, "192.168.0.1");
    strcpy(p.destino, "10.2.36.25");
    strcpy(p.protocolo, "TCP");
    strcpy(p.dato, "Estandar query response.");
    p.suma = 24;
    insertarPaquete(protocolos, p);
    strcpy(p.origen, "10.6.3.236");
    strcpy(p.destino, "19.8.1.111");
    strcpy(p.protocolo, "SECRET MESSAGE");
    strcpy(p.dato, "T4m1 1n34s c4nstr53r l1 c4nf31nz1 y s4l4 m3n5t4s p1r1 d2str53rl1");
    p.suma = strlen(p.dato);
    insertarPaquete(protocolos, p);
    strcpy(p.origen, "10.6.3.236");
    strcpy(p.destino, "19.8.1.111");
    strcpy(p.protocolo, "SECRET MESSAGE");
    strcpy(p.dato, "2st2 2s 5n m2ns1j2 d2 pr52b1");
    p.suma = strlen(p.dato);
    insertarPaquete(protocolos, p);
    
    
}

void imprimirPaquetes(Lista<Protocolo *> *protocolos)
{
    for( int i =0; i< tamano(protocolos); i++)
    {
        Protocolo * temp = obtenerDato(protocolos, i);
        cout<<"Protocolo: "<<temp->nombre<<endl;
        for(int j = 0; j < tamano(temp->listaPaquetes); j++)
        {
            Paquete p = obtenerDato(temp->listaPaquetes, j);
            cout<<"\t"<<p.origen<<endl;
            cout<<"\t"<<p.destino<<endl;
            cout<<"\t"<<p.protocolo<<endl;
            cout<<"\t"<<p.dato<<endl;
            cout<<"\t"<<p.suma<<endl;
            cout<<endl;
        }
        cout<<"------------------------------"<<endl;
        cout<<endl;
    }
}

int main(int argc, char *argv[])
{
    Lista<Protocolo *> *protocolos = crearLista<Protocolo *>();
    quemarDatos(protocolos);
    imprimirPaquetes(protocolos);
    cambiarMensajes(protocolos);
    cout<<"Mensajes desencriptados:"<<endl<<endl<<endl;
    Lista<Paquete> * mensajes = buscarPaquetes(protocolos, "10.6.3.236", "SECRET MESSAGE");
    for( int i = 0; i < tamano(mensajes); i++)
    {
        Paquete p = obtenerDato(mensajes, i);
        cout<<"\t"<<p.origen<<endl;
        cout<<"\t"<<p.destino<<endl;
        cout<<"\t"<<p.protocolo<<endl;
        cout<<"\t"<<p.dato<<endl;
        cout<<"\t"<<p.suma<<endl;
        cout<<endl;
    }
    
    
    
    
    system("pause");
    return EXIT_SUCCESS;
}



