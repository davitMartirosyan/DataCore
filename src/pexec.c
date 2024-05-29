#include "includes.h"

int pexec(table_t *table, query_t **query_list)
{
    fmap_t cmd = find_command(table, query_list);
    if (!cmd)
        return (-1);    
    return (cmd(table, query_list));
}

fmap_t find_command(table_t *table, query_t **query_list)
{
    int		i = -1;
	char	*cmd = NULL;

	cmd = ft_lowercase((*query_list)->tokens->lexeme);
    while (++i < FUNCTIONALITY)
    {
        if (ft_strcmp(cmd, table->cmap[i]) == 0)
		{
			free(cmd);
			return (table->fmap[i]);
		}
    }
	free(cmd);
    return (NULL);
}
