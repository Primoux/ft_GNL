/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:14:04 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/11 20:16:29 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(char *str, char *buf)
{
	int		i;
	int		j;
	char	*tab;

	j = 0;
	i = 0;
	while (buf[i] != '\n')
		i++;
	tab = malloc((ft_strlen(str) + i + 2) * sizeof(char));
	while (str)
	{
		tab[j] = str[j];
		j++;
	}
	i = 0;
	while (buf[i] != '\n')
	{
		tab[j] = buf[i++];
		j++;
	}
	free(str);
	tab[j] = '\n';
	tab[j + 1] = '\0';
	return (tab);
}

void	move_buf(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n' || !buf[i])
	{
		ft_memmove(buf, buf + i, ft_strlen(buf + i));
	}
}

void	*check_buf(char *str, char *buf, int fd)
{
	int	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == 0)
		if (!str)
			return (NULL);
	return ("");
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = "";
	int			bytes_read;
	char		*str;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_strdup("");
	if (check_buf(str, buf, fd) == 0)
		return (NULL);
	while (ft_strchr_nl(buf) == 0)
	{
		str = ft_strjoin(str, buf);
		move_buf(buf);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (check_buf(str, buf, fd) == 0)
			return (NULL);
	}
	str = create_line(str, buf);
	return (str);
}
