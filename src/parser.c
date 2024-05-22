#include "includes.h"

int parse_request(table_t *table, query_t **query_list)
{
    fmap_t cmd = find_command(table, query_list);
    if (!cmd)
        return (0);
    if (cmd(table, query_list) < 0)
        return (-1);
    return (1);
}

fmap_t find_command(table_t *table, query_t **query_list)
{
    int i = -1;
    while (++i < FUNCTIONALITY)
    {
        if (ft_strcmp((*query_list)->cmd, table->cmap[i]) == 0)
            return (table->fmap[i]);
    }
    return (NULL);
}

int check_fields(char **fields, int size)
{
	int i;

	i = -1;
	if (!fields)
		return (INVALID);
	while (fields[++i])
	{
		if (is_valid(fields[i]) == INVALID)
			return (INVALID);
	}
	return (0);
}

int is_valid(char *field)
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

int valid_type(char *type)
{
	return (0);
}
