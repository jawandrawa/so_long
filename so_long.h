#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "../so_long/gnl/get_next_line.h"
#include "../so_long/gnl/get_next_line.c"
#include "../so_long/gnl/get_next_line_utils.c"



typedef struct s_data {
	char	**table; //el mapa
	void	*mlx; 
	void	*win;  //la ventana
	void	*img;
	void	*obstacle;
	void	*colect;
	void	*floor;
	int		img_width;
	int		img_height;
	int		pos_y; //del img
	int		pos_x;
	int		win_width;
	int		win_height;
	
}	t_data;

void get_table(t_data *map,char *table);

#endif