#include "includes.h"
extern int erno;

Orion   *dc_query(table_t *table, char *query)
{
    query_t *q = NULL;
    Orion   *result = NULL;
    if (!query)
        return (NULL);
    if (!(q = lexer(query)))
        return (NULL);
    if (pexec(table, &q) == INVALID)
	{
		printf("invalid query\n");
        clean_space(&q);
        return (NULL);
    }
	// clean_space(&q);
    return (result);
}
