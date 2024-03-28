/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:30:55 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/23 23:30:55 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

#include <stdio.h>

int	map_errparse(struct map_d map_data, char *cut_map);

int	error(struct map_d map_data, char *cut_map)
{
	struct square_d square;
	if (map_data.lines < 1)
		return (-1);
	if ((map_data.empty == map_data.full) || (map_data.full == map_data.obstacle)
		|| (map_data.obstacle == map_data.empty))
		return (-1);
	if ((map_data.empty <= ' ' && map_data.empty >= '~') ||
		(map_data.full <= ' ' && map_data.empty >= '~') ||
		(map_data.obstacle <= ' ' && map_data.empty >= '~'))
		return (-1);
	if (map_errparse(map_data, cut_map) == -1)
		return (-1);
	square = parsing(cut_map, map_data);
	printf("%d\n%d\n", square.start, square.end);
	return (0);
}

int	map_errparse(struct map_d map_data, char *cut_map)
{
	int	i;
	int lenght;

	i = 1;
	while (cut_map[++i] != '\n');
	lenght = i;
	while (cut_map[i] != '\0')
	{
		if (cut_map[i] != map_data.empty &&
			cut_map[i] != map_data.full &&
			cut_map[i] != map_data.obstacle &&
			cut_map[i] != '\n')
			return (-1);
		if (cut_map[i] == '\n')
		{
			if (i % lenght > 0)
				return (-1);
		}
		i++;
	}
	if (cut_map[i - 1] != '\n')
		return (-1);
	return (0);
}