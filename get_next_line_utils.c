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
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	new = malloc (sizeof(char) * (ft_strlen (s1) + len_lf(s2)) + 1);
	if (s1 == NULL || s2 == NULL || new == NULL)
		return (0);
	if(s1)
	{
		while(s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != 0)
		new[i++] = s2[j++];
	if (s2[j] == '\n')
		new[i + j] = s2[j];
	new[i + j + 1] = '\0';
	return (new);
}

size_t	len_lf(char	*s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\n' && len < BUFFER_SIZE)
		len++;
	return (len + 1);
}

char	*get_line(int fd, char *buff)
{
	int		n_bytes;
	char	*new;

	if(!buff)
		return (NULL);
	n_bytes = 1;
	while (!ft_strchr(buff, '\n') && n_bytes != 0)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
			return (NULL);
		new = ft_strjoin(new, buff);
	}
	return(new);
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

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
