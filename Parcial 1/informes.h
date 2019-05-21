#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

typedef struct
{
    int idInstrumento;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    int tipo;
}InstrumentoAuxiliar;



int Informes_listarPorCriterio(Tipo arrayA, Tipo arrayB, int sizeI, int sizeJ, char* criterio);
int Informes_listarCriterioContadorAcumulado(Tipo arrayA, Tipo arrayB, int sizeI, int sizeJ);
int Informes_maxContadorAcumulado(Tipo arrayA, Tipo arrayB, int sizeI, int sizeJ);
int informes_ordenarInstrumentos(InstrumentoAuxiliar array[],int size);
int informes_instrumentoMasUsado(Musico arrayMusicos[], InstrumentoAuxiliar arrayAux[], Instrumento arrayInstrumento[], int sizeArray);
int informes_initInstrmentoAuxiliar(InstrumentoAuxiliar arrayAux[], int sizeArray);



#endif // INFORMES_H_INCLUDED
