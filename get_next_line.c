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
	char		*buff;
	int			n_bytes;		// compare with BUFFER_SIZE
	static char *stc_var;	// VARIABLE ESTATICA EN LA QUE SE GUARDARÁ EL RESTANTE DE LA LECTURA ANTERIOR. 
	int			control;

	control = 0;
	buff = malloc(BUFFER_SIZE);
	stc_var = malloc(BUFFER_SIZE);
	n_bytes = read(fd, buff, BUFFER_SIZE);
	while (control == 0)
	{
		if(find_LF(buff) == 1)
		{
			control = 1;
			stc = asign_stc(buff);
		}
		else
		{
			buff = malloc(sizeof(buff) + BUFFER_SIZE);
			n_bytes = read(fd, &buff[BUFFER_SIZE], BUFFER_SIZE);
		}
	}

}

int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	printf("%s\n\n", line);
}
