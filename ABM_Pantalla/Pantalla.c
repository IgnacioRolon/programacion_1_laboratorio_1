#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "Publicidad.h"
#include "utn_strings.h"
static int generarId(void);

int pan_initPantalla(Pantalla* pPantalla,int len)
{
    int i;
    if(pPantalla!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pPantalla[i].idPantalla=-1;
            pPantalla[i].isEmpty=1;
        }
    }
    return 0;
}

int pan_addPan(Pantalla* pPantalla,int len,int pIndex,char* msgE,int tries)
{
    char bufferName[50];
    char bufferAdress[250];
    char bufferPrecio[20];
    char bufferTipo[20];
    float auxPrecio;
    int auxTipo;
    int retorno=-1;
    if((pPantalla!=NULL)&&(len>0))
    {
        if(((getStringLetras(bufferName,"\nIngrese Nombre: ",msgE,tries)==0)&&
            (getStringAlphanumeric(bufferAdress,"\nIngrese Direccion: ",msgE,tries)==0)))
        {
            if((getStringNumerosFloat(bufferPrecio,"\nIngrese Precio: ",msgE,tries)==0)
                &&(getStringNumeros(bufferTipo,"\nIngrese Tipo 1(LCD) 2(LED): ",msgE,tries)==0))
            {
                auxPrecio=atof(bufferPrecio);
                auxTipo=atoi(bufferTipo);
                strncpy(pPantalla[pIndex].nombre,bufferName,sizeof(bufferName));
                strncpy(pPantalla[pIndex].direccion,bufferAdress,sizeof(bufferAdress));
                pPantalla[pIndex].precio=auxPrecio;
                pPantalla[pIndex].tipo=auxTipo;
                pPantalla[pIndex].idPantalla=generarId();
                pPantalla[pIndex].isEmpty=0;
                retorno=0;
            }
        }
    }
    return retorno;
}

int pan_alter(Pantalla* pPantalla, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferName[50];
    char bufferAdress[250];
    char bufferPrecio[20];
    char bufferTipo[20];
    float auxPrecio;
    int auxTipo;
    int retorno=-1;

    if((pPantalla!=NULL)&&(len>0))
    {
        auxID=pan_getID(pPantalla,len,msgE,tries);
        if(auxID>=0)
        {
            posOfID=pan_findPanById(pPantalla,len,auxID);
            if(posOfID!=-1)
            {
                while(opcion!=5)
                {
                    printf("\n1- Modificar Nombre\n");
                    printf("2- Modificar Direccion\n");
                    printf("3- Modificar Precio\n");
                    printf("4- Modificar Tipo\n");
                    printf("5- Atras (Menu Principal)\n");
                    getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",msgE,1,5,tries);
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",msgE,tries))
                            {
                                strncpy(pPantalla[posOfID].nombre,bufferName,sizeof(bufferName));
                                retorno=0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(!getStringLetras(bufferAdress,"\nIngrese NUEVA Direccion: ",msgE,tries))
                            {
                                strncpy(pPantalla[posOfID].direccion,bufferAdress,sizeof(bufferAdress));
                                retorno=0;
                            }
                            break;
                        }
                        case 3:
                        {
                            if(!getStringNumerosFloat(bufferPrecio,"\nIngrese NUEVO Precio: ",msgE,tries))
                            {
                                auxPrecio=atof(bufferPrecio);
                                pPantalla[posOfID].precio=auxPrecio;
                                retorno=0;
                            }
                            break;
                        }
                        case 4:
                        {
                            if(!getStringNumeros(bufferTipo,"\nIngrese NUEVO Tipo: ",msgE,tries))
                            {
                                auxTipo=atoi(bufferTipo);
                                pPantalla[posOfID].tipo=auxTipo;
                                retorno=0;
                            }
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("\n----No se encontro el ID!-----\n");
            }
        }
    }
    return retorno;
}

int pan_removePantalla(Pantalla* pPantalla, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pPantalla!=NULL && len>0)
    {
        auxID=pan_getID(pPantalla,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=pan_findPanById(pPantalla,len,auxID);
            if(posOfID!=-1)
            {
               pPantalla[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int pan_orderByPrice(Pantalla* pPantalla, int len)
{
    int i;
    int j;
    Pantalla buffer;
    for(i=0;i<len-1;i++)
    {
        if(pPantalla[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(pPantalla[j].isEmpty==1)
            {
                continue;
            }
            if(pPantalla[i].precio>pPantalla[j].precio)
            {
                buffer=pPantalla[i];
                pPantalla[i]=pPantalla[j];
                pPantalla[j]=buffer;
            }
        }
    }
    return 0;
}

int pan_orderByID(Pantalla* pPantalla, int len)
{
    int i;
    int j;
    Pantalla buffer;
    for(i=0;i<len-1;i++)
    {
        if(pPantalla[i].isEmpty==1)
        {
            continue;
        }
        for(j=i+1;j<len;j++)
        {
            if(pPantalla[j].isEmpty==1)
            {
                continue;
            }
            if(pPantalla[i].idPantalla>pPantalla[j].idPantalla)
            {
                buffer=pPantalla[i];
                pPantalla[i]=pPantalla[j];
                pPantalla[j]=buffer;
            }
        }
    }
    return 0;
}

int pan_printPantalla(Pantalla* pPantalla,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pPantalla[i].isEmpty==0)
        {
            printf("\nID: %d\nNombre: %s\nDireccion: %s\nPrecio: %.2f\nTipo: %d\n-------",
                   pPantalla[i].idPantalla,pPantalla[i].nombre,pPantalla[i].direccion,pPantalla[i].precio,pPantalla[i].tipo);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

int pan_findPanById(Pantalla* pPantalla, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPantalla[i].idPantalla==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int pan_findFree(Pantalla* pPantalla, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPantalla[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int pan_getID (Pantalla* pPantalla,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(pPantalla!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}

static int generarId(void)
{
    static int idPant=0;
    return idPant++;
}

int getByID(Pantalla visor[],int ID, int length, Pantalla *resultado)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(ID == visor[i].idPantalla)
        {
            *resultado = visor[i];
            break;
        }
    }
    return 0;
}
