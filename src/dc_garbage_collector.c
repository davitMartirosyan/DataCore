#include "includes.h"

void free_fields(char **fields)
{
	int	i;

	i = 0;
	while (fields[i])
	{
		free(fields[i]);
		i++;
	}
	free(fields);
}

void clean_space(query_t **tok)
{
	(*tok)->size = 0;
	(*tok)->cap = 0;
	(*tok)->maxexp = 0;
	(*tok)->ident_count = 0;
	(*tok)->expression_count = 0;
	(*tok)->expansion_count = 0;
	(*tok)->expansion_key_count = 0;
	(*tok)->expansion_value_count = 0;
	(*tok)->is_inside = false;
	free_tokens(tok);
	free(*tok);
	*tok = NULL;
}

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

void _init_query(void **initializer_list)
{
	((query_t*)(*initializer_list))->is_inside = false;
	((query_t*)(*initializer_list))->size = 0;
	((query_t*)(*initializer_list))->cap = 0;
	((query_t*)(*initializer_list))->expression_count = 0;
	((query_t*)(*initializer_list))->expansion_count = 0;
	((query_t*)(*initializer_list))->ident_count = 0;
	((query_t*)(*initializer_list))->cmd = NULL;
	((query_t*)(*initializer_list))->tokens = NULL;
	((query_t*)(*initializer_list))->cols = NULL;
}
