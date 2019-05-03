#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_strings.h"



int getString(char* pStr, char* msg, char*msgE)
{
    char bufferStr[20];
    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';
    if(pStr!=NULL)
    {
        strncpy(pStr,bufferStr,sizeof(bufferStr));
    }
    return 0;
}


int getInt (int *pNum, char* msg, char* msgE)

{
    int number;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%d",&number)==1)
    {
        (*pNum)=number;
        ret=0;
    }
    else
    {
        printf("%s",msgE);
        fflush(stdin);
        //fpurge(stdin);
    }
    return ret;
}

int getFloat (float *pNum, char* msg, char* msgE)

{
    float number;
    int ret=-1;
    printf("%s",msg);
    if(scanf("%f",&number)==1)
    {
        (*pNum)=number;
        ret=0;
    }
    else
    {
        printf("%s",msgE);
    }
    return ret;
}

int getIntInRange(  int *pNum,
                    char *msg,
                    char *msgE,
                    int minimo,
                    int maximo,
                    int reintentos)
{
    int retorno = -1;
    char bufferStr[20];
    int bufferInt;
    do
    {

        if((pNum != NULL)&&(!getStringNumeros(bufferStr,msg,msgE,reintentos)))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *pNum = bufferInt;
            }
            else
            {
                printf("El numero esta fuera del rango!\n");
                reintentos--;
            }
        }
        else
        {
            printf("No es un numero valido!\n");
            reintentos--;
        }
    } while(retorno==-1 && reintentos>0);
    return retorno;
}

int cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgE)

{
    int i;
    int buffer;
    int ret;
    for(i=0;i<len;i++)
    {
        ret=getInt(&buffer,msg, msgE);
        if(ret)
        {
            break;
        }
        *(pArray+i)=buffer;
    }
    return 0;
}

int cargarArraySecuencialFloat(float* pArray,int len,char* msg, char* msgE)

{
    int i;
    float buffer;
    int ret;
    for(i=0;i<len;i++)
    {
        ret=getFloat(&buffer,msg, msgE);
        if(ret)
        {
            break;
        }
        *(pArray+i)=buffer;
    }
    return 0;
}

int getStringLetras (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isLetter(bufferStr)))
        {
            strncpy(pStr,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf(msgE);
            reintentos--;
        }
    }
    return ret;
}

int getStringNumeros (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isNumber(bufferStr)))
        {
            strncpy(pStr,bufferStr,sizeof(bufferStr));
            retorno=0;
        }
        else
        {
            printf(msgE);
            retorno=-1;
        }
    }
    return retorno;
}

int getStringNumerosFloat (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int retorno=-1;
    while(retorno==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isNumberFloat(bufferStr)))
        {
            strncpy(pStr,bufferStr,sizeof(bufferStr));
            retorno=0;
        }
        else
        {
            printf(msgE);
            retorno=-1;
        }
    }
    return retorno;
}

int getStringAlphanumeric (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[250];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isAlphanumeric(bufferStr)))
        {
            strncpy(pStr,bufferStr,sizeof(bufferStr));
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}

int getTelephone (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isTelephone(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}

int getDni (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isDni(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}

int getCuit (char* pStr, char* msg, char* msgE,int reintentos)
{
    char bufferStr[20];
    int ret=-1;
    while(ret==-1 && reintentos>0)
    {
        if(!getString(bufferStr,msg,msgE)&&(pStr!=NULL)&&(isCuit(bufferStr)))
        {
            strncpy(pStr,bufferStr,20);
            ret=0;
        }
        else
        {
            printf("%s",msgE);
            reintentos--;
        }
    }
    return ret;
}

int findEmptyPlace (char pArray[][20],int* pIndex,int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pArray[i][0]=='\0')
        {
            *pIndex=i;
            ret=0;
            break;
        }
    }
    return ret;
}

int findName(char* name, char parray[][20], int len, int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(strcmp(name,parray[i])==0)
        {
            *pIndex=i;
            ret=0;
            break;
        }
    }
    return ret;
}

int ordenarArrayMayorMenor (char* pArray, int len,int limit)
{
    int i;
    int j;
    char buffer[limit];
    for(i=0;i<len-1;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(pArray[i]>pArray[j])
            {
                buffer[i]=pArray[i];
                pArray[i]=pArray[j];
                pArray[j]=buffer[i];
            }
        }
    }
    return 0;
}

int showArrayInt(int* pArray,int len)

{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}

int showArrayChar(char* pArray,int len)

{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}

int isNumber (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(pStr[i]<'0' || pStr[i]>'9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int isNumberFloat (char* pStr)
{
    int i=0;
    int contadorPuntos=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]<'0' || pStr[i]>'9')&&(pStr[i]!='.'))
        {
            return 0;
        }
        if(pStr[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>1)
            {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

int isLetter (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!=' ')&&(pStr[i]<'a'||pStr[i]>'z')&&(pStr[i]<'A'||pStr[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isAlphanumeric (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!=' ')&&(pStr[i]!='.')&&(pStr[i]<'a'||pStr[i]>'z')&&(pStr[i]<'A'||pStr[i]>'Z')
           &&(pStr[i]<'0' || pStr[i]>'9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isTelephone (char* pStr)
{
    int i=0;
    int contadorGuion=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!=' ')&&(pStr[i]!='-')&&(pStr[i]<'0' || pStr[i]>'9'))
        {
            return 0;
        }
        if(pStr[i]=='-')
        {
            contadorGuion++;
        }
        i++;
    }
    if(contadorGuion==1)
        {
            return 1;
        }
    return 0;
}

int isDni (char* pStr)
{
    int i=0;
    while(pStr[i]!='\0')
    {
        if(!isNumber(pStr))
        {
            return 0;
        }
        if(strlen(pStr)<7 || strlen(pStr)>8)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int isCuit (char* pStr)
{
    int ret=0;
    int i=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]!='-')&&(pStr[i]<'0' || pStr[i]>'9'))
        {
            return 0;
        }
        else if((pStr[2]=='-')&&(pStr[10]=='-' || pStr[11]=='-'))
        {
            ret=1;
        }
        i++;
    }
    return ret;
}
