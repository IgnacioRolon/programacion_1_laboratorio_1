#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "fantasma.h"  //cambiar por nombre entidad
#include "autor.h"

#define QTY_ARRAY_TIPO 10
#define QTY_ARRAY_AUTOR 10
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdfantasma=0;                   //cambiar

    Fantasma arrayFantasma[QTY_ARRAY_TIPO];                   //cambiar
    fantasma_Inicializar(arrayFantasma,QTY_ARRAY_TIPO);                   //cambiar
    fantasma_mock(arrayFantasma, QTY_ARRAY_TIPO, &contadorIdfantasma) ;                     //cambiar fantasma


    int contadorIdautor=0;
    Autor arrayAutor[QTY_ARRAY_AUTOR];                   //cambiar
    autor_Inicializar(arrayAutor,QTY_ARRAY_AUTOR);                   //cambiar
    autor_mock(arrayAutor, QTY_ARRAY_AUTOR, &contadorIdautor) ;                     //cambiar fantasma



    do
    {
        utn_getUnsignedInt("\n\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar \n\n 6) Alta autor \n7) Modificar autor \n8) Baja autor \n9) Listar autor \n10) Ordenar autor \n11) Salir\n",                   //cambiar
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
            case 6: //Alta
                autor_alta(arrayAutor,QTY_ARRAY_TIPO,&contadorIdautor);                   //cambiar
                break;

            case 7: //Modificar
                autor_modificar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 8: //Baja
                autor_baja(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 9://Listar
                autor_listar(arrayAutor,QTY_ARRAY_TIPO);                   //cambiar
                break;

            case 10://Ordenar
                autor_ordenarPorDobleCriterio(arrayAutor,QTY_ARRAY_TIPO,SORT_UP,SORT_DOWN);                   //cambiar
                break;

            case 11://Salir
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
