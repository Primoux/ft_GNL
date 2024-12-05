/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:46:47 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/05 14:23:52 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	static char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		i++;
	}
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	buf[bytes_read] = '\0';
    // printf("%d", bytes_read);
}
