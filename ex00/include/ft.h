/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <tmalbeck@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:41:26 by tmalbeck          #+#    #+#             */
/*   Updated: 2024/05/06 14:41:26 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

struct s_map
{
	int		lines;
	char	empty;
	char	obstacle;
	char	full;
};

struct s_square
{
	int	start;
	int	end;
	int	size;
};

void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_strlenln(char *str);
char			*ft_strcpy(char *fin, char *org);
char			*map_info(char *map);
int				ft_atoi(char *str);
int				error(struct s_map map_data, char *cut_map);
void			map_parse(char *cut_map, struct s_map map_data);
void			send_fill(struct s_square *square,
					struct s_map map_data, int size, char *cut_map);
struct s_square	sort(struct s_square *square, int j);

#endif