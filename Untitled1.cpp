void modificarcantidadproductos(char* sucursal,char *product,char *present,int cantidadrestada)///--------------------------------------------------------------------------
{
    fstream tienda,temp;
    producto nuevo;
    char* paso,*token,*otro;
    paso=new char[200];
    otro=new char[50];
    cin.ignore();
    temp.open("temp.txt",ios::out);
    temp.close();


    if (buscarproducto(product,sucursal))
    {
        tienda.open(sucursal,ios::in|ios::out|ios::app);
//        temp.open("/Users/Lalis/Documents/Universidad/Segundo Semestre/PC/proyecto/proyecto/temp.txt",ios::in|ios::out);
        temp.open("temp.txt",ios::out|ios::in);

        if(!temp)
        {

        }
        nuevo.nombre=new char[20];
        strcpy(nuevo.nombre,product);
//        nuevo=presentacionproducto(nuevo);
//        strcpy(nuevo.nombre,prod);

char * tempo;

        while (!tienda.eof())
        {
            tienda.getline(paso,200,'\n');
            strcpy(otro,paso);
            tempo=new char[strlen(paso)];
            token=strtok(otro,",");
            if(strlen(paso)>0)
            {
            if (strcmp(token,nuevo.nombre)==0)
            {
                presentacion *aux;
                char *taken,*camb;
                int vex=0,ini=0;

                strcpy(tempo,paso);

                token=strtok(tempo,";");

                while(token!=NULL)
                {

                vex=0;

                camb=new char [strlen(token)];
                strcpy(camb,token);

                if (ini==0)
                {
                taken=strtok(camb,",");
                strcpy(nuevo.nombre,taken);
                taken=strtok(NULL,";");
                nuevo.existenciastotales=atoi(taken)-cantidadrestada;
                nuevo.cabeza=aux;
                ini++;
}
else
{
taken=strtok(camb,",");
strcpy(aux->tipo,taken);
taken=strtok(NULL,",");
aux->costo=atof(taken);
taken=strtok(NULL,";");
aux->existencias=atoi(taken);

if (strcmp(aux->tipo,product)==0)
{
aux->existencias-=cantidadrestada;
}
/*while(taken!=NULL)
                {
                taken=strtok(camb,",,;");//esta mierda no sirve=------=----=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
                vex++;
                switch(vex)
                {
                case 1:
                strcpy(aux->tipo,taken);
                break;
                case 2:
                aux->costo=atof(taken);
                break;
case 3:

aux->existencias=atoi(taken);

if (strcmp(aux->tipo,product)==0)
{
aux->existencias-=cantidadrestada;
}
break;
}
}*/
}


token=strtok(NULL,"\n");
}



                temp<<nuevo.nombre<<","<<nuevo.existenciastotales<<";";
                aux=nuevo.cabeza;

                while (aux!=NULL)
                {
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
    while(!temp.eof())
        {
            temp.getline(paso,200,'\n');

            tienda<<paso<<endl;

        }

    }

    remove("temp.txt");
}
