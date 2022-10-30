/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: develoi89 <develoi89@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 08:17:23 by develoi89         #+#    #+#             */
/*   Updated: 2022/10/30 09:44:15 by develoi89        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"

int	main(void)
{
	int		fd;
	char	*aux;
	int		i;

	i = 0;
	fd = open("test/text", O_RDONLY);
	if (fd < 0)
	{
		printf("error, fd = %d\n", fd);
		return (0);
	}
	while (i < 60)
	{
		aux = get_next_line(fd);
		if (aux == NULL)
			return (0);
		printf("prueba: %s", aux);
		i++;
	}
	free (get_next_line(fd));
	close(fd);
	return (0);
}
