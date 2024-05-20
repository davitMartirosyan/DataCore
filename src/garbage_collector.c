#include "includes.h"

void free_fields(char ***fields)
{
	char **field_buffer = *fields;
	int i = 0;
	while (field_buffer[i])
		free(field_buffer[i]);
	free(*fields);
	*fields = NULL;
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