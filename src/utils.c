#include "includes.h"

void print_tokens(querytok_t *toks)
{
	while (toks)
	{
		printf("type: %d | tok: [%s]\n", toks->type, toks->lexeme);
		toks = toks->next;
	}
}
