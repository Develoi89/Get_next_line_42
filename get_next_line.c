/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:40:52 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/14 17:42:11 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_foundit(char *buf, char *str, char *rest)
{
	size_t	lenbuf;
	size_t	lennbuf;
	size_t	i;
	char	*temp;

	lenbuf = ft_strlen(buf);
	lennbuf = ft_strlen(ft_strchr(buf, '\n'));
	i = (ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n')));

	return (str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*rest;
	char		*str;

	if (!fd)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!(ft_strchr(buf, '\n')))
	{
		read (fd, buf, BUFFER_SIZE);
		if (ft_strchr(buf, '\n'))
			return (ft_foundit(buf, str, rest));
		else
			rest = ft_strjoin(rest, buf);
	}
	return (buf);
}

int	main(void)
{
	int	fd;

	fd = open("/Users/ealonso-/Desktop/Proyectos_cursus_home/Get_next_line/text.txt", O_RDONLY);
	printf("prueba: %s", get_next_line(fd));
	close(fd);
	return (0);
}
