/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:03:22 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/28 10:03:22 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"
#include <stdlib.h>

struct s_square	square_exit(struct s_square square)
{
	square.size = 0;
	return (square);
}

struct s_square	square_values(int i, int width, int temp, int map_wid)
{
	struct s_square	square;

	square.start = i;
	square.end = i + width + map_wid * (temp - 1);
	square.size = width;
	return (square);
}

struct s_square	square_check(char *cut_map,
	struct s_map map_data, int i, int width)
{
	int				map_wid;
	int				temp;
	int				check;
	struct s_square	square;

	map_wid = ft_strlenln(cut_map);
	temp = 0;
	while (temp < width)
	{
		if (cut_map[i + map_wid * temp] == map_data.empty)
		{
			check = 0;
			while (check < width)
			{
				if (cut_map[i + map_wid * temp + check] == map_data.empty)
					check++;
				else
					return (square_exit(square));
			}
		}
		else
			return (square_exit(square));
		temp++;
	}
	return (square_values(i, width, temp, map_wid));
}

struct s_square	square_calc(char *cut_map, struct s_map map_data, int i)
{
	int				width;
	struct s_square	square;

	width = 0;
	square.start = i;
	while (cut_map[i++] == map_data.empty)
		width++;
	i = i - width - 1;
	if (width > 1)
	{
		while (width > 0)
		{
			square = square_check(cut_map, map_data, i, width);
			if (square.size > 0)
				return (square);
			width--;
		}
	}
	else
	{
		square.end = square.start;
		square.size = 1;
	}
	return (square);
}

void	map_parse(char *cut_map, struct s_map map_data)
{
	int				i;
	int				size;
	struct s_square	*square;

	i = 0;
	size = 0;
	while (cut_map[i++] != '\0')
	{
		if ((cut_map[i] == map_data.empty) \
			&& (cut_map[i - 1] == map_data.obstacle
				|| cut_map[i - 1] == '\n'))
			size++;
	}
	square = malloc(size * sizeof(struct s_square));
	i = 0;
	size = 0;
	while (cut_map[i++] != '\0')
	{
		if ((cut_map[i] == map_data.empty) \
			&& (cut_map[i - 1] == map_data.obstacle
				|| cut_map[i - 1] == '\n'))
			square[size++] = square_calc(cut_map, map_data, i);
	}
	send_fill(square, map_data, size, cut_map);
	free(square);
}
