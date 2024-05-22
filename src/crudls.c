#include "includes.h"

f_ret	dc_create(table_t *table, query_t **query_list)
{
	char **expansion_lexemes = NULL;
	int size = 0;

	if((*query_list)->expression_count != 3 || (*query_list)->expansion_count != 1)
		return (FAILURE);
	querytok_t *qlist = (*query_list)->tokens;
	while (qlist)
	{
		if (qlist->type == EXPANSION_FIELD)
			break;
		qlist = qlist->next;
	}
	
	expansion_lexemes = ft_split(qlist->lexeme, ',', &size);
	if (check_fields(expansion_lexemes, size))
	{
		printf("Expansion error\n");
		free_fields(&expansion_lexemes);
		return (-1);
	}

	// print_tokens((*query_list)->tokens);
	return (0);
}

f_ret	dc_add(table_t *table, query_t **query_list)
{
	return (FAILURE);
}

f_ret	dc_retrieve(table_t *table, query_t **query_list)
{
	return (FAILURE);
}

f_ret	dc_update(table_t *table, query_t **query_list)
{
	return (FAILURE);
}

f_ret	dc_delete(table_t *table, query_t **query_list)
{
	return (FAILURE);
}

f_ret	dc_list(table_t *table, query_t **query_list)
{
	return (FAILURE);
}

f_ret	dc_sort(table_t *table, query_t **query_list)
{
	return (FAILURE);
}


// f_ret	is_compatible(query_t *query_list)
// {
	
// }