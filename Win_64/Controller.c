#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (path!=NULL&&pArrayListEmployee!=NULL)
    {
        FILE* pFile = (FILE*)malloc(sizeof(FILE*));
        if (pFile!=NULL)
        {
            pFile = fopen(path,"r");
            retVal = parser_EmployeeFromText(pFile,pArrayListEmployee);
            fclose(pFile);
        }
    }
    return retVal;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pArrayListEmployee!=NULL)
    {
        system("cls");

    }
    return retVal;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pArrayListEmployee!=NULL)
    {
        int i , lenght;
        lenght = ll_len(pArrayListEmployee);
        if (lenght>0)
        {
            Employee* auxPtr;
            printEmployeeHeader();
            for (i=0;i<lenght;i++)
            {
                auxPtr = (Employee*)ll_get(pArrayListEmployee,i);
                printOneEmployee(auxPtr);
            }
            retVal = 1;
        }
    }
    return retVal;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (path!=NULL&&pArrayListEmployee!=NULL)
    {
        FILE* pFile = (FILE*)malloc(sizeof(FILE*));
        if (pFile!=NULL)
        {
            pFile = fopen(path,"w");
            retVal = parser_employeeListToText(pFile,pArrayListEmployee);
            fclose(pFile);
            retVal = 1;
        }
    }
    return retVal;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

