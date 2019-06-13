#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - cantidad de elementos leidos exitosamente
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        char buffer [4][128];
        fscanf(pFile,"%[^;];%[^;];%[^;];%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        while (!feof(pFile))
        {
            Employee* new_employee;
            fscanf(pFile,"%[^;];%[^;];%[^;];%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);// "%[^,],%[^,],%[^,],%[^\n]\n"
            new_employee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if (new_employee!=NULL)
            {
                ll_add(pArrayListEmployee,new_employee);
                retVal++;
            }
        }
    }
    return retVal;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  retVal - Cantidad de elementos leidos exitosamente
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        Employee empBuffer;
        Employee* new_employee;
        while (!(feof(pFile)))
        {
            empBuffer.id = -1;  //invalida el buffer para evitar cargas repetidas al final del archivo
            fread(&(empBuffer.id),sizeof(int),1,pFile);
            fread(empBuffer.nombre,sizeof(char),128,pFile);
            fread(&(empBuffer.horasTrabajadas),sizeof(int),1,pFile);
            fread(&(empBuffer.sueldo),sizeof(int),1,pFile);
            new_employee = employee_newParametrosBinarios(&empBuffer);
            if (new_employee!=NULL)
            {
                ll_add(pArrayListEmployee,new_employee);
                retVal++;
            }
        }
    }
    return retVal;
}
int parser_EmployeeListToText (FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        int i , lenght , elementsWriten , employeesWriten = 0, error = 0;
        Employee* auxEmp;
        lenght = ll_len(pArrayListEmployee);
        fprintf(pFile,"Identification;Nombre;Horas Trabajadas;Sueldo\n");
        for (i=0;i<lenght;i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
            if (auxEmp==NULL)
            {
                error = 1;
                break;
            }
            else
            {
                elementsWriten = fprintf(pFile,"%d;%s;%d;%d\n",auxEmp->id,
                                                               auxEmp->nombre,
                                                               auxEmp->horasTrabajadas,
                                                               auxEmp->sueldo);
                employeesWriten++;
                if (elementsWriten<4)
                {
                    error = 1;
                    break;
                }
            }
        }
        if (i==lenght&&error==0)
        {
            retVal = employeesWriten;
        }
    }
    return retVal;
}
int parser_EmployeeListToBinary (FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        int listLen;
        listLen = ll_len(pArrayListEmployee);
        if (listLen > 0 )
        {
            int IDwritten , nameWritten , hoursWritten , salaryWritten , i , error = 0;
            Employee* empBuffer;
            //char header [4][30] = {"Identification","Nombre","HorasTrabajadas","Salario"};
            for (i=0;i<listLen;i++)
            {
                empBuffer = ll_get(pArrayListEmployee,i);
                if (empBuffer!=NULL)
                {
                    IDwritten = fwrite(&(empBuffer->id),sizeof(int),1,pFile);
                    nameWritten = fwrite(empBuffer->nombre,sizeof(char),128,pFile);
                    hoursWritten = fwrite(&(empBuffer->horasTrabajadas),sizeof(int),1,pFile);
                    salaryWritten = fwrite(&(empBuffer->sueldo),sizeof(int),1,pFile);
                    if (IDwritten!=1||nameWritten!=128||hoursWritten!=1||salaryWritten!=1)
                    {
                        error = 1;
                        break;
                    }
                }
            }
            if (i==listLen&&error==0)
            {
                retVal = listLen;
            }
        }

    }
    return retVal;
}





























