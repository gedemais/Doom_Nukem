#include "main.h"
/*
char	*ReadBMP(char *file)
{
    int i;

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    int row_padded = (width * 3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

	while (i < height)
    {
        fread(data, sizeof(unsigned char), row_padded, f);
        for(int j = 0; j < width * 3; j += 3)
        {
            // Convert (B, G, R) to (R, G, B)
            tmp = data[j];
            data[j] = data[j + 2];
            data[j + 2] = tmp;
        }
		i++;
    }

    fclose(f);
    return data;
}*/

char	*bmp_read(char *path, int *wdt, int *hgt)
{
	char	*file;
	int		fd;

	(void)wdt;
	(void)hgt;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if (!(file = read_file(fd)))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (file);
}
