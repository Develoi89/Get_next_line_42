/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 17:10:06 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/14 16:36:05 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) > len)
		i = len;
	else
		i = ft_strlen(s);
	new = malloc(i + 1 * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, i + 1);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*r;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	r = (char *)s + i;
	if (s[i] != (char)c)
		return (0);
	else
		return (r);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		while (n)
		{
			n--;
			*((unsigned char *)(dest + n)) = *((unsigned char *)(src + n));
		}
	}
	else
	{
		while (i < n)
		{
			*((unsigned char *)(dest + i)) = *((unsigned char *)(src + i));
			i++;
		}
	}	
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(len1 + len2 + 1 * sizeof(char));
	if (!join)
		return (NULL);
	ft_memmove(join, s1, len1);
	ft_memmove(join + len1, s2, len2 + 1);
	return (join);
}

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*get_next_line(int fd);

#endif