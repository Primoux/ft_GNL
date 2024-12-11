/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:14:01 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/11 11:42:28 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s)
{
	int	i;

	i = 0;
	while (s[i] || s[i] == '\n')
	{
		if (s[i] == '\n')
		{
			return (&s[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	len_s2;
	size_t	len_s1;
	size_t	i;
	char *str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (size == 0 || !str)
		return (NULL);
	i = 0;
	while (len_s1 + i < size - 1 && s2[i] != '\0')
	{
		s1[len_s1 + i] = s2[i];
		i++;
	}
	s1[len_s1 + i] = '\0';
	return (len_s1 + len_s2);
}
