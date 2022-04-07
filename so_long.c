/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:23:36 by mtacunan          #+#    #+#             */
/*   Updated: 2022/04/07 15:57:52 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char *filename, char *compare)
{
	int	len;
	int	i;

	len = ft_strlen(filename);
	i = len - 4;
	while (i < len)
	{
		if (filename[i] != *compare)
			return (0);
		compare++;
		i++;
	}
	return (1);
}

int	choose_key(int key, t_data *tab)
{
	int	i;
	int	j;

	if (key == 53)
	{
		free_map(tab);
		exit (0);
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
			exit(1);
		}
	}
	return (0);
}

int	close_win_x(void)
{
	exit (1);
	return (1);
}

void	c_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_data	tab;

	atexit(c_leaks);
	if (argc == 2 && check_format(argv[1], ".ber"))
	{
		tab.img_height = 64;
		tab.img_width = 64;
		init_map(&tab, argv[1]);
		mlx_key_hook(tab.win, choose_key, &tab);
		mlx_hook(tab.win, 17, 1L << 17, close_win_x, &tab);
		mlx_loop(tab.mlx);
	}
	else
	{
		write(2, "Error: el programa necesita un único argumento \
 de tipo \".ber\".\n", 65);
		return (1);
	}
}
