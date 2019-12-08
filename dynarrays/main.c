#include "dynarray.h"

int		main(void)
{
	t_dynarray	arr;

	if (init_dynarray(&arr, sizeof(int), 42))
		return (1);
	return (0);
}
