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
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        while (!feof(pFile))
        {
            Employee* new_employee;
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            new_employee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
            if (new_employee!=NULL)
            {
                ll_add(pArrayListEmployee,new_employee);
                retVal++;
            }
        }
    }
    return retVal;  // "%[^,],%[^,],%[^,],%[^\n]\n"
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
int parser_EmployeeListToText (FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        int i , lenght , elementsWriten , error = 0;
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
                elementsWriten = fprintf(pFile,"%d;%s;%d;%d\n",auxEmp->id,auxEmp->nombre,auxEmp->horasTrabajadas,auxEmp->sueldo);
                if (elementsWriten<4)
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
