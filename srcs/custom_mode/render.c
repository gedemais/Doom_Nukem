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

//call img: env->mlx.img_mlx

#include "main.h"

void		my_string_put(t_env *env, char *img, t_point o, int font);

void		get_str(t_env	*env, char **path_list, int len, int i)
{
	t_ttf_config	*conf;
	int				pos;

	env->edit_env.scroll.current = 0;
	conf = ttf_config();
	ft_bzero(conf->s, sizeof(unsigned char) * 1024);
	len = 0;
	if (len == 0)
	{
		ft_strcpy((char *)conf->s, "no file found");
		puts((const char *)conf->s);
		return ;
	}
	pos = env->edit_env.scroll.current + i;
	len -= 1;
	if (pos > len)
		pos = pos - len;
	ft_strcpy((char *)conf->s, path_list[pos]);
}

static void		scroll_file(t_env *env, char **path_list, t_point o, t_point d)
{
	t_ttf_config	*conf;
	int				case_size;
	int				len;
	int				nb_case;

	if (path_list == NULL)
		return ;
	conf = ttf_config();
	case_size = 50;
	nb_case = d.y / case_size;
	len = ft_tablen(path_list);
	len = 1;
	if (nb_case > len)
		nb_case = len;
	printf("nb_case: %d\n", nb_case);
	for (int i = 0; i < nb_case; i++)
	{
		t_point	pos;
		t_point	dims;
		t_point	police;

		pos.x = o.x;	
		pos.y = o.y + i * case_size;
		police.x = 10;
		police.y = 10;
		dims.x = d.x;
		dims.y = case_size;
		draw_rectangle(env->mlx.img_data, pos, dims, 0xffffff);
		get_str(env, path_list, len, i);
		puts("a");
		my_string_put(env, env->mlx.img_data, police, 1);
		puts("b");
	}
}

static void		scrolling(t_env *env)
{
	char	**path_list;
	t_point	o;
	t_point	d;

	o.x = 0;
	o.y = 0;
	d.x = WDT;
	d.y = HGT;
	path_list = listpath("./resources/maps", ".map");
	scroll_file(env, path_list, o, d);
	return ;
}

int				render_custom(void *param)
{
	t_env	*env;

	env = ((t_env*)param);
	ft_memset(env->mlx.img_data, 0, sizeof(int) * WDT * HGT);
	scrolling(env);
	if (env->events.keys[KEY_M])
		switch_context(env, C_TITLE_SCREEN);
	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
	//mlx_string_put(env->mlx.mlx_ptr, env->mlx.mlx_win, 10, 10, 0xffffff, "Contexte : custom");
	return (0);
}
