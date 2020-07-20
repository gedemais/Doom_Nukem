/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countdown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 12:45:35 by gedemais          #+#    #+#             */
/*   Updated: 2020/07/19 15:24:35 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		put_section(t_env *env, int var, t_point pos, bool sep)
{
	t_ttf_config	*conf;
	char			*section;

	conf = ttf_config();
	conf->size = 24;
	ft_bzero(conf->s, MAX_STR_CHARS);
	if (!(section = ft_itoa(var)))
		return (-1);
	ft_strcpy((char*)conf->s, section);
	free(section);
	if (sep)
		ft_strcat((char*)conf->s, ":");
	my_string_put(env, env->mlx.img_data, pos, FONT_COOLVETICA);
	return (0);
}

int		handle_countdown(t_env *env, t_point pos)
{
	float	tmp;
	int		mins;
	int		seconds;
	int		tenth;
	int		length;

	env->cmp_env.countdown -= env->data.spent;
	mins = (int)env->cmp_env.countdown / 60;
	seconds = (int)env->cmp_env.countdown % 60;
	tmp = env->cmp_env.countdown - (int)env->cmp_env.countdown;
	tmp *= 10.0f;
	tenth = tmp;
	length = ft_nb_len(mins) * 24;
	draw_rectangle(env->mlx.img_data,
		(t_point){200, 200}, (t_point){200, 2}, 0);
	put_section(env, mins, pos, true);
	length = ft_strlen((char*)((t_ttf_config*)ttf_config())->s) * 20;
	put_section(env, seconds, (t_point){pos.x + length, pos.y}, true);
	length += ft_strlen((char*)((t_ttf_config*)ttf_config())->s) * 20;
	put_section(env, tenth, (t_point){pos.x + length, pos.y}, false);
	printf("%d:%d:%d\n", mins, seconds, tenth);
	return (0);
}
