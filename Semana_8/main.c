#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
    char name [50];
    int age ;
    int isEmpty;
}sPerson;
/*
*   hacer:
*   1. funcion cargar enteros
*   2.         mostrar
*   3.         ordenar
*   4.         calcule maximo
*   5.         calcule promedo
*/
int getCharacter (char*);
void printChar(char* character);
int getNum (int* pNum , int min ,int max , char* message , char* errMessage);
int getPerson (sPerson* p_PersonList , int* lenght);
void printOnePerson (sPerson* person);
void printPersonList (sPerson* p_PersonList , int lenght );
void initPersonList (sPerson* p_PersonList , int* lenght);
int main()
{
   // sPerson* p_PersonList ;
   // static int personListElements = 0;
  //  p_PersonList = (sPerson*)malloc(sizeof(sPerson));
   // personListElements ++;
  //  initPersonList(p_PersonList, &personListElements);
  //  printPersonList(p_PersonList,personListElements);
    return 0;
}
void printChar (char* character)
{
    char* pCharacter = character;
    printf("Direccion del puntero %p\n",&pCharacter);
    printf("Direccion de la variable %p\n",character);
    printf("Contenido del puntero %p\n\n",pCharacter);
    pCharacter = character;
    printf("Ingrese un caracter: ");
    fflush(stdin);
    scanf("%c",pCharacter);
    printf("\nDireccion del puntero %p\n",&pCharacter);
    printf("Direccion de la variable %p\n",character);
    printf("Contenido del puntero %p\n\n",pCharacter);
}
int getNum (int* pNum , int min ,int max , char* message , char* errMessage)
{
    int itsDone = 0;
    if (pNum!= NULL)
    {
        int auxNum ;
        printf("%s",message);
        fflush(stdin);
        scanf( "%d", &auxNum);
        if (auxNum > max || auxNum < min)
        {
            printf("%s", errMessage);
        }
        else
        {
            *pNum = auxNum;
            itsDone = 1;
        }
    }
        return itsDone;
}
int getName (char* pName , char* message , char* errMessage)
{
    char auxName[51];
    int itsDone = 0;
    int i = 0;
    printf("\n%s", message);
    fflush(stdin);
    gets(auxName);
    while(isName(auxName,51)==0)
    {
        if (i > 5)
        {
            break;
        }
        printf("\n%s",errMessage );
        fflush(stdin);
        gets(auxName);
        i++;
    }
    if (isName(auxName)==1)
    {
        pName = (char*)malloc(sizeof(char)*(strlen(auxName)));
        if (pName != NULL)
        {
            strcpy(pName,auxName);
            itsDone = 1;
        }
    }
    return itsDone;
}
int isName (char* inputData , int lenght )
{
    int isValid = 0;
    int i;
    if (inputData != NULL)
    {
        for (i = 0; i < lenght; i++)
        {
            if ( isalpha(inputData[i])== 0 )
            {
                if (inputData[i] != ' ')
                {
                    if ( inputData[i] == '\0' && i > 2 )
                    {
                        isValid = 1;
                        break;
                    }
                }
            }
        }
    }
    return isValid;
}
int getPerson (sPerson* p_PersonList , int* lenght)
{
    sPerson auxPerson;
    printf("\nIngrese el nombre: ");
    fflush(stdin);
    gets(auxPerson.name);
    printf("\nIngrese la edad: ");
    fflush(stdin);
    scanf("%d" , &auxPerson.age );
    auxPerson.isEmpty=0;
    return 0;
}
int getNewSpace (sPerson* p_PersonList , int lenght )
{
    return 0;
}
void printPersonList (sPerson* p_PersonList , int lenght )
{
    int i;
    for (i = 0 ; i < lenght ; i++ )
    {
        printOnePerson(p_PersonList+i);
    }
}
void printOnePerson (sPerson* pPerson)
{
    if (pPerson != NULL)
    {
        if (pPerson->isEmpty == 0)
        {
            printf("\nNombre: %s", pPerson->name);
            printf("\nedad: %d\n", pPerson->age);
        }
    }

}
/*int storeOnePerson (sPerson* p_PersonList)
{
    int itsDone = 0;
    if (p_PersonList != NULL)
    {
        sPerson auxPerson;
        auxPerson = getPerson();
        p_PersonList = (sPerson*)realloc(p_PersonList, sizeof(sPerson));
        int i , j;
        i = (sizeof(p_PersonList))/(sizeof(sPerson));
        for ( j = 0 ; j < i ; j++ )
        {
            if ( )
            {
                p_PersonList[j] = auxPerson;
                itsDone = 1;
                break;
            }
        }
    }
    return itsDone;
}*/
void initPersonList (sPerson* p_PersonList , int* lenght)
{
    int i;
    char names [10] [20] = {"0001", "0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009" , "0010"};
    int ages [10] = {10 , 20 ,30,40,50,60,70,80,90,100};
    if (p_PersonList != NULL )
    {
        sPerson* auxPointer;
        for ( i = 0 ; i < 10 ; i++ )
        {
            auxPointer = (sPerson*)realloc(p_PersonList, (sizeof(sPerson)) * (*lenght+1) );
            *lenght += 1;
            if ( auxPointer != p_PersonList && auxPointer != NULL)
            {
                p_PersonList = auxPointer;
            }
            (p_PersonList+i) ->age = ages[i];
            strcpy((p_PersonList+i) ->name,names[i]);
            (p_PersonList+i) ->isEmpty = 0;
        }

    }

}

