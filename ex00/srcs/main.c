/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:16:17 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/22 11:16:17 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER 1000

char	*get_map(char *av)
{
	int		file;
	int		size;
	char	*str;

	str = (char *)malloc(BUFFER * sizeof(char));
	file = open(av, O_RDWR);
	if (file == -1)
		return ("map error\n");
	size = read(file, str, BUFFER);
	if (size == -1)
	{
		close(file);
		return ("map error\n");
	}
	str[size] = '\0';
	close(file);
	return (str);
}

int	main(int ac, char *av[])
{
	char	*map;
	while (ac >= 2)
	{
		map = get_map(av[ac - 1]);
		ft_putstr(map_info(map));
		ac--;
	}
	free(map);
	return (0);
}