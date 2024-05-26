#include "libft.h"

char * ft_lowercase(char * s)
{
    char *new;
    int i = 0;
    if (!s)
        return (NULL);
    new = malloc(sizeof(char) * ((int)ft_strlen(s)));
    strcpy(new, s);
    if (!new)
        return (NULL);
    while(new[i])
    {
        new[i] = tolower((unsigned char)new[i]);
        i++;
    }
    return (new);
}