#include "libft.h"

int ft_find_first_of(char *pattern, char *s) {
    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; pattern[j] != '\0'; j++) {
            if (s[i] == pattern[j]) {
                return i;
            }
        }
    }
    return (STRINGNPOS);
}
