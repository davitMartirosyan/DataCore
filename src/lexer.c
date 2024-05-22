#include "includes.h"

int erno = 0;

query_t *lexer(char *q)
{
	query_t     *query = NULL;
	int         len = ft_strlen(q);
	int         actual = 0;
	int			i = 0;

	query = malloc(sizeof(query_t));
	if (!query)
		return (NULL);
	_init_query((void*)&query);
	while (q && q[i])
	{
		if (q[i] && ft_iswordpart(q[i]) && (int)ft_strlen(q) > i)
		{
			add_word(query, q, &i);
			continue;
		}
		else if (q[i] && q[i] == '{')
		{
			if(add_expansion(query, q, &i, "}", EXPANSION_FIELD) != 0)
			{
				//error log
				printf(EBADSYNTAX);
				clean_space(&query);
				return (NULL);
			}
			continue;
		}
		else if (q[i] && q[i] == '<')
		{
			if (add_expansion(query, q, &i, ">", IDENTIFIER) != 0)
			{
        		//error log
				printf(EBADSYNTAX);
				clean_space(&query);
				return (NULL);
			}
			continue;
		}
		else if (q[i] && ft_isspace(q[i]))
		{
			i++; 
			continue;
		}
		else
		{
			//error log
			printf(EBADSYNTAX);
			clean_space(&query);
			return (NULL);
		}
		i++;
	}
	query->cmd = ft_lowercase(query->tokens->lexeme);
	return(query);
}

int add_expansion(query_t *tok, char *query, int *i, char *pattern, type_t type)
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
			// printf("Expanssion: [%s]\n", tmp);
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

void add_word(query_t *tok, char *query, int *i)
{
	int wordlen = 0;
	int j = *i;

	while (query[j] && (ft_iswordpart(query[j])))
	{
		j++;
		wordlen++;
	}
	char *wd = ft_substr(query, *i, wordlen);
	// printf("Word: [%s]\n", wd);
	append_node(&tok->tokens, wd, (!tok->size) ? COMMAND : WORD);
	free(wd);
	wd = NULL;
	tok->expression_count++;
	tok->size++;
	*i += wordlen;
}

