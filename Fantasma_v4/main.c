#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"  //cambiar por nombre entidad


#define QTY_ARRAY_TIPO 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdfantasma=0;                   //cambiar

    Fantasma arrayFantasma[QTY_ARRAY_TIPO];                   //cambiar
    fantasma_Inicializar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar

    //*******************************************************************
    arrayFantasma[0].idUnico=0;
    arrayFantasma[0].isEmpty=0;
    arrayFantasma[0].varInt=0;
    arrayFantasma[0].varFloat=0;
    strcpy(arrayFantasma[0].varLongString,"CCCCC");
    strcpy(arrayFantasma[0].varString,"CCCCC");
    contadorIdfantasma++;

    arrayFantasma[1].idUnico=1;
    arrayFantasma[1].isEmpty=0;
    arrayFantasma[1].varInt=0;
    arrayFantasma[1].varFloat=0;
    strcpy(arrayFantasma[1].varLongString,"AAAAA");
    strcpy(arrayFantasma[1].varString,"AAAAA");
    contadorIdfantasma++;

    arrayFantasma[2].idUnico=0;
    arrayFantasma[2].isEmpty=0;
    arrayFantasma[2].varInt=0;
    arrayFantasma[2].varFloat=20;
    strcpy(arrayFantasma[2].varLongString,"BBBBB");
    strcpy(arrayFantasma[2].varString,"BBBBBB");
    contadorIdfantasma++;

    arrayFantasma[3].idUnico=0;
    arrayFantasma[3].isEmpty=0;
    arrayFantasma[3].varInt=0;
    arrayFantasma[3].varFloat=10;
    strcpy(arrayFantasma[3].varLongString,"BBBBB");
    strcpy(arrayFantasma[3].varString,"BBBBBB");
    contadorIdfantasma++;


    //********************************************************************

    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n6) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                fantasma_alta(arrayFantasma,QTY_ARRAY_TIPO,&contadorIdfantasma);                   //cambiar
                break;

            case 2: //Modificar
                fantasma_modificar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                fantasma_baja(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 4://Listar
                fantasma_listar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                fantasma_ordenarPorDobleCriterio(arrayFantasma,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 6://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
