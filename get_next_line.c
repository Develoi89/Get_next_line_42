/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:16:13 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/17 19:19:39 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_foundit(char *buf, char **rest, char **str)
{
	size_t	lenbuf;
	size_t	lennbuf;
	char	*aux;

	lenbuf = ft_strlen(buf);
	lennbuf = ft_strlen(ft_strchr(buf, '\n'));
	aux = *str;
	*str = ft_strjoin(aux, ft_substr(buf, 0, (lenbuf - lennbuf + 1)));
	free (aux);
	*rest = ft_substr(buf, (lenbuf - lennbuf + 1), lenbuf + 1);
	return (*str);
}

char	*ft_doblejump(char **rest)
{
	size_t	lenrest;
	size_t	lennrest;
	char	*temp;
	char	*line;

	lenrest = ft_strlen(*rest);
	lennrest = ft_strlen(ft_strchr(*rest, '\n'));
	line = ft_substr(*rest, 0, (lenrest - lennrest) + 1);
	temp = ft_substr(*rest, (lenrest - lennrest) + 2, lenrest + 1);
	free (*rest);
	*rest = temp;
	free (temp);
	return (line);
}

char	*ft_1ststep(char **rest)
{
	if (*rest)
	{
		if (ft_strchr(*rest, '\n'))
			return (ft_doblejump(rest));
		else
			return (ft_substr(*rest, 0, strlen(*rest)));
	}
	return (NULL);
}

void	*ft_saveit(char *buf, char **str)
{
	char	*aux;

	if (*str == NULL)
	{
		*str = ft_substr(buf, 0, ft_strlen(buf) + 1);
		if (!*str)
			return (NULL);
	}
	else
	{
		aux = *str;
		*str = ft_strjoin(aux, buf);
		free (aux);
		if (!*str)
			return (NULL);
	}
	return (*str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*rest;
	int			nbr;
	char		*str;

	nbr = 1;
	str = ft_1ststep(&rest);
	if (str && ft_strchr(str, '\n'))
		return (str);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !fd)
		return (NULL);
	while (nbr != 0)
	{
		nbr = read(fd, buf, BUFFER_SIZE);
		buf[nbr] = '\0';
		if (ft_strchr(buf, '\n'))
			return (ft_foundit(buf, &rest, &str));
		else
		{
			str = ft_saveit(buf, &str);
		}
	}
	free(buf);
	return (str);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*aux;
// 	int		i = 0;

// 	fd = open("/Users/ealonso-/Desktop/Proyectos_cursus_home/Get_next_line/text.txt", O_RDONLY);
// 	while (i < 28)
// 	{
// 		aux = get_next_line(fd);
// 		printf("prueba: %s", aux);
// 		i++;
// 	}
// 	free (get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
