/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:55:29 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/14 19:36:11 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


int	main(void)
{
	int		fd;
	char	*str;

	fd = open("read_error.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE : '%s'\n", str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	return (0);
}
