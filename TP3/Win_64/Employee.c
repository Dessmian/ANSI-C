#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"
/* Los setter deben contener validaciones
    -pido memoria
    -cargo campos
    -si hay error libero memoria
    */
Employee* employee_new()
{
    int tries = 0;
    Employee* retEmp = NULL;
    do
    {
        retEmp =(Employee*) malloc(sizeof(Employee));
        tries++;
    }while (retEmp==NULL&&tries<10);
    return retEmp;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* new_employee = NULL;
    if (idStr!=NULL&&nombreStr!=NULL&&horasTrabajadasStr!=NULL&&sueldoStr!=NULL)
    {
        int idOk = 0 , nombreOK = 0 , horasOK = 0 , sueldoOK = 0;
        new_employee = employee_new();
        if (new_employee!=NULL)
        {
            if (isInt(idStr,strlen(idStr)))
            {
                int auxID = atoi(idStr);
                idOk = employee_setId(new_employee,auxID);
            }
            if (isName(nombreStr,strlen(nombreStr)))
            {
                strcpy(new_employee->nombre,nombreStr);
                nombreOK = 1;
            }
            if (isInt(horasTrabajadasStr,strlen(horasTrabajadasStr)))
            {
                int auxHoras = atoi(horasTrabajadasStr);
                horasOK = employee_setHorasTrabajadas(new_employee,auxHoras);
            }
            if (isInt(sueldoStr,strlen(sueldoStr)))
            {
                int auxSueldo = atoi(sueldoStr);
                sueldoOK = employee_setSueldo(new_employee,auxSueldo);
            }
        }
        if (idOk==0 || nombreOK == 0 || horasOK == 0 || sueldoOK == 0)
        {
            free(new_employee);
            new_employee = NULL;
        }
    }
    return new_employee;
}
void employee_delete(Employee* ptrEmp)
{
    if (ptrEmp!=NULL)
    {
        free(ptrEmp);
    }
}

int employee_setId(Employee* ptrEmp,int id)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (id>0)
        {
            ptrEmp->id = id;
            retVal = 1;
        }
    }
    return retVal;
}
int employee_getId(Employee* ptrEmp,int* id)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&id!=NULL)
    {
        *id = ptrEmp->id;
        retVal = 1;
    }
    return retVal;
}

int employee_setNombre(Employee* ptrEmp,char* nombre)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&nombre!=NULL)
    {
        if (isName(nombre,strlen(nombre)))
        {
            strcpy(&(ptrEmp->nombre),nombre);
            retVal = 1;
        }
    }
    return retVal;
}
int employee_getNombre(Employee* ptrEmp,char* nombre)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,ptrEmp->nombre);
        retVal = 1;
    }
    return retVal;
}

int employee_setHorasTrabajadas(Employee* ptrEmp,int horasTrabajadas)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (horasTrabajadas>0)
        {
            ptrEmp->horasTrabajadas = horasTrabajadas;
            retVal = 1;
        }
    }
    return retVal;
}
int employee_getHorasTrabajadas(Employee* ptrEmp,int* horasTrabajadas)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas = ptrEmp->horasTrabajadas;
        retVal = 1;
    }
    return retVal;
}

int employee_setSueldo(Employee* ptrEmp,int sueldo)
{
    int retVal = 0;
    if (ptrEmp!=NULL)
    {
        if (sueldo>0)
        {
            ptrEmp->sueldo = sueldo;
            retVal = 1;
        }
    }
    return retVal;
}
int employee_getSueldo(Employee* ptrEmp,int* sueldo)
{
    int retVal = 0;
    if (ptrEmp!=NULL&&sueldo!=NULL)
    {
        *sueldo = ptrEmp->sueldo;
    }
    return retVal;
}
void printEmpHeader ()
{
    printf("\n ID  |  Nombre\t\t\t| Horas Trabajadas | Sueldo\n");
}
void printOneEmployee (Employee* ptrEmp)
{
    if (ptrEmp!=NULL)
    {
        printf(" %d  | %s\t| %d\t| %d\n",ptrEmp->id,ptrEmp->nombre,ptrEmp->horasTrabajadas,ptrEmp->sueldo);
    }
}
int getEmployeeIndexByParam (char* paramValue,int field,Employee* ptrEmp)
{
    int retVal = 0;
    if (paramValue!=NULL&&ptrEmp!=NULL)
    {

    }
    return retVal;
}
