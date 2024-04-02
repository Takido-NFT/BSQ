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

#include <stdio.h>

struct	square_d square_calc(char *cut_map, struct map_d map_data, int i);

struct	square_d *map_parse(char *cut_map, struct map_d map_data)
{
	int	i;
	int j;
	struct square_d *square;
	
	i = 0;
	j = 0;
	while (cut_map[i] != '\0')
	{
		if ((cut_map[i] == map_data.empty) && (cut_map[i - 1] == map_data.obstacle))
			j++;
		i++;
	}
	square = malloc(j * sizeof(struct square_d));
	i = 0;
	j = 0;
	while (cut_map[i] != '\0')
	{
		if ((cut_map[i] == map_data.empty) && (cut_map[i - 1] == map_data.obstacle))
		{
			square[j] = square_calc(cut_map, map_data, i);
			j++;
		}
		i++;
	}
	printf("Start : %d\n", square[1].start);
	printf("End : %d\n", square[1].end);
	printf("Size : %d\n\n", square[1].size);
	return (square);
}

struct	square_d square_calc(char *cut_map, struct map_d map_data, int i)
{
	int	width;
	int	temp;
	int check;
	int	map_wid = ft_strlenln(cut_map);
	struct square_d square;
	

	width = 0;
	temp = 0;
	check = 0;
	square.start = i;
	while (cut_map[i] == map_data.empty)
	{
		width++;
		i++;
	}
	i = i - width;
	printf("width = %d\n", width);
	if (width > 1)
	{
		while (temp < width)
		{
			if (cut_map[i + map_wid * temp] == map_data.empty)
			{
				while (check < width)
				{
					if (cut_map[i + map_wid * temp + check] == map_data.empty)
						check++;
					else
					{
						square.size = 0;
						return (square);
					}
				}
				check = 0;
			}
			else
			{
				square.size = 0;
				return (square);
			}
			temp++;
		}
		square.end = i + width + map_wid * (temp - 1);
		square.size = width * width;
	}
	else 
	{
		square.end = square.start;
		square.size = 1;
	}
	return (square);
}
/*Fonction qui lit toute la map, puis quand une char vide est rencontré, alors on appelle une fonction
  qui va déterminer la longeur de la ligne de char vide et ensuite regarder si les lignes inférieurs
  sont elles aussi de char vide et quelles forment la longeur attendue du carré, si oui alors une structure
  square_d sera renvoyé, contenant le nombre du char de début, de fin, ainsi que la taille du carré*/
