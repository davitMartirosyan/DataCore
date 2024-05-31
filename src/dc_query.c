#include "includes.h"
extern int erno;

Orion   *dc_query(table_t *table, char *query)
{
    query_t *q = NULL;
    Orion   *result = NULL;
    if (!query)
        return (NULL);
    q = lexer(query);
    if (!q)
        return (NULL);
    // print_tokens(q->tokens);
    if (pexec(table, &q) == INVALID)
	{
		printf("invalid query\n");
        clean_space(&q);
        return (NULL);
    }
	clean_space(&q);
    // system("leaks datacore");
    return (result);
}
