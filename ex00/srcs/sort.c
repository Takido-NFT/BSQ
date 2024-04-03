/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:27:46 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/04/02 15:27:46 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Récupérer toutes les structures générés à l'envers, qui sont précisés avec j, 
on bubble sort square[j].size, on récupère le plus grand on sait donc quelle structure
est la plus grande, ainsi que parmi les plus grande celle la plus en haut à gauche*/

#include "../include/ft.h"

struct  square_d sort(struct square_d *square, int size)
{
	int	i;
	int num;
    int	max;

	i = 0;
	num = 0;
	max = square[i].size;
	while (i < size - 1)
	{
		i++;
		if (max < square[i].size)
		{
			max = square[i].size;
			num = i;
		}
	}
    return (square[num]);
}