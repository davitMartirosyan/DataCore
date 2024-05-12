#include "includes.h"

Orion   *dc_query(table_t *table, char *query)
{
    querytok_t *tokens;
    if (!query)
        return (NULL);

    tokens = lexer(ft_strtrim(ft_strdup(query), " \n\t\r\b"));
    // if (!tokens)
    // {
    //     fprintf(stderr, "Syntax error on line :1:\n");
    //     return (NULL);
    // }
    return (NULL);
}