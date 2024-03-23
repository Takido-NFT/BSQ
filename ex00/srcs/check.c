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

struct map_d
{
	int lines;
	char empty;
	char obstacle;
	char full;
};

struct map_d struct_map_data(char *map_sdata, int i)
{
	struct map_d map_data;

	map_data.lines = ft_atoi(map_sdata);
	map_data.empty = map_sdata[i - 4];
	map_data.obstacle = map_sdata[i - 3];
	map_data.full = map_sdata[i - 2];
	return (map_data);
}

char	*map_info(char *map)
{
	char	*cut_map;
	char	*map_sdata;
    int		i;
	int		j;
	struct map_d map_data;

	map_sdata = malloc((ft_strlen(map) + 1) * sizeof(char));
	cut_map = malloc((ft_strlen(map) + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (map[i - 1] != '\n')
	{
		map_sdata[i] = map[i];
		i++;
	}
	map_sdata[i] = '\0';
	map_data = struct_map_data(map_sdata, i);
	printf("Lines : %d\n", map_data.lines);
	printf("Empty character : %c\n", map_data.empty);
	printf("Obstacle character : %c\n", map_data.obstacle);
	printf("Full character : %c\n", map_data.full);
	while (map[i] != '\0')
	{
		cut_map[j] = map[i];
		i++;
		j++;
	}
	cut_map[j] = '\0';
	free(map_sdata);
	return (cut_map);
}