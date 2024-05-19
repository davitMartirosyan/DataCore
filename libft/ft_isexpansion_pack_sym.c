#include "libft.h"

bool ft_isexpansion_pack_sym(int ch)
{
    if (ft_isalnum(ch) || ft_isspace(ch) || ch == ',')
        return (true);
    return (false);
}