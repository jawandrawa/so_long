/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:11:23 by mtacunan          #+#    #+#             */
/*   Updated: 2022/03/16 17:21:25 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_table(t_data *map, char *table)
{
	/*check que termine en .ber*/
	int	i;
	int	lines;
	int	fd;
	int	range_x;

	i = 0;
	fd = open (table, O_RDONLY);
	lines = get_lines(table);
	map->win_height = lines * map->img_height;
	map->table = malloc(sizeof(char *) * lines);
	while (i < lines)
	{
		map->table[i] = get_next_line(fd);
		i++;
	}
	range_x = ft_strlen(map->table[0]) - 1;
	map->win_width = range_x * map->img_width;
	close(fd);
}

void	put_image(void *name_image, int i, int j,t_data *map)
{
	mlx_put_image_to_window(map->mlx, map->win, name_image, \
	j * map->img_width, i * map->img_height);
}

void	put_table(t_data *map, char *filename)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_lines(filename))
	{
		j = 0;
		while (map->table[i][j])
		{
			if (map->table[i][j] == '1')
				put_image(map->obstacle, i, j, map);
			else if (map->table[i][j] == 'P')
			{
				map->pos_x = j * map->img_width;
				map->pos_y = i * map->img_height;
				put_image(map->img, i, j, map);
			}
			else if (map->table[i][j] == 'C')
				put_image(map->colect, i, j, map);
			else if (map->table[i][j] == 'E')
				put_image(map->exit, i, j, map);
			j++;
		}
		i++;
	}
}

void	get_coins(t_data *map, char *filename)
{
	int	coins;
	int	lines;
	int	i;
	int	j;

	i = 0;
	coins = 0;
	lines = get_lines(filename);
	while (i < lines)
	{
		j = 0;
		while (map->table[i][j])
		{
			if (map->table[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	map->coins = coins;
}

int	get_lines(char *table)
{
	int		cont;
	char	*aux;
	int		fd;

	fd = open (table, O_RDONLY);
	cont = 0;
	aux = "";
	while (aux)
	{
		aux = get_next_line(fd);
		if (!aux)
			break ;
		cont++;
		free(aux);
	}
	close(fd);
	free(aux);
	return (cont);
}

void	init_map(t_data *map, char *filename)
{
	map->mlx = mlx_init();
	map->obstacle = mlx_xpm_file_to_image(map->mlx, "./images/obstacle.xpm", \
	&map->img_width, &map->img_height);
	map->img = mlx_xpm_file_to_image(map->mlx, "./images/image.xpm", \
	&map->img_width, &map->img_height);
	map->floor = mlx_xpm_file_to_image(map->mlx, "./images/floor.xpm", \
	&map->img_width, &map->img_height);
	map->colect = mlx_xpm_file_to_image(map->mlx, "./images/colect.xpm", \
	&map->img_width, &map->img_height);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./images/exit.xpm", \
	&map->img_width, &map->img_height);
	if(!map->obstacle || !map->img)
	{
		write(1, "Se fué a la verga\n", 19);
		exit(1);	
	}
	map->win = mlx_new_window(map->mlx, map->win_width, \
				map->win_height, "mtacunan solong");
	get_table(map, filename);
	map->coins_collect = 0;
	get_coins(map, filename);
	put_table(map, filename);
}
