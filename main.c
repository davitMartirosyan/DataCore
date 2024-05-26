#include "includes.h"

int main(int ac, char **av, char **envp)
{
    printf("Welcome to the DataCore\n");
	(void)ac;
	(void)av;
	(void)envp;
    table_t *table = dc_init(__DATABASE__);
	while (1)
	{
		char *q = readline("$Orion: ");
		if (!q)
			break;
		Orion *query = dc_query(table, q);
		free(q);
	}
	// char *res = result("fname", (string_t*)query->s_type);
	// Orion* q1 = dc_query(table, "CREATE users {     char fname char lname } >");
	// Orion* q2 = dc_query(table, "UPDATE users {fname, lname} {Davit, Martirosyan}");
	// Orion* q2 = dc_query(table, "UPDATE users {fname, lname} {Davit, Martirosyan} of <id:1>");
	dc_cleanup(&table);
}



