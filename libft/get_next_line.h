/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmartiro <dmartiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 05:27:36 by dmartiro          #+#    #+#             */
/*   Updated: 2024/05/10 01:25:12 by dmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define BUFFER_SIZE 1
char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *buffer, int ch);
char	*join(char *stat, char *buffer);
char	*after(char *buffer);
char	*before(char *buffer);
char	*read_line(int fd, char *buffer);
#endif
