/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:16:17 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/03/22 11:16:17 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER 1000

char	*get_map(char *av)
{
	int		file;
	int		size;
	int		buffer;
	char	*str;

	buffer = buffer_size(av);
	str = (char *)malloc(buffer * sizeof(char));
	file = open(av, O_RDWR);
	if (file == -1)
	{
		ft_putstr("map error\n");
		return (NULL);
	}
	size = read(file, str, buffer);
	if (size == -1)
	{
		close(file);
		ft_putstr("map error\n");
		return (NULL);
	}
	str[size] = '\0';
	close(file);
	return (str);
}

char	*get_stdin(void)
{
	int		size;
	char	*str;

	str = (char *)malloc(BUFFER * sizeof(char));
	size = read(STDIN_FILENO, str, BUFFER);
	if (size == -1)
	{
		ft_putstr("map error\n");
		close(size);
		return (NULL);
	}
	str[size] = '\0';
	close(size);
	return (str);
}

char	*clear_map(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[j] != '\0')
	{
		str[i] = str[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	result_map(char *map, char *str)
{
	if (map != NULL)
	{
		str = map_info(map);
		if (str != NULL)
			ft_putstr(clear_map(str));
		else
			ft_putstr("map error\n");
	}
	free(map);
	free(str);
}

int	main(int ac, char *av[])
{
	char	*map;
	char	*str;
	int		i;

	map = NULL;
	str = NULL;
	i = 1;
	if (ac == i)
	{
		map = get_stdin();
		result_map(map, str);
	}
	while (ac > i)
	{
		map = get_map(av[i++]);
		result_map(map, str);
	}
	return (0);
}
