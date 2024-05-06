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

char	*square_fill(char *cut_map, struct s_square square,
	struct s_map map_data, int i)
{
	int		map_wid;
	int		iteration;
	int		width;

	map_wid = ft_strlenln(cut_map);
	iteration = 0;
	width = square.size;
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
			i = i + map_wid - width - 1;
			iteration = 0;
		}
		i++;
	}
	return (cut_map);
}

char	*square_fill_one(char *cut_map,
	struct s_map map_data, int i)
{
	cut_map[i] = map_data.full;
	return (cut_map);
}

void	send_fill(struct s_square *square,
	struct s_map map_data, int size, char *cut_map)
{
	struct s_square	biggest;
	int				i;

	biggest = sort(square, size);
	i = biggest.start;
	if (biggest.size > 1)
		square_fill(cut_map, biggest, map_data, i);
	else
		square_fill_one(cut_map, map_data, i);
}
