#include "main.h"
/*
static void		swap_bytes(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}*/

static int		read_bmp_header(int fd, int *wdt, int *hgt)
{
	unsigned char	header[BMP_HSIZE];

	if (read(fd, header, BMP_HSIZE) < BMP_HSIZE)
	{
		ft_putstr_fd(BMP_HEADER, 2);
		return (-1);
	}
	ft_memcpy(wdt, (void*)&header[18], sizeof(int));
	ft_memcpy(hgt, (void*)&header[22], sizeof(int));
	*wdt = abs(*wdt);
	*hgt = abs(*hgt);
	return (0);
}

static char		*read_bmp_data(int fd, int wdt, int hgt, size_t line_size)
{
	char			*line;
	char			*data;
	int				data_size;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	(void)wdt;
		printf("%zu\n", line_size);
	data_size = (int)line_size * hgt * 2;
	if (!(data = ft_strnew((size_t)data_size))
		|| !(line = ft_strnew((size_t)line_size)))
		return (NULL);
	printf("%d\n", data_size);
	while (read(fd, line, line_size) == (int)line_size)
	{
		i = 0;
		while (i < line_size)
		{
//			swap_bytes(&line[i], &line[i + 2]);
//			line[i + 3] = 0;
			ft_memcpy(&data[j], &line[i], 3);
			i += 3;
			j += 4;
		}
	}
	return (data);
}

char			*bmp_read(char *path, int *wdt, int *hgt)
{
	char	*data;
	int		fd;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		ft_putstr_fd(BMP_HEADER, 2);
		ft_putendl_fd(path, 2);
		return (NULL);
	}
	if (read_bmp_header(fd, wdt, hgt)
		|| !(data = read_bmp_data(fd, *wdt, *hgt, (size_t)(*wdt * 3))))
	{
		close(fd);
		return (NULL);
	}
	printf("wdt = %d | hgt = %d\n", *wdt, *hgt);
	return (data);
}
