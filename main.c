#include "./includes/includes.h"
int main( void )
{
    printf("Welcome to the DataCore\n");
    table_t *table;
    datacore_init(&table);

    student_t newuser = {0};

//strcpy(newuser.fname, "Davit");
//strcpy(newuser.lname, "Martirosyan");
//strcpy(newuser.faculty, "Civil Defense");

	//datacore_Create(table, &newuser);
	//free(newuser.fname);
	//free(newuser.lname);
	//free(newuser.faculty);
    	//free(table);

	datacore_Retrieve(table, 0, &newuser);
}
