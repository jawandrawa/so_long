#include "so_long.h"

void get_table(int fd, t_data *map)
{
	int	i;

	i = 0;
	map->table = malloc(sizeof(char *)*5);
	while(i<5)
	{
		map->table[i]=get_next_line(fd);
		//printf("gola\n");
		i++;
	}
}
int main()
{
	t_data test;
	int fd;
	int i= 0;
	fd = open ("./test.ber", O_RDONLY);
	get_table(fd,&test);
	while(i <5)
	{
	printf("%s",test.table[i]);
	i++;
	}
}