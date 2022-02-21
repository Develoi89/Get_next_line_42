/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealonso- <ealonso-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:10:09 by ealonso-          #+#    #+#             */
/*   Updated: 2022/02/21 18:50:26 by ealonso-         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_len;
	size_t	s2_len;
	int		aux1;
	int		aux2;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	aux1 = 0;
	aux2 = 0;
	new_s = malloc(s1_len + s2_len + 1);
	if (!s1 || !s2 || !new_s)
		return (NULL);
	while (s1[aux1])
	{
		new_s[aux1] = s1[aux1];
		aux1++;
	}
	while (s2[aux2])
	{
		new_s[aux1++] = s2[aux2++];
	}
	new_s[aux1] = '\0';
	return (new_s);
}
