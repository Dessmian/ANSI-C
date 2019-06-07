#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if(pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        int dataRead = 0;
        char id [51];
        char name [128];
        char workedHours [51];
        char salary [51];
        while(!feof(pFile))
        {
            dataRead = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,name,workedHours,salary);
            Employee* emp = employee_newParametros(id,name,workedHours,salary);
            ll_add(pArrayListEmployee,emp);
        }
        if (dataRead > 0)
        {
            retVal = 1;
        }
    }

    return retVal;
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
int parser_employeeListToText (FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        int i , lenght;
        lenght = ll_len(pArrayListEmployee);
        Employee* auxPtr;
        int datosEscritos;
        fprintf(pFile,"ID;Nombre;Horas Trabajadas;Sueldo\n");
        for (i=1;i<lenght;i++)
        {
            auxPtr = (Employee*) ll_get(pArrayListEmployee,i);
            if (auxPtr!=NULL)
            {

                //datosEscritos = fprintf(pFile,"%d,%s,%d,%d\n",auxPtr->id,auxPtr->nombre,auxPtr->horasTrabajadas,auxPtr->sueldo);
                //printf("%d\n",datosEscritos);
                fwrite(&(auxPtr->id),1,sizeof(int),pFile );
                fwrite(&(auxPtr->nombre),strlen(auxPtr->nombre),sizeof(char),pFile );//itoa(auxPtr->id),itoa(auxPtr->nombre),itoa(auxPtr->horasTrabajadas),itoa(auxPtr->sueldo)
                fwrite(&(auxPtr->horasTrabajadas),1,sizeof(int),pFile );
                fwrite(&(auxPtr->sueldo),1,sizeof(int),pFile );
            }
        }
        /*if (datosEscritos>0)
        {
            retVal = 1;
        }*/
    }
    return retVal;
}
