int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_askfor_name(void* ptrEmployee);
int controller_askfor_hours(void* ptrEmployee);
int controller_askfor_salary(void* ptrEmployee);
int controller_askfor_ID(void* ptrEmployee);
int controller_askfor_unsignedInt(char* message);

int controller_compare_ID(LinkedList* pArrayListEmployee, int IDentification);

int controller_getEmployee (LinkedList* pArrayListEmployee);
void getOption(int* option);

int controller_switch(int indexOne, int indexTwo);
int getOrder(int* retOrder);
int controller_sortByParam (LinkedList* pArrayListEmployee,int (*pFunc)(void* ,void*), int order);
