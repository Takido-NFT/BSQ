/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:49:13 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/23 22:49:13 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

int	ft_atoi(char *str)
{
	int	res;
	int	signe;
	int	i;

	res = 0;
	signe = 1;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * signe);
}
