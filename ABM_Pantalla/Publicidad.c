#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "Publicidad.h"
#include "utn_strings.h"
static int generarId(void);

int pub_initPublicidad(Publicidad* pPublicidad,int len)
{
    int i;
    if(pPublicidad!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pPublicidad[i].idPublicidad=-1;
            pPublicidad[i].isEmpty=1;
        }
    }
    return 0;
}

int pub_addPub(Publicidad* pPublicidad,Pantalla* pPantalla,int len,char* msgE,int tries)
{
    int auxID;
    int posOfId;
    char bufferCuit[20];
    char bufferArchivo[250];
    char bufferDias[20];
    int auxDias;
    int retorno=-1;
    if((pPublicidad!=NULL)&&(len>0))
    {
        auxID=pub_getID(pPublicidad,len,msgE,tries);
        posOfId=pan_findPanById(pPantalla,len,auxID);
        if((auxID>=0)&&(posOfId!=-1))
        {
            if((!getCuit(bufferCuit,"\nIngrese CUIT: ",msgE,tries))&&
               (!getStringAlphanumeric(bufferArchivo,"\nIngrese nombre de Archivo: ",msgE,tries)))
               {
                   if(!getStringNumeros(bufferDias,"\nIngrese Dias a contratar: ",msgE,tries))
                   {
                       auxDias=atoi(bufferDias);
                       strncpy(pPublicidad[posOfId].cuit,bufferCuit,sizeof(bufferCuit));
                       strncpy(pPublicidad[posOfId].archivo,bufferArchivo,sizeof(bufferArchivo));
                       pPublicidad[posOfId].dias=auxDias;
                       pPublicidad[posOfId].idPublicidad=generarId();
                       pPublicidad[posOfId].isEmpty=0;
                       retorno=0;
                   }
               }
        }
        else
        {
            printf("\n----EL ID de pantalla no es valido!----\n");
        }
    }

    return retorno;
}

int pub_removePublicidad(Publicidad* pPublicidad, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pPublicidad!=NULL && len>0)
    {
        auxID=pub_getID(pPublicidad,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=pub_findPubById(pPublicidad,len,auxID);
            if(posOfID!=-1)
            {
               pPublicidad[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int pub_printContrataciones(Publicidad* pPublicidad,Pantalla* pPantalla,char* cuit,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if((pPublicidad[i].isEmpty==0)&&(pPantalla[i].isEmpty==0))
        {
            printf("\nID: %d\nNombre: %s\nDireccion: %s\nPrecio: %.2f\nTipo: %d\n-------",
                   pPantalla[i].idPantalla,pPantalla[i].nombre,pPantalla[i].direccion,pPantalla[i].precio,pPantalla[i].tipo);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El cliente no existe!----\n");
    }
    return 0;
}

int pub_findPubById(Publicidad* pPublicidad, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPublicidad[i].idPublicidad==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int pub_findFree(Publicidad* pPublicidad, int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pPublicidad[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int pub_getID (Publicidad* pPublicidad,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(pPublicidad!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID de pantalla a contratar: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}

static int generarId(void)
{
    static int idPubli=0;
    return idPubli++;
}


int pan_findContratacionByIdCuit(Pantalla* pPantalla, int len, int idE)
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
