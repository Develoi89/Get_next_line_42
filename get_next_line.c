/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:40:52 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/08 19:23:13 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*lineres;

	lineres = NULL;
	if (!fd)
		return (NULL);
	read (fd, lineres, BUFFER_SIZE);
	return (lineres);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("prueba: %s", get_next_line(fd));
	close(fd);
	return (0);
}
