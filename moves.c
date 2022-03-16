/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:11:20 by mtacunan          #+#    #+#             */
/*   Updated: 2022/03/16 15:11:21 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	m_rigth(t_data *tab)
{
	int	i;
	int	j;

	i = tab->pos_y / tab->img_height;
	j = tab->pos_x / tab->img_width;
	if (tab->table[i][j] == 'C')
	{
		tab->coins_collect++;
		tab->table[i][j] = '0';
	}
	if (!((tab->table[i][j + 1] == 'E' && tab->coins != tab->coins_collect)
		|| tab->table[i][j + 1] == '1'))
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, \
			tab->pos_x, tab->pos_y);
		tab->pos_x += tab->img_width;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, \
			tab->pos_x, tab->pos_y);
	}
}

void	m_left(t_data *tab)
{
	int	i;
	int	j;

	i = tab->pos_y / tab->img_height;
	j = tab->pos_x / tab->img_width;
	if (tab->table[i][j] == 'C')
	{
		tab->coins_collect++;
		tab->table[i][j] = '0';
	}
	if (!((tab->table[i][j - 1] == 'E' && tab->coins != tab->coins_collect)
		|| tab->table[i][j - 1] == '1'))
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, \
		tab->pos_x, tab->pos_y);
		tab->pos_x -= tab->img_width;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, \
		tab->pos_x, tab->pos_y);
	}
}

void	m_up(t_data *tab)
{
	int	i;
	int	j;

	i = tab->pos_y / tab->img_height;
	j = tab->pos_x / tab->img_width;
	if (tab->table[i][j] == 'C')
	{
		tab->coins_collect++;
		tab->table[i][j] = '0';
	}
	if (!((tab->table[i - 1][j] == 'E' && tab->coins != tab->coins_collect)
		|| tab->table[i - 1][j] == '1'))
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, \
		tab->pos_x, tab->pos_y);
		tab->pos_y -= tab->img_height;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, \
		tab->pos_x, tab->pos_y);
	}
}

void	m_down(t_data *tab)
{
	int	i;
	int	j;

	i = tab->pos_y / tab->img_height;
	j = tab->pos_x / tab->img_width;
	if (tab->table[i][j] == 'C')
	{
		tab->coins_collect++;
		tab->table[i][j] = '0';
	}
	if (!((tab->table[i + 1][j] == 'E' && tab->coins != tab->coins_collect)
		|| tab->table[i + 1][j] == '1'))
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, \
		tab->pos_x, tab->pos_y);
		tab->pos_y += tab->img_height;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, \
		tab->pos_x, tab->pos_y);
	}
}

void	movings(t_data *tab, int key)
{
	if (key == 2)
		m_rigth(tab);
	if (key == 0)
		m_left(tab);
	if (key == 13)
		m_up(tab);
	if (key == 1)
		m_down(tab);
}
