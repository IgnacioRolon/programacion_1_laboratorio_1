#ifndef UTN_STRINGS_H_INCLUDED
#define UTN_STRINGS_H_INCLUDED

int getString(char* pStr, char* msg, char*msgE);
int getInt (int *pNum, char* msg, char* msgE);
int getFloat (float *pNum, char* msg, char* msgE);

int getIntInRange (int *pNum,char *msg,char *msgE,int minimo,int maximo,int reintentos);
int cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgE);
int cargarArraySecuencialFloat(float* pArray,int len,char* msg, char* msgE);

int getStringLetras (char* pStr, char* msg, char* msgE,int reintentos);
int getStringNumeros (char* pStr, char* msg, char* msgE,int reintentos);
int getStringNumerosFloat (char* pStr, char* msg, char* msgE,int reintentos);
int getStringAlphanumeric (char* pStr, char* msg, char* msgE,int reintentos);
int getTelephone (char* pStr, char* msg, char* msgE,int reintentos);
int getDni (char* pStr, char* msg, char* msgE,int reintentos);
int getCuit (char* pStr, char* msg, char* msgE,int reintentos);

int findEmptyPlace (char pArray[][20],int* pIndex,int len);
int findName(char* name, char parray[][20], int len, int* pIndex);
int ordenarArrayMayorMenor (char* pArray, int len,int limit);

int showArrayInt(int* pArray,int len);
int showArrayChar(char* pArray,int len);

int isNumber (char* pStr);
int isNumberFloat (char* pStr);
int isLetter (char* pStr);
int isAlphanumeric (char* pStr);
int isTelephone (char* pStr);
int isDni (char* pStr);
int isCuit (char* pStr);

#endif // UTN_STRINGS_H_INCLUDED
