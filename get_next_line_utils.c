/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:10:09 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/14 19:14:58 by ealonso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) + 1;
	str = (char *) malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i] != 0)
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
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
