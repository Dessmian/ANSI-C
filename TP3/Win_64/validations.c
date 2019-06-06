#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int isName (char* inputStr , int lenght)
{
    int retVal = 0;
    if (inputStr!=NULL&&lenght>0)
    {
        int i , error = 0;
        for (i=0;i<lenght;i++)
        {
            if((isalpha(*(inputStr+i)))== 0 )
            {
                if ((isspace(*(inputStr+i)))== 0 )
                {
                    error = 1;
                    break;
                }
            }
            if (i==0)
            {
                if(isspace(*(inputStr+i)))
                {
                    error = 1;
                    break;
                }
            }
        }
        if (i==lenght&&error==0)
        {
            retVal = 1;
        }
    }
    return retVal;
}
int isInt (char* inputStr , int lenght)
{
    int retVal = 0;
    if (inputStr!=NULL&&lenght>0)
    {
        int i , error = 0;
        for (i=0;i<lenght;i++)
        {
            if ((isdigit(*(inputStr+i)))==0 )
            {
                error = 1;
                break;
            }
        }
        if (i==lenght&&error==0)
        {
            retVal = 1;
        }
    }
    return retVal;
}
