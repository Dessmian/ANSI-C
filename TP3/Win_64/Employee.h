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
void employee_delete();

int employee_setId(Employee* ptrEmp,int id);
int employee_getId(Employee* ptrEmp,int* id);

int employee_setNombre(Employee* ptrEmp,char* nombre);
int employee_getNombre(Employee* ptrEmp,char* nombre);

int employee_setHorasTrabajadas(Employee* ptrEmp,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* ptrEmp,int* horasTrabajadas);

int employee_setSueldo(Employee* ptrEmp,int sueldo);
int employee_getSueldo(Employee* ptrEmp,int* sueldo);

void printEmpHeader ();
void printOneEmployee (Employee* ptrEmp);

int getEmployeeIndexByParam (char* paramValue,int field,Employee* ptrEmp);


#endif // employee_H_INCLUDED
