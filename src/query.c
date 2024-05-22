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
    if (!parse_request(table, &q) < 0)
    {
        clean_space(&q);
        return (NULL);
    }
    return (result);
}
