#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "entregas.h"

int parser_EntregaFromText(FILE* pFile , LinkedList* pArrayListEntrega)
{
    int retorno = -1;
    int flag=0;
    char bufferId[50];
    char bufferTipo[128];
    char bufferCantidad[50];
    char bufferImporte[50];

    Entrega* pEntrega;
    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferTipo, bufferCantidad, bufferImporte);
        if(flag == 0)
        {
            flag++;
            continue;
        }
        pEntrega = entrega_newParametros(bufferId, bufferTipo, bufferCantidad, bufferImporte);
        if(pEntrega != NULL)
        {
            ll_add(pArrayListEntrega, pEntrega);
            retorno = 0;
        }
    }
    return retorno;
}
