

#include "so_long.h"
typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*floor;
	int		img_width;
	int		img_height;
	int		pos_y;
	int		pos_x;
	
}	t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void put_image(t_data *info)
// {
// 	info->img = mlx_xpm_file_to_image(info->mlx, "image.xpm", &info->img_width, &info->img_height);
// 	info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->line_length, &info->endian);
// 	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
// 	//mlx_loop(info->mlx);
// }
void movings (t_data *tab, int key)
{
	if(key == 2 && tab->pos_x + 64 < 1920) //derecha
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, tab->pos_x , tab->pos_y);
		tab->pos_x += 64;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, tab->pos_x , tab->pos_y);
	}
	if(key == 0 && tab->pos_x - 64 >= 0) //izquierda
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, tab->pos_x , tab->pos_y);
		tab->pos_x -= 64;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, tab->pos_x , tab->pos_y);
	}
	if(key == 13 && tab->pos_y - 64 >= 0) //arriba
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, tab->pos_x , tab->pos_y);
		tab->pos_y -= 64;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, tab->pos_x , tab->pos_y );
	}
	if(key == 1 && tab->pos_y + 64 < 1080) //abajo
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, tab->pos_x , tab->pos_y);
		tab->pos_y += 64;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, tab->pos_x ,tab->pos_y);
	}
	return;
}

int	choose_key(int key, t_data *vars)
{
	//escp : 53
	if(key == 53)
	{
		mlx_destroy_image(vars->mlx,vars->img);
 		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (key == 2 || key == 0 ||  key== 1 || key == 13)
	{
		printf("%p",vars);
		movings(vars,key);
	}

	//a : 0
	//s : 1
	//d : 2
	//w : 13

	return (0);
}


// int close(t_data *vars)
// {
// 		mlx_destroy_image(vars->mlx,vars->img);
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// }

// int	main(void)
// {
// 	t_data	vars;
// 	void *window;

// 	vars.mlx = mlx_init();
// 	window = mlx_new_window(vars.mlx, 1080, 1080, "Hello world!");
// 	// put_image(&vars);
// 	// printf("muero\n");
// 	// mlx_key_hook(vars.win, choose_key, &vars); //holdea las teclas 
// 	// //mlx_hook(vars.win,5,1L<<5,close,vars.mlx);
// 	// mlx_loop(vars.mlx);
// }

// int	main(void)
// {
// 	t_data	tab;
// 	info_tab tab;
// 	tab.mlx = mlx_init();
// 	tab.win = mlx_new_window(tab.mlx, 1920, 1080, "mtacunan solong");
// 	mlx_key_hook(tab.win, choose_key, &tab);
// 	mlx_xpm_file_to_image(tab.mlx, "image.xpm",&tab.img_width, &tab.img_height);
// 	// tab.addr = mlx_get_data_addr(tab.img, &tab.bits_per_pixel, &tab.line_length, &tab.endian);
// 	// mlx_put_image_to_window(tab.mlx, tab.win, tab.img, 0, 0);
// 	mlx_loop(tab.mlx);

// }
int	main(void)
{
	t_data tab;
	
	//inizializar todas las imagenes y los valores de las posiciones de la misma manera que el mapa
	tab.pos_x=0;
	tab.pos_y=0;
	tab.mlx = mlx_init();
	tab.win = mlx_new_window(tab.mlx, 1920, 1080, "mtacunan solong");
	tab.img = mlx_xpm_file_to_image(tab.mlx, "./image.xpm", &tab.img_width, &tab.img_height);
	tab.floor = mlx_xpm_file_to_image(tab.mlx, "./floor.xpm", &tab.img_width, &tab.img_height);

	mlx_put_image_to_window(tab.mlx, tab.win, tab.img, tab.pos_x, tab.pos_y);

//holdea las teclas
	mlx_key_hook(tab.win, choose_key, &tab);

	mlx_loop(tab.mlx);
}