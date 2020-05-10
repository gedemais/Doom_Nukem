#include "main.h"

static int		*bt_arrays(int index)
{
	static int	arrays[6][32] = {{}, {}, {}, {}, {}, {}};
	static bool	first = true;
	int			i;

	i = 0;
	if (first)
	{
		while (++i < NB_CUBES_ICONES)
			arrays[0][i] = i;
		while (++i < 32 + NB_SLOPES_ICONES)
			arrays[1][i] = i;
		while (++i < 64 + NB_SLOPES_ICONES)
			arrays[2][i] = i;
		while (++i < 96 + NB_SLOPES_ICONES)
			arrays[3][i] = i;
		while (++i < 128 + NB_SLOPES_ICONES)
			arrays[4][i] = i;
	}
	first = false;
	return (arrays[index]);
}

static void		switch_cube_type(char *bt, t_events *e)
{
	static int	bt_cube = 0;
	int			*ptr;

	ptr = bt_arrays(0);
	if (e->buttons[BUTTON_SCROLL_UP])
		bt_cube = (bt_cube >= NB_CUBES_ICONES) ? 0 : bt_cube + 1;
	else if (e->buttons[BUTTON_SCROLL_DOWN])
		bt_cube = (bt_cube < 0) ? NB_CUBES_ICONES - 1 : bt_cube - 1;
	*bt = (char)ptr[bt_cube];
}

static void		switch_slope_type(char bc, char *bt, t_events *e)
{
	static int	bt_slope = 0;
	int			*ptr;

	if (bc == BC_SLOPE_NORD)
	{
		ptr = bt_arrays(1);
		if (e->buttons[BUTTON_SCROLL_UP])
			bt_slope = (bt_slope >= 32 + NB_SLOPES_ICONES) ? 32 : bt_slope + 1;
		else if (e->buttons[BUTTON_SCROLL_DOWN])
			bt_slope = (bt_slope < 32) ? 32 + NB_SLOPES_ICONES - 1 : bt_slope - 1;
	}
	else if (bc == BC_SLOPE_SUD)
	{
		ptr = bt_arrays(2);
		if (e->buttons[BUTTON_SCROLL_UP])
			bt_slope = (bt_slope >= 64 + NB_SLOPES_ICONES) ? 64 : bt_slope + 1;
		else if (e->buttons[BUTTON_SCROLL_DOWN])
			bt_slope = (bt_slope < 64) ? 64 + NB_SLOPES_ICONES - 1 : bt_slope - 1;
	}
	else if (bc == BC_SLOPE_OUEST)
	{
		ptr = bt_arrays(3);
		if (e->buttons[BUTTON_SCROLL_UP])
			bt_slope = (bt_slope >= 96 + NB_SLOPES_ICONES) ? 96 : bt_slope + 1;
		else if (e->buttons[BUTTON_SCROLL_DOWN])
			bt_slope = (bt_slope < 96) ? 96 + NB_SLOPES_ICONES - 1 : bt_slope - 1;
	}
	else if (bc == BC_SLOPE_EST)
	{
		ptr = bt_arrays(4);
		if (e->buttons[BUTTON_SCROLL_UP])
			bt_slope = (bt_slope >= 128 + NB_SLOPES_ICONES) ? 128 : bt_slope + 1;
		else if (e->buttons[BUTTON_SCROLL_DOWN])
			bt_slope = (bt_slope < 128) ? 128 + NB_SLOPES_ICONES - 1 : bt_slope - 1;
	}
	else
		return ;
	*bt = (char)ptr[bt_slope];
}

/*
static void		switch_obj_type(char *bt, t_events *e)
{
	
}*/

void			switch_block_type(t_env *env, t_events *e)
{
	char		*bt;
	char		bc;

	bc = env->edit_env.current_bc;
	bt = &env->edit_env.current_bt;
	if (bc == BC_CUBE)
		switch_cube_type(bt, e);
	else if (ft_inbounds(bc, BC_SLOPE_NORD, BC_SLOPE_EST))
		switch_slope_type(bc, bt, e);
}
