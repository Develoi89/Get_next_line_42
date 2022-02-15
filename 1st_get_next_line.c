/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:40:52 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/15 16:57:45 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_saveit(char *buf, char *rest)
{
	if (rest == NULL)
	{
		rest = buf;
		free (buf);
		return (rest);
	}
	else
		rest = ft_strjoin(rest, buf);
	if (!rest)
		return (NULL);
	rest[ft_strlen(rest)] = '\0';
	return (rest);
}

char	*ft_foundit(char *buf, char *rest)
{
	size_t	lenbuf;
	size_t	lennbuf;
	size_t	i;
	char	*temp;
	char	*str;

	lenbuf = ft_strlen(buf);
	lennbuf = ft_strlen(ft_strchr(buf, '\n'));
	i = (ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n')));
	temp = ft_substr(buf, 0, i +1);
	if (!temp)
		return (NULL);
	str = ft_strjoin(rest, temp);
	if (!str)
		return (NULL);
	str[ft_strlen(str)] = '\0';
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
	int			nbr;

	while (fd)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf || !fd)
			return (NULL);
		nbr = read (fd, buf, BUFFER_SIZE);
		if (nbr == 0)
			return (NULL);
		buf[ft_strlen(buf)] = '\0';
		if (ft_strchr(buf, '\n'))
			return (ft_foundit(buf, rest));
		else
		{
			rest = ft_saveit(buf, rest);
		}
	}
	return (NULL);
}

int	main(void)
{
	int		fd;

	fd = open("/Users/ealonso-/Desktop/Proyectos_cursus_home/Get_next_line/text.txt", O_RDONLY);
	while (fd)
	{
		printf("prueba: %s", get_next_line(fd));
		if (!get_next_line(fd))
			return (0);
	}
	free (get_next_line(fd));
	close(fd);
	return (0);
}
