/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:23:11 by dmartiro          #+#    #+#             */
/*   Updated: 2022/04/03 21:29:02 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int an)
{
	if ((an >= 48 && an <= 57)
		|| (an >= 65 && an <= 90)
		|| (an >= 97 && an <= 122))
		return (an);
	return (0);
}
