/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswordpart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 07:03:19 by root              #+#    #+#             */
/*   Updated: 2024/05/18 03:04:11 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_iswordpart(int ch)
{
    if(!ft_isspace(ch) && !ft_isspecial(ch) && ft_isalnum(ch))
        return (1);
    else
        return (0);
}