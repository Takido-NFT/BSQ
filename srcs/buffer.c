/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:07:27 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/05/14 09:07:27 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER 1000

int	get_witdh(char *map)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (map[i - 1] != '\n')
		i++;
	while (map[i] != '\n')
	{
		i++;
		width++;
	}
	width += 2;
	return (width);
}

char	*get_height(char *av)
{
	int		file;
	int		size;
	char	*map;

	map = (char *)malloc(BUFFER * sizeof(char));
	file = open(av, O_RDWR);
	if (file == -1)
	{
		ft_putstr("map error\n");
		return (NULL);
	}
	size = read(file, map, BUFFER);
	if (size == -1)
	{
		close(file);
		ft_putstr("map error\n");
		return (NULL);
	}
	map[size] = '\0';
	close(file);
	return (map);
}

int	buffer_size(char *av)
{
	char	*map;
	int		height;
	int		width;

	map = get_height(av);
	height = ft_atoi(map);
	width = get_witdh(map);
	free(map);
	return (height * width);
}
