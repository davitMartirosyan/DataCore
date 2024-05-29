#include "includes.h"

int dc_columns(query_t **query_list, char **fields, int size)
{
    char **column = NULL;
    char *meta = NULL;
    char *join = NULL;
    int sz = 0;
    int i = 0;
    while (fields[i])
    {
        column = ft_split(fields[i], ' ', &sz);
        if (dc_column_type(column, sz) == INVALID)
        {
            free_fields(column);
            return (INVALID);
        }
        join = join_arguments(column[0], ':', column[1], ';');
        (*query_list)->cols = column_join((*query_list)->cols, join);
        free(join);
        free_fields(column);
        column = NULL;
        i++;
    }
    return (1);
}


int dc_column_type(char **col, int size)
{
	if (!col)
		return (INVALID);
	if (size != 2)
        return (INVALID);
    if (ft_strncmp(col[0], "char", 4) == 0 || ft_strncmp(col[0], "int", 3) == 0)
    {
        if (ft_find_first_of(":{}[]|!%^&*()+\'\"<>/\\;:", col[1]) != STRINGNPOS)
            return (INVALID);
        return (VALID);
    }
	return (INVALID);
}

char	*column_join(char * s1, char * s2)
{
	char	*arguments = NULL;
	int		i = -1;
    int     j = -1;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
    
	arguments = malloc(sizeof(char) *  (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!arguments)
		return (NULL);
    while (s1[++i])
        arguments[i] = s1[i];
    while (s2[++j])
        arguments[i++] = s2[j];
    arguments[i] = '\0';
    free(s1);
    s1 = 0;
	return (arguments);
}

char	*join_arguments(char *s1, char ident, char *s2, char delim)
{
	char	*arguments;
	int		i;
	int		c;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	arguments = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 3));
	if (!arguments)
		return (NULL);
	i = -1;
	c = -1;
	while (s1[++i])
		arguments[i] = s1[i];
	arguments[i++] = ident;
	while (s2[++c])
		arguments[i++] = s2[c];
    arguments[i++] = delim;
	arguments[i] = '\0';
	return (arguments);
}
