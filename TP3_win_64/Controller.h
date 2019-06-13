int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_askfor_name(char* retName);
int controller_askfor_hours(int* retHours);
int controller_askfor_salary(int* retSalary);
int controller_askfor_ID(int* retID);
int controller_askfor_unsignedInt(char* message, int* retInt);

int controller_compare_ID(LinkedList* pArrayListEmployee, int IDentification);

int controller_getEmployee (LinkedList* pArrayListEmployee);
void getOption(int* option);
