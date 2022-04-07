/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:44:38 by mtacunan          #+#    #+#             */
/*   Updated: 2022/04/07 14:48:32 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(void *name_image, int i, int j, t_data *map)
{
	mlx_put_image_to_window(map->mlx, map->win, name_image, \
	j * map->img_width, i * map->img_height);
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
	free(aux);
	close(fd);
	return (cont);
}

void	ft_error(char *msg, t_data *map)
{
	write(2, "Error", 6);
	if (msg)
	{
		write(2, ": ", 3);
		write(2, msg, ft_strlen(msg));
	}
	write(2, "\n", 1);
	if (map->lines > 0)
		free_map(map);
	exit(1);
}

void	free_map(t_data *map)
{
	while (map->lines >= 0)
	{
		free(map->table[map->lines - 1]);
		map->lines--;
	}
	free(map->table);
}
