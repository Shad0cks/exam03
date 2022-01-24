#include "header.h"

FILE * getfd (char *path)
{
	return (fopen(path, "r"));
}

void init_data(FILE * file, t_data *data)
{
	fscanf(file, "%d %d %c", &data->width, &data->height, &data->background);
	printf("%d %d %c\n", data->width, data->height, data->background);
}

int main(int ac, char **av)
{
	FILE * fd;
	t_data data;

	if (ac > 2 || ac <= 1)
	{
		write(1, "Error: argument\n", 17);
		return (1);
	}
	fd = getfd(av[1]);
	if (fd == NULL)
	{
		write(1, "Error: Operation file corrupted\n", 33);
		return (1);
	}
	init_data(fd, &data);
	return (0);
}