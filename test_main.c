/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:55:29 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/15 11:55:54 by enchevri         ###   ########.fr       */
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
	int		i;

	i = 0;
	fd = open("/home/enchevri/francinette/tests/get_next_line/fsoares/1char.txt",
			O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE %d: '%s'\n", i++, str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	i = 0;
	printf("---------------------------------------------------------------------------------------------------------------\n");
	fd = open("/home/enchevri/francinette/tests/get_next_line/fsoares/empty.txt",
			O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE %d: '%s'\n", i++, str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	printf("---------------------------------------------------------------------------------------------------------------\n");
	fd = open("/home/enchevri/francinette/tests/get_next_line/fsoares/giant_line.txt",
			O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE %d: '%s'\n", i++, str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	printf("---------------------------------------------------------------------------------------------------------------\n");
	fd = open("/home/enchevri/francinette/tests/get_next_line/fsoares/lines_around_10.txt",
			O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE %d: '%s'\n", i++, str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	printf("---------------------------------------------------------------------------------------------------------------\n");
	fd = open("/home/enchevri/francinette/tests/get_next_line/fsoares/multiple_nl.txt",
			O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE %d: '%s'\n", i++, str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	printf("---------------------------------------------------------------------------------------------------------------\n");
	fd = open("/home/enchevri/francinette/tests/get_next_line/fsoares/one_line_no_nl.txt",
			O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE %d: '%s'\n", i++, str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	printf("---------------------------------------------------------------------------------------------------------------\n");
	fd = open("/home/enchevri/francinette/tests/get_next_line/fsoares/only_nl.txt",
			O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE %d: '%s'\n", i++, str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	printf("---------------------------------------------------------------------------------------------------------------\n");
	fd = open("/home/enchevri/francinette/tests/get_next_line/fsoares/read_error.txt",
			O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE %d: '%s'\n", i++, str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	printf("---------------------------------------------------------------------------------------------------------------\n");
	
	fd = open("/home/enchevri/francinette/tests/get_next_line/fsoares/variable_nls.txt",
			O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("LIGNE %d: '%s'\n", i++, str);
		free(str);
	}
	str = get_next_line(fd);
	printf("LIGNE : '%s'\n", str);
	free(str);
	close(fd);
	return (0);
}
