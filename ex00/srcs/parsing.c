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

struct	square_d parsing(char *cut_map, struct map_d map_data)
{
	int	i;
	int	j;
	int width;
	int temp;
	int check;
	int end_empty;
	struct square_d square;

	i = 0;
	j = 0;
	width = 0;
	temp = 0;
	check = 0;
	end_empty = 0;
	while (cut_map[i] != '\0')
	{
		if (cut_map[i] == map_data.empty)
		{
			j = i; //keep the start value
			square.start = j;
			while (cut_map[i] == map_data.empty)
			{
				width++;
				i++;
			}
			end_empty = i;
			temp = width;
			i = j; //keep the start
			while (temp > 0)
			{
				while (cut_map[i + (map_data.lines * temp)] == map_data.empty)
				{
					check++;
					i++;
				}
				if (check != width)
					square.start = -1;
				i = j;
				check = 0;
				temp--;
			}
			square.end = width;
			i = end_empty;
		}
		i++;
	}
	return (square);
}
/*Récupérer la longeur de la ligne vide, puis regarder chaque line inférieur si elle est complètement
  vide on a: str[i] jusqu'à str[i + 3] qui est vide alors on va checker si: str[i + (map_data.lines * width)]
  jusqu'à str[i + 3 + (map_data.lines * witdh]*/
