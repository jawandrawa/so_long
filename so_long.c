

#include "so_long.h"

int	its_valid(t_data tab, int key)
{
	int i;
	int j;
	
	if(key == 2) //derecha
	{	
		i = tab.pos_y  / 64;
		j = (tab.pos_x + 64) / 64;
		if (tab.pos_x + 64 >= tab.win_width || tab.table[i][j] == '1')
			return(0);
		return(1);
	}
	else if(key == 0) //izquierda
	{
		i = tab.pos_y  / 64;
		j = (tab.pos_x - 64) / 64;
		if (tab.pos_x - 64 < 0 || tab.table[i][j] == '1')
			return(0);
		return(1);
	}
	else if(key == 1) //abajo
	{
		i = (tab.pos_y + 64) / 64;
		j = tab.pos_x / 64;
		if (tab.pos_y + 64 >= tab.win_height || tab.table[i][j] == '1')
			return(0);
		return(1);
	}
	else if(key == 13) //arriba
	{
		i = (tab.pos_y - 64) / 64;
		j = tab.pos_x / 64;
		if (tab.pos_y - 64 < 0 || tab.table[i][j] == '1')
			return(0);
		return(1);
	}
	return(1);
}
void movings (t_data *tab, int key)
{
	if(key == 2 && its_valid(*tab,2)) //derecha
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, tab->pos_x , tab->pos_y);
		tab->pos_x += 64;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, tab->pos_x , tab->pos_y);
	}
	if(key == 0 &&its_valid(*tab,0) ) //izquierda
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, tab->pos_x , tab->pos_y);
		tab->pos_x -= 64;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, tab->pos_x , tab->pos_y);
	}
	if(key == 13 && its_valid(*tab,13) ) //arriba
	{
		mlx_put_image_to_window(tab->mlx, tab->win, tab->floor, tab->pos_x , tab->pos_y);
		tab->pos_y -= 64;
		mlx_put_image_to_window(tab->mlx, tab->win, tab->img, tab->pos_x , tab->pos_y );
	}
	if(key == 1 && its_valid(*tab,1)) //abajo
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
	if (key == 2 || key == 0 ||  key == 1 || key == 13)
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

int get_lines(char  *table)
{
	int cont;
	char	*aux;
	int	fd;

	fd = open (table, O_RDONLY);
	cont = 0;
	aux = "";
	while(aux)
	{
		aux = get_next_line(fd);
		if (!aux)
			break ;
		cont++;
	}
	close(fd);
	free(aux);
	return (cont);
}

void get_table(t_data *map,char *table)
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
	map->table = malloc(sizeof(char *)*lines);
	while(i < lines)
	{
		map->table[i]=get_next_line(fd);
		i++;
	}
	range_x = ft_strlen(map->table[0]) - 1;
	map->win_width = range_x * map->img_width;
	close(fd);
}

//antes qiedaa hacer una funcion que vea si el mapa es valido y que limpie todo 
void put_table(t_data *map)
{
	int i;
	int	j;
	int	lines;

	i = 0;
	lines = get_lines("./test.ber");
	map->obstacle = mlx_xpm_file_to_image(map->mlx,"./images/obstacle.xpm",&map->img_width, &map->img_height);
	map->img = mlx_xpm_file_to_image(map->mlx,"./images/image.xpm",&map->img_width, &map->img_height);
	map->floor = mlx_xpm_file_to_image(map->mlx, "./images/floor.xpm", &map->img_width, &map->img_height);
	map->colect= mlx_xpm_file_to_image(map->mlx, "./images/colect.xpm", &map->img_width, &map->img_height);
	while(i < lines)
	{
		j = 0;
		while(map->table[i][j])
		{
			if(map->table[i][j] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->obstacle,j * map->img_width , i * map->img_height);
		//if(*map->table[0] == '0')
			else if (map->table[i][j] == 'P')
			{
				map->pos_x =  j * map->img_width;
				map->pos_y = i * map->img_height;
				mlx_put_image_to_window(map->mlx, map->win, map->img,map->pos_x, map->pos_y);
			}
			else if(map->table[i][j] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->colect,j * map->img_width , i * map->img_height);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_data tab;
	
	//inizializar todas las imagenes y los valores de las posiciones de la misma manera que el mapa

	tab.img_height = 64;
	tab.img_width = 64;
	get_table(&tab,"./test.ber");

	// tab.win_width = 1920;
	// tab.win_height = 1024;
	tab.mlx = mlx_init();
	tab.win = mlx_new_window(tab.mlx, tab.win_width, tab.win_height, "mtacunan solong");


	put_table(&tab);
	// tab.img = mlx_xpm_file_to_image(tab.mlx, "./images/image.xpm", &tab.img_width, &tab.img_height);
	// mlx_put_image_to_window(tab.mlx, tab.win, tab.img, tab.pos_x, tab.pos_y);

//holdea las teclas
	mlx_key_hook(tab.win, choose_key, &tab);

	mlx_loop(tab.mlx);
}