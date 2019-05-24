#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Orquesta.h"
#include "Instrumentos.h"
#include "Musico.h"
#define ORQUESTAS_MAX 50
#define INSTRUMENTOS_MAX 20
#define MUSICOS_MAX 1000

int main()
{
    Orquesta arrayOrquestas[50];
    int idOrquestas = 0;
    orquesta_Inicializar(arrayOrquestas, ORQUESTAS_MAX);

    Instrumento arrayInstrumentos[20];
    int idInstrumentos = 0;
    instrumento_Inicializar(arrayInstrumentos, INSTRUMENTOS_MAX);

    Musico arrayMusicos[1000];
    int idMusicos = 0;
    musico_Inicializar(arrayMusicos, MUSICOS_MAX);

    int respuesta = -2;
    while(respuesta != 10)
    {
        utn_getUnsignedInt("\n1) Agregar Orquesta\n2) Eliminar Orquesta\n3) Imprimir Orquestas\n4) Agregar Musico\n5) Modificar Musico\n6) Eliminar Musico\n7) Imprimir Musicos\n8) Agregar Instrumento\n9) Imprimir Instrumentos\n10) Salir\n", "ERROR: Ingrese un numero valido.", 0, 3, 0, 10, 1, &respuesta);
        switch(respuesta)
        {
            case 1:
                orquesta_alta(arrayOrquestas, ORQUESTAS_MAX, &idOrquestas);
                break;
            case 2:
                orquesta_baja(arrayOrquestas, ORQUESTAS_MAX);
                break;
            case 3:
                orquesta_listar(arrayOrquestas, ORQUESTAS_MAX);
                break;
            case 4:
                musico_alta(arrayMusicos, arrayOrquestas, arrayInstrumentos, MUSICOS_MAX, &idMusicos);
                break;
            case 5:
                musico_listar(arrayMusicos, arrayInstrumentos, MUSICOS_MAX);
                musico_modificar(arrayMusicos, arrayOrquestas, MUSICOS_MAX);
                break;
            case 6:
                musico_baja(arrayMusicos, MUSICOS_MAX);
                break;
            case 7:
                musico_listar(arrayMusicos, arrayInstrumentos, MUSICOS_MAX);
                break;
            case 8:
                instrumento_alta(arrayInstrumentos, INSTRUMENTOS_MAX, &idInstrumentos);
                break;
            case 9:
                instrumento_listar(arrayInstrumentos, INSTRUMENTOS_MAX);
                break;
        }
    }
}
