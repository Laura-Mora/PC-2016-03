#include <stdio.h>
#include <iostream>
using namespace std;
void unir(int m, int n, int *ap, int *ab, int tam, int *ac);
void leer(int m, int n, int *ap, int *ab);
int main(){
    int m,n,a[10],b[10],c[20],d[20],e[20],tam;
    int *ap,*ab,*ac;
    cout<<"tama–o vector a";
    cin>>m;
    cout<<"tama–o vector b";
    cin>>n;
    tam=m+n;
    ap=&a[0];
    ab=&b[0];
    leer(m,n,ap,ab);
    unir(m,n,ap,ab,tam,ac);
    return 0;
}
int *menu(){
    int *op,opc;
    do{
        cout<<"1.Union"<<"\n"<<"2.Interseccion"<<"\n"<<"3.Diferencia"<<"\n"<<"Cual opcion desea ejecutar?";
        cin>>opc;
    }while(opc>2||opc<1);
    op=&opc;
    return op;
}
void leer(int m, int n, int *ap, int *ab){
    for(int i=0;i<m;i++){
        cin>>*(ap+i);
    }
    for(int i=0;i<n;i++){
        cin>>*(ab+i);
    }
    for(int i=0;i<m;i++){
        cout<<*(ap+i);
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        cout<<*(ab+i);
    }

}
void unir(int m, int n, int *ap, int *ab, int tam, int *ac){
    int j=0;
    for(int i=0;i<m;i++){
        *(ac+i)=*(ap+i);
    }
    for(int i=m;i<tam;i++){
        *(ac+i)=*(ab+j);
        j++;
    }
    for(int i=0;i<tam;i++){
        cout<<*(ac+i)<<" ";
    }
}
