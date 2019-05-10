#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];

}Autor;


#endif // AUTOR_H_INCLUDED

int autor_Inicializar(Autor array[], int size);                                    //cambiar autor
int autor_buscarEmpty(Autor array[], int size, int* posicion);                    //cambiar autor
int autor_buscarID(Autor array[], int size, int valorBuscado, int* posicion);                    //cambiar autor
int autor_buscarInt(Autor array[], int size, int valorBuscado, int* posicion);                    //cambiar autor
int autor_buscarString(Autor array[], int size, char* valorBuscado, int* indice);                    //cambiar autor
int autor_alta(Autor array[], int size, int* contadorID);                          //cambiar autor
int autor_baja(Autor array[], int sizeArray);                                      //cambiar autor
int autor_bajaValorRepetidoInt(Autor array[], int sizeArray, int valorBuscado);
int autor_modificar(Autor array[], int sizeArray);                                //cambiar autor
int autor_ordenarPorDobleCriterio(Autor array[],int size, int orderFirst, int orderSecond);                                  //cambiar autor
int autor_listar(Autor array[], int size);                      //cambiar autor
void autor_mock(Autor arrayAutor[], int size,int *contadorId);                      //cambiar autor

