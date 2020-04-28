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

static void     tab_free(void **add, int len)
{
	int i;

	if (add == NULL)
		return ;
	i = -1;
	while (++i < len && add[i])
		ft_memdel(&add[i]);
	ft_memdel(add);
}

static char		*ft_strlcpy(char *dst, const char *src, size_t len)
{
	int		i;

	i = 0;
	while (src[i] && len--)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void		display_str(t_env *env, char **path_list, t_point police, int i)
{
	int				len;
	int				pos;
	int				size;
	t_ttf_config	*conf;

	conf = ttf_config();
	ft_bzero(conf->s, sizeof(unsigned char) * 1024);
	len = ft_tablen(path_list);
	if (len == 0)
		ft_strlcpy((char *)conf->s, "no file found", 13);
	else
	{
		size = env->edit_env.scroll.d.x / (conf->size + 10);
		pos = env->edit_env.scroll.current + i;
		if (pos > len - 1)
			pos = pos - len;
		ft_strlcpy((char *)conf->s, path_list[pos], size);
	}
	my_string_put(env, env->mlx.img_data, police, 1);
}

static void		display_file(t_env *env, char **path_list, t_point o, t_point d)
{
	t_point			pos;
	t_point			police;

	if (path_list == NULL)
		return ;
	for (int i = 0; i < env->edit_env.scroll.nb_case; i++)
	{
		pos.x = o.x;	
		pos.y = o.y + i * env->edit_env.scroll.case_size + i;
		police.x = pos.x + 10;
		police.y = pos.y + env->edit_env.scroll.case_size - 10;
		draw_rectangle(env->mlx.img_data,
			pos, (t_point){ d.x, env->edit_env.scroll.case_size }, 0xff00ff);
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
	path_list = listpath("./resources/maps", ".map");
	env->edit_env.scroll.d = d;
	env->edit_env.scroll.o = o;
	env->edit_env.scroll.case_size = 50;
	env->edit_env.scroll.nb_case = d.y / env->edit_env.scroll.case_size - 1;
	len = ft_tablen(path_list);
	env->edit_env.scroll.max = len;
	if (env->edit_env.scroll.nb_case > len)
		env->edit_env.scroll.nb_case = len;
	display_file(env, path_list, o, d);
	tab_free((void **)path_list, len);
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
	mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : custom");
	return (0);
}
