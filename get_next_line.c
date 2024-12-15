/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:14:04 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/15 08:50:37 by enchevri         ###   ########.fr       */
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
	int	i;
	int	j;

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
	free(str);
	if (buf[i] == '\n')
	{
		tab[j] = '\n';
		tab[j + 1] = '\0';
	}
	else
		tab[j + i] = '\0';
}

char	*create_line(char *str, char *buf)
{
	int		i;
	char	*tab;

	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	tab = malloc((ft_strlen(str) + i + 2) * sizeof(char));
	fill_tab(str, buf, tab);
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
	ssize_t		bytes_read;
	char		*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = malloc(1);
	str[0] = 0;
	bytes_read = 1;
	while (ft_strchr_nl(buf) == NULL && bytes_read && bytes_read != -1)
	{
		if (buf[0])
		{
			str = ft_strjoin(str, buf);
			ft_bzero(buf, ft_strlen(buf), 0);
		}
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(str), NULL);
		buf[bytes_read] = '\0';
	}
	if (bytes_read <= 0 && buf[0] == 0 && str[0] == 0)
		return (free(str), NULL);
	str = create_line(str, buf);
	
	move_buf(buf);
	return (str);
}
