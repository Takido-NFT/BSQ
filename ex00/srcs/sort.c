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

#include <stdio.h>

struct  square_d sort(struct square_d *square, int j)
{
    int temp;
    int sup;
    int k;

    temp = j;
    sup = 0;
    k = j - 3;
    printf("j = %d\n", j);
    while (k > 0)
    {
        while (j > 0)
        {
            if (square[k].size >= square[j].size)
            {
                sup++;
            }
            if (square[k].size < square[j].size)
            {
                sup--;
            }
            if (sup == temp)
            {
                printf("size = %d\n", square[k].size);
                return (square[k]);
            }
            j--;
        }
        sup = 0;
        j = temp;
        k--;
    }
    return (square[k]);
}