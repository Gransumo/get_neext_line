/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:23:58 by gcastro-          #+#    #+#             */
/*   Updated: 2022/07/19 12:24:01 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*new;
	int			n_bytes;
	static char	*missing_text;
	char		*buff;
	int			control;

	control = 0;
	buff = malloc (sizeof(char) * BUFFER_SIZE);
	if (missing_text != NULL)
		new = missing_text;
	if(buff == NULL)
		return (NULL);
	while (control == 0)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == 0 || n_bytes == -1 && new == NULL)
			return (NULL);
		new = ft_strjoin(new, buff);
		if (ft_strchr (new, '\n') != NULL)
			control = 1;
	}
	missing_text = ft_strchr (buff, '\n');
	free (buff);
	return (new);
}

int main()
{
	int fd;
	int i;

	i = 0;
	fd = open("text", O_RDONLY);
/* 	nb = read(fd, buff, BUFFER_SIZE);
	printf("%s\n%i", buff, nb); */
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	
	return (0);
}
