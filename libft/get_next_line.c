/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 05:37:44 by dmartiro          #+#    #+#             */
/*   Updated: 2024/05/10 01:24:42 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *buffer, int ch)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == ch)
			return ((char *)buffer + i);
		i++;
	}
	return (0);
}


char	*join(char *stat, char *buffer)
{
	char	*join;
	size_t	i;
	size_t	c;

	if (!stat)
	{
		stat = (char *)malloc(sizeof(char) * 1);
		stat[0] = '\0';
	}
	if (!stat || !buffer)
		return (NULL);
	i = -1;
	c = -1;
	join = (char *)malloc(sizeof(char)
			* (ft_strlen(stat) + ft_strlen(buffer) + 1));
	if (!join)
		return (NULL);
	while (stat[++i] != '\0')
		join[i] = stat[i];
	while (buffer[++c])
		join[i++] = buffer[c];
	join[i] = '\0';
	free(stat);
	return (join);
}

char	*after(char *buffer)
{
	char	*afnl;
	size_t	i;
	size_t	c;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	afnl = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!afnl)
		return (NULL);
	c = 0;
	i++;
	while (buffer[i])
		afnl[c++] = buffer[i++];
	afnl[c] = '\0';
	free(buffer);
	return (afnl);
}

char	*before(char *buffer)
{
	char	*bfnl;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	bfnl = (char *)malloc(sizeof(char) * (i + 2));
	if (!bfnl)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		bfnl[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		bfnl[i] = buffer[i];
		i++;
	}
	bfnl[i] = '\0';
	return (bfnl);
}

char	*read_line(int fd, char *buffer)
{
	int		desc;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	desc = 1;
	while (desc != 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		desc = read(fd, buff, BUFFER_SIZE);
		if (desc == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[desc] = '\0';
		buffer = join(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*stat;
	char		*oneline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stat = read_line(fd, stat);
	if (!stat)
		return (NULL);
	oneline = before(stat);
	stat = after(stat);
	return (oneline);
}
