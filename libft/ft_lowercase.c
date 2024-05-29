#include "libft.h"

char * ft_lowercase(char * s)
{
    char *new;
    int i = -1;
    if (!s)
        return (NULL);
    new = malloc(sizeof(char) * ((int)ft_strlen(s) + 1));
    if (!new)
        return (NULL);
    while(s[++i])
        new[i] = ft_tolower(s[i]);
    new[i] = '\0';
    return (new);
}