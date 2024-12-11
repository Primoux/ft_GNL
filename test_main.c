/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:55:29 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/09 20:12:36 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	int		i;

	i = 1;
	if (argc < 2)
	{
		printf("No args");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%d :%s", i, str);
		i++;
		free(str);
		if (i > 20)
		{
			return (1);
		}
	}
	close(fd);
	return (0);
}
