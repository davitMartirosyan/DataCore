#include "includes.h"
extern int erno;

Orion   *dc_query(table_t *table, char *query)
{
    if (!query)
        return (NULL);
    query_t *q = lexer(query);
    if (q)
    {
        // printf("****\n");
        // print_tokens(q->tokens);
        free_tokens(&q);
        free(q);
        q = NULL;
    }
    // system("leaks datacore");
    return (NULL);
}
