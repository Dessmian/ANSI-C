#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "validations.h"
#include "prints.h"

void getOption(int* option)
{
    if (option!=NULL)
    {
        fflush(stdin);
        scanf("%d",option);
    }
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int - cantidad de datos leidos
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (path!=NULL&&pArrayListEmployee!=NULL)
    {
        FILE* pFile = NULL;
        pFile = fopen(path,"r");
        if (pFile!=NULL)
        {
            retVal = parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
        fclose(pFile);
        print_loaded();
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
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retVal;
    if (path!=NULL&&pArrayListEmployee!=NULL)
    {
        FILE* pFile = NULL;
        pFile = fopen(path,"rb");
        if (pFile!=NULL)
        {
            retVal = parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        }
        fclose(pFile);
    }
    return retVal;
}

/** \brief Alta de empleados
 *
 * \param pArraylistEmployee LinkedList* - lista de empleados
 * \return int - 0 si no se pudo cargar - 1 si se pudo
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pArrayListEmployee!=NULL)
    {
        int idOK, nameOK, hoursOK, salaryOK;
        int* auxID = (int*)malloc(sizeof(int));
        int *
        int auxHours = 0, auxSalary = 0;
        char* auxName = (char*)malloc( (sizeof(char))*128 );
        if (auxName!=NULL)
        {
            switch(1)
            {

            case 1:
                system("cls");
                printf("ALTA EMPLEADOS\n\n");
                idOK = controller_askfor_ID(&auxID);
                if (idOK==1)
                {
                    int tries = 0;
                    int sugestion = employee_getNewID(pArrayListEmployee);
                    do
                    {
                        idOK = controller_compare_ID(pArrayListEmployee,auxID);
                        switch (idOK)
                        {

                        case 0:
                            idOK = 1;
                            break;
                        case 1:

                            if (sugestion != (-1) )
                            {
                                printf("\nEl id ingresado ya esta en uso. ID sugerido: %d",sugestion);
                                idOK = controller_askfor_ID(&auxID);
                            }
                            break;
                        }
                    }while (idOK == 1 || tries > 4);
                }
                else
                {
                    clearScreen();
                    printf("Hubo un error al ingresar el ID. Datos invalidos ingresados.\nIntente mas tarde.\n");
                    pause();
                    break;
                }
                nameOK = controller_askfor_name(auxName);
                if (nameOK==0)
                {
                    clearScreen();
                    printf("Hubo un error al ingresar el nombre. Datos invalidos ingresados.\nIntente mas tarde.\n");
                    pause();
                    break;
                }
                hoursOK = controller_askfor_hours(&auxHours);
                if (hoursOK==0)
                {
                    clearScreen();
                    printf("Hubo un error al ingresar las horas. Datos invalidos ingresados.\nIntente mas tarde.\n");
                    pause();
                    break;

                    salaryOK = controller_askfor_salary(&auxSalary);
                    if (salaryOK==0)
                    {
                        clearScreen();
                        printf("Hubo un error al ingresar el salario. Datos invalidos ingresados.\nIntente mas tarde.\n");
                        pause();
                        break;
                    }
                    if (idOK&&nameOK&&hoursOK&&salaryOK)
                    {
                        Employee* employeeNew = employee_newParametrosInt(auxID,auxName,auxHours,auxSalary);
                        if (employeeNew!=NULL)
                        {
                            ll_add(pArrayListEmployee,employeeNew);
                            retVal = 1;
                            free(auxName);
                            printf("\n\nDatos cargados exitosamente.\n");
                            pause();
                        }
                    }
                }
            }


        }
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
    int retVal = 0;
    if (pArrayListEmployee!=NULL)
    {
        int option = 0 , index = 0, tries;
        while (option!=3)
        {
            clearScreen();
            print_employee_AddMenu();
            fflush(stdin);
            getOption(&option);
            switch (option)
            {
            case 1:
                tries = 0;
                index = controller_getEmployee(pArrayListEmployee);
                while (index<1&&tries<4)
                {
                    tries++;
                    index = controller_getEmployee(pArrayListEmployee);
                }
                if (index>0)
                {
                    Employee* ptrBufferEmployee;
                    ptrBufferEmployee = (Employee*)ll_get(pArrayListEmployee,index);
                    retVal = employee_modify(ptrBufferEmployee,pArrayListEmployee);
                }
                break;
            case 2:
                controller_ListEmployee(pArrayListEmployee);
                newLine();
                pause();
                break;
            default:
                print_invalidOption();
                newLine();
                pause();
                break;
            }
        }

    }
    return retVal;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* - lista empleados
 * \return int - cantidad de empleados eliminados
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pArrayListEmployee!=NULL)
    {
        int index , option = 0 , tries;
        while (option!=3)
        {
            clearScreen();
            print_employee_deleteMenu();
            fflush(stdin);
            getOption(&option);
            switch (option)
            {
            case 1:
                tries = 0;
                index = controller_getEmployee(pArrayListEmployee);
                while (index<1&&tries<4)
                {
                    tries++;
                    index = controller_getEmployee(pArrayListEmployee);
                }
                if (index>0)
                {
                    Employee* bufferEmployee;
                    bufferEmployee = (Employee*)ll_get(pArrayListEmployee,index);
                    if (bufferEmployee!=NULL)
                    {
                        int  confirm = 0;
                        newLine();
                        printOneEmployee(bufferEmployee);
                        print_confirm("borrar este empleado");
                        getOption(&confirm);
                        if (confirm==1)
                        {
                            ll_remove(pArrayListEmployee,index);
                            retVal++;
                            printf("\nDatos eliminados.");
                            pause();
                        }
                        else
                        {
                            printf("\nRetornando al menu previo...");
                            pause();
                        }
                    }
                }
                break;
            case 2:
                controller_ListEmployee(pArrayListEmployee);
                newLine();
                pause();
                break;
            case 3:
                break;
            default:
                print_invalidOption();
                break;
            }
        }
    }
    return retVal;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* - lista empleados
 * \return int - 1 si la lista es valida - 0 si la lista no es valida
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pArrayListEmployee!=NULL)
    {
        int lenght = ll_len(pArrayListEmployee);
        if (lenght>0)
        {
            int i;
            Employee* auxEmp = NULL;
            printEmpHeader();
            for (i=0 ; i<lenght ; i++)
            {
                auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
                printOneEmployee(auxEmp);
            }
            if (i==lenght)
            {
                retVal = 1;
            }
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
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (path!=NULL&&pArrayListEmployee!=NULL)
    {
        FILE* pFile = NULL;
        pFile = fopen(path,"w");
        if (pFile!=NULL)
        {
            parser_EmployeeListToText(pFile,pArrayListEmployee);
        }
        fclose(pFile);
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
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (path!=NULL&&pArrayListEmployee!=NULL)
    {
        FILE* pFile = NULL;
        pFile = fopen(path,"wb");
        if (pFile!=NULL)
        {
            retVal = parser_EmployeeListToBinary(pFile,pArrayListEmployee);
        }
        fclose(pFile);
    }
    return retVal;
}




/** \brief pide nombre y lo verifica
 *
 * \param retName char* -  el nombre ingresado
 * \return int - 1 si lo pudo verificar y cargar - 0 si no pudo
 *
 */
int controller_askfor_name(char* retName)
{
    int retVal = 0;
    if (retName!=NULL)
    {
        char* auxStr = NULL;
        auxStr = (char*)malloc((sizeof(char)) * 128);
        if (auxStr!=NULL)
        {
            int isValid, counter = 0;
            printf("\nIngrese nombre: ");
            fflush(stdin);
            fgets(auxStr,127,stdin);
            isValid = isName(auxStr,strlen(auxStr));
            while (isValid==0 && counter<5)
            {
                printf("\nHubo un error, vuelva a intentar. Ingrese nombre: ");
                fflush(stdin);
                fgets(auxStr,127,stdin);
                isValid = isName(auxStr,strlen(auxStr));
                counter++;
            }
            if (isValid==1)
            {
               // if ( (sizeof(retName)) >= ( (strlen(auxStr)) * (sizeof(char)) ) )
               // {
                    strcpy(retName,auxStr);
                    retVal = 1;
               // }
                //else
               // {
                //    char* auxPtr;
                 //   auxPtr = (char*)realloc(retName, ( (sizeof(char)) * ((strlen(auxStr))+2) ) );
                 //   if (auxPtr!=NULL && auxPtr!=retName)
                 //   {
                   //     retName = auxPtr;
                   //     strcpy(retName,auxStr);
                   //     retVal = 1;
                  //  }
                //}

            }
        }
        free(auxStr);
    }
    return retVal;
}
/** \brief pide horas y verifica que sea un numero positivo
 *
 * \param retHours int* - las horas ingresadas
 * \return int - 1 si lo pudo cargar - 0 si no pudo
 *
 */
int controller_askfor_hours(int* retHours)
{
    int retVal = 0;
    if (retHours!=NULL)
    {
        retVal = controller_askfor_unsignedInt("Ingrese horas: ",retHours);
    }
    return retVal;
}
/** \brief pide salario y verifica que sea un numero positivo
 *
 * \param retSalary int* - el salario ingresado
 * \return int - 1 si lo pudo cargar - 0 si no pudo
 *
 */
int controller_askfor_salary(int* retSalary)
{
    int retVal = 0;
    if (retSalary!=NULL)
    {
        retVal = controller_askfor_unsignedInt("Ingrese salario: ",retSalary);
    }
    return retVal;
}
/** \brief pide id y verifica que sea un numero positivo (no verifica repeticion)
 *
 * \param retID int* - el id ingresado
 * \return int - 1 si lo pudo cargar - 0 si no pudo
 *
 */
int controller_askfor_ID(int* retID)
{
    int retVal = 0;
    if (retID!=NULL)
    {
        retVal = controller_askfor_unsignedInt("Ingrese ID: ",retID);
    }
    return retVal;
}
/** \brief imprime un mensaje y guarda un numero entero positivo
 *
 * \param message char* - el mensaje a imprimir
 * \param retInt int* - el numero ingresado
 * \return int - 1 si lo pudo cargar - 0 si no pudo
 *
 */
int controller_askfor_unsignedInt(char* message, int* retInt)
{
    int retVal = 0;
    if (message!=NULL&&retInt!=NULL)
    {
        int auxInt = -1, counter = 0;
        printf("\n%s",message);
        fflush(stdin);
        scanf("%d",&auxInt);
        while ( auxInt < 0 && counter < 5 )
        {
            counter++;
            printf("\n\nHubo un error, vuelva a intentar. %s",message);
            fflush(stdin);
            scanf("%d",&auxInt);
        }
        if (auxInt>0)
        {
            *retInt = auxInt;
            retVal = 1;
        }
    }
    return retVal;
}
/** \brief recorre una lista de empleados y verifica si el id pasado ya existe
 *
 * \param pArrayListEmployee LinkedList* - lista empleados
 * \param IDentification int - ID a verificar
 * \return int - -1 si el puntero es nulo o el id negativo - 0 si no existe - 1 si existe
 *
 */
int controller_compare_ID(LinkedList* pArrayListEmployee, int IDentification)
{
    int retVal = -1;
    if (pArrayListEmployee!=NULL&&IDentification>0)
    {
        int lengh;
        lengh = ll_len(pArrayListEmployee);
        if (lengh>0)
        {
            int i;
            Employee* auxEmp = NULL;
            for (i=0; i<lengh; i++)
            {
                auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
                if (auxEmp!=NULL)
                {
                    if ( (auxEmp->id) == IDentification)
                    {
                        retVal = 1;
                        break;
                    }
                }
            }
            if (i==lengh&&retVal!=1)
            {
                retVal = 0;
            }
        }
    }
    return retVal;
}
int controller_getEmployee (LinkedList* pArrayListEmployee)
{
    int retVal = 0;
    if (pArrayListEmployee!=NULL)
    {
        int i , lenght , auxID = 0;
        Employee* auxPtr = NULL;
        lenght = ll_len(pArrayListEmployee);
        printf("\n\nIngrese el ID del empleado: ");
        fflush(stdin);
        scanf("%d",&auxID);
        for (i=0;i<lenght;i++)
        {
            auxPtr = (Employee*)ll_get(pArrayListEmployee,i);
            if (auxPtr!=NULL)
            {
                if (auxPtr->id==auxID)
                {
                    retVal = i;
                    break;
                }
            }
        }
    }
    return retVal;
}
//int itsReady (void* pArrayListEmployee)













