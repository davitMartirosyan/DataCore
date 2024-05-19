#include "includes.h"
extern int erno;

void    free_tokens(query_t **qtok)
{
    querytok_t *current = ((*qtok)->tokens);
    querytok_t *next_node = NULL;

    while (current != NULL)
    {
        next_node = current->next;
        free(current->lexeme); // Free the duplicated string
        free(current);        // Free the node itself
        current = next_node;
    }
}

Orion   *dc_query(table_t *table, char *query)
{
    if (!query)
        return (NULL);
    query_t *q = lexer(query);
    if (q)
    {
        print_tokens(q->tokens);
        free_tokens(&q);
        free(q);
        q = NULL;
    }
    // system("leaks datacore");
    return (NULL);
}
