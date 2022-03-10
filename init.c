#include "so_long.h"
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

int main()
{
	t_data test;
	int lines = get_lines("./test.ber");
	get_table(&test,"./test.ber");
	while(lines-- >= 0)
	{
		printf("%s\n",test.table[lines]);

	}
	put_table(test);
}