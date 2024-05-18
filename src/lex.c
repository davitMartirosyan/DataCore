#include "includes.h"

query_t *lexer(char *query)
{
    query_t     *tok = NULL;
    int         len = ft_strlen(query);
    int         actual = 0;
	int			i = 0;

    tok = malloc(sizeof(query_t));
	tok->is_inside = false;
	tok->maxexp = 0;
	tok->size = 0;
	tok->cap = 0;
	tok->tokens = NULL;
	if (!tok)
		return (NULL);
	while (query && query[i])
	{
		if (query[i] && ft_iswordpart(query[i]) && (int)ft_strlen(query) > i)
		{
			if (query[i] && tok->is_inside)
				addexpfield(tok, query, &i);
			else if(query[i] && !tok->is_inside)
				addword(tok, query, &i);
		}
		if (query[i] && query[i] == '{')
		{
			if (tok->is_inside)
			{
				printf("Epression error on point of : %d\n", i);
				return (NULL);
			}
			expansionopen(tok, query, &i);
		}
		if (query[i] && query[i] == '}')
		{
			if(!tok->is_inside)
			{
				printf("Epression error on point of : %d\n", i);
				return (NULL);
			}
			expansionclose(tok, query, &i);
		}
		if(query[i] && ft_isspace(i)){i++; continue;}
		i++;
	}
	printf("*****************\n");
    return(tok);
}

void	expansionopen(query_t *tok, char *query, int *i)
{
	char *expopen = ft_substr(ft_strdup(query), *i, 1);
	tok->is_inside = true;
	// printf("Op: |%s|\n", expopen);
	append_node(&tok->tokens, expopen, EXPANSION_OPEN);
	free(expopen);
}

void	expansionclose(query_t *tok, char *query, int *i)
{
	char *expclose = ft_substr(ft_strdup(query), *i, 1);
	tok->is_inside = false;
	// printf("Cl: |%s|\n", expclose);
	append_node(&tok->tokens, expclose, EXPANSION_CLOSE);
	free(expclose);
}

void addword(query_t *tok, char *query, int *i)
{
	int wordlen = 0;
	int j = *i;

	while (query[j] && (ft_iswordpart(query[j]) || query[j] == ':'))
	{
		j++;
		wordlen++;
	}
	char *word = ft_substr(ft_strdup(query), *i, wordlen);
	// printf("Word: |%s|\n", word);
	append_node(&tok->tokens, word, WORD);
	free(word);
	*i += wordlen;
}

void	addexpfield(query_t *tok, char *query, int *i)
{
	int expansion_len = 0;
	int j = *i;

	while (query[j] && query[j] != ',' && query[j] != '}')
	{
		j++;
		expansion_len++;
	}
	char *expansion_field = ft_substr(ft_strdup(query), *i, expansion_len);
	// printf("Field: |%s|\n", expansion_field);
	append_node(&tok->tokens, expansion_field, EXPANSION_FIELD);
	free(expansion_field);
	*i += expansion_len;
}


void print_tokens(querytok_t *toks)
{
	while (toks)
	{
		printf("type: %d | tok: %s\n", toks->type, toks->token);
		toks = toks->next;
	}
}


querytok_t *create_node(char *word, type_t type)
{
    querytok_t *new_node = malloc(sizeof(querytok_t));
    if (!new_node)
		return (NULL);

    new_node->token = ft_strdup(word);
    if (!new_node->token) {free(new_node); return NULL;}
    new_node->type = type;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void append_node(querytok_t **tokens, char *word, type_t type)
{
    querytok_t *new_node = create_node(word, type);
    if (!new_node)
		return ;

    if (!(*tokens))
    {
        *tokens = new_node;
        return;
    }

    querytok_t *current = *tokens;
    while (current->next)
		current = current->next;
    current->next = new_node;
    new_node->prev = current;
}