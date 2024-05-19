#include "includes.h"

int erno = 0;

query_t *lexer(char *query)
{
	query_t     *tok = NULL;
	int         len = ft_strlen(query);
	int         actual = 0;
	int			i = 0;

	tok = malloc(sizeof(query_t));
	tok->is_inside = false;
	tok->size = 0;
	tok->cap = 0;
	tok->expression_count = 0;
	tok->expansion_count = 0;
	tok->tokens = NULL;

	if (!tok)
		return (NULL);
	while (query && query[i])
	{
		if (query[i] && ft_iswordpart(query[i]) && (int)ft_strlen(query) > i)
		{
			addword(tok, query, &i);
			continue;
		}
		else if (query[i] && query[i] == '{')
		{
			if(expansion(tok, query, &i) != 0)
				return (NULL);
			continue;
		}
		else if (query[i] && query[i] == '<')
		{
			if (identify(tok, query, &i) != 0)
				return (NULL);
			continue;
		}
		else if (query[i] && ft_isspace(query[i]))
		{
			i++; 
			continue;
		}
		else
		{
			printf("Syntax error: unxepected identifier: |%c|\n", query[i]);
			return (NULL);
		}
		i++;
	}
	printf("expressions : %d\n", tok->expression_count);
	printf("expansions  : %d\n", tok->expansion_count);
	printf("exp keys    : %d\n", tok->expansion_key_count);
	printf("exp values  : %d\n", tok->expansion_value_count);
	return(tok);
}

int expansion(query_t *tok, char *query, int*i)
{
	int j;
	int find;
	char *exp;
	char **fields;
	int size;

	j = *i + 1;
	find = ft_find_first_of("}", query+j);
	if (find != STRINGNPOS)
	{
		exp = ft_substr(query, j, find);
		printf("expansion: [%s]\n", exp);
		fields = ft_split(exp, ',', &size);
		free(exp);
		exp = NULL;
		if (checkFields(fields, size) == INVALID)
		{
			printf("Invlaid fields\n");
			return (-1);
		}
		else
		{
			if (tok->expansion_count == 0)
			tok->expansion_key_count = size;
			else
				tok->expansion_value_count = size;
			tok->expression_count++;
			tok->expansion_count++;
		}
		*i += find + 2;
		return (0);
	}
	return (STRINGNPOS);
}

int identify(query_t *tok, char *query, int *i)
{
	int j = *i + 1;
	return (0);
}

void addword(query_t *tok, char *query, int *i)
{
	int wordlen = 0;
	int j = *i;

	while (query[j] && (ft_iswordpart(query[j])))
	{
		j++;
		wordlen++;
	}
	char *wd = ft_substr(query, *i, wordlen);
	printf("Word: |%s|\n", wd);
	append_node(&tok->tokens, wd, WORD);
	free(wd);
	wd = NULL;
	*i += wordlen;
	tok->expression_count++;
}

int checkFields(char **fields, int size)
{
	int i;

	i = -1;
	if (!fields)
		return (INVALID);
	while (fields[++i])
	{
		if (isValid(fields[i]) == INVALID)
			return (INVALID);
	}
	return (0);
}

int isValid(char *field)
{
	int i;
	int size;
	char **pair;

	i = -1;
	pair = ft_split(field, ' ', &size);
	if (size != 2)
		return (INVALID);
	if (ft_strcmp(pair[0], "char") == 0 || ft_strcmp(pair[0], "int") == 0)
	{
		while (pair[1][++i])
			if (!ft_iswordpart(pair[1][i]))
				return (INVALID);
	}
	else
		return (INVALID);
	return (0);
}

int validType(char *type)
{

	return (0);
}