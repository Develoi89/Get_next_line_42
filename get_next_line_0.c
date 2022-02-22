/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:35:43 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/22 17:45:23 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_principal(char *guardar, int fd)
{
	int		numbytes;
	char	*buffer;

	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	numbytes = 1;
	while (numbytes && !ft_strchr(guardar, '\n'))
	{
		numbytes = read(fd, buffer, BUFFER_SIZE);
		if (numbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[numbytes] = '\0';
		guardar = ft_strjoin(guardar, buffer);
	}
	free(buffer);
	return (guardar);
}

char	*ft_linia(char *guardar)
{
	int		i;
	char	*str;

	i = 0;
	if (!guardar[i])
		return (NULL);
	while (guardar[i] && guardar[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (guardar[i] && guardar[i] != '\n')
	{
		str[i] = guardar[i];
		i++;
	}
	if (guardar[i] == '\n')
	{
		str[i] = guardar[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_static(char *guardar)
{
	int		i;
	int		j;
	int		len;
	char	*str2;

	i = 0;
	while (guardar[i] && guardar[i] != '\n')
		i++;
	if (!guardar[i])
	{
		free(guardar);
		return (NULL);
	}
	len = (ft_strlen(guardar) - i);
	str2 = malloc((len + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	j = 0;
	i++;
	while (guardar[i])
		str2[j++] = guardar[i++];
	str2[j] = '\0';
	free(guardar);
	return (str2);
}

char	*get_next_line(int fd)
{
	char		*linia;
	static char	*guardar;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (0);
	guardar = ft_principal(guardar, fd);
	if (!guardar)
		return (0);
	linia = ft_linia(guardar);
	guardar = ft_static(guardar);
	return (linia);
}
