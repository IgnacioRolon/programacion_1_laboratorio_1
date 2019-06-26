#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float importe;
}Entrega;

Entrega* entrega_new();
Entrega* entrega_newParametros(char* id,char* tipo,char* cantidad, char* importe);
int entrega_delete(Entrega* this);

int entrega_setId(Entrega* this,int id);
int entrega_getId(Entrega* this,int* resultado);
int entrega_setIdAsString(Entrega* this, char* id);
int entrega_getIdAsString(Entrega* this, char* resultado);

int entrega_setTipo(Entrega* this,char* tipo);
int entrega_getTipo(Entrega* this,char* resultado);

int entrega_setCantidad(Entrega* this,int cantidad);
int entrega_getCantidad(Entrega* this,int* resultado);
int entrega_setCantidadAsString(Entrega* this, char* cantidad);
int entrega_getCantidadAsString(Entrega* this, char* resultado);

int entrega_setImporte(Entrega* this,float importe);
int entrega_getImporte(Entrega* this,float* resultado);
int entrega_setImporteAsString(Entrega* this, char* importe);
int entrega_getImporteAsString(Entrega* this, char* resultado);

int entrega_filtrarGold(void* this);
int entrega_filtrarPlus(void* this);
int entrega_filtrarRegular(void* this);

#endif // Entrega_H_INCLUDED
