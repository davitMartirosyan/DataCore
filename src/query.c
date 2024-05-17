#include "includes.h"
void    free_tokens(query_t **qtok)
{
    querytok_t *current = ((*qtok)->tokens);
    querytok_t *next_node = NULL;

    while (current != NULL)
    {
        next_node = current->next;
        free(current->token); // Free the duplicated string
        free(current);        // Free the node itself
        current = next_node;
    }
    *qtok = NULL;
}

Orion   *dc_query(table_t *table, char *query)
{
    if (!query)
        return (NULL);

    query_t *q = lexer(ft_strtrim(ft_strdup(query), " \n\t\r\b"));
    print_tokens(q->tokens);
    free_tokens(&q);
    return (NULL);
}