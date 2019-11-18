#ifndef LISTAS_H
#define LISTAS_H

template<typename T>
struct Nodo
{
    Nodo<T> * sig;
    T info; //Esta es la informacion de la lista
};

template<typename T>
struct Lista
{
    Nodo<T> * cab;
    int tam;
};


template<typename T>
void imprimir(Lista<T> *);

template<typename T>
void insertar(Lista<T> *, T);

template<typename T>
bool vacia(Lista<T> *);

template<typename T>
int tamano(Lista<T> *);

template<typename T>
T obtenerDato(Lista<T> *, int);

template<typename T>
bool eliminar(Lista<T> *, int);

template<typename T>
void destruirLista(Lista<T> *);

template<typename T>
Lista<T> *crearLista();

#endif
