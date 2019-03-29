#include <stdio.h>
#include <stdlib.h>

int isValidInt(int number, int minimum, int maximum)
{
    if(number >= minimum && number <= maximum)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int getInt(char *message, char *errorMessage, int minimum, int maximum, int retries, int *input)
{
    int returnValue = -1;
    int buffer;
    if(message != NULL && errorMessage != NULL && input != NULL && maximum >= minimum && retries >= 0)
    {
        do
        {
            printf("%s", message);
            scanf("%d", &buffer);
            if(isValidInt(buffer, minimum, maximum))
            {
                *input = buffer;
                returnValue = 0;
                break;
            }else
            {
                printf("%s", errorMessage);
            }
            retries--;
        }while(retries >= 0);
    }
    return returnValue;
}

int isValidFloat(float number, float minimum, float maximum)
{
    if(number >= minimum && number <= maximum)
    {
        return 1;
    }
    return 0;
}

int getFloat(char *message, char *errorMessage, float minimum, float maximum, int retries, float *input)
{
    int returnValue = -1;
    float buffer;
    if(message != NULL && errorMessage != NULL && input != NULL && maximum>=minimum && retries >= 0)
    {
        do
        {
            printf("%s", message);
            scanf("%f", &buffer);
            if(isValidFloat(buffer, minimum, maximum))
            {
                *input = buffer;
                returnValue = 0;
                break;
            }else
            {
                printf("%s", errorMessage);
            }
            retries--;
        }while(retries >= 0);
    }
    return returnValue;
}

int isValidChar(char letter, char minimum, char maximum)
{
    if(letter>=minimum && letter <= maximum)
    {
        return 1;
    }
    return 0;
}

int getChar(char *message, char *errorMessage, char minimum, char maximum, int retries, char *input)
{
    char buffer;
    int returnValue = -1;
    if(message != NULL && errorMessage != NULL && input != NULL && maximum >= minimum && retries >= 0)
    {
        do
        {
            printf("%s", message);
            __fpurge(stdin);
            scanf("%c", &buffer);
            //fflush(stdin); para windows
            if(isValidChar(buffer, minimum, maximum))
            {
                *input = buffer;
                returnValue = 0;
                break;
            }else
            {
                printf("%s", errorMessage);
            }
            retries--;
        }while(retries >= 0);
    }
    return returnValue;
}
