#include "includes.h"
extern int dc_errno;
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
	dc_errno = 0;
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

void dc_cleanup(table_t **table)
{
    if (!*table)
        return ;
    // fclose(table->db);
    // close(table->fd);
    free((*table)->dbase_name);
    free((*table)->meta_dbase_name);
    free((*table)->metainfo); 
    __destruct(table);
}

void _dealloc(garbage_collector_t *space)
{
	free_fields(space->list);
}