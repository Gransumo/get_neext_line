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
	int			n_bytes;
	static char	*missing_text;
	char		*buff;
	int			control;

	control = 0;
	buff = malloc (BUFFER_SIZE);
	if (missing_text != '\0')
		*new = missing_text;
	while (control == 0)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == 0 && new == NULL)
			return (NULL);
		new = ft_strjoin(new, buff);
		if (ft_strchr (new, '\n') != NULL)
			control = 1;
	}
	missig_text = ft_strchr (new, '\n');
	new = final_str (new);
	free (buff);
	return (new);
}
