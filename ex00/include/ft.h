#ifndef FT_H
# define FT_H

struct map_d
{
	int lines;
	char empty;
	char obstacle;
	char full;
};

struct square_d {
	int	start;
	int	end;
	int size;
};

void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *fin, char *org);
char	*map_info(char *map);
int	    ft_atoi(char *str);
int		error(struct map_d map_data, char *cut_map);
struct	square_d *map_parse(char *cut_map, struct map_d map_data);

#endif