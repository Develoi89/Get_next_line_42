/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:16:13 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/15 18:50:09 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_foundit(char *buf, char *rest)
{
	char	*str;

	
}

void	*ft_saveit(char *buf, char *rest)
{
	if (rest == null)
	{
		rest = ft_substr(buf, 0, ft_strlen(buf));
		rest[ft_strlen(rest)] = '\0';
	}
	else
	{
		ft_strjoin(rest, buf);
		rest[ft_strlen(rest)] = '\0';
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*rest;
	int			nbr;

	if (ft_strchr(rest, '\n'))
		return (ft_doblejump(rest));
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf || !fd)
		return (NULL);
	nbr = read(fd, buf, BUFFER_SIZE);
	if (nbr == 0)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	if (ft_strchr(buf, '\n'))
		return (ft_foundit());
	else
	{
		ft_saveit(buf, rest);
		free (buf);
		if (nbr != 0)
			get_next_line(fd);
	}
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