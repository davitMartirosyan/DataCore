#include "includes.h"

int dc_columns(char **fields, int size)
{
    char **column = NULL;
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
		// printf("%s : %s\n", column[0], column[1]);
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
