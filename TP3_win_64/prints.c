#include <stdlib.h>
#include <stdio.h>
#include "prints.h"
void pause(void)
{
    system("pause");
}
void newLine(void)
{
    printf("\n");
}
void goodbye(void)
{
    printf("Adios.");
}
void print_employee_modificationMenu(void)
{
    printf("MODIFICA EMLPLEADOS\n\n");
    printf("1. Buscar por ID.\n");
    printf("2. Listar Empleados.\n");
    printf("3. Salir.\n");
}
void print_employee_deleteMenu(void)
{
    printf("MODIFICA EMLPLEADOS\n\n");
    printf("1. Buscar por ID.\n");
    printf("2. Listar Empleados.\n");
    printf("3. Salir.\n");
}
void print_confirm(char* string)
{
    printf("Esta seguo que desea %s?\n",string);
    printf("1.Si");
    printf("2.No");
}
void print_employee_AddMenu(void)
{
    printf("1. Modificar ID.\n");
    printf("2. Modificar Nombre.\n");
    printf("3. Modificar Horas.\n");
    printf("4. Modificar Salario\n");
    printf("5. Guardar Cambios.\n");
    printf("6. Salir.\n");
}
void print_main_MENU(void)
{
    printf("MENU PRINCIPAL\n\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf(" 3. Alta de empleado.\n");
    printf(" 4. Modificar datos de empleado.\n");
    printf(" 5. Baja de empleado.\n");
    printf(" 6. Listar empleados.\n");
    printf(" 7. Ordenar empleados.\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir.");
}
void print_error_invalidData(char* this)
{
    clearScreen();
    printf("Hubo un error al ingresar %s. Datos invalidos ingresados.\nIntente mas tarde.\n",this);
    pause();
}
void print_invalidOption(void)
{
    printf("\nOpcion invalida. ");
}
void clearScreen(void)
{
    system("cls");
}
void print_loaded(void)
{
    newLine();
    printf("Datos cargados exitosamente...");
    newLine();
    pause();
}
