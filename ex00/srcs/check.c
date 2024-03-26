/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:19:10 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/22 16:19:10 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"
#include <stdlib.h>

#include <stdio.h>

int struct_map_data(char *map_sdata, int i, char *cut_map)
{
	struct map_d map_data;

	if (map_sdata[i - 5] >= '0' && map_sdata[i - 5] <= '9')
	{
		map_data.lines = ft_atoi(map_sdata);
		map_data.empty = map_sdata[i - 3];
		map_data.obstacle = map_sdata[i - 2];
		map_data.full = map_sdata[i - 1];
	}
	else
		return (-1);
	/*
	printf("Lines: %d\n", map_data.lines);
	printf("Empty: %c\n", map_data.empty);
	printf("Full: %c\n", map_data.full);
	printf("Obstacle: %c\n", map_data.obstacle);
	*/
	if (error(map_data, cut_map) == -1)
		return (-1);
	return (0);
}

char	*map_cut(char *map, int i, char *map_sdata)
{
	char	*cut_map;
	int		temp;
	int		j;

	temp = i;
	j = 0;
	cut_map = malloc((ft_strlen(map) + 1) * sizeof(char));
	while (map[i] != '\0')
	{
		cut_map[j] = map[i];
		i++;
		j++;
	}
	cut_map[j] = '\0';
	if (struct_map_data(map_sdata, temp, cut_map) == -1)
		return (NULL);
	return (cut_map);
}

char	*map_info(char *map)
{
	char	*map_sdata;
    int		i;

	map_sdata = malloc((ft_strlen(map) + 1) * sizeof(char));
	i = 0;
	while (map[i] != '\n')
	{
		map_sdata[i] = map[i];
		i++;
	}
	map_sdata[i] = '\0';
	return (map_cut(map, i, map_sdata));
}
