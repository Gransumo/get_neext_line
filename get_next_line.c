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

char	*get_init_new(char *missing_text)
{
	char	*new;
	size_t		i;

	i = 0;
	new = malloc(len_lf(missing_text)+ 1);
	while(i < len_lf(missing_text))
	{
		new[i] = missing_text[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*missing_text;
	char		*buff;

	buff = malloc (sizeof(char) * BUFFER_SIZE);
	if(buff == NULL)
		return (NULL);
	if (missing_text != NULL)
	{
		if(ft_strchr (missing_text, '\n') != NULL)
		{
			new = get_init_new(missing_text);
			missing_text = ft_strchr (missing_text, '\n');
			free(buff);
			return(new);
		}
		else
			new = missing_text;
	}
	new = get_new(fd, buff);
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
	//printf("%s", get_next_line(fd));
	
	return (0);
}