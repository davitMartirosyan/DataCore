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
	tok->ident_count = 0;
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
			if(addExpansion(tok, query, &i, "}", EXPANSION_FIELD) != 0)
			{
				printf(EBADSYNTAX);
				clean_space(&tok);
				return (NULL);
			}
			continue;
		}
		else if (query[i] && query[i] == '<')
		{
			if (addExpansion(tok, query, &i, ">", IDENTIFIER) != 0)
			{
				printf(EBADSYNTAX);
				clean_space(&tok);
				return (NULL);
			}
			continue;
		}
		else if (query[i] && ft_isspace(query[i]))
		{
			i++; 
			continue;
		}
		else
		{
			printf(EBADSYNTAX);
			clean_space(&tok);
			return (NULL);
		}
		i++;
	}
	// printf("expressions : %d\n", tok->expression_count);
	// printf("expansions  : %d\n", tok->expansion_count);
	// printf("exp keys    : %d\n", tok->expansion_key_count);
	// printf("exp values  : %d\n", tok->expansion_value_count);
	// system("leaks datacore");
	return(tok);
}

int addExpansion(query_t *tok, char *query, int *i, char *pattern, type_t type)
{
	int j;
	int find;
	char *ident;
	char *tmp;

	j = *i + 1;
	find = ft_find_first_of(pattern, query+j);
	if (find != STRINGNPOS)
	{
		ident = ft_substr(query, j, find);
		tmp = ft_strtrim(ident, __SET__);
		if(ft_find_first_of("{}[]\n\t\r\a\b", tmp) == STRINGNPOS)
		{
			printf("Expanssion: [%s]\n", tmp);
			append_node(&tok->tokens, tmp, type);
			free(tmp);
			tok->expression_count++;
			if(type == EXPANSION_FIELD)
				tok->expansion_count++;
			else if (type == IDENTIFIER)
				tok->ident_count++;
			tok->size++;
			*i += find + 2;
			return (0);
		}
		else {free(tmp); free(ident); return (1);}
		
	}
	return (STRINGNPOS);
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
	printf("Word: [%s]\n", wd);
	append_node(&tok->tokens, wd, (!tok->size) ? COMMAND : WORD);
	free(wd);
	wd = NULL;
	tok->expression_count++;
	tok->size++;
	*i += wordlen;
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
