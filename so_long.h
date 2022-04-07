/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:58:34 by mtacunan          #+#    #+#             */
/*   Updated: 2022/04/07 14:48:22 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "../so_long/gnl/get_next_line.h"

typedef struct s_data
{
	char	**table;
	int		lines;
	void	*mlx;
	void	*win;
	void	*img_u;
	void	*img_r;
	void	*img_l;
	void	*img_d;
	void	*img;
	void	*exit;
	void	*obstacle;
	void	*colect;
	void	*floor;
	int		img_width;
	int		img_height;
	int		pos_y;
	int		pos_x;
	int		win_width;
	int		win_height;
	int		coins;
	int		coins_collect;
	int		p_count;
	int		e_count;
	int		moves;
}	t_data;
void	init_images(t_data *map);
void	ft_error(char *msg, t_data *map);
void	put_image(void *name_image, int i, int j, t_data *map);
int		get_lines(char *table);
int		check_format(char *filename, char *compare);
int		check_borders(t_data *map);
int		check_chars(t_data *map);
int		validate_map(t_data *map);
void	get_table(t_data *map, char *table);
void	get_coins(t_data *map);
void	put_table(t_data *map);
void	init_map(t_data *map, char *filename);
void	m_rigth(t_data *tab);
void	m_left(t_data *tab);
void	m_up(t_data *tab);
void	m_down(t_data *tab);
void	movings(t_data *tab, int key);
void	free_map(t_data *map);

#endif