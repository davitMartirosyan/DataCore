#include "includes.h"

f_ret	dc_create(table_t *table, query_t **query_list)
{
	querytok_t *expand = NULL;
	querytok_t *table_name = NULL;
	f_ret ret_val = 0;
	char **expansion_lexemes = NULL;
	char *meta = NULL;
	int size = 0;

	if ((*query_list)->expression_count != 3 || (*query_list)->expansion_count != 1)
		return (INVALID);
	expand = find((*query_list)->tokens, EXPANSION_FIELD);
	table_name = find((*query_list)->tokens, WORD);
	expansion_lexemes = ft_split(expand->lexeme, ',', &size);
	if (dc_columns(query_list, expansion_lexemes, size) < 0)
		ret_val = INVALID;
	if (dc_create_file(table, __METADATA__, table_name->lexeme, ".meta", 0644) < 0)
		ret_val = INVALID;
	free_fields(expansion_lexemes);
	return (ret_val);
}


querytok_t *find(querytok_t *qlist, type_t type)
{
	while (qlist)
	{
		if (qlist->type == type)
			break;
		qlist = qlist->next;
	}
	return (qlist);
}