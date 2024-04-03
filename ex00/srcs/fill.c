/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:51:25 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/04/03 14:51:25 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

#include <stdio.h>

/*Add particular case for size 1*/
char	*square_fill(char *cut_map, struct square_d square, struct map_d map_data)
{
	//char 	*fill_map;
	int		map_wid;
	int		iteration;
	int		width;
	int		i;

	//fill_map = malloc((ft_strlen(cut_map) + 1) * sizeof(char));
	map_wid = ft_strlenln(cut_map);
	printf("map_width = %d\n", map_wid);
	iteration = 0;
	i = square.start;
	width = 0;
	while (cut_map[i] == map_data.empty)
	{
		width++;
		i++;
	}
	i = square.start;
	while (i < square.end)
	{
		if (iteration < width)
		{
			cut_map[i] = map_data.full;
			iteration++;
		}
		else
		{
			printf("i = %d\n", i);
			i = i + map_wid - width - 1;
			iteration = 0;
		}
		i++;
	}
	printf("Filled map :\n%s\n", cut_map);
	return (cut_map);
}