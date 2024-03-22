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

char	*map_info(char *map)
{
	char	*cut_map;
    int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i - 1] != '\n')
		i++;
	while (map[i] != '\0')
	{
		cut_map[j] = map[i];
		i++;
		j++;
	}
	cut_map[j] = '\0';
	return (cut_map);
}