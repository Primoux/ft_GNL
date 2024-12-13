/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:14:04 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/13 15:55:53 by enchevri         ###   ########.fr       */
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
	tab = malloc((ft_strlen(str) + i + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (str[j])
	{
		tab[j] = str[j];
		j++;
	}
	while (x < i && buf[x])
	{
		tab[j + x] = buf[x];
		x++;
	}
	free(str);
	if (buf[i] == '\n')
		tab[j + i] = '\n';
	tab[j + i + 1] = '\0';
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
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	// str = malloc(1);
	// str[0] = 0;
	str = strdup("");
	bytes_read = 1;
	while (ft_strchr_nl(buf) == NULL && bytes_read != 0)
	{
		printf("%dx : buf at start : '%s'\n", i, buf);
		printf("%dx : str at start : '%s'\n", i, str);
		if (buf[0])
		{
			str = ft_strjoin(str, buf);
			ft_bzero(buf, ft_strlen(buf), 0);
		}
		printf("%dx : buf at end   : '%s'\n", i, buf);
		printf("%dx : str at end   : '%s'\n", i, str);
		printf("----------------------------------------\n");
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		i++;
	}
	if (bytes_read == 0 && buf[0] == 0)
		return (NULL);
	str = create_line(str, buf);
	move_buf(buf);
	return (str);
}
