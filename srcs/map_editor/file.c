#include "main.h"

int		write_infile(char *f_path, char *str, int len, bool token)
{
	int        file;

	if (token)
		unlink(f_path);
	file = open(f_path, O_CREAT | O_WRONLY, 0666);
	if (file > 0)
	{
		write(file, str, len);
		close(file);
		return (1);
	}
	return (0);
}
