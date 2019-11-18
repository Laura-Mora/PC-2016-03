//
//  Taller 02 pc .cpp
//  PC
//
//  Created by Laura Juliana Mora on 28/07/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "Taller 02 pc .hpp"
#include <iostream>

#include <time.h>

#include <stdlib.h>
using namespace std;
void aleatorio(int nums[]);
void ordenar(int *nums[]);
int main(){
    int al[10],*pos[10];
    aleatorio(al);
    for(int i=0;i<10;i++){
        pos[i]=&al[i];
    }
    return 0;
}
void aleatorio(int nums[]){

    for(int i=0;i<10;i++){
        nums[i]=(1+rand()%100);
    }
}
