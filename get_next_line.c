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

char	*get_init_new(char *str)
{
	int i;
	char *new;

	i = 0;
	new = malloc(len_lf(str) + 1);
	while(str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = str[i];
	i++;
	new[i] = 0;
	return (new);
}

void	ft_free(char *buff, char *aux)
{
	free(buff);
	free(aux);
}

char	*get_next_line(int fd)
{
	char		*new;
	static char	*missing_text;
	char		*buff;
	char		*aux;

	if(missing_text != NULL)
	{
		if(ft_strchr(missing_text, '\n'))
		{
			new = get_init_new(missing_text);
			missing_text = ft_strchr (missing_text, '\n');
			return(new);
		}
		else
			aux = missing_text;
	}
	buff = malloc (BUFFER_SIZE + 1);
	aux = malloc(sizeof(char) * 1);
	if(buff == NULL || aux == NULL)
		return (NULL);
	aux[0] = 0;
	new = ft_strjoin(aux, get_line(fd, buff));
	missing_text = ft_strchr (buff, '\n');
	ft_free (buff, aux);
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
	//printf("%s", get_next_line(fd));
	
	return (0);
}