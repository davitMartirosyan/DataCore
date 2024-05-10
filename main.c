#include "./includes/includes.h"

int main(int ac, char **av, char **envp)
{
    printf("Welcome to the DataCore\n");
	(void)ac;
	(void)av;
	(void)envp;
    table_t *table = dc_init(__DATABASE__);

	dc_query(table, "ADD INTO db {fname:lname:age:grade:faculty} {Davit:Martirosyan:25:100:civil defense}");


	dc_cleanup(table);
}
