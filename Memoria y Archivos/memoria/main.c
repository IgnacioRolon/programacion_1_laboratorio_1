#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "persona.h"
#include "utn.h"

int main()
{
    Persona *pArrayPersona[2000];
    int i = 0;
    int flag=0;
    char bufferId[50];
    char bufferName[50];
    char bufferApellido[50];
    char bufferEstado[50];

    //int limite = 2;
    //char auxName[50];
    //char auxName2[50];

    FILE *pFile = NULL;
    pFile = fopen("data.csv", "r");

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferName, bufferApellido, bufferEstado);
            if(flag == 0)
            {
                flag++;
                continue;
            }
            pArrayPersona[i] = Pers_newStr(bufferId, bufferName, bufferApellido, bufferEstado);
            i++;
        }
        fclose(pFile);
        Pers_getApellido(pArrayPersona[50], bufferApellido);
        printf("Apellido: %s", bufferApellido);
    }


/*
    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Pers_new();

    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("OK");
        for(int i=0;i<limite;i++)
        {
            pArrayPersona[i] =  Pers_new();
            utn_getName("\nIngrese el nombre: ", "Error", 0, 50, 5, auxName);
            utn_getName("\nIngrese el apellido: ", "Error", 0, 50, 5, auxName2);
            __fpurge(stdin);
            if(!Pers_setId(pArrayPersona[i],14)
                && !Pers_setEstado(pArrayPersona[i], 1)
                && !Pers_setNombre(pArrayPersona[i], auxName)
                && !Pers_setApellido(pArrayPersona[i], auxName2))
            {
                Pers_getNombre(pArrayPersona[i], auxName);
                Pers_getApellido(pArrayPersona[i], auxName2);
                printf("\nNombre: %s", auxName);
                printf("\nApellido: %s\n", auxName2);
                printf("Ingreso OK\n");
            }
        }
        //auxInt = Pers_compararPorNombre(pArrayPersona[0], pArrayPersona[1]);
        //printf("Comparacion: %d", auxInt);
    }
*/

    return 0;
}
