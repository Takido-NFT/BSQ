/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:30:55 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/23 23:30:55 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	error(struct map_d map_data)
{
	if (map_data.lines < 1)
		return (-1);
	if ((map_data.empty == map_data.full) || (map_data.full == map_data.obstacle)
		|| (map_data.obstacle == map_data.empty))
		return (-1);
	if ((map_data.empty <= ' ' && map_data.empty >= '~') ||
		(map_data.full <= ' ' && map_data.empty >= '~') ||
		(map_data.obstacle <= ' ' && map_data.empty >= '~'))
		return (-1);
	return (0);
}