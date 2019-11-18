#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void aleatorio(int nums[],int tam);
void ordenar(int *num[],int tam);
int main(){
    int al[10],*pos[10],tam=10;
    aleatorio(al,tam);
    for(int i=0;i<tam;i++){
        *(pos+i)=&al[i];
        cout<<*(*pos+i)<<" "<<*(pos+i)<<"\n";
    }
    ordenar(pos,tam);
    cout<<"\n";
    for(int i=0;i<tam;i++){
        cout<<*pos[i]<<" "<<*(pos+i)<<"\n";
    }
    return 0;
}
void aleatorio(int nums[],int tam){
    srand(time(NULL));
    for(int i=0;i<tam;i++){
       *(nums+i)=(1+rand()%100);

        }
}
void ordenar(int *num[],int tam){
    int *aux;
    for(int i=0;i<tam;i++){
        for(int j=i+1;j<tam;j++){
            if(**(num+i)>**(num+j)){
                aux=*(num+i);
               *(num+i)=*(num+j);
                *(num+j)=aux;
            }
        }
    }
}
