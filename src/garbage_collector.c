#include "includes.h"

void free_fields(char ***fields)
{
	char **field_buffer = *fields;
	int i = 0;
	while (field_buffer[i])
		free(field_buffer[i]);
	free(*fields);
	*fields = NULL;
}
