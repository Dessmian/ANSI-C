#include <stdio.h>
#include <stdlib.h>
#include "movies.h"
#include "actors.h"
#include "menues.h"
#include "getData.h"
#include "validateData.h"
int isNumber(char inputData)
{
    if(inputData >= '0' && inputData <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isNaN(char inputData)
{
    if (inputData >= '0' && inputData <= '9')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int isFloat(char* inputData)
{
    int dots = 0;
    int index = 0;
    int itsNegative = 0;
    int isValid = 1;
    for ( index = 0 ; index < strlen(inputData) ; index++ )
    {
        if (index == 0)
        {
            if (inputData[index] == '\0')
            {
                isValid = 0;
                break;
            }
            if(isNaN(inputData[index]) )
            {
                if(inputData[index] == '-')
                {
                    itsNegative = 1;
                }
                else
                {
                    isValid = 0;
                    break;
                }
            }
        }
        else
        {
            if (index == 1 && itsNegative == 1)
            {
                if (inputData[index] == '.' || inputData[index] == '\0')
                {
                    isValid = 0;
                    break;
                }
            }
            else
            {
                if (inputData[index] == '\0')
                {
                    isValid = 1;
                }
                if (isNaN(inputData[index]) )
                {
                    if (inputData[index] == '.')
                    {
                        dots++;
                        if (dots > 1)
                        {
                            isValid = 0;
                            break;
                        }
                    }
                    else
                    {
                        isValid = 0;
                        break;
                    }
                }
            }
        }
    }
    return isValid;
}
int isInt(char* inputData)
{
    int i;
    int itIs = 1;
    for (i = 0 ; i < strlen(inputData) ; i++)
    {
        if(isNaN(inputData[i]) )
        {
            itIs = 0;
            break;
        }
    }
    return itIs;
}
int isLetter(char inputData)
{
    int isValid;
    if(inputData > 'z' || inputData < 'a')
    {
        if(inputData > 'Z' || inputData < 'A')
        {
            isValid = 0;
        }
        else
        {
            isValid = 1;
        }
    }
    else
    {
        isValid = 1;
    }
    return isValid;
}
int isNaL(char inputData)
{
    int isValid;
    if(inputData > 'z' || inputData < 'a')
    {
        if(inputData > 'Z' || inputData < 'A')
        {
            isValid = 1;
        }
        else
        {
            isValid = 0;
        }
    }
    else
    {
        isValid = 0;
    }
    return isValid;
}
int hasOnlyLetters(char* inputData)
{
    int i;
    int itIs = 1;
    for(i = 0 ; i < strlen(inputData) ; i++)
    {
        if(isNaL(inputData[i]) )
        {
            itIs = 0;
            break;
        }
    }
    return itIs;
}
int isName(char* inputData)
{
    int i;
    int itIs = 0;
    int len;
    len = strlen(inputData);
    if (len > 1)
    {
        for (i = 0 ; i < len ; i++)
        {
            if (isNaL(inputData[i]))
            {
                if (inputData[i]!=' ')
                {
                    itIs = 0;
                    break;
                }
            }
            else
            {
                itIs = 1;
            }
        }
    }
    return itIs;
}
int isTitle ( char* inputData )
{
    int itIs = 0;
    if(isLetter(inputData[0]))
    {
        itIs = 1;
    }
    return itIs;
}




























