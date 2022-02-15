/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:40:52 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/15 15:10:30 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_foundit(char *buf, char *str, char *rest)
{
	size_t	lenbuf;
	size_t	lennbuf;
	size_t	i;
	char	*temp;

	lenbuf = ft_strlen(buf);
	lennbuf = ft_strlen(ft_strchr(buf, '\n'));
	i = (ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n')));
	temp = ft_substr(buf, 0, i +1);
	if (!temp)
		return (NULL);
	str = ft_strjoin(rest, temp);
	if (!str)
		return (NULL);
	free (rest);
	free (temp);
	rest = ft_substr(buf, i + 1, lenbuf + 1);
	if (!rest)
		return (NULL);
	free (buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*rest;
	char		*str;

	str = NULL;
	if (!fd)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (buf)
	{
		read (fd, buf, BUFFER_SIZE);
		if (ft_strchr(buf, '\n'))
			return (ft_foundit(buf, str, rest));
		else
		{
			if (rest == NULL)
				rest = buf;
			rest = ft_strjoin(rest, buf);
			if (!rest)
				return (NULL);
		}
	}
	return (NULL);
}

int	main(void)
{
	int	fd;

	fd = open("/Users/ealonso-/Desktop/Proyectos_cursus_home/Get_next_line/text.txt", O_RDONLY);
	while (fd)
		printf("prueba: %s", get_next_line(fd));
	close(fd);
	return (0);
}
