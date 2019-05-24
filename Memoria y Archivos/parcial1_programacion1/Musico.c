#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "Musico.h" //cambiar por nombre entidad
#include "Orquesta.h"
#include "Instrumentos.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)                                    //cambiar musico
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer apellido vacio en un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un apellido vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)                                                   //cambiar campo edad
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], Orquesta arrayOrquesta[], Instrumento arrayInstrumento[], int size, int* contadorID)                          //cambiar musico
{
    int retorno=-1;
    int posicion;
    int aux;
    int bufferInt;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)                          //cambiar musico
        {
            printf("\nNo hay apellidoes vacios");
        }
        else
        {
            if(utn_getUnsignedInt("\nIngrese el ID de la Orquesta a la que pertenece el musico:\n","\nID Invalida.\n",1,sizeof(int),1,10,1,&bufferInt))
            {
                return retorno;
            }           //mensaje + cambiar campo edad         //mensaje + cambiar campo varFloat
            else
            {
                if(!orquesta_buscarID(arrayOrquesta, 50, bufferInt, &aux))
                {
                    array[posicion].idOrquesta = bufferInt;
                }else
                {
                    return retorno;
                }
            }
            if(utn_getUnsignedInt("\nIngrese el ID del Instrumento que toca el musico:\n","\nID Invalida.\n",1,sizeof(int),1,10,1,&bufferInt))
            {
                return retorno;
            }           //mensaje + cambiar campo edad         //mensaje + cambiar campo varFloat
            else
            {
                if(!instrumento_buscarID(arrayInstrumento, 20, bufferInt, &aux))
                {
                    array[posicion].idInstrumento = bufferInt;
                }else
                {
                    return retorno;
                }
            }
            if(utn_getName("\nIngrese el nombre del Musico: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre))
            {
                return retorno;
            }                      //mensaje + cambiar campo nombre
            if(utn_getName("\nIngrese el apellido del Musico: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido))
            {
                return retorno;
            }                 //mensaje + cambiar campo apellido
            if(utn_getUnsignedInt("\nIngrese la edad: ","\nEdad invalida.\n",1,sizeof(int),1,10,1,&bufferInt))
            {
                return retorno;
            }else
            {
                array[posicion].edad = bufferInt;
            }
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            printf("\n ID: %d\n ID Orquesta: %d\n ID Instrumento: %d\n Nombre: %s\n Apellido: %s\n Edad: %d\n",
                  array[posicion].idUnico,array[posicion].idOrquesta,array[posicion].idInstrumento,array[posicion].nombre, array[posicion].apellido, array[posicion].edad);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)                                      //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].edad=0;                                                               //cambiar campo edad                                                            //cambiar campo varFloat
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");
            array[posicion].idOrquesta = 0;
            array[posicion].idInstrumento = 0;                                               //cambiar campo apellido
            retorno=0;
            printf("\nBaja realizada con exito.\n");
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].edad=0;                                                               //cambiar campo edad                                                           //cambiar campo varFloat
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], Orquesta arrayOrquesta[], int sizeArray)                                //cambiar musico
{
    int retorno=-1;
    int posicion;
    int id;
    int aux;
    int bufferInt;                                                                                 //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            utn_getUnsignedInt("\nIngrese lo que desea modificar:\n1- Edad\n2- ID de Orquesta\n","\nError",1,sizeof(int),1,10,1,&opcion);
            __fpurge(stdin);
                switch(opcion)
                {
                    case 1:
                        if(utn_getUnsignedInt("\nIngrese la edad: ","\nEdad invalida.\n",1,sizeof(int),1,10,1,&bufferInt))
                        {
                            printf("Edad invalida");
                            return retorno;
                        }else
                        {
                            printf("Edad cambiada exitosamente.");
                            array[posicion].edad = bufferInt;
                        }
                        break;
                    case 2:
                        if(utn_getUnsignedInt("\nIngrese el ID de la nueva Orquesta: ","\nID Invalida.\n",1,sizeof(int),1,10,1,&bufferInt))
                        {
                            printf("ID Invalida.");
                            return retorno;
                        }           //mensaje + cambiar campo edad         //mensaje + cambiar campo varFloat
                        else
                        {
                            if(!orquesta_buscarID(arrayOrquesta, 50, bufferInt, &aux))
                            {
                                array[posicion].idOrquesta = bufferInt;
                                printf("\nOrquesta modificada exitosamente.\n");
                            }else
                            {
                                printf("\nLa orquesta indicada no existe.\n");
                                return retorno;
                            }
                        }
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array musico Array de musico
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
/*
int musico_ordenarPorDobleCriterio(Musico array[],int size, int orderFirst, int orderSecond)                              //cambiar musico
{
    int retorno=-1;
    int i;
    Musico buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].varFloat < array[i+1].varFloat) && orderSecond) ||
                        ((array[i].varFloat > array[i+1].varFloat) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}
*/

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], Instrumento arrayInstrumento[], int size)                      //cambiar musico
{
    int retorno=-1;
    char bufferTipo[15];
    int i;
    int aux;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            {
                instrumento_buscarID(arrayInstrumento, 20, array[i].idInstrumento, &aux);
                switch(arrayInstrumento[aux].tipo)
                {
                    case 1:
                        strcpy(bufferTipo, "Cuerdas");
                        break;
                    case 2:
                        strcpy(bufferTipo, "Viento-madera");
                        break;
                    case 3:
                        strcpy(bufferTipo, "Viento-metal");
                        break;
                    case 4:
                        strcpy(bufferTipo, "Percusion");
                        break;
                }

                printf("\n ID: %d\n Nombre: %s\n Apellido: %s\n Nombre de Instrumento: %s\n Tipo de Instrumento: %s\n",
                       array[i].idUnico,array[i].nombre,array[i].apellido,arrayInstrumento[aux].nombre,bufferTipo);      //cambiar todos
            }
        }
        retorno=0;
    }
    return retorno;
}


