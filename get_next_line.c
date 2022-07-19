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
	char	*buff;
	int		n_bytes;

	buff = malloc(20);
	n_bytes = read(fd, buff, 20);
	
}

int main()
{
	int fd;

	fd = open("text.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	printf("%s\n\n", line);
}
