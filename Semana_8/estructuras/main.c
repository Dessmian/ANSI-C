#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name [51];
    int ID;
    float salary;
} sEmployee;
sEmployee* builder_Employee ();
sEmployee* builder_EmployeeParameters(int,char*,float);
void printOneEmployee (sEmployee*);
int set_EmployeeName(sEmployee* , char*);
int set_EmployeeSalary(sEmployee* , float);
int set_EmployeeID (sEmployee* , int);
int get_EmployeeName(sEmployee* , char*);
int get_EmployeeSalary(sEmployee* , float);
int get_EmployeeID (sEmployee* , int);
void free_Employee (sEmployee*);

int main()
{

    return 0;
}
sEmployee* builder_Employee ()
{
    sEmployee* anEmployee;
}
