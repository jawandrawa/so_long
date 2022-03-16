/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:23:36 by mtacunan          #+#    #+#             */
/*   Updated: 2022/03/16 16:25:48 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	close_win_x(t_data tab)
// {
// 	if(!)
// 	exit(0);
// }

int	choose_key(int key, t_data *tab)
{
	int	i;
	int	j;

	if (key == 53)
	{
		system("leaks so_long");
		exit(0);
	}
	if (key == 2 || key == 0 || key == 1 || key == 13)
	{
		movings(tab, key);
		i = tab->pos_y / tab->img_height;
		j = tab->pos_x / tab->img_width;
		if (tab->table[i][j] == 'E' && tab->coins_collect == tab->coins)
		{
			mlx_destroy_image(tab->mlx, tab->img);
			mlx_destroy_window(tab->mlx, tab->win);
			system("leaks so_long");
			exit(1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	tab;

	if (argc == 2)
	{
		printf("lines: %d\n",get_lines(argv[1]));
		tab.img_height = 64;
		tab.img_width = 64;
		init_map(&tab, argv[1]);
		mlx_key_hook(tab.win, choose_key, &tab);
		mlx_loop(tab.mlx);
	}
	else
		return (0);
}
