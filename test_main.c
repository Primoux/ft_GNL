/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:55:29 by enchevri          #+#    #+#             */
/*   Updated: 2024/12/13 15:04:25 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 1;
	fd = open("test1.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	str = get_next_line(fd);
	printf("LIGNE 1 :'%s'\n", str);
	free(str);
	str = get_next_line(fd);
	printf("LIGNE 2 :'%s'\n", str);
	free(str);
	str = get_next_line(fd);
	printf("LIGNE 3 :'%s'\n", str);
	free(str);
	str = get_next_line(fd);
	printf("LIGNE 4 :'%s'\n", str);
	free(str);
	str = get_next_line(fd);
	printf("LIGNE 5 :'%s'\n", str);
	free(str);
	close(fd);
	return (0);
}
