#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_delete(Employee* ptr);
void employee_init(Employee* ptrEmp);
int Employee_strucToText(Employee* ptrEmp,char* retStr);

int employee_setId(Employee* ptrEmp,int id);
int employee_getId(Employee* ptrEmp,int* id);

int employee_setNombre(Employee* ptrEmp,char* nombre);
int employee_getNombre(Employee* ptrEmp,char* nombre);

int employee_setHorasTrabajadas(Employee* ptrEmp,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* ptrEmp,int* horasTrabajadas);

int employee_setSueldo(Employee* ptrEmp,int sueldo);
int employee_getSueldo(Employee* ptrEmp,int* sueldo);

int employee_generateNewID(int* newID,LinkedList* pArrayListEmployee);
int employee_askForNombre(char* nombre);
int employee_askForHorasTrabajadas(int* horasTrabajadas);
int employee_askForSueldo(int* sueldo);

int employee_getMaxID(LinkedList* pArrayListEmployee);

int isName(char* inputStr , int lenght);
int isNumericUnsigned(char* inputStr,int lenght);

void printEmployeeHeader (void);
void printOneEmployee (Employee* ptrEmp);

#endif // employee_H_INCLUDED
