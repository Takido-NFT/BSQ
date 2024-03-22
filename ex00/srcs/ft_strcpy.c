/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:37:09 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/22 16:37:09 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

char	*ft_strcpy(char *fin, char *org)
{
	int	i;

	i = 0;
	while (org[i] != '\0')
	{
		fin[i] = org[i];
		i++;
	}
	fin[i] = '\0';
	return (fin);
}