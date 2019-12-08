#ifndef DYNARRAY_H
# define DYNARRAY_H

# include "../libft/libft.h"
# include <stdbool.h>

typedef struct	s_dynarray
{
	void		*c;
	void		*tmp;
	int			cell_size;
	int			nb_cells;
	int			byte_size;
	int			t_byte_size;
}				t_dynarray;

int				init_dynarray(t_dynarray *arr, int cell_size, int nb_cells);
void			*dyacc(t_dynarray *arr, int index);

int				pop_dynarray(t_dynarray *arr);
int				push_dynarray(t_dynarray *arr, void *src, bool back);


#endif
