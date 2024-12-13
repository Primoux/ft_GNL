/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:14:04 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/13 19:03:48 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_bzero(char *s, size_t end, size_t start)
{
	while (start < end)
	{
		s[start] = '\0';
		start++;
	}
	return (s);
}

char	*create_line(char *str, char *buf)
{
	int		i;
	int		j;
	char	*tab;
	int		x;

	x = 0;
	j = 0;
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	
	free(str);
	if (buf[i] == '\n')
	{
		tab[j + i] = '\n';
		tab[j + i + 1] = '\0';
	}
	else
	{
		tab[j + i] = '\0';
	}
	return (tab);
}



void	move_buf(char *buf)
{
	int		i;
	size_t	new_buf_len;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		i++;
	new_buf_len = ft_strlen(buf + i);
	ft_memmove(buf, buf + i, new_buf_len);
	ft_bzero(buf, ft_strlen(buf), new_buf_len);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	int			bytes_read;
	char		*str;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(1);
	str[0] = 0;
	bytes_read = 1;
	while (ft_strchr_nl(buf) == NULL && bytes_read != 0)
	{
		if (buf[0])
		{
			str = ft_strjoin(str, buf);
			ft_bzero(buf, ft_strlen(buf), 0);
		}
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
	}
	if (bytes_read == 0 && buf[0] == 0)
		return (free(str), NULL);
	str = create_line(str, buf);
	move_buf(buf);
	return (str);
}
