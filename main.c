#include "./includes/includes.h"
extern const char  * const sys_siglist[];

int main(int ac, char **av, char **envp)
{
    printf("Welcome to the DataCore\n");
	(void)ac;
	(void)av;
	(void)envp;
    table_t *table = dc_init(__DATABASE__);
	while (1)
	{
		char *orion = readline("$orion: ");
		// Orion *create = dc_query(table, "CREATE users    {                 char fname    , char lname           , int         :      age              } id:1");
		// Orion *add    = dc_query(table, "ADD TO users{    fname, age, lname    }    {   Davit, 25, Martirosyan            }    ");
		// Orion *ret    = dc_query(table, "RETREIVE FROM users {fname, lname} OF id:1");
		Orion *upd    = dc_query(table, orion);
		"UPDATE IN users {fname}  {Davo} OF id:1";
		// Orion *del    = dc_query(table, "DELETE FROM users id:1");
		// Orion *lst    = dc_query(table, "LIST users");
		// Orion *srt    = dc_query(table, "SORT users BY fname"); /// ??????????????????????
	}
	dc_cleanup(table);
}
