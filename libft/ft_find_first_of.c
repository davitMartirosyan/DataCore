#include "libft.h"

int ft_find_first_of(char *pattern, char *s)
{
    int i;

    i = -1;
    if (!pattern || !s)
        return (0);
    while (++i < (int)ft_strlen(s))
    {
        int j;

        j = -1;
        while (++j < (int)ft_strlen(pattern))
            if (s[i] == pattern[j])
                return (i);
    }
    return (STRINGNPOS);
}
