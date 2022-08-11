/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:25:23 by gcastro-          #+#    #+#             */
/*   Updated: 2022/07/19 12:25:24 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	j = 0; 
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	new = malloc (ft_strlen (s1) + ft_strlen (s2) + 1);
	if (new == NULL)
		return (0);
	while(s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while(s1[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] == '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	x;
	size_t	i;

	i = 0;
	x = ft_strlen ((char *)s);
	while (i != x + 1)
	{
		if (*s == (unsigned char)c)
			return ((char *) s);
		s++;
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
