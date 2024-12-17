/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:14:04 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/17 08:33:46 by enchevri         ###   ########.fr       */
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

void	fill_tab(char *str, char *buf, char *tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		tab[j] = str[j];
		j++;
	}
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		tab[j] = buf[i++];
		j++;
	}
	if (buf[i] == '\n')
	{
		tab[j] = '\n';
		tab[j + 1] = '\0';
	}
	else
		tab[j] = '\0';
	free(str);
}

char	*create_line(char *str, char *buf)
{
	size_t	i;
	char	*tab;

	i = 0;
	if (!str || !buf)
		return (free(str), NULL);
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		i++;
	tab = malloc((ft_strlen(str) + i + 1) * sizeof(char));
	if (!tab)
		return (free(str), NULL);
	fill_tab(str, buf, tab);
	return (tab);
}

void	move_buf(char *buf)
{
	size_t	i;
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
	ssize_t		bytes_read;
	char		*str;

	str = create_malloc();
	if (BUFFER_SIZE <= 0 || fd < 0 || !str)
		return (free(str), NULL);
	bytes_read = 1;
	while (ft_strchr_nl(buf) == 0 && bytes_read > 0)
	{
		if (buf[0])
		{
			str = create_line(str, buf);
			if (!str)
				return (NULL);
			ft_bzero(buf, ft_strlen(buf), 0);
		}
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return ((free(str), NULL));
	}
	if ((bytes_read == 0 && buf[0] == 0 && str[0] == 0))
		return (free(str), NULL);
	str = create_line(str, buf);
	return (move_buf(buf), str);
}
