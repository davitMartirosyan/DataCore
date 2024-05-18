#include "libft.h"

char * ft_lowercase(char * s)
{
    char *new;
    int i = 0;
    if (!s)
        return (NULL);
    new = malloc(sizeof(char) * ((int)ft_strlen(s)));
    if (!new)
        return (NULL);
    while(s[i])
    {
        if (s[i] >= 65 && s[i] <= 90)
            new[i] = s[i] + 32;
        else
            new[i] = s[i];
        i++;
    }
    return (new);
}