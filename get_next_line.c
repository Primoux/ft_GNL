/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:14:04 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/11 12:48:03 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*str;

	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(buf) != 0)
		{
			str = ft_strjoin(str, buf, ft_strchr(buf));
		}
		else if ()
		{
			str = ft_strlcat(str, buf, ft_strlen(buf));
		}
	}
}
