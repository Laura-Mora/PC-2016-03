#include <iostream>
#define MAX 10
using namespace std;
void ordenar(int **ptr, int tam);
void leer(int n, int m, int tam, int *ptra, int *ptrb, int *ptr);
void imprimir(int *ptr, int tam);
int main() {
    int a[MAX], b[MAX], c[20],m,n,tam;
    int *ptr, *ptra,*ptrb ;
    do{
        cout<<"Tamanio vector a: ";
        cin>>m;
    }while(m>10);
    do{
        cout<<"Tamanio vector b: ";
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
    int i=0,pa=0, pb=0, tam1=0,**bum;
    cout<< tam;
    while(i<tam){
        if(pa<m){
            cout<<"Dato vector a:";
            cin>>*(ptra+i);
            *(ptr+i)=*(ptra+i);
            i++;
            pa++;
        }
        if(pb<n){
            cout<<"Datos vector b:";
            cin>>*(ptrb+i);
            *(ptr+i)=*(ptrb+i);
            i++;
            pb++;
        }
        tam1=pb+pa;
        bum=&ptr;
        //ordenar(bum,tam1);
    }
    imprimir(ptr,tam);
}
void ordenar(int **ptr, int tam){
    int i,j;
    int *aux;
    for(i=0;i<tam-1;i++)
        for(j=i+1;j<tam;j++)
            if(**(ptr+i)>**(ptr+j))
            {
                aux=*(ptr+i);
                *(ptr+i)=*(ptr+j);
                *(ptr+j)=aux;
            }
}
void imprimir(int *ptr, int tam){
    for(int i=0;i<tam;i++){
        cout<<" "<<*(ptr+i);
    }
}

