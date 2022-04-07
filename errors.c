/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:41:58 by mtacunan          #+#    #+#             */
/*   Updated: 2022/04/07 12:10:55 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_dim(t_data *map)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(map->table[0]);
	while (i < map->lines)
	{
		if (ft_strlen(map->table[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_chars(t_data *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->lines)
	{
		j = -1;
		while (map->table[i][++j])
		{
			if (map->table[i][j] != '0' && map->table[i][j] != '1'
				&& map->table[i][j] != 'E' && map->table[i][j] != 'P'
				&& map->table[i][j] != 'C' && map->table[i][j] != '\n')
				return (0);
		}
	}
	return (1);
}

void	check_elements(t_data *map)
{
	int	i;
	int	j;
	int	p_aux;
	int	e_aux;

	p_aux = 0;
	e_aux = 0;
	i = -1;
	while (++i < map->lines)
	{
		j = -1;
		while (map->table[i][++j])
		{
			if (map->table[i][j] == 'P')
				p_aux++;
			if (map->table[i][j] == 'E')
				e_aux++;
		}
	}
	map->p_count = p_aux;
	map->e_count = e_aux;
}

int	check_borders(t_data *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->lines)
	{
		if (map->table[i][0] == '\n')
			return (0);
		if (i == 0 || i == map->win_height / map->img_height - 1)
		{
			j = -1;
			while (map->table[i][++j])
			{
				if (map->table[i][j] != '1')
					return (0);
			}
		}
		else
		{	
			if (!(map->table[i][0] == '1'
				&& map->table[i][ft_strlen(map->table[i]) - 1] == '1'))
				return (0);
		}
	}
	return (1);
}

int	validate_map(t_data *map)
{
	check_elements(map);
	if (map->e_count == 0)
		return (0);
	if (map->p_count != 1)
		return (0);
	if (map->coins == 0)
		return (0);
	if (check_chars(map) && check_dim(map) && check_borders(map))
		return (1);
	return (0);
}
