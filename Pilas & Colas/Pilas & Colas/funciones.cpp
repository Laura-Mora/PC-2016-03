//
//  funciones.cpp
//  Pilas & Colas
//
//  Created by Laura Juliana Mora on 3/11/16.
//  Copyright © 2016 Laura Juliana Mora. All rights reserved.
//

#include "funciones.hpp"
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
void prio(compo p[]){
    p[0].prio=4;
    p[0].vari='^';
    p[1].prio=3;
    p[1].vari='*';
    p[2].prio=3;
    p[2].vari='/';
    p[3].prio=2;
    p[3].vari='+';
    p[4].prio=2;
    p[4].vari='-';
    p[5].prio=1;
    p[5].vari='=';
    p[6].prio=0;
    p[6].vari=')';
    p[7].prio=0;
    p[7].vari='(';
}
