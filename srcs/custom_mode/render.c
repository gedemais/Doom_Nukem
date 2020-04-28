/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 02:37:10 by gedemais          #+#    #+#             */
/*   Updated: 2020/01/30 02:50:01 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		display_str(t_env *env, char **path_list, t_point police, int i)
{
	int				len;
	int				pos;
	t_ttf_config	*conf;

	env->edit_env.scroll.current = 0;
	conf = ttf_config();
	ft_bzero(conf->s, sizeof(unsigned char) * 1024);
	len = ft_tablen(path_list);
	len = 0;
	if (len == 0)
	{
		ft_strcpy((char *)conf->s, "no file found");
		return ;
	}
	pos = env->edit_env.scroll.current + i;
	len -= 1;
	if (pos > len)
		pos = pos - len;
	ft_strcpy((char *)conf->s, path_list[pos]);
	(void)police;
	//my_string_put(env, env->mlx.img_data, police, 1);
}

static void		display_file(t_env *env, char **path_list, t_point o, t_point d)
{
	t_point			pos;
	t_point			dims;
	t_point			police;
	t_ttf_config	*conf;

	if (path_list == NULL)
		return ;
	conf = ttf_config();
	for (int i = 0; i < env->edit_env.scroll.nb_case; i++)
	{
		pos.x = o.x;	
		pos.y = o.y + i * env->edit_env.scroll.case_size;
		police.x = pos.x + 10;
		police.y = pos.y + 10;
		dims.x = d.x;
		dims.y = env->edit_env.scroll.case_size;
		draw_rectangle(env->mlx.img_data, pos, dims, 0xffffff);
		display_str(env, path_list, police, i);
	}
}

static void		scroll_file(t_env *env)
{
	int		len;
	char	**path_list;
	t_point	o;
	t_point	d;

	o.x = 0;
	o.y = 0;
	d.x = WDT;
	d.y = HGT;
	env->edit_env.scroll.case_size = 50;
	env->edit_env.scroll.current = 0;
	path_list = listpath("./resources/maps", ".map");
	env->edit_env.scroll.nb_case = d.y / env->edit_env.scroll.case_size;
	len = ft_tablen(path_list);
	if (env->edit_env.scroll.nb_case > len)
		env->edit_env.scroll.nb_case = len;
	display_file(env, path_list, o, d);
}

int				render_custom(void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	ft_memset(env->mlx.img_data, 0, sizeof(int) * WDT * HGT);
	scroll_file(env);
	if (env->events.keys[KEY_M])
		switch_context(env, C_TITLE_SCREEN);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	//mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : custom");
	return (0);
}
