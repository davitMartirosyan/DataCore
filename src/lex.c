#include "includes.h"

querytok_t *lexer(char *query)
{
    query_t     *tok = NULL;
    int         len = ft_strlen(query);
    int         actual = 0;

    tok = malloc(sizeof(query_t));
    if (!tok)
        return (NULL);
    tok->iskeyset = false;
    tok->isvalueset = false;
    for(int i = 0; i < len;)
    {
        if (query[i] && ft_isalpha(query[i]) && (int)ft_strlen(query) > i)
            addword(&tok, &i, query);
        if (query[i] && ft_isspace(query[i])){i++; continue;}
        if (query[i] && query[i] == '{')
            addexpansion(&tok, &i, query);
        i++;
    }

    //fill iskeyset=true in query_t struct if  first part of expansions (keys) was found,
    // now you can find second part e.g. (values) and fill isvalueset=true {} -> {} 
    free(tok);
    return(NULL);
}

void	addword(query_t **tokens, int *i, char *query)
{
	int		len;
	char	*wordpart;

	len = wordlen(query, *i);
	wordpart = NULL;
	wordpart = word(query, len, *i);
    printf("word -> %s\n", wordpart);
	free(wordpart);
	*i += len;
}

void addexpansion(query_t **tokens, int *i, char *query)
{
    int s = *i;
    int e = 0;
    bool oppened = true;
    while (oppened)
    {
        if (query[s] == '}')
            oppened = false;
        s++;
        e++;
    }
    char *keys = ft_substr(query, *i, e);
    *i += e;
    printf("keys|values -> %s\n", keys);
    free(keys);
}

void	space(query_t **tokens, int *i, char *query)
{
	int		s;
	int		len;
	char	*separator;

	s = *i;
	len = 0;
	separator = NULL;
	while (query[++s])
	{
		if (!ft_isspace(query[s]))
			break ;
		++len;
	}
	separator = word(query, len, *i);
	free(separator);
	*i += len;
}

char	*word(char *query, int len, int s_pos)
{
	char	*word;
	int		i;

	i = 0;
	word = NULL;
	word = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		word[i] = query[s_pos];
		s_pos++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	wordlen(char *wordstart, int s_pos)
{
	int	i;

	i = 0;
	while (wordstart[s_pos] && ft_iswordpart(wordstart[s_pos]))
	{
		s_pos++;
		i++;
	}
	return (i);
}