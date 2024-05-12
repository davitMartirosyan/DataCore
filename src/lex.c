#include "includes.h"
void addword(query_t **tokens, int *pos, char *query);
void addexpansion(query_t **tokens, int *pos, char *query);

querytok_t *lexer(char *query)
{
    query_t     *tok = NULL;
    int         len = ft_strlen(query);
    int         actual = 0;
	int			i = 0;
    tok = malloc(sizeof(query_t));
    if (!tok)
        return (NULL);
	tok->maxexp		= 0;
	tok->brace_count = 0;
    tok->iskeyset 	= false;
    tok->isvalueset = false;
	tok->worderr 	= false;
	tok->experr 	= false;
	tok->sperr		= false;
	tok->open		= false;
	tok->in			= false;
	tok->out		= false;
	
	while (query && query[i])
    {
		if (query[i] && ft_iswordpart(query[i]) && (int)ft_strlen(query) > i)
			addword(&tok, &i, query);
		else if (query[i] && ft_isspace(query[i]))
		{
			i++;
			continue;
		}
		else if (query[i] && query[i] == '{')
			addexpansion(&tok, &i, query);
		if (tok->worderr || tok->experr || tok->open || tok->close)
		{
			printf("error\n");
			free(tok);
			return (NULL);
		}
		i++;
    }
    //fill iskeyset=true in query_t struct if  first part of expansions (keys) was found,
    // now you can find second part e.g. (values) and fill isvalueset=true {} -> {}
    free(tok);
	free(query);
    return(NULL);
}

void addword(query_t **tokens, int *pos, char *query)
{
	int e_pos = *pos;
	int s_pos = *pos;
	char *wordpart;

	while (query[e_pos])
	{
		if (!query[e_pos] || !ft_iswordpart(query[e_pos]))
			break;
		e_pos++;
	}
	wordpart = ft_substr(ft_strdup(query), s_pos, (e_pos - s_pos));
	printf("wordpart: (%s)\n", wordpart);
	free(wordpart);
	*pos += (e_pos - s_pos);
}

void addexpansion(query_t **tokens, int *pos, char *query)
{
	int s_pos = *pos;
	int e_pos = *pos + 1;
	char *expansion;

	(*tokens)->open = true;
	// printf("%s\n", query+s_pos);
	while (query[e_pos])
	{
		if (!query[e_pos] || !ft_iswordpart(query[e_pos]))
		{
			if (query[e_pos] == '}')
			{
				(*tokens)->close = true;
				break;
			}
			else if (query[e_pos] == '{')
			{
				(*tokens)->experr = true;
				break;
			}
		}
		e_pos++;
	}
	// printf("%s\n", query+e_pos);

	if ((*tokens)->close && !(*tokens)->experr)
	{
		expansion = ft_substr(ft_strdup(query), s_pos, (e_pos - s_pos + 1));
		printf("expansion: (%s)\n", expansion);
		free(expansion);
		(*tokens)->open		= false;
		(*tokens)->experr	= false;
		(*tokens)->close	= false;
	}
	*pos += (e_pos - s_pos);
}