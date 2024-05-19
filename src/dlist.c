#include "includes.h"

querytok_t *create_node(char *word, type_t type)
{
    querytok_t *new_node = malloc(sizeof(querytok_t));
    if (!new_node)
		return (NULL);

    new_node->lexeme = ft_strdup(word);
    if (!new_node->lexeme) {free(new_node); return NULL;}
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