#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "LinkedList.h"
#include "Employee.h"
Employee* employee_new()
{
    Employee* ptrEmp = (Employee*)malloc(sizeof(Employee));
    employee_init(ptrEmp);
    return ptrEmp;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* ptrEmp = NULL;
    if (idStr!=NULL&&nombreStr!=NULL&&horasTrabajadasStr!=NULL&&sueldoStr!=NULL)
    {
        ptrEmp = employee_new();
        if (ptrEmp!=NULL)
        {
            employee_setId(ptrEmp,atoi(idStr));
            employee_setHorasTrabajadas(ptrEmp,atoi(horasTrabajadasStr));
            employee_setSueldo(ptrEmp,atoi(sueldoStr));
            employee_setNombre(ptrEmp,nombreStr);
        }
   }
    return ptrEmp;
}
int employee_delete(Employee* ptr)
{
    int retVal = 0;
    if (ptr!=NULL)
    {
        free(ptr);
        retVal = 1;
    }
    return retVal;
}
void employee_init (Employee* ptrEmp)
{
    if (ptrEmp!=NULL)
    {
        ptrEmp->horasTrabajadas = 0;
        ptrEmp->id = 0;
        ptrEmp->sueldo = 0;
        strcpy(ptrEmp->nombre,"\0\0");
    }
}
int employee_setId(Employee* ptrEmp,int id)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        ptrEmp->id = id;
        retVal = 1;
    }
    return retVal;
}
int employee_getId(Employee* ptrEmp,int* id)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (id==NULL)
        {
            id = (int*) malloc(sizeof(int));
        }
        if (id!=NULL)
        {
            *id = ptrEmp->id;
            retVal = 1;
        }
    }
    return retVal;
}
int employee_setNombre(Employee* ptrEmp,char* nombre)
{
    int retVal = 0;
    if (ptrEmp!=NULL && nombre!=NULL)
    {
        strcpy(ptrEmp->nombre,nombre);
        retVal = 1;
    }
    return retVal;
}
int employee_getNombre(Employee* ptrEmp,char* nombre)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (nombre==NULL)
        {
            nombre = (char*)malloc((sizeof(char))*(strlen(ptrEmp->nombre)));
        }
        if (nombre!=NULL)
        {
            strcpy(nombre,ptrEmp->nombre);
            retVal = 1;
        }
    }
    return retVal;
}
int employee_setHorasTrabajadas(Employee* ptrEmp,int horasTrabajadas)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        ptrEmp->horasTrabajadas = horasTrabajadas;
        retVal = 1;
    }
    return retVal;
}
int employee_getHorasTrabajadas(Employee* ptrEmp,int* horasTrabajadas)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (horasTrabajadas==NULL)
        {
            horasTrabajadas = (int*) malloc(sizeof(int));
        }
        if (horasTrabajadas!=NULL)
        {
            *horasTrabajadas = ptrEmp->horasTrabajadas;
            retVal = 1;
        }
    }
    return retVal;
}
int employee_setSueldo(Employee* ptrEmp,int sueldo)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        ptrEmp->sueldo = sueldo;
        retVal = 1;
    }
    return retVal;
}
int employee_getSueldo(Employee* ptrEmp,int* sueldo)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (sueldo==NULL)
        {
            sueldo = (int*)malloc(sizeof(int));
        }
        if (sueldo!=NULL)
        {
            *sueldo = ptrEmp->sueldo;
            retVal = 1;
        }
    }
    return retVal;
}
int employee_generateNewID(int* newID,LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pArrayListEmployee!=NULL)
    {
        if (newID==NULL)
        {
            newID = (int*)malloc(sizeof(int));
        }
        if (newID!=NULL)
        {
            int auxID = employee_getMaxID(pArrayListEmployee);
            *newID = auxID+1;
            retVal = 1;
        }
    }
    return retVal;
}
int employee_askForNombre(char* nombre)
{
    int retVal = 0;
    if (nombre==NULL)
    {
        nombre = (char*)malloc(sizeof(char)*128);
    }
    if (nombre!=NULL)
    {
        char auxNombre [128];
        printf("\nIngrese el nombre: ");
        fgets(auxNombre,127,stdin);
        if (isName(auxNombre,strlen(auxNombre)))
        {
            nombre = (char*)realloc(nombre,((strlen(auxNombre))*(sizeof(char))));
            strcpy(nombre,auxNombre);
            retVal = 1;
        }
        else
        {
            int count = 0;
            while (!(isName(auxNombre,strlen(auxNombre))) && count < 5 )
            {
                count +=1;
                printf("\nError, vuelva a intentar. Ingrese el nombre: ");
                fgets(auxNombre,127,stdin);
                if (isName(auxNombre,strlen(auxNombre)))
                {
                    nombre = (char*)realloc(nombre,((strlen(auxNombre))*(sizeof(char))));
                    strcpy(nombre,auxNombre);
                    retVal = 1;
                    break;
                }
            }
        }
    }
    return retVal;
}
int employee_askForHorasTrabajadas(int* horasTrabajadas)
{
    int retVal = 0;
    if (horasTrabajadas==NULL)
    {
        horasTrabajadas = (int*)malloc(sizeof(int));
    }
    if (horasTrabajadas!=NULL)
    {
        char auxStr [12];
        printf("\nIngrese las horas trabajadas: ");
        fgets(auxStr,11,stdin);
        if (isNumericUnsigned(auxStr,strlen(auxStr)))
        {
            int auxInt = atoi(auxStr);
            if (auxInt>0&&auxInt<(pow(2,(sizeof(int)*8)))/2)
            {
                *horasTrabajadas = auxInt;
                retVal = 1;
            }
        }
        else
        {
            int count = 0;
            while(!(isNumericUnsigned(auxStr,strlen(auxStr)))&&count<5)
            {
                count+=1;
                printf("\nError, vuelva a intentar. Ingrese las horas trabajadas: ");
                fgets(auxStr,11,stdin);
                if (isNumericUnsigned(auxStr,strlen(auxStr)))
                {
                    int auxInt = atoi(auxStr);
                    if (auxInt>0&&auxInt<(pow(2,(sizeof(int)*8)))/2)
                    {
                        *horasTrabajadas = auxInt;
                        retVal = 1;
                        break;
                    }
                }
            }
        }
    }
    return retVal;
}
int employee_askForSueldo(int* sueldo)
{
    int retVal = 0;
    if (sueldo==NULL)
    {
        sueldo = (int*)malloc(sizeof(int));
    }
    if (sueldo!=NULL)
    {
        char auxStr [12];
        printf("\nIngrese el sueldo: ");
        fgets(auxStr,11,stdin);
        if (isNumericUnsigned(auxStr,strlen(auxStr)))
        {
            int auxInt = atoi(auxStr);
            if (auxInt>0&&auxInt<(pow(2,(sizeof(int)*8)))/2)
            {
                *sueldo = auxInt;
                retVal = 1;
            }
        }
        else
        {
            int count = 0;
            while(!(isNumericUnsigned(auxStr,strlen(auxStr)))&&count<5)
            {
                count+=1;
                printf("\nError, vuelva a intentar. Ingrese el sueldo: ");
                fgets(auxStr,11,stdin);
                if (isNumericUnsigned(auxStr,strlen(auxStr)))
                {
                    int auxInt = atoi(auxStr);
                    if (auxInt>0&&auxInt<(pow(2,(sizeof(int)*8)))/2)
                    {
                        *sueldo = auxInt;
                        retVal = 1;
                        break;
                    }
                }
            }
        }
    }
    return retVal;
}

int employee_getMaxID(LinkedList* pArrayListEmployee)
{
    int maxID = -1;
    if (pArrayListEmployee!=NULL)
    {
        int lenght = ll_len(pArrayListEmployee);
        int i;
        maxID = 0;
        Employee* auxPtr;
        for (i = 0 ; i < lenght ; i++)
        {
            auxPtr = (Employee*) ll_get(pArrayListEmployee,i);
            if ((auxPtr->id)>maxID)
            {
                maxID = auxPtr->id;
            }
        }
    }
    return maxID;
}
int isName(char* inputStr , int lenght)
{
    int retVal = 0;
    if (inputStr!=NULL&&lenght>3)
    {
        int i;
        for (i=0;i<lenght;i++)
        {
            if (!(isalpha(*(inputStr+i))))
            {
                break;
            }
        }
        if (i==lenght)
        {
            retVal = 1;
        }
    }
    return retVal;
}
int isNumericUnsigned(char* inputStr,int lenght)
{
    int retVal = 0;
    if (inputStr!=NULL)
    {
        if (lenght>0)
        {
            int i;
            for (i=0;i<lenght;i++)
            {
                if(!(isdigit(*(inputStr+i))))
                {
                    break;
                }
            }
            if (i==lenght)
            {
                if(i==1)
                {
                    if(isdigit(*inputStr))
                    {
                        retVal = 1;
                    }
                }
                else
                {
                    retVal = 1;
                }
            }
        }
    }
    return retVal;
}
void printEmployeeHeader (void)
{
    printf("\n   ID   | Nombre\t| Horas Trabajadas | Sueldo \n");
}
void printOneEmployee (Employee* ptrEmp)
{
    if (ptrEmp!=NULL)
    {
        printf(" %d\t\t|  %5s\t\t\t| %d\t\t|  %d  \n",ptrEmp->id,ptrEmp->nombre,ptrEmp->horasTrabajadas,ptrEmp->sueldo);
    }
}
/*int Employee_strucToText(Employee* ptrEmp,char* retStr)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (retStr==NULL)
        {
            retStr = (char*)malloc(sizeof(char));
        }
        if (retStr!=NULL)
        {
            char auxID [21] , auxHoras [21] , auxSueldo[21];

        }
    }
    return retVal;
}*/























































