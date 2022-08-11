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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	new = malloc (ft_strlen (s1) + len_LF(s2) + 1);
	if (new == NULL)
		return (0);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[i] && s2[j] != '\n')
	{
		new[i + j] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		new[i + j] = s2[j];
	new[i + j + 1] == '\0';
	return (new);
}

int	len_lf(char	*s)
{
	int	len;

	len = 0;
	while (s[len] != '\n')
		len++;
	return (len + 1);
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
