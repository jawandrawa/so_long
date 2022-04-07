/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:11:23 by mtacunan          #+#    #+#             */
/*   Updated: 2022/04/07 14:51:40 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_table(t_data *map, char *table)
{
	int		i;
	int		rd;
	int		range_x;

	i = 0;
	rd = open (table, O_RDONLY);
	if (!map->lines)
		ft_error("Introduzca un mapa válido", map);
	map->win_height = map->lines * map->img_height;
	map->table = malloc(sizeof(char *) * map->lines);
	if (!map->table)
		return ;
	while (i < map->lines)
	{
		map->table[i] = get_next_line(rd);
		if (!map->table[i])
		{
			write(2, "Error: el mapa solo puede contener \
un salto de linea al final.\n", 63);
			exit (1);
		}
		i++;
	}
	range_x = ft_strlen(map->table[0]);
	map->win_width = range_x * map->img_width;
	close(rd);
}

void	put_table(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
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

void	get_coins(t_data *map)
{
	int	coins;
	int	i;
	int	j;

	i = 0;
	coins = 0;
	while (i < map->lines)
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

void	init_images(t_data *map)
{
	map->obstacle = mlx_xpm_file_to_image(map->mlx, "./images/obstacle.xpm", \
		&map->img_width, &map->img_height);
	map->img = mlx_xpm_file_to_image(map->mlx, "./images/img_d.xpm", \
		&map->img_width, &map->img_height);
	map->floor = mlx_xpm_file_to_image(map->mlx, "./images/floor.xpm", \
		&map->img_width, &map->img_height);
	map->colect = mlx_xpm_file_to_image(map->mlx, "./images/colect.xpm", \
		&map->img_width, &map->img_height);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./images/exit.xpm", \
		&map->img_width, &map->img_height);
	map->img_u = mlx_xpm_file_to_image(map->mlx, "./images/img_u.xpm", \
		&map->img_width, &map->img_height);
	map->img_r = mlx_xpm_file_to_image(map->mlx, "./images/img_r.xpm", \
		&map->img_width, &map->img_height);
	map->img_l = mlx_xpm_file_to_image(map->mlx, "./images/img_l.xpm", \
		&map->img_width, &map->img_height);
	map->img_d = mlx_xpm_file_to_image(map->mlx, "./images/img_d.xpm", \
		&map->img_width, &map->img_height);
}

void	init_map(t_data *map, char *filename)
{
	map->lines = get_lines(filename);
	get_table(map, filename);
	get_coins(map);
	if (!validate_map(map))
	{
		ft_error("el mapa introducido no cumple las características necesarias.\n\
Por favor pruebe con otro mapa", map);
	}
	map->moves = 0;
	map->mlx = mlx_init();
	init_images(map);
	map->win = mlx_new_window(map->mlx, map->win_width, \
				map->win_height, "mtacunan solong");
	if (!map->obstacle || !map->exit || !map->floor)
		ft_error("No se encontró una de las imágenes", map);
	map->coins_collect = 0;
	put_table(map);
}
