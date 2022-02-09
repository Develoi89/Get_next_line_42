/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:40:52 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/09 17:03:17 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[33];

	if (!fd)
		return (NULL);
	read (fd, buf, 32);
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
