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
        char auxID [128] , auxNombre [128] , auxHoras [128] , auxSueldo [128];
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxNombre,auxHoras,auxSueldo);
        while (!feof(pFile))
        {
            *auxID = '\0';
            *auxNombre = '\0';
            *auxHoras = '\0';
            *auxSueldo = '\0';
            Employee* new_employee;
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxID,auxNombre,auxHoras,auxSueldo);
            new_employee = employee_newParametros(auxID,auxNombre,auxHoras,auxSueldo);
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
