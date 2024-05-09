/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:18:07 by dmartiro          #+#    #+#             */
/*   Updated: 2023/02/17 00:42:56 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float   ft_atof(char *n)
{
    float   f;
    int     i;
    int     sign;
    float   cout;

    f = 0.0;
    i = 0;
    sign = 1;
    cout = 0;
    while (n[i] && ft_isspace(n[i]))
        i++;
    if (n[i] == '-')
        sign = -1;
    if (n[i] == '-' || n[i] == '+')
        i++;
    while (n[i] && ft_isdigit(n[i]))
        f = f * 10.0 + (n[i++] - '0');
    if (n[i++] == '.')
    {
        while (n[i] && ft_isdigit(n[i]))
        {
            f = f * 10.0 + (n[i++] - '0');
            cout++;
        }
        while (cout--)
            f = floor(f) * 0.1;
    }
    return (f * sign);
}
