#include "includes.h"

int dc_add_fields(char **fields, int size)
{
    char *column_type = NULL;
    char *column_name = NULL;
    char **column = NULL;
    int sz = 0;
    int i = 0;

    while (fields[i])
    {
        column = ft_split(fields[i], ' ', &sz);
        if (dc_field(column, sz) == INVALID)
        {
            free_fields(column);
            return (0);
        }
        free_fields(column);
        column = NULL;
        i++;
    }
    return (1);
}

int dc_field(char **col, int size)
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