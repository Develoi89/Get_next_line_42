/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:39:37 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/22 19:55:21 by ealonso-         ###   ########.fr       */
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

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (0);
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
		if (nbr < 0)
		{
			free (buff);
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
	while (rest[i] && rest[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (rest[i++] && rest[i] != '\n')
		line[i] = rest[i];
	line[i] = '\n';
	line[i++] = '\0';
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
	len = ft_strlen(rest) -i;
	bck = malloc((len + 1) * sizeof(char));
	if (!bck)
		return (NULL);
	j = -1;
	while (rest[i++])
		bck[j++] = rest[i];
	bck[j] = '\0';
	free (rest);
	return (bck);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*aux;
// 	int		i = 0;

// 	fd = open("/Users/ealonso-/Desktop/Proyectos_cursus_home/Get_next_line/text.txt", O_RDONLY);
// 	while (i < 20)
// 	{
// 		aux = get_next_line(fd);
// 		printf("%s", aux);
// 		free (aux);
// 		aux = NULL;
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
