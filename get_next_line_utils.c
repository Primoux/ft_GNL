/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:14:01 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/13 18:48:58 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_nl(char *s)
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
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (size-- > 0)
			((unsigned char *)dest)[size] = ((unsigned char *)src)[size];
	}
	else
		while (i < size)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	return (dest);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	tab = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[x] = s1[i++];
		x++;
	}
	i = 0;
	while (s2[i])
	{
		tab[x] = s2[i++];
		x++;
	}
	free(s1);
	tab[x] = '\0';
	return (tab);
}
