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
#include "../include/ft.h"

struct s_square	sort(struct s_square *square, int size)
{
	int	i;
	int	num;
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
