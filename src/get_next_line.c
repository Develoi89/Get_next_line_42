/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: develoi89 <develoi89@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:39:37 by ealonso-          #+#    #+#             */
/*   Updated: 2022/10/30 09:46:09 by develoi89        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*go_to_read(char *rest, int fd);
char	*go_to_split_it(char *rest);
char	*save_the_rest(char *rest);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	rest = go_to_read(rest, fd);
	if (!rest)
		return (NULL);
	line = go_to_split_it(rest);
	rest = save_the_rest(rest);
	return (line);
}

char	*go_to_read(char *rest, int fd)
{
	char	*buff;
	int		nbr;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	nbr = 1;
	while (nbr && !ft_strchr(rest, '\n'))
	{
		nbr = read(fd, buff, BUFFER_SIZE);
		if (nbr == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbr] = '\0';
		rest = ft_strjoin(rest, buff);
	}
	free (buff);
	return (rest);
}

char	*go_to_split_it(char *rest)
{
	int		i;
	char	*line;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*save_the_rest(char *rest)
{
	int		i;
	int		j;
	int		len;
	char	*bck;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	len = ft_strlen(rest) -i;
	bck = malloc((len + 1) * sizeof(char));
	if (!bck)
		return (NULL);
	j = 0;
	i++;
	while (rest[i])
		bck[j++] = rest[i++];
	bck[j] = '\0';
	free (rest);
	return (bck);
}
