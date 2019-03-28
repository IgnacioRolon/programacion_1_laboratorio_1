#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int firstNumber(float *numberOne)
{
    float localNumberOne;
    printf("\nIngrese el primer numero \n");
    scanf("%f", &localNumberOne);
    *numberOne = localNumberOne;
    return 0;
}

int secondNumber(float *numberTwo)
{
    float localNumberTwo;
    printf("\nIngrese el segundo numero \n");
    scanf("%f", &localNumberTwo);
    *numberTwo = localNumberTwo;
    return 0;
}


int addNumbers(float addFirstNumber, float addSecondNumber, int confirmInputs)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputs)
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");
    }else
    {
        mathResult = addFirstNumber + addSecondNumber;
        printf("\nLa suma es: %f", mathResult);
        returnValue = 0;
    }
    return returnValue;
}

int substractNumbers(float subFirstNumber, float subSecondNumber, int confirmInputs)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputs)
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");
    }else
    {
        mathResult = subFirstNumber - subSecondNumber;
        printf("\nLa resta es: %f", mathResult);
        returnValue = 0;
    }
    return returnValue;
}

int multiplyNumbers(float multiFirstNumber, float multiSecondNumber, int confirmInputs)
{
    int returnValue = -1;
    float mathResult;
    if (confirmInputs)
    {
        printf("ERROR: No se ha ingresado alguno de los 2 operandos.");

    }else
    {
        mathResult = multiFirstNumber * multiSecondNumber;
        printf("\nEl producto es: %f", mathResult);
        returnValue = 0;
    }
    return returnValue;
}

int factorizeNumbers(float factorFirstNumber, int confirmInputs)
{
    int returnValue = -1;
    float mathResult = factorFirstNumber;
    int i;
    if (confirmInputs)
    {
        printf("ERROR: No se ha ingresado el primer operando.");
    }else
    {
        for(i = factorFirstNumber - 1;i>0;i--)
        {
            mathResult = mathResult * i;
        }
        printf("\nLa factorizacion es: %f", mathResult);
        returnValue = 0;
    }
    return returnValue;
}
