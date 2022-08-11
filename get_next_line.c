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

char	*get_next_line(int fd);
{
	char		*new;
	int			n_bytes;		// compare with BUFFER_SIZE
	//static char *stc_var;	// VARIABLE ESTATICA EN LA QUE SE GUARDARÁ EL RESTANTE DE LA LECTURA ANTERIOR. 
	int			control;
	char		*buff;

	control = 0;
	buff = malloc(BUFFER_SIZE);
	while (control == 0)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if(n_bytes == 0)
			return (NULL);
		new = ft_strjoin(new, buff);
		if(ft_strchr(new, '\n'))
			control = 1;
	}
	
	free(buff);
	return (new);
}

int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	printf("%s\n\n", line);
}
