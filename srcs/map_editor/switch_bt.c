#include "main.h"

static int		*bt_arrays(int index)
{
	static int	arrays[3][128] = {{}, {}, {}};
	static bool	first = true;
	int			i;

	i = 0;
	if (first)
	{
		while (++i < NB_CUBES_ICONES)
			arrays[0][i] = i;
		while (++i < 128 + NB_SLOPES_ICONES)
			arrays[1][i] = i;
	}
	first = false;
	return (arrays[index]);
 }

static void		switch_cube_type(unsigned char *bt, t_events *e)
{
	static int	bt_cube = 0;
	int			*ptr;

	ptr = bt_arrays(0);
	if (e->buttons[BUTTON_SCROLL_UP])
		bt_cube = (bt_cube >= NB_CUBES_ICONES) ? 0 : bt_cube + 1;
	else if (e->buttons[BUTTON_SCROLL_DOWN])
		bt_cube = (bt_cube < 0) ? NB_CUBES_ICONES - 1 : bt_cube - 1;
	*bt = (unsigned char)ptr[bt_cube];
}

static void		switch_slope_type(unsigned char bc, unsigned char *bt, t_events *e)
{
	static int				bt_slope = 0;
	static unsigned char	last_bc = 0;
	int			*ptr;

	ptr = bt_arrays(1);
	if (bt_slope == 0 || last_bc != bc)
		bt_slope = bc * 32;
	if (bc == BC_SLOPE_NORD)
	{
		if (e->buttons[BUTTON_SCROLL_UP])
			bt_slope = (bt_slope >= 32 + NB_SLOPES_ICONES - 1) ? 32 : bt_slope + 1;
		else if (e->buttons[BUTTON_SCROLL_DOWN])
			bt_slope = (bt_slope < 32) ? 32 + NB_SLOPES_ICONES - 1 : bt_slope - 1;
	}
	else if (bc == BC_SLOPE_SUD)
	{
		if (e->buttons[BUTTON_SCROLL_UP])
			bt_slope = (bt_slope >= 64 + NB_SLOPES_ICONES - 1) ? 64 : bt_slope + 1;
		else if (e->buttons[BUTTON_SCROLL_DOWN])
			bt_slope = (bt_slope < 64) ? 64 + NB_SLOPES_ICONES - 1 : bt_slope - 1;
	}
	else if (bc == BC_SLOPE_OUEST)
	{
		if (e->buttons[BUTTON_SCROLL_UP])
			bt_slope = (bt_slope >= 96 + NB_SLOPES_ICONES - 1) ? 96 : bt_slope + 1;
		else if (e->buttons[BUTTON_SCROLL_DOWN])
			bt_slope = (bt_slope < 96) ? 96 + NB_SLOPES_ICONES - 1 : bt_slope - 1;
	}
	else if (bc == BC_SLOPE_EST)
	{
		if (e->buttons[BUTTON_SCROLL_UP])
			bt_slope = (bt_slope >= 128 + NB_SLOPES_ICONES - 1) ? 128 : bt_slope + 1;
		else if (e->buttons[BUTTON_SCROLL_DOWN])
			bt_slope = (bt_slope < 128) ? 128 + NB_SLOPES_ICONES - 1 : bt_slope - 1;
	}
	else
		return ;
	*bt = (unsigned char)ptr[bt_slope];
	last_bc = bc;
}

/*
static void		switch_obj_type(char *bt, t_events *e)
{
	
}*/

void			switch_block_type(t_env *env, t_events *e)
{
	unsigned char	*bt;
	unsigned char	bc;

	bc = env->edit_env.current_bc;
	bt = &env->edit_env.current_bt;
	if (bc == BC_CUBE)
		switch_cube_type(bt, e);
	else if (ft_inbounds(bc, BC_SLOPE_NORD, BC_SLOPE_EST))
		switch_slope_type(bc, bt, e);
}
