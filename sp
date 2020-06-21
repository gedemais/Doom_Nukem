Binary file srcs//main.o matches
Binary file srcs//free.o matches
srcs//scroll_file.c:9:	s = &env->scroll;
srcs//scroll_file.c:10:	if (!(s->list = listpath(path, extension)))
srcs//scroll_file.c:11:		return (-1);
srcs//scroll_file.c:12:	s->max = ft_tablen(s->list);
srcs//scroll_file.c:13:	s->d = (t_point){400, 800};
srcs//scroll_file.c:14:	s->o = (t_point){100, 100};
srcs//scroll_file.c:15:	s->color = 0xaaaaaa;
srcs//scroll_file.c:16:	s->font = SCROLL_FILE_FONT;
srcs//scroll_file.c:17:	s->case_size = 50;
srcs//scroll_file.c:18:	s->mouse_index = -1;
srcs//scroll_file.c:19:	s->nb_case = s->d.y / s->case_size - 1;
srcs//scroll_file.c:20:	if (s->case_size > s->max)
srcs//scroll_file.c:21:		s->nb_case = s->max;
srcs//scroll_file.c:22:	if (s->nb_case < 1)
srcs//scroll_file.c:23:		s->nb_case = 1;
srcs//scroll_file.c:34:	s = &env->scroll;
srcs//scroll_file.c:36:	ft_bzero(conf->s, sizeof(unsigned char) * 1024);
srcs//scroll_file.c:37:	if (s->max == 0)
srcs//scroll_file.c:38:		ft_strlcpy((char *)conf->s, "No map found!", 13);
srcs//scroll_file.c:41:		size = s->d.x / (conf->size + 10);
srcs//scroll_file.c:42:		pos = s->current + i;
srcs//scroll_file.c:43:		if (pos > s->max - 1)
srcs//scroll_file.c:44:			pos = pos - s->max;
srcs//scroll_file.c:45:		ft_strlcpy((char *)conf->s, s->list[pos], size);
srcs//scroll_file.c:46:		if (s->mouse_index == i && env->events.buttons[BUTTON_LCLIC])
srcs//scroll_file.c:48:			ft_strdel(&s->s_path);
srcs//scroll_file.c:49:			s->s_path = ft_strdup(s->list[pos]);
srcs//scroll_file.c:52:	my_string_put(env, env->mlx.img_data, police, s->font);
srcs//scroll_file.c:61:	s = &env->scroll;
srcs//scroll_file.c:62:	mouse_x = env->events.mouse_pos.x;
srcs//scroll_file.c:63:	mouse_y = env->events.mouse_pos.y;
srcs//scroll_file.c:66:		s->mouse_index = i;
srcs//scroll_file.c:67:	else if (mouse_x < s->o.x || mouse_x > s->o.x + s->d.x
srcs//scroll_file.c:68:	|| mouse_y < s->o.y || mouse_y > s->o.y + s->nb_case * s->case_size)
srcs//scroll_file.c:69:		s->mouse_index = -1;
srcs//scroll_file.c:74:	if (env->scroll.mouse_index > -1)
srcs//scroll_file.c:76:		if (env->events.buttons[BUTTON_SCROLL_UP])
srcs//scroll_file.c:77:			++env->scroll.current;
srcs//scroll_file.c:78:		else if (env->events.buttons[BUTTON_SCROLL_DOWN])
srcs//scroll_file.c:79:			--env->scroll.current;
srcs//scroll_file.c:81:	env->events.buttons[BUTTON_SCROLL_UP] = false;
srcs//scroll_file.c:82:	env->events.buttons[BUTTON_SCROLL_DOWN] = false;
srcs//scroll_file.c:91:	s = &env->scroll;
srcs//scroll_file.c:92:	s->current = s->current < 0 ? s->max : s->current;
srcs//scroll_file.c:93:	s->current = s->current > s->max ? 0 : s->current;
srcs//scroll_file.c:94:	i = -1;
srcs//scroll_file.c:95:	while (++i < s->nb_case)
srcs//scroll_file.c:97:		pos = (t_point){s->o.x, s->o.y + i * s->case_size + i};
srcs//scroll_file.c:98:		get_mouse_index(env, pos, (t_point){s->d.x, s->case_size}, i);
srcs//scroll_file.c:99:		draw_rectangle(env->mlx.img_data, pos, (t_point){s->d.x, s->case_size},
srcs//scroll_file.c:100:			s->mouse_index == i ? 0x00ffff : s->color);
srcs//scroll_file.c:101:		display_str(env, (t_point){pos.x + 10, pos.y + s->case_size - 10}, i);
srcs//scroll_file.c:103:	if (s->mouse_index == -1)
srcs//scroll_file.c:104:		ft_strdel(&s->s_path);
Binary file srcs//dev_handle_events.o matches
srcs//resources_paths.c:7:										"resources/maps/sawed-off.obj",
srcs//resources_paths.c:8:										"resources/maps/glock-18.obj",
srcs//resources_paths.c:11:										"resources/maps/mag-7.obj",
srcs//resources_paths.c:14:										"resources/maps/tec-9.obj",
srcs//resources_paths.c:22:										"resources/maps/map-test.obj",
srcs//resources_paths.c:112:					"resources/samples/weapons/ak47-reload.wav",
srcs//resources_paths.c:113:					"resources/samples/weapons/ak47-shot.wav",
srcs//resources_paths.c:114:					"resources/samples/weapons/aug-reload.wav",
srcs//resources_paths.c:115:					"resources/samples/weapons/aug-shot.wav",
srcs//resources_paths.c:116:					"resources/samples/weapons/famas-reload.wav",
srcs//resources_paths.c:117:					"resources/samples/weapons/famas-shot.wav",
srcs//resources_paths.c:118:					"resources/samples/weapons/galil-reload.wav",
srcs//resources_paths.c:119:					"resources/samples/weapons/galil-shot.wav",
srcs//resources_paths.c:120:					"resources/samples/weapons/glock-reload.wav",
srcs//resources_paths.c:121:					"resources/samples/weapons/glock-shot.wav",
srcs//resources_paths.c:122:					"resources/samples/weapons/mag7-reload.wav",
srcs//resources_paths.c:123:					"resources/samples/weapons/mag7-shot.wav",
srcs//resources_paths.c:124:					"resources/samples/weapons/negev-reload.wav",
srcs//resources_paths.c:125:					"resources/samples/weapons/negev-shot.wav",
srcs//resources_paths.c:126:					"resources/samples/weapons/sawed-off-fill.wav",
srcs//resources_paths.c:127:					"resources/samples/weapons/sawed-off-pump.wav",
srcs//resources_paths.c:128:					"resources/samples/weapons/sawed-off-shot.wav",
srcs//resources_paths.c:129:					"resources/samples/weapons/tec9-reload.wav",
srcs//resources_paths.c:130:					"resources/samples/weapons/tec9-shot.wav",
srcs//resources_paths.c:131:					"resources/samples/weapons/ump45-reload.wav",
srcs//resources_paths.c:132:					"resources/samples/weapons/ump45-shot.wav",
Binary file srcs//rasterizer/raster_triangles.o matches
srcs//rasterizer/fill_triangle_texture.c:21:	if (txt->txt_w < env->cam.z_buffer[pos[2]])
srcs//rasterizer/fill_triangle_texture.c:23:	if (pos[0] == env->data.half_hgt)
srcs//rasterizer/fill_triangle_texture.c:24:		if (pos[1] == env->data.half_wdt)
srcs//rasterizer/fill_triangle_texture.c:25:			env->mid = *t;
srcs//rasterizer/fill_triangle_texture.c:26:	if (t->textured && t->sp >= 0)
srcs//rasterizer/fill_triangle_texture.c:28:		cu = txt->txt_u / txt->txt_w;
srcs//rasterizer/fill_triangle_texture.c:29:		cv = txt->txt_v / txt->txt_w;
srcs//rasterizer/fill_triangle_texture.c:30:		color = sample_pixel((int*)txt->texture->img_data,
srcs//rasterizer/fill_triangle_texture.c:31:			(t_point){txt->texture->hgt, txt->texture->wdt},
srcs//rasterizer/fill_triangle_texture.c:33:		color = shade_color(color, t->scale);
srcs//rasterizer/fill_triangle_texture.c:36:		color = t->color;
srcs//rasterizer/fill_triangle_texture.c:37:	env->cam.z_buffer[pos[2]] = txt->txt_w;
srcs//rasterizer/fill_triangle_texture.c:38:	*(int*)(&env->mlx.img_data[pos[3]]) = color;
srcs//rasterizer/fill_triangle_texture.c:45:		steps[0] = (txt->t_step * txt->txt_su);
srcs//rasterizer/fill_triangle_texture.c:46:		steps[1] = (txt->t_step * txt->txt_eu);
srcs//rasterizer/fill_triangle_texture.c:47:		steps[2] = (txt->t_step * txt->txt_sv);
srcs//rasterizer/fill_triangle_texture.c:48:		steps[3] = (txt->t_step * txt->txt_ev);
srcs//rasterizer/fill_triangle_texture.c:50:	steps[4] = (txt->t_step * txt->txt_sw);
srcs//rasterizer/fill_triangle_texture.c:51:	steps[5] = (txt->t_step * txt->txt_ew);
srcs//rasterizer/fill_triangle_texture.c:52:	simples[0] = txt->txt_su;
srcs//rasterizer/fill_triangle_texture.c:54:	simples[2] = txt->txt_sv;
srcs//rasterizer/fill_triangle_texture.c:56:	simples[4] = txt->txt_sw;
srcs//rasterizer/fill_triangle_texture.c:64:		simples[0] -= steps[0];
srcs//rasterizer/fill_triangle_texture.c:66:		simples[2] -= steps[2];
srcs//rasterizer/fill_triangle_texture.c:69:	simples[4] -= steps[4];
srcs//rasterizer/fill_triangle_texture.c:81:	j = txt->ax;
srcs//rasterizer/fill_triangle_texture.c:82:	txt->t_step = 1.0f / (txt->bx - txt->ax);
srcs//rasterizer/fill_triangle_texture.c:83:	px = abs(i - 1) * WDT + j;
srcs//rasterizer/fill_triangle_texture.c:85:	simplify_interpolation(txt, steps, simples, t->textured);
srcs//rasterizer/fill_triangle_texture.c:86:	while (j < txt->bx)
srcs//rasterizer/fill_triangle_texture.c:88:		if (t->textured)
srcs//rasterizer/fill_triangle_texture.c:90:			txt->txt_u = simples[0] + simples[1];
srcs//rasterizer/fill_triangle_texture.c:91:			txt->txt_v = simples[2] + simples[3];
srcs//rasterizer/fill_triangle_texture.c:93:		txt->txt_w = simples[4] + simples[5];
srcs//rasterizer/fill_triangle_texture.c:94:		update_expr(steps, simples, t->textured);
srcs//rasterizer/fill_triangle_texture.c:107:	i = ceil(t->points[0].y);
srcs//rasterizer/fill_triangle_texture.c:108:	end = ceil(t->points[1].y);
srcs//rasterizer/fill_triangle_texture.c:112:		set_line_bounds_top(txt, t, i - t->points[0].y);
srcs//rasterizer/fill_triangle_texture.c:113:		txt->txt_u = txt->txt_su;
srcs//rasterizer/fill_triangle_texture.c:114:		txt->txt_v = txt->txt_sv;
srcs//rasterizer/fill_triangle_texture.c:115:		txt->txt_w = txt->txt_sw;
srcs//rasterizer/fill_triangle_texture.c:126:	i = ceil(t->points[1].y);
srcs//rasterizer/fill_triangle_texture.c:127:	end = ceil(t->points[2].y);
srcs//rasterizer/fill_triangle_texture.c:131:		set_line_bounds_bot(txt, t, (float[2]){i - t->points[0].y, i - t->points[1].y});
srcs//rasterizer/fill_triangle_texture.c:132:		txt->txt_u = txt->txt_su;
srcs//rasterizer/fill_triangle_texture.c:133:		txt->txt_v = txt->txt_sv;
srcs//rasterizer/fill_triangle_texture.c:134:		txt->txt_w = txt->txt_sw;
srcs//rasterizer/fill_triangle_texture.c:142:	if (t->voxel)
srcs//rasterizer/fill_triangle_texture.c:143:		txt->texture = &env->edit_env.btxts[t->sp];
srcs//rasterizer/fill_triangle_texture.c:144:	else if (t->textured && env->context != C_CUSTOM)
srcs//rasterizer/fill_triangle_texture.c:145:		txt->texture = dyacc(&env->maps[env->scene].txts, t->sp);
srcs//rasterizer/fill_triangle_texture.c:146:	else if (t->textured && env->context == C_CUSTOM)
srcs//rasterizer/fill_triangle_texture.c:147:		txt->texture = dyacc(&env->edit_env.map.txts, t->sp);
srcs//rasterizer/fill_triangle_texture_bis.c:17:	if (t->points[1].y < t->points[0].y)
srcs//rasterizer/fill_triangle_texture_bis.c:19:		swap_floats(&t->points[0].y, &t->points[1].y);
srcs//rasterizer/fill_triangle_texture_bis.c:20:		swap_floats(&t->points[0].x, &t->points[1].x);
srcs//rasterizer/fill_triangle_texture_bis.c:21:		t->textured ? swap_floats(&t->txt[0].u, &t->txt[1].u) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:22:		t->textured ? swap_floats(&t->txt[0].v, &t->txt[1].v) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:23:		swap_floats(&t->txt[0].w, &t->txt[1].w);
srcs//rasterizer/fill_triangle_texture_bis.c:25:	if (t->points[2].y < t->points[0].y)
srcs//rasterizer/fill_triangle_texture_bis.c:27:		swap_floats(&t->points[2].y, &t->points[0].y);
srcs//rasterizer/fill_triangle_texture_bis.c:28:		swap_floats(&t->points[2].x, &t->points[0].x);
srcs//rasterizer/fill_triangle_texture_bis.c:29:		t->textured ? swap_floats(&t->txt[2].u, &t->txt[0].u) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:30:		t->textured ? swap_floats(&t->txt[2].v, &t->txt[0].v) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:31:		swap_floats(&t->txt[2].w, &t->txt[0].w);
srcs//rasterizer/fill_triangle_texture_bis.c:33:	if (t->points[2].y < t->points[1].y)
srcs//rasterizer/fill_triangle_texture_bis.c:35:		swap_floats(&t->points[2].y, &t->points[1].y);
srcs//rasterizer/fill_triangle_texture_bis.c:36:		swap_floats(&t->points[2].x, &t->points[1].x);
srcs//rasterizer/fill_triangle_texture_bis.c:37:		t->textured ? swap_floats(&t->txt[2].u, &t->txt[1].u) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:38:		t->textured ? swap_floats(&t->txt[2].v, &t->txt[1].v) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:39:		swap_floats(&t->txt[2].w, &t->txt[1].w);
srcs//rasterizer/fill_triangle_texture_bis.c:45:	if (txt->dy1)
srcs//rasterizer/fill_triangle_texture_bis.c:47:		txt->ax_step = txt->dx1 / txt->dy1;
srcs//rasterizer/fill_triangle_texture_bis.c:49:			txt->u1_step = txt->du1 / txt->dy1;
srcs//rasterizer/fill_triangle_texture_bis.c:51:			txt->v1_step = txt->dv1 / txt->dy1;
srcs//rasterizer/fill_triangle_texture_bis.c:52:		txt->w1_step = txt->dw1 / txt->dy1;
srcs//rasterizer/fill_triangle_texture_bis.c:55:	if (txt->dy2)
srcs//rasterizer/fill_triangle_texture_bis.c:57:		txt->bx_step = txt->dx2 / txt->dy2;
srcs//rasterizer/fill_triangle_texture_bis.c:59:			txt->u2_step = txt->du2 / txt->dy2;
srcs//rasterizer/fill_triangle_texture_bis.c:61:			txt->v2_step = txt->dv2 / txt->dy2;
srcs//rasterizer/fill_triangle_texture_bis.c:62:		txt->w2_step = txt->dw2 / txt->dy2;
srcs//rasterizer/fill_triangle_texture_bis.c:73:	txt->dx1 = t->points[a].x - t->points[b].x;
srcs//rasterizer/fill_triangle_texture_bis.c:74:	txt->dy1 = t->points[a].y - t->points[b].y;
srcs//rasterizer/fill_triangle_texture_bis.c:75:	txt->du1 = t->textured ? t->txt[a].u - t->txt[b].u : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:76:	txt->dv1 = t->textured ? t->txt[a].v - t->txt[b].v : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:77:	txt->dw1 = t->txt[a].w - t->txt[b].w;
srcs//rasterizer/fill_triangle_texture_bis.c:81:		txt->dx2 = t->points[2].x - t->points[0].x;
srcs//rasterizer/fill_triangle_texture_bis.c:82:		txt->dy2 = t->points[2].y - t->points[0].y;
srcs//rasterizer/fill_triangle_texture_bis.c:83:		txt->du2 = t->textured ? t->txt[2].u - t->txt[0].u : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:84:		txt->dv2 = t->textured ? t->txt[2].v - t->txt[0].v : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:85:		txt->dw2 = t->txt[2].w - t->txt[0].w;
srcs//rasterizer/fill_triangle_texture_bis.c:87:	compute_steps(txt, t->textured);
srcs//rasterizer/fill_triangle_texture_bis.c:92:	txt->ax = t->points[0].x + current * txt->ax_step;
srcs//rasterizer/fill_triangle_texture_bis.c:93:	txt->bx = t->points[0].x + current * txt->bx_step;
srcs//rasterizer/fill_triangle_texture_bis.c:95:	txt->txt_su = t->textured ? t->txt[0].u + current * txt->u1_step : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:96:	txt->txt_sv = t->textured ? t->txt[0].v + current * txt->v1_step : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:97:	txt->txt_sw = t->txt[0].w + current * txt->w1_step;
srcs//rasterizer/fill_triangle_texture_bis.c:99:	txt->txt_eu = t->textured ? t->txt[0].u + current * txt->u2_step : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:100:	txt->txt_ev = t->textured ? t->txt[0].v + current * txt->v2_step : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:101:	txt->txt_ew = t->txt[0].w + current * txt->w2_step;
srcs//rasterizer/fill_triangle_texture_bis.c:103:	if (txt->ax > txt->bx)
srcs//rasterizer/fill_triangle_texture_bis.c:105:		swap_floats(&txt->ax, &txt->bx);
srcs//rasterizer/fill_triangle_texture_bis.c:106:		t->textured ? swap_floats(&txt->txt_su, &txt->txt_eu) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:107:		t->textured ? swap_floats(&txt->txt_sv, &txt->txt_ev) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:108:		swap_floats(&txt->txt_sw, &txt->txt_ew);
srcs//rasterizer/fill_triangle_texture_bis.c:114:	txt->ax = t->points[1].x + currents[1] * txt->ax_step;
srcs//rasterizer/fill_triangle_texture_bis.c:115:	txt->bx = t->points[0].x + currents[0] * txt->bx_step;
srcs//rasterizer/fill_triangle_texture_bis.c:117:	txt->txt_su = t->textured ? t->txt[1].u + currents[1] * txt->u1_step : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:118:	txt->txt_sv = t->textured ? t->txt[1].v + currents[1] * txt->v1_step : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:119:	txt->txt_sw = t->txt[1].w + currents[1] * txt->w1_step;
srcs//rasterizer/fill_triangle_texture_bis.c:121:	txt->txt_eu = t->textured ? t->txt[0].u + currents[0] * txt->u2_step : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:122:	txt->txt_ev = t->textured ? t->txt[0].v + currents[0] * txt->v2_step : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:123:	txt->txt_ew = t->txt[0].w + currents[0] * txt->w2_step;
srcs//rasterizer/fill_triangle_texture_bis.c:125:	if (txt->ax > txt->bx)
srcs//rasterizer/fill_triangle_texture_bis.c:127:		swap_floats(&txt->ax, &txt->bx);
srcs//rasterizer/fill_triangle_texture_bis.c:128:		t->textured ? swap_floats(&txt->txt_su, &txt->txt_eu) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:129:		t->textured ? swap_floats(&txt->txt_sv, &txt->txt_ev) : 0;
srcs//rasterizer/fill_triangle_texture_bis.c:130:		swap_floats(&txt->txt_sw, &txt->txt_ew);
srcs//rasterizer/raster_tools.c:21:	ft_memset(env->mlx.img_data, 0, env->data.data_size);
srcs//rasterizer/raster_tools.c:22:	while (i < size - 4)
srcs//rasterizer/raster_tools.c:24:		env->cam.z_buffer[i] = -INFINITY;
srcs//rasterizer/raster_tools.c:25:		env->cam.z_buffer[i + 1] = -INFINITY;
srcs//rasterizer/raster_tools.c:26:		env->cam.z_buffer[i + 2] = -INFINITY;
srcs//rasterizer/raster_tools.c:27:		env->cam.z_buffer[i + 3] = -INFINITY;
srcs//rasterizer/raster_tools.c:34:	update_xrotation_matrix(env->cam.rx_m, 0);
srcs//rasterizer/raster_tools.c:35:	update_yrotation_matrix(env->cam.ry_m, 0);
srcs//rasterizer/raster_tools.c:36:	update_zrotation_matrix(env->cam.rz_m, 0);
srcs//rasterizer/raster_tools.c:37:	matrix_mult_matrix(env->cam.rz_m, env->cam.rx_m, env->cam.w_m);
srcs//rasterizer/raster_tools.c:47:	env->cam.stats.dir = (t_vec3d){0, 0, 1, 0};
srcs//rasterizer/raster_tools.c:48:	up = (t_vec3d){0, -1, 0, 0};
srcs//rasterizer/raster_tools.c:51:	yaw_rad = ft_to_radians(env->cam.stats.yaw);
srcs//rasterizer/raster_tools.c:52:	pitch_rad = ft_to_radians(env->cam.stats.pitch);
srcs//rasterizer/raster_tools.c:54:	update_yrotation_matrix(env->cam.cry_m, yaw_rad);
srcs//rasterizer/raster_tools.c:55:	update_xrotation_matrix(env->cam.crx_m, pitch_rad);
srcs//rasterizer/raster_tools.c:56:	matrix_mult_matrix(env->cam.crx_m, env->cam.cry_m, env->cam.cr_m);
srcs//rasterizer/raster_tools.c:58:	env->cam.stats.dir = matrix_mult_vec(env->cam.cr_m, target);
srcs//rasterizer/raster_tools.c:59:	up = matrix_mult_vec(env->cam.cr_m, (t_vec3d){0, -1, 0, 0});
srcs//rasterizer/raster_tools.c:60:	target = vec_add(env->cam.stats.pos, env->cam.stats.dir);
srcs//rasterizer/raster_tools.c:62:	matrix_pointat(env->cam.c_m, env->cam.stats.pos, target, up);
srcs//rasterizer/raster_tools.c:64:	inverse_matrix(env->cam.c_m, env->cam.v_m);
srcs//rasterizer/triangle_pipeline.c:21:	scale = (t_vec3d){env->data.half_wdt, env->data.half_hgt, 1.0f, 1.0f};
srcs//rasterizer/triangle_pipeline.c:22:	t->points[0] = vec_add(t->points[0], pad);
srcs//rasterizer/triangle_pipeline.c:23:	t->points[1] = vec_add(t->points[1], pad);
srcs//rasterizer/triangle_pipeline.c:24:	t->points[2] = vec_add(t->points[2], pad);
srcs//rasterizer/triangle_pipeline.c:26:	t->points[0] = vec_mult(t->points[0], scale);
srcs//rasterizer/triangle_pipeline.c:27:	t->points[1] = vec_mult(t->points[1], scale);
srcs//rasterizer/triangle_pipeline.c:28:	t->points[2] = vec_mult(t->points[2], scale);
srcs//rasterizer/triangle_pipeline.c:33:	t->txt[0] = clipped.txt[0];
srcs//rasterizer/triangle_pipeline.c:34:	t->txt[1] = clipped.txt[1];
srcs//rasterizer/triangle_pipeline.c:35:	t->txt[2] = clipped.txt[2];
srcs//rasterizer/triangle_pipeline.c:37:	t->txt[0].u /= t->points[0].w;
srcs//rasterizer/triangle_pipeline.c:38:	t->txt[1].u /= t->points[1].w;
srcs//rasterizer/triangle_pipeline.c:39:	t->txt[2].u /= t->points[2].w;
srcs//rasterizer/triangle_pipeline.c:41:	t->txt[0].v /= t->points[0].w;
srcs//rasterizer/triangle_pipeline.c:42:	t->txt[1].v /= t->points[1].w;
srcs//rasterizer/triangle_pipeline.c:43:	t->txt[2].v /= t->points[2].w;
srcs//rasterizer/triangle_pipeline.c:45:	t->txt[0].w = 1.0f / t->points[0].w;
srcs//rasterizer/triangle_pipeline.c:46:	t->txt[1].w = 1.0f / t->points[1].w;
srcs//rasterizer/triangle_pipeline.c:47:	t->txt[2].w = 1.0f / t->points[2].w;
srcs//rasterizer/triangle_pipeline.c:53:	t->points[0] = multiply_matrix(env->cam.p_m, clipped.points[0]);
srcs//rasterizer/triangle_pipeline.c:54:	t->points[1] = multiply_matrix(env->cam.p_m, clipped.points[1]);
srcs//rasterizer/triangle_pipeline.c:55:	t->points[2] = multiply_matrix(env->cam.p_m, clipped.points[2]);
srcs//rasterizer/triangle_pipeline.c:59:	t->points[0] = vec_fdiv(t->points[0], t->points[0].w);
srcs//rasterizer/triangle_pipeline.c:60:	t->points[1] = vec_fdiv(t->points[1], t->points[1].w);
srcs//rasterizer/triangle_pipeline.c:61:	t->points[2] = vec_fdiv(t->points[2], t->points[2].w);
srcs//rasterizer/triangle_pipeline.c:65:	t->color = clipped.color;
srcs//rasterizer/triangle_pipeline.c:66:	t->textured = clipped.textured;
srcs//rasterizer/triangle_pipeline.c:67:	t->voxel = clipped.voxel;
srcs//rasterizer/triangle_pipeline.c:68:	t->sp = clipped.sp;
srcs//rasterizer/triangle_pipeline.c:69:	t->mesh = clipped.mesh;
srcs//rasterizer/triangle_pipeline.c:72:		return (-1);
srcs//rasterizer/triangle_pipeline.c:84:	illum = vec_dot(normal, env->cam.light);
srcs//rasterizer/triangle_pipeline.c:89:	t.points[0] = multiply_matrix(env->cam.v_m, t.points[0]);
srcs//rasterizer/triangle_pipeline.c:90:	t.points[1] = multiply_matrix(env->cam.v_m, t.points[1]);
srcs//rasterizer/triangle_pipeline.c:91:	t.points[2] = multiply_matrix(env->cam.v_m, t.points[2]);
srcs//rasterizer/triangle_pipeline.c:99:			return (-1);
srcs//rasterizer/triangle_pipeline.c:111:	if (t->sp == BTXT_NONE)
srcs//rasterizer/triangle_pipeline.c:113:	t->points[0] = matrix_mult_vec(env->cam.w_m, t->points[0]);
srcs//rasterizer/triangle_pipeline.c:114:	t->points[1] = matrix_mult_vec(env->cam.w_m, t->points[1]);
srcs//rasterizer/triangle_pipeline.c:115:	t->points[2] = matrix_mult_vec(env->cam.w_m, t->points[2]);
srcs//rasterizer/triangle_pipeline.c:116:	line1 = vec_sub(t->points[1], t->points[0]);
srcs//rasterizer/triangle_pipeline.c:117:	line2 = vec_sub(t->points[2], t->points[0]);
srcs//rasterizer/triangle_pipeline.c:120:	m->corp.norm = normal;
srcs//rasterizer/triangle_pipeline.c:121:	if (vec_dot(normal, vec_sub(t->points[0], env->cam.stats.pos)) < 0.0f)
srcs//rasterizer/triangle_pipeline.c:124:			return (-1);
Binary file srcs//rasterizer/clipping.o matches
srcs//rasterizer/rasterizer.c:20:	env = thr->env;
srcs//rasterizer/rasterizer.c:21:	while (thr->index < thr->end)
srcs//rasterizer/rasterizer.c:23:		fill_triangle_texture((t_env*)thr->env, dyacc(&env->cam.to_raster, thr->index));
srcs//rasterizer/rasterizer.c:24:		//draw_triangle(&env->mlx, *(t_triangle*)dyacc(&env->cam.to_raster, thr->index));
srcs//rasterizer/rasterizer.c:25:		thr->index++;
srcs//rasterizer/rasterizer.c:27:	if (thr->mono)
srcs//rasterizer/rasterizer.c:40:	thread.tris = &env->cam.to_raster;
srcs//rasterizer/rasterizer.c:43:	thread.end = env->cam.to_raster.nb_cells;
srcs//rasterizer/rasterizer.c:52:	ft_memcpy(&cam, &env->cam, sizeof(t_cam));
srcs//rasterizer/rasterizer.c:54:		return (-1);
srcs//rasterizer/rasterizer.c:55:	ft_memcpy(&env->cam, &cam, sizeof(t_cam));
srcs//rasterizer/rasterizer.c:65:	i = -1;
srcs//rasterizer/rasterizer.c:66:	map_spawn(env, &env->cam, map, respawn);
srcs//rasterizer/rasterizer.c:68:	while (++i < map->nmesh)
srcs//rasterizer/rasterizer.c:70:		j = -1;
srcs//rasterizer/rasterizer.c:71:		if (!(m = dyacc(&map->meshs, i)))
srcs//rasterizer/rasterizer.c:72:			return (-1);
srcs//rasterizer/rasterizer.c:73:		if (m->type == BTXT_NONE)
srcs//rasterizer/rasterizer.c:76:		while (++j < m->tris.nb_cells)
srcs//rasterizer/rasterizer.c:77:			triangle_pipeline(env, dyacc(&m->tris, j), &env->cam.to_clip, m);
srcs//rasterizer/rasterizer.c:79:	if (raster_triangles(env, &env->cam.to_clip))
srcs//rasterizer/rasterizer.c:80:		return (-1);
srcs//rasterizer/rasterizer.c:81:	env->scene = map->index;
srcs//rasterizer/rasterizer.c:82:	clear_dynarray(&env->cam.to_clip);
srcs//rasterizer/aim.c:8:	hwdt = env->data.half_wdt;
srcs//rasterizer/aim.c:9:	hhgt = env->data.half_hgt;
srcs//rasterizer/aim.c:12:		env->cam.stats.yaw -= fabs((hwdt - x) * SENSI) * env->cam.stats.aspect_ratio; // A caper
srcs//rasterizer/aim.c:13:		env->cam.stats.pitch += fabs((hhgt - y) * SENSI);
srcs//rasterizer/aim.c:18:		env->cam.stats.yaw -= fabs((hwdt - x) * SENSI) * env->cam.stats.aspect_ratio;
srcs//rasterizer/aim.c:19:		env->cam.stats.pitch -= fabs((hhgt - y) * SENSI);
srcs//rasterizer/aim.c:30:	hwdt = env->data.half_wdt;
srcs//rasterizer/aim.c:31:	hhgt = env->data.half_hgt;
srcs//rasterizer/aim.c:34:		env->cam.stats.yaw += fabs((hwdt - x) * SENSI) * env->cam.stats.aspect_ratio;
srcs//rasterizer/aim.c:35:		env->cam.stats.pitch += fabs((hhgt - y) * SENSI);
srcs//rasterizer/aim.c:40:		env->cam.stats.yaw += fabs((hwdt - x) * SENSI) * env->cam.stats.aspect_ratio;
srcs//rasterizer/aim.c:41:		env->cam.stats.pitch -= fabs((hhgt - y) * SENSI);
srcs//rasterizer/aim.c:53:	data = &env->data;
srcs//rasterizer/aim.c:54:	mouse_x = env->events.mouse_pos.x;
srcs//rasterizer/aim.c:55:	mouse_y = env->events.mouse_pos.y;
srcs//rasterizer/aim.c:59:	mlx_mouse_move(env->mlx.mlx_win, data->half_wdt, data->half_hgt);
srcs//rasterizer/aim.c:61:	env->events.mouse_pos.x = data->half_wdt;
srcs//rasterizer/aim.c:62:	env->events.mouse_pos.y = data->half_hgt;
srcs//rasterizer/rotation_matrices.c:24:    m[1][2] = -s;
srcs//rasterizer/rotation_matrices.c:40:    m[2][0] = -s;
srcs//rasterizer/rotation_matrices.c:54:    m[1][0] = -s;
Binary file srcs//rasterizer/camera.o matches
srcs//rasterizer/matrices.c:5:	cam->p_m[0][0] = cam->stats.aspect_ratio * cam->stats.fovr;
srcs//rasterizer/matrices.c:6:	cam->p_m[1][1] = cam->stats.fovr;
srcs//rasterizer/matrices.c:7:	cam->p_m[2][2] = cam->stats.ffar / cam->stats.fdelta;
srcs//rasterizer/matrices.c:8:	cam->p_m[3][2] = (-cam->stats.ffar * cam->stats.fnear) / cam->stats.fdelta;
srcs//rasterizer/matrices.c:9:	cam->p_m[2][3] = 1.0f;
srcs//rasterizer/matrices.c:10:	cam->p_m[3][3] = 0.0f;
srcs//rasterizer/matrices.c:20:		ft_memset(&cam->p_m[i][0], 0, sizeof(float) * 4);
srcs//rasterizer/matrices.c:21:		ft_memset(&cam->rx_m[i][0], 0, sizeof(float) * 4);
srcs//rasterizer/matrices.c:22:		ft_memset(&cam->ry_m[i][0], 0, sizeof(float) * 4);
srcs//rasterizer/matrices.c:23:		ft_memset(&cam->rz_m[i][0], 0, sizeof(float) * 4);
srcs//rasterizer/matrices.c:24:		ft_memset(&cam->crx_m[i][0], 0, sizeof(float) * 4);
srcs//rasterizer/matrices.c:25:		ft_memset(&cam->cry_m[i][0], 0, sizeof(float) * 4);
srcs//rasterizer/matrices.c:31:		cam->p_m[i][i] = 1.0f;
srcs//rasterizer/matrices.c:32:		cam->rx_m[i][i] = 1.0f;
srcs//rasterizer/matrices.c:33:		cam->ry_m[i][i] = 1.0f;
srcs//rasterizer/matrices.c:34:		cam->rz_m[i][i] = 1.0f;
srcs//rasterizer/matrices.c:35:		cam->crx_m[i][i] = 1.0f;
srcs//rasterizer/matrices.c:36:		cam->cry_m[i][i] = 1.0f;
srcs//rasterizer/clipping_bis.c:20:	out[0].points[0] = clip->in[0];
srcs//rasterizer/clipping_bis.c:21:	out[0].txt[0] = clip->txt_in[0];
srcs//rasterizer/clipping_bis.c:23:	out[0].points[1] = vec_intersect_plane(plane_p, plane_n, (t_vec3d[2]){clip->in[0], clip->out[0]}, &t);
srcs//rasterizer/clipping_bis.c:24:	out[0].txt[1].u = t * (clip->txt_out[0].u - clip->txt_in[0].u) + clip->txt_in[0].u;
srcs//rasterizer/clipping_bis.c:25:	out[0].txt[1].v = t * (clip->txt_out[0].v - clip->txt_in[0].v) + clip->txt_in[0].v;
srcs//rasterizer/clipping_bis.c:26:	out[0].txt[1].w = t * (clip->txt_out[0].w - clip->txt_in[0].w) + clip->txt_in[0].w;
srcs//rasterizer/clipping_bis.c:28:	out[0].points[2] = vec_intersect_plane(plane_p, plane_n, (t_vec3d[2]){clip->in[0], clip->out[1]}, &t);
srcs//rasterizer/clipping_bis.c:29:	out[0].txt[2].u = t * (clip->txt_out[1].u - clip->txt_in[0].u) + clip->txt_in[0].u;
srcs//rasterizer/clipping_bis.c:30:	out[0].txt[2].v = t * (clip->txt_out[1].v - clip->txt_in[0].v) + clip->txt_in[0].v;
srcs//rasterizer/clipping_bis.c:31:	out[0].txt[2].w = t * (clip->txt_out[1].w - clip->txt_in[0].w) + clip->txt_in[0].w;
srcs//rasterizer/clipping_bis.c:39:	out[0].points[0] = clip->in[0];
srcs//rasterizer/clipping_bis.c:40:	out[0].points[1] = clip->in[1];
srcs//rasterizer/clipping_bis.c:41:	out[0].txt[0] = clip->txt_in[0];
srcs//rasterizer/clipping_bis.c:42:	out[0].txt[1] = clip->txt_in[1];
srcs//rasterizer/clipping_bis.c:44:	out[0].points[2] = vec_intersect_plane(plane_p, plane_n, (t_vec3d[2]){clip->in[0], clip->out[0]}, &t);
srcs//rasterizer/clipping_bis.c:45:	out[0].txt[2].u = t * (clip->txt_out[0].u - clip->txt_in[0].u) + clip->txt_in[0].u;
srcs//rasterizer/clipping_bis.c:46:	out[0].txt[2].v = t * (clip->txt_out[0].v - clip->txt_in[0].v) + clip->txt_in[0].v;
srcs//rasterizer/clipping_bis.c:47:	out[0].txt[2].w = t * (clip->txt_out[0].w - clip->txt_in[0].w) + clip->txt_in[0].w;
srcs//rasterizer/clipping_bis.c:49:	out[1].points[0] = clip->in[1];
srcs//rasterizer/clipping_bis.c:50:	out[1].txt[0] = clip->txt_in[1];
srcs//rasterizer/clipping_bis.c:55:	out[1].points[2] = vec_intersect_plane(plane_p, plane_n, (t_vec3d[2]){clip->in[1], clip->out[0]}, &t);
srcs//rasterizer/clipping_bis.c:56:	out[1].txt[2].u = t * (clip->txt_out[0].u - clip->txt_in[1].u) + clip->txt_in[1].u;
srcs//rasterizer/clipping_bis.c:57:	out[1].txt[2].v = t * (clip->txt_out[0].v - clip->txt_in[1].v) + clip->txt_in[1].v;
srcs//rasterizer/clipping_bis.c:58:	out[1].txt[2].w = t * (clip->txt_out[0].w - clip->txt_in[1].w) + clip->txt_in[1].w;
srcs//rasterizer/clipping_bis.c:64:	if (clip->inside == 1 && clip->outside == 2)
srcs//rasterizer/clipping_bis.c:75:	else if (clip->inside == 2 && clip->outside == 1)
srcs//rasterizer/clipping_bis.c:101:	clip->inside = 0;
srcs//rasterizer/clipping_bis.c:102:	clip->outside = 0;
srcs//rasterizer/clipping_bis.c:105:		if (clip->d[i] >= 0)
srcs//rasterizer/clipping_bis.c:107:			clip->in[clip->inside++] = in.points[i];
srcs//rasterizer/clipping_bis.c:108:			clip->txt_in[clip->txt_inside++] = in.txt[i];
srcs//rasterizer/clipping_bis.c:112:			clip->out[clip->outside++] = in.points[i];
srcs//rasterizer/clipping_bis.c:113:			clip->txt_out[clip->txt_outside++] = in.txt[i];
Binary file srcs//rasterizer/matrix_ops.o matches
srcs//rasterizer/matrix_tools.c:28:	m[0][3] = -vec_dot(new_r, pos);
srcs//rasterizer/matrix_tools.c:30:	m[1][3] = -vec_dot(new_up, pos);
srcs//rasterizer/matrix_tools.c:32:	m[2][3] = -vec_dot(new_f, pos);
srcs//rasterizer/matrix_tools.c:51:	r[3][0] = -(m[3][0] * r[0][0] + m[3][1] * r[1][0] + m[3][2] * r[2][0]);
srcs//rasterizer/matrix_tools.c:52:	r[3][1] = -(m[3][0] * r[0][1] + m[3][1] * r[1][1] + m[3][2] * r[2][1]);
srcs//rasterizer/matrix_tools.c:53:	r[3][2] = -(m[3][0] * r[0][2] + m[3][1] * r[1][2] + m[3][2] * r[2][2]);
Binary file srcs//rasterizer/raster_tools.o matches
Binary file srcs//rasterizer/triangle_pipeline.o matches
srcs//rasterizer/raster_triangles.c:17:	thread->env = env;
srcs//rasterizer/raster_triangles.c:18:	thread->tris = &env->cam.to_raster;
srcs//rasterizer/raster_triangles.c:19:	thread->start = thread->id * part;
srcs//rasterizer/raster_triangles.c:20:	thread->index = thread->start;
srcs//rasterizer/raster_triangles.c:21:	thread->end = thread->start + part + (thread->id == NB_THREADS - 1 ? rest : 0);
srcs//rasterizer/raster_triangles.c:22:	thread->mono = false;
srcs//rasterizer/raster_triangles.c:23:	if (pthread_create(&thread->thread, NULL, rasthreader, thread))
srcs//rasterizer/raster_triangles.c:24:		return (-1);
srcs//rasterizer/raster_triangles.c:41:				return (-1);
srcs//rasterizer/raster_triangles.c:47:				return (-1);
srcs//rasterizer/raster_triangles.c:58:	clip_mesh_triangles(arr, &env->cam.to_raster, env->cam.clip_arrs);
srcs//rasterizer/raster_triangles.c:60:	if (env->cam.to_raster.nb_cells < NB_THREADS)
srcs//rasterizer/raster_triangles.c:64:		switch_threads(env, threads, env->cam.to_raster.nb_cells, false);
srcs//rasterizer/raster_triangles.c:65:		switch_threads(env, threads, env->cam.to_raster.nb_cells, true);
srcs//rasterizer/raster_triangles.c:67:	clear_dynarray(&env->cam.to_raster);
Binary file srcs//rasterizer/fill_triangle_texture_bis.o matches
Binary file srcs//rasterizer/fill_triangle_texture.o matches
Binary file srcs//rasterizer/aim.o matches
srcs//rasterizer/clipping.c:17:	static t_vec3d	ps[4] = {{0, 1.0f, 0, 0}, {0, -1.0f, 0, 0},
srcs//rasterizer/clipping.c:18:								{1.0f, 0, 0, 0}, {-1.0f, 0, 0, 0}};
srcs//rasterizer/clipping.c:28:		to_add = clip_triangle((t_vec3d){0, HGT - 1, 0, 0}, ps[1], t, clipped);
srcs//rasterizer/clipping.c:32:		to_add = clip_triangle((t_vec3d){WDT - 1, 0, 0, 0}, ps[3], t, clipped);
srcs//rasterizer/clipping.c:64:		while (i < arrs[p - 1].nb_cells)
srcs//rasterizer/clipping.c:66:			tmp = *(t_triangle*)dyacc(&arrs[p - 1], i);
srcs//rasterizer/clipping.c:70:		clear_dynarray(&arrs[p - 1]);
srcs//rasterizer/clipping.c:73:	i = -1;
srcs//rasterizer/clipping.c:85:	while (i < tris->nb_cells)
srcs//rasterizer/clipping.c:91:	i = -1;
Binary file srcs//rasterizer/rasterizer.o matches
Binary file srcs//rasterizer/matrices.o matches
srcs//rasterizer/camera.c:8:	if (address != map && !map->init)
srcs//rasterizer/camera.c:10:		map->init = true;
srcs//rasterizer/camera.c:11:		cam->stats.pos = map->spawn;
srcs//rasterizer/camera.c:12:		cam->stats.pos = vec_add(map->spawn, (t_vec3d){0, map->cam.corp.dims.y, 0, 0});
srcs//rasterizer/camera.c:13:		map->cam.corp.pos = map->spawn;
srcs//rasterizer/camera.c:14:		map->cam.corp.o = vec_sub(map->cam.corp.pos, vec_fdiv(map->cam.corp.dims, 2.0f));
srcs//rasterizer/camera.c:15:		cam->stats.yaw = map->cam_dir.u;
srcs//rasterizer/camera.c:16:		cam->stats.pitch = map->cam_dir.v;
srcs//rasterizer/camera.c:20:		cam->stats.pos = respawn ? map->spawn : map->cam.corp.pos;
srcs//rasterizer/camera.c:21:		map->cam.corp.pos = respawn ? map->spawn : map->cam.corp.pos;
srcs//rasterizer/camera.c:22:		map->cam.corp.o = vec_sub(map->cam.corp.pos, vec_fdiv(map->cam.corp.dims, 2.0f));
srcs//rasterizer/camera.c:23:		cam->stats.yaw = respawn ? map->cam.yaw : cam->stats.yaw;
srcs//rasterizer/camera.c:24:		cam->stats.pitch = respawn ? map->cam.pitch : cam->stats.pitch;
srcs//rasterizer/camera.c:37:			return (-1);
srcs//rasterizer/camera.c:51:		m = dyacc(&env->maps[i].meshs, 0);
srcs//rasterizer/camera.c:52:		printf("scene %d : mesh 0 : %d triangles\n", i, m->tris.nb_cells);
srcs//rasterizer/camera.c:65:		cam = &env->maps[i].cam;
srcs//rasterizer/camera.c:66:		cam->yaw = env->maps[i].cam_dir.u;
srcs//rasterizer/camera.c:67:		cam->pitch = env->maps[i].cam_dir.v;
srcs//rasterizer/camera.c:68:		cam->corp.pos = env->maps[i].spawn;
srcs//rasterizer/camera.c:69:		cam->corp.o = vec_sub(cam->corp.pos, vec_fdiv(cam->corp.dims, 2.0f));
srcs//rasterizer/camera.c:70:		cam->corp.dims = (t_vec3d){2, 3.0f, 2, 1.0f};
srcs//rasterizer/camera.c:78:	cam->stats.aspect_ratio = (float)HGT / (float)WDT;
srcs//rasterizer/camera.c:79:	cam->stats.fnear = 0.01f;
srcs//rasterizer/camera.c:80:	cam->stats.ffar = 1000.0f;
srcs//rasterizer/camera.c:81:	cam->stats.fovd = 70.0f;
srcs//rasterizer/camera.c:82:	cam->stats.fovr = (float)(1.0f / tan(cam->stats.fovd * 0.5f / 180.0f * 3.14159f));
srcs//rasterizer/camera.c:83:	cam->stats.fdelta = cam->stats.ffar - cam->stats.fnear;
srcs//rasterizer/camera.c:84:	cam->stats.pos = (t_vec3d){0, 0, 0, 0};
srcs//rasterizer/camera.c:85:	cam->stats.dir = (t_vec3d){10.0f, 40.0f, 0.0f, 0.0f};
srcs//rasterizer/camera.c:86:	cam->stats.pitch = 0;
srcs//rasterizer/camera.c:87:	cam->stats.yaw = 0;
srcs//rasterizer/camera.c:88:	cam->light = (t_vec3d){0.0f, 2.0f, 0.0f, 0.0f};
srcs//rasterizer/camera.c:89:	cam->light = vec_normalize(cam->light);
srcs//rasterizer/camera.c:91:	if (init_cameras_meshs(env) || allocate_clipping_arrays(cam->clip_arrs)
srcs//rasterizer/camera.c:92:		|| init_dynarray(&cam->to_clip, sizeof(t_triangle), MIN_TO_RASTER)
srcs//rasterizer/camera.c:93:		|| init_dynarray(&cam->to_raster, sizeof(t_triangle), MIN_TO_RASTER)
srcs//rasterizer/camera.c:94:		|| !(cam->z_buffer = (float*)malloc(sizeof(float) * (HGT * WDT))))
srcs//rasterizer/camera.c:95:		return (-1);
Binary file srcs//rasterizer/rotation_matrices.o matches
Binary file srcs//rasterizer/matrix_tools.o matches
Binary file srcs//rasterizer/clipping_bis.o matches
Binary file srcs//map_editor/map_to_scene.o matches
srcs//map_editor/build_map.c:8:	if (env->map == NULL)
srcs//map_editor/build_map.c:10:	i = -1;
srcs//map_editor/build_map.c:11:	while (*env->map && ++i < env->width)
srcs//map_editor/build_map.c:13:		j = -1;
srcs//map_editor/build_map.c:14:		while (**env->map && ++j < env->height)
srcs//map_editor/build_map.c:15:			ft_strdel((char**)&env->map[i][j]);
srcs//map_editor/build_map.c:16:		ft_strdel((char**)&env->map[i]);
srcs//map_editor/build_map.c:18:	free(env->map);
srcs//map_editor/build_map.c:19:	env->map = NULL;
srcs//map_editor/build_map.c:29:	if (!(env->map = (unsigned char ***)ft_memalloc(sizeof(unsigned char **) * env->width)))
srcs//map_editor/build_map.c:31:	x = -1;
srcs//map_editor/build_map.c:32:	while (error == 0 && ++x < env->width)
srcs//map_editor/build_map.c:34:		if (!(env->map[x] = (unsigned char **)ft_memalloc(sizeof(unsigned char *) * env->height)))
srcs//map_editor/build_map.c:36:		y = -1;
srcs//map_editor/build_map.c:37:		while (error == 0 && ++y < env->height)
srcs//map_editor/build_map.c:39:			if (!(env->map[x][y] = (unsigned char *)ft_memalloc(sizeof(unsigned char) * env->depth)))
srcs//map_editor/build_map.c:54:	while (x < new->width)
srcs//map_editor/build_map.c:57:		while (z < new->depth)
srcs//map_editor/build_map.c:59:			new->map[x][0][z] = BTXT_OBSIDIENNE;
srcs//map_editor/build_map.c:69:		return (-1);
srcs//map_editor/build_map.c:72:		return (-1);
Binary file srcs//map_editor/replace_by_face.o matches
srcs//map_editor/creative.c:7:	f = vec_fmult(env->cam.stats.dir, MAPED_WALK_SPEED);
srcs//map_editor/creative.c:8:	r = (t_vec3d){f.z, 0, -f.x, f.w};
srcs//map_editor/creative.c:10:		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
srcs//map_editor/creative.c:12:		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
srcs//map_editor/creative.c:14:		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
srcs//map_editor/creative.c:16:		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));
srcs//map_editor/creative.c:24:	bc = &env->edit_env.current_bc;
srcs//map_editor/creative.c:25:	if (on && e->keys[KEY_DOWN])
srcs//map_editor/creative.c:31:		env->edit_env.current_bt = *bc * 32;
srcs//map_editor/creative.c:34:	else if (on && e->keys[KEY_UP])
srcs//map_editor/creative.c:36:		if (*bc - 1 < BC_CUBE)
srcs//map_editor/creative.c:37:			*bc = BC_MAX - 1;
srcs//map_editor/creative.c:39:			*bc -= 1;
srcs//map_editor/creative.c:40:		env->edit_env.current_bt = *bc * 32;
srcs//map_editor/creative.c:43:	else if (!e->keys[KEY_DOWN] && !e->keys[KEY_UP])
srcs//map_editor/creative.c:52:	if (!e->buttons[BUTTON_LCLIC])
srcs//map_editor/creative.c:55:	if (!e->buttons[BUTTON_RCLIC])
srcs//map_editor/creative.c:58:	if (e->buttons[BUTTON_LCLIC] && env->mid.mesh && put_delay <= 0
srcs//map_editor/creative.c:61:	else if (e->buttons[BUTTON_RCLIC] && del_delay <= 0
srcs//map_editor/creative.c:65:	put_delay--;
srcs//map_editor/creative.c:66:	del_delay--;
srcs//map_editor/creative.c:72:	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]))
srcs//map_editor/creative.c:73:		move(env, e->keys);
srcs//map_editor/creative.c:75:	if (e->keys[KEY_E]) // Custom only, a tej d'ici
srcs//map_editor/creative.c:78:	if (env->events.keys[KEY_P])
srcs//map_editor/creative.c:79:		export_maped_map(&env->edit_env);
srcs//map_editor/creative.c:88:	if (e->keys[KEY_UP] || e->keys[KEY_DOWN] || e->buttons[BUTTON_SCLIC]
srcs//map_editor/creative.c:89:		|| e->buttons[BUTTON_SCROLL_DOWN] || e->buttons[BUTTON_SCROLL_UP])
srcs//map_editor/creative.c:91:	e->buttons[BUTTON_SCROLL_UP] = false;
srcs//map_editor/creative.c:92:	e->buttons[BUTTON_SCROLL_DOWN] = false;
srcs//map_editor/creative.c:97:	static int	last_gui_use = -1;
srcs//map_editor/creative.c:99:	last_gui_use == -1 ? last_gui_use = 500 : 0;
srcs//map_editor/creative.c:100:	handle_keys(env, &env->events);
srcs//map_editor/creative.c:101:	handle_mouse(env, &env->events);
srcs//map_editor/creative.c:104:	env->mid.mesh = NULL;
srcs//map_editor/creative.c:105:	assert(!rasterizer(env, &env->edit_env.map, false));
srcs//map_editor/creative.c:106:	refresh_last_gui(&env->events, &last_gui_use);
srcs//map_editor/creative.c:111:		last_gui_use--;
srcs//map_editor/creative.c:114:	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
Binary file srcs//map_editor/export.o matches
srcs//map_editor/block.c:8:	i = -1;
srcs//map_editor/block.c:9:	while (++i < map->meshs.nb_cells)
srcs//map_editor/block.c:11:		mesh = dyacc(&map->meshs, i);
srcs//map_editor/block.c:12:		if (mesh->m_pos[0] == pos[0]
srcs//map_editor/block.c:13:				&& mesh->m_pos[1] == pos[1]
srcs//map_editor/block.c:14:				&& mesh->m_pos[2] == pos[2])
srcs//map_editor/block.c:28:	if (x < 0 || x > env->edit_env.new_map.width - 1
srcs//map_editor/block.c:29:		|| y < 0 || y > env->edit_env.new_map.height - 1
srcs//map_editor/block.c:30:		|| z < 0 || z > env->edit_env.new_map.depth - 1)
srcs//map_editor/block.c:32:	m = get_blockindex(&env->edit_env.map, (int[3]){x, y, z}, &i);
srcs//map_editor/block.c:33:	if (m->type == BTXT_OBSIDIENNE)
srcs//map_editor/block.c:35:		m->type = BTXT_NONE;
srcs//map_editor/block.c:36:		del_recursif(env, x - 1, y, z);
srcs//map_editor/block.c:39:		del_recursif(env, x, y - 1, z);
srcs//map_editor/block.c:41:		del_recursif(env, x, y, z - 1);
srcs//map_editor/block.c:47:	if (env->mid.mesh && env->mid.mesh->type == BTXT_OBSIDIENNE)
srcs//map_editor/block.c:50:			env->mid.mesh->m_pos[0],
srcs//map_editor/block.c:51:			env->mid.mesh->m_pos[1],
srcs//map_editor/block.c:52:			env->mid.mesh->m_pos[2]);
srcs//map_editor/block.c:61:	if (!env->mid.mesh)
srcs//map_editor/block.c:63:	mesh = env->mid.mesh;
srcs//map_editor/block.c:64:	ft_memcpy(pos, mesh->m_pos, sizeof(int) * 3);
srcs//map_editor/block.c:65:	mesh->type = BTXT_NONE;
srcs//map_editor/block.c:66:	env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]] = BTXT_NONE;
srcs//map_editor/block.c:77:	i = -1;
srcs//map_editor/block.c:78:	if (!env->mid.mesh)
srcs//map_editor/block.c:80:	mesh = env->mid.mesh;
srcs//map_editor/block.c:81:	bt = (env->edit_env.current_bt == 0) ? 1 : env->edit_env.current_bt;
srcs//map_editor/block.c:82:	ft_memcpy(pos, mesh->m_pos, sizeof(int) * 3);
srcs//map_editor/block.c:83:	if (env->events.buttons[BUTTON_SCLIC])
srcs//map_editor/block.c:84:		if (env->events.buttons[BUTTON_SCROLL_UP]
srcs//map_editor/block.c:85:			|| env->events.buttons[BUTTON_SCROLL_DOWN])
srcs//map_editor/block.c:87:			mesh->type = bt;
srcs//map_editor/block.c:88:			env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]] = bt;
srcs//map_editor/block.c:89:			while (++i < mesh->tris.nb_cells)
srcs//map_editor/block.c:90:				((t_triangle*)dyacc(&mesh->tris, i))->sp = mesh->type;
srcs//map_editor/block.c:102:	bc = env->edit_env.current_bc;
srcs//map_editor/block.c:103:	ft_memcpy(pos, &env->mid.mesh->m_pos, sizeof(int) * 3);
srcs//map_editor/block.c:104:	if (replace_by_face(env, pos, env->mid.face_i, env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]]))
srcs//map_editor/block.c:106:	new = get_blockindex(&env->edit_env.map, pos, &m_index);
srcs//map_editor/block.c:107:	new->type = env->edit_env.current_bt + 1;
srcs//map_editor/block.c:108:	env->edit_env.new_map.map[pos[0]][pos[1]][pos[2]] = new->type;
srcs//map_editor/block.c:110:	free_dynarray(&new->tris);
srcs//map_editor/block.c:113:		create_cube(env, new, new->type);
srcs//map_editor/block.c:115:		create_slope(env, new, new->type);
srcs//map_editor/block.c:116:	attribute_mesh(&env->edit_env.map, m_index);
srcs//map_editor/new_map.c:14:	img = env->mlx.img_data;
srcs//map_editor/new_map.c:38:	conf->size = 16;
srcs//map_editor/new_map.c:39:	ft_memset(conf->s, 0, MAX_STR_CHARS);
srcs//map_editor/new_map.c:40:	ft_strcpy((char*)conf->s, err_msg[error]);
srcs//map_editor/new_map.c:41:	my_string_put(env, env->mlx.img_data, (t_point){100, 450}, FONT_ARIAL);
srcs//map_editor/new_map.c:42:	ft_memset(conf->s, 0, MAX_STR_CHARS);
srcs//map_editor/new_map.c:49:	ret = is_on_button(env->events.mouse_pos, env->edit_env.buttons[MAPED_NM_BUTTON_CREATE]);
srcs//map_editor/new_map.c:50:	env->edit_env.buttons[MAPED_NM_BUTTON_CREATE].is_hover = ret;
srcs//map_editor/new_map.c:51:	if (ret && env->events.buttons[BUTTON_LCLIC]
srcs//map_editor/new_map.c:52:		&& !(env->edit_env.error = create_me_map(env)))
srcs//map_editor/new_map.c:55:	ret = is_on_button(env->events.mouse_pos, env->edit_env.buttons[MAPED_NM_BUTTON_MAPED]);
srcs//map_editor/new_map.c:56:	env->edit_env.buttons[MAPED_NM_BUTTON_MAPED].is_hover = ret;
srcs//map_editor/new_map.c:57:	if (ret && env->events.buttons[BUTTON_LCLIC])
srcs//map_editor/new_map.c:61:	if (env->edit_env.error == -1)
srcs//map_editor/new_map.c:64:		display_new_map_error(env, env->edit_env.error);
srcs//map_editor/new_map.c:70:	map_sprite(env->mlx.img_data, env->sprites[SP_ME_NM_TITLE],
srcs//map_editor/new_map.c:74:	render_button(env, env->edit_env.buttons[MAPED_NM_BUTTON_CREATE]);
srcs//map_editor/new_map.c:75:	render_button(env, env->edit_env.buttons[MAPED_NM_BUTTON_MAPED]);
srcs//map_editor/new_map.c:76:	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
Binary file srcs//map_editor/convert_matrice.o matches
srcs//map_editor/menu.c:20:	i = -1;
srcs//map_editor/menu.c:22:		if (is_on_button(env->events.mouse_pos, env->edit_env.buttons[i]))
srcs//map_editor/menu.c:24:			if (!env->events.buttons[BUTTON_LCLIC] && clic)
srcs//map_editor/menu.c:33:			clic = env->events.buttons[BUTTON_LCLIC];
srcs//map_editor/menu.c:34:			env->edit_env.buttons[i].is_hover = true;
srcs//map_editor/menu.c:37:			env->edit_env.buttons[i].is_hover = false;
srcs//map_editor/menu.c:43:	render_button(env, env->edit_env.buttons[MAPED_MENU_BUTTON_NEW_MAP]);
srcs//map_editor/menu.c:44:	render_button(env, env->edit_env.buttons[MAPED_MENU_BUTTON_MAIN_MENU]);
srcs//map_editor/menu.c:51:	s = &env->scroll;
srcs//map_editor/menu.c:53:	if (s->s_path)
srcs//map_editor/menu.c:55:		if (import_maped_map(&env->edit_env, s->s_path))
srcs//map_editor/menu.c:57:			printf("Parsing Failed for map |%s|\n", s->s_path);
srcs//map_editor/menu.c:59:			return (-1);
srcs//map_editor/menu.c:62:			return (-1);
srcs//map_editor/menu.c:65:	ft_strdel(&s->s_path);
srcs//map_editor/menu.c:72:	map_sprite(env->mlx.img_data, env->sprites[SP_ME_BACKGROUND], (t_point){0, 0});
srcs//map_editor/menu.c:73:	map_sprite(env->mlx.img_data, env->sprites[SP_ME_MENU_TITLE], (t_point){420, 60});
srcs//map_editor/menu.c:76:		return (-1);
srcs//map_editor/menu.c:79:	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
Binary file srcs//map_editor/routines.o matches
Binary file srcs//map_editor/render_pallet.o matches
Binary file srcs//map_editor/file.o matches
srcs//map_editor/create_map.c:11:			return (-1);
srcs//map_editor/create_map.c:24:	e = &env->edit_env;
srcs//map_editor/create_map.c:25:	s[0] = env->ttfs.fields[FIELD_NM_MAP_WIDTH].str.c;
srcs//map_editor/create_map.c:26:	s[1] = env->ttfs.fields[FIELD_NM_MAP_HEIGHT].str.c;
srcs//map_editor/create_map.c:27:	s[2] = env->ttfs.fields[FIELD_NM_MAP_DEPTH].str.c;
srcs//map_editor/create_map.c:30:	e->new_map.width = ft_atoi(s[0]);
srcs//map_editor/create_map.c:31:	e->new_map.height = ft_atoi(s[1]);
srcs//map_editor/create_map.c:32:	e->new_map.depth = ft_atoi(s[2]);
srcs//map_editor/create_map.c:33:	if (!ft_inbounds(e->new_map.width, 1, INT_MAX)
srcs//map_editor/create_map.c:34:		|| !ft_inbounds(e->new_map.height, 1, INT_MAX)
srcs//map_editor/create_map.c:35:		|| !ft_inbounds(e->new_map.depth, 1, INT_MAX))
srcs//map_editor/create_map.c:37:	if (e->new_map.width * e->new_map.height * e->new_map.depth > MAX_CHUNKS)
srcs//map_editor/create_map.c:48:	input = env->ttfs.fields[FIELD_NM_NAME].str.c;
srcs//map_editor/create_map.c:57:	if (!(env->edit_env.new_map.name = ft_strdup(input)))
srcs//map_editor/create_map.c:70:	if (build_map(env, &env->edit_env.new_map))
srcs//map_editor/create_map.c:71:		return (-1);
Binary file srcs//map_editor/events.o matches
srcs//map_editor/listpath.c:16:	i = -1;
srcs//map_editor/listpath.c:35:	while (len--)
srcs//map_editor/listpath.c:45:	size = ft_strlen(read->d_name);
srcs//map_editor/listpath.c:46:	while (size > 0 && read->d_name[size] != '.')
srcs//map_editor/listpath.c:47:		--size;
srcs//map_editor/listpath.c:50:	if (good_format(read->d_name + size, format) == 1)
srcs//map_editor/listpath.c:52:		while (--size > -1)
srcs//map_editor/listpath.c:53:			if (!ft_isalnum(read->d_name[size]))
srcs//map_editor/listpath.c:55:		if (!(*path_tab = tab_add(*path_tab, read->d_name)))
srcs//map_editor/listpath.c:56:			return (-1);
srcs//map_editor/listpath.c:75:			if (check_format(&path_tab, read, format) == -1)
Binary file srcs//map_editor/switch_bt.o matches
srcs//map_editor/import.c:25:		return (-1);
srcs//map_editor/import.c:30:		return (-1);
srcs//map_editor/import.c:35:		return (-1);
srcs//map_editor/import.c:63:	if (!(env->new_map.name = get_file_name(name)))
srcs//map_editor/import.c:64:		return (-1);
srcs//map_editor/import.c:66:	if ((fd = open(path, O_RDONLY)) == -1)
srcs//map_editor/import.c:69:		return (-1);
srcs//map_editor/import.c:74:		return (-1);
srcs//map_editor/import.c:78:		return (-1);
srcs//map_editor/import.c:79:	env->new_map.flat = (unsigned char*)file;
srcs//map_editor/import.c:80:	if (!flat_to_matrice(&env->new_map, offset, len))
srcs//map_editor/import.c:81:		return (-1);
Binary file srcs//map_editor/input_field.o matches
srcs//map_editor/crosshair.c:10:	h.x = env->data.half_wdt - CROSSHAIR_SIZE;
srcs//map_editor/crosshair.c:11:	h.y = env->data.half_hgt - CROSSHAIR_THICKNESS;
srcs//map_editor/crosshair.c:12:	v.x = env->data.half_wdt - CROSSHAIR_THICKNESS;
srcs//map_editor/crosshair.c:13:	v.y = env->data.half_hgt - CROSSHAIR_SIZE;
srcs//map_editor/crosshair.c:18:	draw_rectangle(env->mlx.img_data, h, h_d, CROSSHAIR_COLOR);
srcs//map_editor/crosshair.c:19:	draw_rectangle(env->mlx.img_data, v, v_d, CROSSHAIR_COLOR);
Binary file srcs//map_editor/pallet.o matches
srcs//map_editor/render.c:33:	edit_env = &env->edit_env;
srcs//map_editor/render.c:39:		return (-1);
srcs//map_editor/render.c:41:	if (routines[edit_env->sub_context][i])
srcs//map_editor/render.c:42:		routines[edit_env->sub_context][i](env);
srcs//map_editor/render.c:43:	edit_env->sub_context = i;
srcs//map_editor/render.c:54:	return (sub_contexts[env->edit_env.sub_context](env));
Binary file srcs//map_editor/setup_me.o matches
Binary file srcs//map_editor/category_pallet.o matches
Binary file srcs//map_editor/neighbourgs.o matches
Binary file srcs//map_editor/load_shapes.o matches
Binary file srcs//map_editor/build_map.o matches
srcs//map_editor/replace_by_face.c:8:		pos[2]--;
srcs//map_editor/replace_by_face.c:14:		pos[1]--;
srcs//map_editor/replace_by_face.c:15:	if (!ft_inbounds(pos[0], 0, env->edit_env.new_map.width - 1)
srcs//map_editor/replace_by_face.c:16:			|| !ft_inbounds(pos[1], 0, env->edit_env.new_map.height - 1)
srcs//map_editor/replace_by_face.c:17:			|| !ft_inbounds(pos[2], 0, env->edit_env.new_map.depth - 1))
srcs//map_editor/replace_by_face.c:29:		pos[2]--;
srcs//map_editor/replace_by_face.c:31:		pos[0]--;
srcs//map_editor/replace_by_face.c:33:		pos[1]--;
srcs//map_editor/replace_by_face.c:34:	if (!ft_inbounds(pos[0], 0, env->edit_env.new_map.width - 1)
srcs//map_editor/replace_by_face.c:35:			|| !ft_inbounds(pos[1], 0, env->edit_env.new_map.height - 1)
srcs//map_editor/replace_by_face.c:36:			|| !ft_inbounds(pos[2], 0, env->edit_env.new_map.depth - 1))
srcs//map_editor/replace_by_face.c:46:		pos[0]--;
srcs//map_editor/replace_by_face.c:50:		pos[2]--;
srcs//map_editor/replace_by_face.c:52:		pos[1]--;
srcs//map_editor/replace_by_face.c:53:	if (!ft_inbounds(pos[0], 0, env->edit_env.new_map.width - 1)
srcs//map_editor/replace_by_face.c:54:			|| !ft_inbounds(pos[1], 0, env->edit_env.new_map.height - 1)
srcs//map_editor/replace_by_face.c:55:			|| !ft_inbounds(pos[2], 0, env->edit_env.new_map.depth - 1))
srcs//map_editor/replace_by_face.c:67:		pos[0]--;
srcs//map_editor/replace_by_face.c:71:		pos[1]--;
srcs//map_editor/replace_by_face.c:72:	if (!ft_inbounds(pos[0], 0, env->edit_env.new_map.width - 1)
srcs//map_editor/replace_by_face.c:73:			|| !ft_inbounds(pos[1], 0, env->edit_env.new_map.height - 1)
srcs//map_editor/replace_by_face.c:74:			|| !ft_inbounds(pos[2], 0, env->edit_env.new_map.depth - 1))
srcs//map_editor/replace_by_face.c:92:		pos[0]--;
srcs//map_editor/replace_by_face.c:96:		pos[1]--;
srcs//map_editor/replace_by_face.c:98:		pos[2]--;
srcs//map_editor/replace_by_face.c:101:	if (!ft_inbounds(pos[0], 0, env->edit_env.new_map.width - 1)
srcs//map_editor/replace_by_face.c:102:			|| !ft_inbounds(pos[1], 0, env->edit_env.new_map.height - 1)
srcs//map_editor/replace_by_face.c:103:			|| !ft_inbounds(pos[2], 0, env->edit_env.new_map.depth - 1))
Binary file srcs//map_editor/creative.o matches
srcs//map_editor/map_to_scene.c:10:		t->points[i].x += new->m_pos[0] * 2;
srcs//map_editor/map_to_scene.c:11:		t->points[i].y += new->m_pos[1] * 2;
srcs//map_editor/map_to_scene.c:12:		t->points[i].z += new->m_pos[2] * 2;
srcs//map_editor/map_to_scene.c:19:	if (x < 0 || x > map->width - 1
srcs//map_editor/map_to_scene.c:20:		|| y < 0 || y > map->height - 1
srcs//map_editor/map_to_scene.c:21:		|| z < 0 || z > map->depth - 1)
srcs//map_editor/map_to_scene.c:23:	return (map->map[x][y][z] > BTXT_NONE);
srcs//map_editor/map_to_scene.c:31:	neighbours += test_neighbours(map, pos[0] - 1, pos[1], pos[2]);
srcs//map_editor/map_to_scene.c:33:	neighbours += test_neighbours(map, pos[0], pos[1] - 1, pos[2]);
srcs//map_editor/map_to_scene.c:35:	neighbours += test_neighbours(map, pos[0], pos[1], pos[2] - 1);
srcs//map_editor/map_to_scene.c:48:		ret = type - 160 + BTXT_JUKEBOX - 1;
srcs//map_editor/map_to_scene.c:49:	if (env->context == C_CUSTOM)
srcs//map_editor/map_to_scene.c:50:		if (full_neighbours(&env->edit_env.new_map, new->m_pos))
srcs//map_editor/map_to_scene.c:62:	mesh = dyacc(&scene->meshs, index);
srcs//map_editor/map_to_scene.c:63:	while (i < mesh->tris.nb_cells)
srcs//map_editor/map_to_scene.c:65:		t = dyacc(&mesh->tris, i);
srcs//map_editor/map_to_scene.c:66:		t->mesh = mesh;
srcs//map_editor/map_to_scene.c:81:		return (-1);
srcs//map_editor/map_to_scene.c:83:		return (-1);
srcs//map_editor/map_to_scene.c:84:	if (env->context == C_CUSTOM)
srcs//map_editor/map_to_scene.c:86:	if (push_dynarray(&scene->meshs, &new, false))
srcs//map_editor/map_to_scene.c:87:		return (-1);
srcs//map_editor/map_to_scene.c:88:	attribute_mesh(scene, scene->nmesh);
srcs//map_editor/map_to_scene.c:89:	scene->nmesh = scene->meshs.nb_cells;
srcs//map_editor/map_to_scene.c:101:	x = -1;
srcs//map_editor/map_to_scene.c:102:	edit_env = &env->edit_env;
srcs//map_editor/map_to_scene.c:103:	scene = &edit_env->map;
srcs//map_editor/map_to_scene.c:104:	if (init_dynarray(&scene->meshs, sizeof(t_mesh), MAX_CHUNKS))
srcs//map_editor/map_to_scene.c:105:		return (-1);
srcs//map_editor/map_to_scene.c:106:	while (++x < edit_env->new_map.width)
srcs//map_editor/map_to_scene.c:108:		y = -1;
srcs//map_editor/map_to_scene.c:109:		while (++y < edit_env->new_map.height)
srcs//map_editor/map_to_scene.c:111:			z = -1;
srcs//map_editor/map_to_scene.c:112:			while (++z < edit_env->new_map.depth)
srcs//map_editor/map_to_scene.c:114:					edit_env->new_map.map[x][y][z], (int[3]){x, y, z}))
srcs//map_editor/map_to_scene.c:115:					return (-1);
srcs//map_editor/map_to_scene.c:118:	scene->spawn = (t_vec3d){0, 0, 0, 0};
srcs//map_editor/routines.c:7:	env->ttfs.fields[0].rendered = true;
srcs//map_editor/routines.c:8:	env->ttfs.fields[1].rendered = true;
srcs//map_editor/routines.c:9:	env->ttfs.fields[2].rendered = true;
srcs//map_editor/routines.c:10:	env->ttfs.fields[3].rendered = true;
srcs//map_editor/routines.c:31:	env->ttfs.fields[0].rendered = false;
srcs//map_editor/routines.c:32:	env->ttfs.fields[1].rendered = false;
srcs//map_editor/routines.c:33:	env->ttfs.fields[2].rendered = false;
srcs//map_editor/routines.c:34:	env->ttfs.fields[3].rendered = false;
Binary file srcs//map_editor/menu.o matches
srcs//map_editor/convert_matrice.c:8:	nb[1] = -1;	
srcs//map_editor/convert_matrice.c:9:	while (++nb[1] < env->width)
srcs//map_editor/convert_matrice.c:11:		nb[2] = -1;
srcs//map_editor/convert_matrice.c:12:		while (++nb[2] < env->height)
srcs//map_editor/convert_matrice.c:14:			nb[3] = -1;
srcs//map_editor/convert_matrice.c:15:			while (++nb[3] < env->depth)
srcs//map_editor/convert_matrice.c:16:				env->flat[nb[0]++] = env->map[nb[1]][nb[2]][nb[3]];
srcs//map_editor/convert_matrice.c:17:			if (nb[2] + 1 < env->height)
srcs//map_editor/convert_matrice.c:18:				env->flat[nb[0]++] = 127;
srcs//map_editor/convert_matrice.c:20:		if (nb[1] + 1 < env->width)
srcs//map_editor/convert_matrice.c:22:			env->flat[nb[0]++] = 127;
srcs//map_editor/convert_matrice.c:23:			env->flat[nb[0]++] = 127;
srcs//map_editor/convert_matrice.c:26:	env->flat[nb[0]] = '\0';
srcs//map_editor/convert_matrice.c:34:	if (env->map == NULL
srcs//map_editor/convert_matrice.c:35:		|| env->width + env->height + env->depth == 0)
srcs//map_editor/convert_matrice.c:37:	size = (env->width + 1) * (env->height + 2) * env->depth;
srcs//map_editor/convert_matrice.c:38:	if (!(env->flat = (unsigned char *)ft_memalloc((sizeof(unsigned char) * (size + 1)))))
srcs//map_editor/convert_matrice.c:47:	if (env->width == 0)
srcs//map_editor/convert_matrice.c:48:		env->width = nb[0] - nb[1];
srcs//map_editor/convert_matrice.c:49:	else if (env->width != nb[0] - nb[1])
srcs//map_editor/convert_matrice.c:51:	if (env->flat[nb[0] + 1] == 127)
srcs//map_editor/convert_matrice.c:53:		if (env->height == 0)
srcs//map_editor/convert_matrice.c:54:			env->height = nb[2];
srcs//map_editor/convert_matrice.c:55:		else if (env->height != nb[2])
srcs//map_editor/convert_matrice.c:68:	if (env->width != nb[0] - nb[1])
srcs//map_editor/convert_matrice.c:70:	if (env->height == 0)
srcs//map_editor/convert_matrice.c:71:		env->height = nb[2];
srcs//map_editor/convert_matrice.c:72:	if (env->depth == 0)
srcs//map_editor/convert_matrice.c:73:		env->depth = nb[3];
srcs//map_editor/convert_matrice.c:74:	return (env->height == nb[2]);
srcs//map_editor/convert_matrice.c:83:	nb[0] = -1;
srcs//map_editor/convert_matrice.c:87:		while (nb[0] < len && env->flat[nb[0]] != 127)
srcs//map_editor/convert_matrice.c:89:		if (env->flat[nb[0]] == 127)
srcs//map_editor/convert_matrice.c:100:	ft_swap(&env->width, &env->depth);
srcs//map_editor/convert_matrice.c:101:	return (env->width && env->height && env->depth);
srcs//map_editor/convert_matrice.c:112:	w = -1;
srcs//map_editor/convert_matrice.c:113:	while (++w < env->width)
srcs//map_editor/convert_matrice.c:115:		h = -1;
srcs//map_editor/convert_matrice.c:116:		while (++h < env->height)
srcs//map_editor/convert_matrice.c:118:			d = -1;
srcs//map_editor/convert_matrice.c:119:			while(++d < env->depth)
srcs//map_editor/convert_matrice.c:121:				while (env->flat[i] == 127)
srcs//map_editor/convert_matrice.c:123:				env->map[w][h][d] = env->flat[i];
srcs//map_editor/convert_matrice.c:132:	env->flat += offset;
srcs//map_editor/convert_matrice.c:133:	len -= offset;
srcs//map_editor/convert_matrice.c:134:	if (env->flat == NULL
srcs//map_editor/convert_matrice.c:138:		env->flat -= offset;
srcs//map_editor/convert_matrice.c:142:	env->flat -= offset;
srcs//map_editor/export.c:11:		return (-1);
srcs//map_editor/export.c:16:		return (-1);
srcs//map_editor/export.c:22:		return (-1);
srcs//map_editor/export.c:43:	i = -1;
srcs//map_editor/export.c:44:	if (!flat_map(&env->new_map, &matrice_len))
srcs//map_editor/export.c:54:	i = -1;
srcs//map_editor/export.c:56:		file[i + *len] = env->new_map.flat[i];
srcs//map_editor/export.c:69:	if (write_header(&header, env->new_map.name))
srcs//map_editor/export.c:70:		return (-1);
srcs//map_editor/export.c:72:	gen_path(path, env->new_map.name);
srcs//map_editor/export.c:74:		return (-1);
srcs//map_editor/export.c:76:		return (-1);
Binary file srcs//map_editor/block.o matches
Binary file srcs//map_editor/new_map.o matches
Binary file srcs//map_editor/listpath.o matches
srcs//map_editor/switch_bt.c:27:	if (e->buttons[BUTTON_SCROLL_UP])
srcs//map_editor/switch_bt.c:29:	else if (e->buttons[BUTTON_SCROLL_DOWN])
srcs//map_editor/switch_bt.c:30:		bt_cube = (bt_cube < 0) ? NB_CUBES_ICONES - 1 : bt_cube - 1;
srcs//map_editor/switch_bt.c:45:		if (e->buttons[BUTTON_SCROLL_UP])
srcs//map_editor/switch_bt.c:46:			bt_slope = (bt_slope >= 32 + NB_CUBES_ICONES - 1) ? 32 : bt_slope + 1;
srcs//map_editor/switch_bt.c:47:		else if (e->buttons[BUTTON_SCROLL_DOWN])
srcs//map_editor/switch_bt.c:48:			bt_slope = (bt_slope < 32) ? 32 + NB_CUBES_ICONES - 1 : bt_slope - 1;
srcs//map_editor/switch_bt.c:52:		if (e->buttons[BUTTON_SCROLL_UP])
srcs//map_editor/switch_bt.c:53:			bt_slope = (bt_slope >= 64 + NB_CUBES_ICONES - 1) ? 64 : bt_slope + 1;
srcs//map_editor/switch_bt.c:54:		else if (e->buttons[BUTTON_SCROLL_DOWN])
srcs//map_editor/switch_bt.c:55:			bt_slope = (bt_slope < 64) ? 64 + NB_CUBES_ICONES - 1 : bt_slope - 1;
srcs//map_editor/switch_bt.c:59:		if (e->buttons[BUTTON_SCROLL_UP])
srcs//map_editor/switch_bt.c:60:			bt_slope = (bt_slope >= 96 + NB_CUBES_ICONES - 1) ? 96 : bt_slope + 1;
srcs//map_editor/switch_bt.c:61:		else if (e->buttons[BUTTON_SCROLL_DOWN])
srcs//map_editor/switch_bt.c:62:			bt_slope = (bt_slope < 96) ? 96 + NB_CUBES_ICONES - 1 : bt_slope - 1;
srcs//map_editor/switch_bt.c:66:		if (e->buttons[BUTTON_SCROLL_UP])
srcs//map_editor/switch_bt.c:67:			bt_slope = (bt_slope >= 128 + NB_CUBES_ICONES - 1) ? 128 : bt_slope + 1;
srcs//map_editor/switch_bt.c:68:		else if (e->buttons[BUTTON_SCROLL_DOWN])
srcs//map_editor/switch_bt.c:69:			bt_slope = (bt_slope < 128) ? 128 + NB_CUBES_ICONES - 1 : bt_slope - 1;
srcs//map_editor/switch_bt.c:79:	if (e->buttons[BUTTON_SCROLL_UP])
srcs//map_editor/switch_bt.c:80:		*bt = (*bt >= 160 + NB_INTERACTIVES - 1) ? 160 : *bt + 1;
srcs//map_editor/switch_bt.c:81:	else if (e->buttons[BUTTON_SCROLL_DOWN])
srcs//map_editor/switch_bt.c:82:		*bt = (*bt <= 160) ? 160 + NB_INTERACTIVES - 1 : *bt - 1;
srcs//map_editor/switch_bt.c:90:	bc = env->edit_env.current_bc;
srcs//map_editor/switch_bt.c:91:	bt = &env->edit_env.current_bt;
Binary file srcs//map_editor/import.o matches
Binary file srcs//map_editor/create_map.o matches
srcs//map_editor/events.c:22:	sc = env->edit_env.sub_context;
srcs//map_editor/events.c:63:	env->events.mouse_pos = (t_point){x, y};
srcs//map_editor/render_pallet.c:5:	pos = (t_point){o.x + (index * 34) - 1, o.y};
srcs//map_editor/render_pallet.c:6:	draw_rectangle(env->mlx.img_data, pos, (t_point){3, 34}, 0x00ff00);
srcs//map_editor/render_pallet.c:7:	draw_rectangle(env->mlx.img_data, pos, (t_point){34, 2}, 0x00ff00);
srcs//map_editor/render_pallet.c:9:	draw_rectangle(env->mlx.img_data, pos, (t_point){3, 34}, 0x00ff00);
srcs//map_editor/render_pallet.c:10:	pos.x -= 34;
srcs//map_editor/render_pallet.c:12:	draw_rectangle(env->mlx.img_data, pos, (t_point){37, 2}, 0x00ff00);
srcs//map_editor/render_pallet.c:25:	conf->size = 14;
srcs//map_editor/render_pallet.c:26:	index = env->edit_env.current_bt - 160;
srcs//map_editor/render_pallet.c:28:	ft_strcpy((char*)conf->s, names[index]);
srcs//map_editor/render_pallet.c:29:	my_string_put(env, env->mlx.img_data, o, FONT_COOLVETICA);
srcs//map_editor/render_pallet.c:42:	index = env->edit_env.current_bt % 32;
srcs//map_editor/render_pallet.c:43:	while (i < BTXT_MAX - 1)
srcs//map_editor/render_pallet.c:50:			blit_sprite(env->mlx.img_data, p[i].sprite, pos, 2.0f);
srcs//map_editor/neighbourgs.c:5:	if (pos[0] < 0 || pos[0] > map->width - 1
srcs//map_editor/neighbourgs.c:6:		|| pos[1] < 0 || pos[1] > map->height - 1
srcs//map_editor/neighbourgs.c:7:		|| pos[2] < 0 || pos[2] > map->depth - 1)
srcs//map_editor/neighbourgs.c:9:	if (map->map[pos[0]][pos[1]][pos[2]] > BTXT_NONE)
srcs//map_editor/neighbourgs.c:17:	int			*pos = new->m_pos;
srcs//map_editor/neighbourgs.c:20:	if (new->type == BTXT_NONE)
srcs//map_editor/neighbourgs.c:23:	i = -1;
srcs//map_editor/neighbourgs.c:24:	while (++i < new->tris.nb_cells)
srcs//map_editor/neighbourgs.c:26:		tri = dyacc(&new->tris, i);
srcs//map_editor/neighbourgs.c:27:		if (tri->face_i == FACE_NORD)
srcs//map_editor/neighbourgs.c:28:			tri->sp = check_face(&env->edit_env.new_map, new->type,
srcs//map_editor/neighbourgs.c:29:				(int[3]){ pos[0], pos[1], pos[2] - 1});
srcs//map_editor/neighbourgs.c:30:		else if (tri->face_i == FACE_SUD)
srcs//map_editor/neighbourgs.c:31:			tri->sp = check_face(&env->edit_env.new_map, new->type,
srcs//map_editor/neighbourgs.c:33:		else if (tri->face_i == FACE_EST)
srcs//map_editor/neighbourgs.c:34:			tri->sp = check_face(&env->edit_env.new_map, new->type,
srcs//map_editor/neighbourgs.c:35:				(int[3]){ pos[0] - 1, pos[1], pos[2] });
srcs//map_editor/neighbourgs.c:36:		else if (tri->face_i == FACE_OUEST)
srcs//map_editor/neighbourgs.c:37:			tri->sp = check_face(&env->edit_env.new_map, new->type,
srcs//map_editor/neighbourgs.c:39:		else if (tri->face_i == FACE_UP)
srcs//map_editor/neighbourgs.c:40:			tri->sp = check_face(&env->edit_env.new_map, new->type,
srcs//map_editor/neighbourgs.c:42:		else if (tri->face_i == FACE_BOTTOM)
srcs//map_editor/neighbourgs.c:43:			tri->sp = check_face(&env->edit_env.new_map, new->type,
srcs//map_editor/neighbourgs.c:44:				(int[3]){ pos[0], pos[1] - 1, pos[2] });
srcs//map_editor/setup_me.c:21:	me_env = &env->edit_env;
srcs//map_editor/setup_me.c:22:	b = &me_env->buttons[MAPED_NM_BUTTON_CREATE];
srcs//map_editor/setup_me.c:23:	sps[0] = &env->sprites[SP_ME_BUTTON_CREATE_1C];
srcs//map_editor/setup_me.c:24:	sps[1] = &env->sprites[SP_ME_BUTTON_CREATE_1H];
srcs//map_editor/setup_me.c:25:	sps[2] = &env->sprites[SP_ME_BUTTON_CREATE_1O];
srcs//map_editor/setup_me.c:27:	b->r_down = (t_point){600 + env->sprites[SP_ME_BUTTON_CREATE_1C].wdt, 500 + env->sprites[SP_ME_BUTTON_CREATE_1C].hgt};
srcs//map_editor/setup_me.c:29:	b = &me_env->buttons[MAPED_NM_BUTTON_MAPED];
srcs//map_editor/setup_me.c:30:	sps[0] = &env->sprites[SP_NM_BUTTON_MAPED_2C];
srcs//map_editor/setup_me.c:31:	sps[1] = &env->sprites[SP_NM_BUTTON_MAPED_2H];
srcs//map_editor/setup_me.c:32:	sps[2] = &env->sprites[SP_NM_BUTTON_MAPED_2O];
srcs//map_editor/setup_me.c:34:	b->r_down = (t_point){200 + env->sprites[SP_NM_BUTTON_MAPED_2C].wdt, 500 + env->sprites[SP_NM_BUTTON_MAPED_2C].hgt};
srcs//map_editor/setup_me.c:43:	me_env = &env->edit_env;
srcs//map_editor/setup_me.c:44:	b = &me_env->buttons[MAPED_MENU_BUTTON_MAIN_MENU];
srcs//map_editor/setup_me.c:45:	sps[0] = &env->sprites[SP_CP_BUTTON_1C];
srcs//map_editor/setup_me.c:46:	sps[1] = &env->sprites[SP_CP_BUTTON_1H];
srcs//map_editor/setup_me.c:47:	sps[2] = &env->sprites[SP_CP_BUTTON_1O];
srcs//map_editor/setup_me.c:49:	b->r_down = (t_point){800 + env->sprites[SP_CP_BUTTON_1C].wdt, 600 + env->sprites[SP_CP_BUTTON_1C].hgt};
srcs//map_editor/setup_me.c:51:	b = &me_env->buttons[MAPED_MENU_BUTTON_NEW_MAP];
srcs//map_editor/setup_me.c:52:	sps[0] = &env->sprites[SP_ME_BUTTON_2C];
srcs//map_editor/setup_me.c:53:	sps[1] = &env->sprites[SP_ME_BUTTON_2H];
srcs//map_editor/setup_me.c:54:	sps[2] = &env->sprites[SP_ME_BUTTON_2O];
srcs//map_editor/setup_me.c:56:	b->r_down = (t_point){800 + env->sprites[SP_ME_BUTTON_2C].wdt, 500 + env->sprites[SP_CP_BUTTON_2C].hgt};
srcs//map_editor/setup_me.c:65:	ttf = &env->ttfs;
srcs//map_editor/setup_me.c:66:	ft_memset(&ttf->fields, 0, sizeof(t_text_box) * FIELD_MAX);
srcs//map_editor/setup_me.c:67:	ttf->fields[0].o = (t_point){140, 350};
srcs//map_editor/setup_me.c:68:	ttf->fields[1].o = (t_point){440, 350};
srcs//map_editor/setup_me.c:69:	ttf->fields[2].o = (t_point){740, 350};
srcs//map_editor/setup_me.c:70:	ttf->fields[3].o = (t_point){440, 200};
srcs//map_editor/setup_me.c:72:	if (!(ttf->fields[0].name = ft_strdup("Width"))
srcs//map_editor/setup_me.c:73:		|| !(ttf->fields[1].name = ft_strdup("Height"))
srcs//map_editor/setup_me.c:74:		|| !(ttf->fields[2].name = ft_strdup("Depth"))
srcs//map_editor/setup_me.c:75:		|| !(ttf->fields[3].name = ft_strdup("Name")))
srcs//map_editor/setup_me.c:76:		return (-1);
srcs//map_editor/setup_me.c:78:	if (init_dynarray(&ttf->fields[0].str, sizeof(char), 0)
srcs//map_editor/setup_me.c:79:		|| init_dynarray(&ttf->fields[1].str, sizeof(char), 0)
srcs//map_editor/setup_me.c:80:		|| init_dynarray(&ttf->fields[2].str, sizeof(char), 0)
srcs//map_editor/setup_me.c:81:		|| init_dynarray(&ttf->fields[3].str, sizeof(char), 0))
srcs//map_editor/setup_me.c:82:		return (-1);
srcs//map_editor/setup_me.c:92:	mlx = &env->mlx;
srcs//map_editor/setup_me.c:95:		if (load_texture(mlx, blocs_txt_paths(i), &env->edit_env.btxts[i], 1))
srcs//map_editor/setup_me.c:96:			return (-1);
srcs//map_editor/setup_me.c:104:	env->edit_env.env = env;
srcs//map_editor/setup_me.c:105:	env->edit_env.current_bt = BTXT_BRICK;
srcs//map_editor/setup_me.c:106:	env->edit_env.current_bc = BC_CUBE;
srcs//map_editor/setup_me.c:107:	env->edit_env.sub_context = MAPED_SC_MENU;
srcs//map_editor/setup_me.c:110:		|| init_cubes_pallet(env, &env->edit_env))
srcs//map_editor/setup_me.c:111:		return (-1);
srcs//map_editor/category_pallet.c:10:	draw_rectangle(env->mlx.img_data, top_o, top_dims, CG_COLOR);
srcs//map_editor/category_pallet.c:11:	if (index  == (unsigned int)env->edit_env.current_bc)
srcs//map_editor/category_pallet.c:14:		draw_rectangle(env->mlx.img_data, top_o, dims, 0x00aa00);
srcs//map_editor/category_pallet.c:24:	conf->size = 14;
srcs//map_editor/category_pallet.c:26:	ft_bzero(conf->s, MAX_STR_CHARS);
srcs//map_editor/category_pallet.c:27:	ft_memcpy(conf->s, str, ft_strlen(s));
srcs//map_editor/category_pallet.c:28:	my_string_put(env, env->mlx.img_data, o, FONT_ARIAL);
srcs//map_editor/category_pallet.c:29:	ft_bzero(conf->s, MAX_STR_CHARS);
srcs//map_editor/category_pallet.c:35:	draw_rectangle(env->mlx.img_data,
srcs//map_editor/category_pallet.c:36:			(t_point){o.x - 3, o.y}, (t_point){dims.x + 3, 3}, CG_COLOR);
srcs//map_editor/category_pallet.c:38:	o.y -= (dims.y * BC_MAX);
srcs//map_editor/category_pallet.c:40:	draw_rectangle(env->mlx.img_data, o, (t_point){dims.x, 3}, 0xffffff);
srcs//map_editor/category_pallet.c:42:	draw_rectangle(env->mlx.img_data, (t_point){o.x - 3, o.y}, v, CG_COLOR);
srcs//map_editor/category_pallet.c:44:	draw_rectangle(env->mlx.img_data,
srcs//map_editor/category_pallet.c:45:		(t_point){o.x + dims.x - 3, o.y}, v, CG_COLOR);
srcs//map_editor/category_pallet.c:65:		render_category(env, (t_point){o.x + 5, o.y + dims.y - 5}, strings[i]);
srcs//map_editor/load_shapes.c:7:		((t_triangle*)dyacc(&new->tris, 5))->face_i = FACE_NORD;
srcs//map_editor/load_shapes.c:8:		((t_triangle*)dyacc(&new->tris, 11))->face_i = FACE_NORD;
srcs//map_editor/load_shapes.c:9:		((t_triangle*)dyacc(&new->tris, 1))->face_i = FACE_SUD;
srcs//map_editor/load_shapes.c:10:		((t_triangle*)dyacc(&new->tris, 7))->face_i = FACE_SUD;
srcs//map_editor/load_shapes.c:11:		((t_triangle*)dyacc(&new->tris, 2))->face_i = FACE_BOTTOM;
srcs//map_editor/load_shapes.c:12:		((t_triangle*)dyacc(&new->tris, 8))->face_i = FACE_BOTTOM;
srcs//map_editor/load_shapes.c:13:		((t_triangle*)dyacc(&new->tris, 3))->face_i = FACE_OUEST;
srcs//map_editor/load_shapes.c:14:		((t_triangle*)dyacc(&new->tris, 9))->face_i = FACE_OUEST;
srcs//map_editor/load_shapes.c:15:		((t_triangle*)dyacc(&new->tris, 4))->face_i = FACE_UP;
srcs//map_editor/load_shapes.c:16:		((t_triangle*)dyacc(&new->tris, 10))->face_i = FACE_UP;
srcs//map_editor/load_shapes.c:17:		((t_triangle*)dyacc(&new->tris, 0))->face_i = FACE_EST;
srcs//map_editor/load_shapes.c:18:		((t_triangle*)dyacc(&new->tris, 6))->face_i = FACE_EST;
srcs//map_editor/load_shapes.c:22:		((t_triangle*)dyacc(&new->tris, 4))->face_i = SFACE_SLOPE;
srcs//map_editor/load_shapes.c:23:		((t_triangle*)dyacc(&new->tris, 7))->face_i = SFACE_SLOPE;
srcs//map_editor/load_shapes.c:24:		((t_triangle*)dyacc(&new->tris, 2))->face_i = SFACE_LEFT;
srcs//map_editor/load_shapes.c:25:		((t_triangle*)dyacc(&new->tris, 1))->face_i = SFACE_RIGHT;
srcs//map_editor/load_shapes.c:26:		((t_triangle*)dyacc(&new->tris, 3))->face_i = SFACE_BOTTOM;
srcs//map_editor/load_shapes.c:27:		((t_triangle*)dyacc(&new->tris, 0))->face_i = SFACE_FRONT;
srcs//map_editor/load_shapes.c:28:		((t_triangle*)dyacc(&new->tris, 5))->face_i = SFACE_FRONT;
srcs//map_editor/load_shapes.c:29:		((t_triangle*)dyacc(&new->tris, 6))->face_i = SFACE_BOTTOM;
srcs//map_editor/load_shapes.c:40:	new->type = get_block_type(env, new, type);
srcs//map_editor/load_shapes.c:41:	mesh = dyacc(&env->maps[SCENE_CUBE].meshs, 0);
srcs//map_editor/load_shapes.c:42:	if (init_dynarray(&new->tris, sizeof(t_triangle), 0))
srcs//map_editor/load_shapes.c:43:		return (-1);
srcs//map_editor/load_shapes.c:44:	while (i < mesh->tris.nb_cells)
srcs//map_editor/load_shapes.c:46:		ft_memcpy(&t, dyacc(&mesh->tris, i), sizeof(t_triangle));
srcs//map_editor/load_shapes.c:50:		t.sp = new->type;
srcs//map_editor/load_shapes.c:51:		if (push_dynarray(&new->tris, &t, false))
srcs//map_editor/load_shapes.c:52:			return (-1);
srcs//map_editor/load_shapes.c:81:		return (-1);
srcs//map_editor/load_shapes.c:82:	new->type = get_block_type(env, new, type);
srcs//map_editor/load_shapes.c:83:	mesh = dyacc(&env->maps[obj].meshs, 0);
srcs//map_editor/load_shapes.c:84:	if (init_dynarray(&new->tris, sizeof(t_triangle), 0))
srcs//map_editor/load_shapes.c:85:		return (-1);
srcs//map_editor/load_shapes.c:86:	while (i < mesh->tris.nb_cells)
srcs//map_editor/load_shapes.c:88:		ft_memcpy(&t, dyacc(&mesh->tris, i), sizeof(t_triangle));
srcs//map_editor/load_shapes.c:92:		t.sp = new->type;
srcs//map_editor/load_shapes.c:93:		if (push_dynarray(&new->tris, &t, false))
srcs//map_editor/load_shapes.c:94:			return (-1);
srcs//map_editor/pallet.c:5:	p[BTXT_BRICK - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:6:	p[BTXT_DARK_BRICK - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:7:	p[BTXT_CLEAN_STONE - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:8:	p[BTXT_DIRT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:9:	p[BTXT_DIRT_GRASS - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:10:	p[BTXT_DIRT_SNOW - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:11:	p[BTXT_ICE - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:12:	p[BTXT_GOLD - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:13:	p[BTXT_IRON - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:14:	p[BTXT_LIGHT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:15:	p[BTXT_OBSIDIENNE - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:16:	p[BTXT_SAND - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:17:	p[BTXT_STONE - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:18:	p[BTXT_WOOD_A - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:19:	p[BTXT_WOOD_A_CUT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:20:	p[BTXT_WOOD_B - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:21:	p[BTXT_WOOD_B_CUT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:22:	p[BTXT_WOOD_C - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:23:	p[BTXT_WOOD_C_CUT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:24:	p[BTXT_WOOD_D - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:25:	p[BTXT_WOOD_D_CUT - 1] = (t_cube_pallet){.cube = 1, .slope = 1, .obj = 0};
srcs//map_editor/pallet.c:26:	p[BTXT_JUKEBOX - 1] = (t_cube_pallet){.cube = 0, .slope = 0, .obj = 1};
srcs//map_editor/pallet.c:27:	p[BTXT_MYSTERY_BOX - 1] = (t_cube_pallet){.cube = 0, .slope = 0, .obj = 1};
srcs//map_editor/pallet.c:28:	p[BTXT_DOOR - 1] = (t_cube_pallet){.cube = 0, .slope = 0, .obj = 1};
srcs//map_editor/pallet.c:29:	p[BTXT_LAVA - 1] = (t_cube_pallet){.cube = 0, .slope = 0, .obj = 1};
srcs//map_editor/pallet.c:30:	p[BTXT_SPAWNER - 1] = (t_cube_pallet){.cube = 0, .slope = 0, .obj = 1};
srcs//map_editor/pallet.c:31:	p[BTXT_MOB_SPAWNER - 1] = (t_cube_pallet){.cube = 0, .slope = 0, .obj = 1};
srcs//map_editor/pallet.c:32:	//pallet[BTXT_ - 1] = (t_cube_pallet){.cube = , .slope = , .obj = };
srcs//map_editor/pallet.c:63:	if (!(nb_icones = count_icones(env->edit_env.pallet, bc)))
srcs//map_editor/pallet.c:66:	o = (t_point){env->data.half_wdt - (offset / 2), 600}; // bbox origin
srcs//map_editor/pallet.c:71:	draw_rectangle(env->mlx.img_data, o, dims, 0xffffff); // top
srcs//map_editor/pallet.c:73:	draw_rectangle(env->mlx.img_data, o, s_dims, 0xffffff); // sides
srcs//map_editor/pallet.c:75:	draw_rectangle(env->mlx.img_data, o, s_dims, 0xffffff);
srcs//map_editor/pallet.c:76:	o.x -= offset;
srcs//map_editor/pallet.c:79:	draw_rectangle(env->mlx.img_data, o, dims, 0xffffff); // bottom
srcs//map_editor/pallet.c:87:	bc = env->edit_env.current_bc;
srcs//map_editor/pallet.c:89:	render_pallet(env, env->edit_env.pallet, o, bc);
srcs//map_editor/pallet.c:99:	set_renderable(edit_env->pallet);
srcs//map_editor/pallet.c:100:	while (i < BTXT_MAX - 1)
srcs//map_editor/pallet.c:104:		if (load_texture(&env->mlx, path,
srcs//map_editor/pallet.c:105:				&edit_env->pallet[i].sprite, false))
srcs//map_editor/pallet.c:106:			return (-1);
Binary file srcs//map_editor/render.o matches
srcs//map_editor/input_field.c:8:									'-', '8', '0', 0, 'o', 'u', 0, 'i', 'p', 0,
srcs//map_editor/input_field.c:27:				return (-1);
srcs//map_editor/input_field.c:44:		return (-1);
srcs//map_editor/input_field.c:47:		tmp = &ttfs->fields[i];
srcs//map_editor/input_field.c:48:		if (ttfs->fields[i].rendered)
srcs//map_editor/input_field.c:50:				return (-1);
srcs//map_editor/input_field.c:65:	conf->size = 20;
srcs//map_editor/input_field.c:67:	ft_memset(conf->s, 0, sizeof(char) * MAX_STR_CHARS);
srcs//map_editor/input_field.c:68:	ft_strcpy((char*)conf->s, box->name);
srcs//map_editor/input_field.c:69:	name_pos = (t_point){box->o.x + 50, box->o.y};
srcs//map_editor/input_field.c:70:	my_string_put(env, env->mlx.img_data, name_pos, FONT_ARIAL);
srcs//map_editor/input_field.c:72:	box->b_o = (t_point){box->o.x, box->o.y + conf->size};
srcs//map_editor/input_field.c:73:	draw_rectangle(env->mlx.img_data, box->b_o, TEXT_BOX_DIMS, TEXT_BOX_COLOR);
srcs//map_editor/input_field.c:74:	ft_memset(conf->s, 0, sizeof(char) * MAX_STR_CHARS);
srcs//map_editor/input_field.c:76:	s = (unsigned char *)box->str.c;
srcs//map_editor/input_field.c:77:	s[box->str.nb_cells] = 0;
srcs//map_editor/input_field.c:78:	ft_strcpy((char*)conf->s, box->str.c);
srcs//map_editor/input_field.c:79:	my_string_put(env, env->mlx.img_data, (t_point){box->b_o.x, box->b_o.y + conf->size}, FONT_ARIAL);
srcs//map_editor/input_field.c:80:	ft_memset(conf->s, 0, sizeof(char) * MAX_STR_CHARS);
srcs//map_editor/input_field.c:90:	while (i < boxs->nb_cells)
srcs//map_editor/input_field.c:94:		if (box->in)
srcs//map_editor/input_field.c:109:	mp = env->events.mouse_pos;
srcs//map_editor/input_field.c:110:	while (i < boxs->nb_cells)
srcs//map_editor/input_field.c:114:		if (ft_inbounds(mp.x, box->b_o.x, box->b_o.x + (TEXT_BOX_DIMS).x)
srcs//map_editor/input_field.c:115:			&& ft_inbounds(mp.y, box->b_o.y, box->b_o.y + (TEXT_BOX_DIMS).y))
srcs//map_editor/input_field.c:116:			box->in = true;
srcs//map_editor/input_field.c:118:			box->in = false;
srcs//map_editor/input_field.c:128:	if (env->events.keys[KEY_BACKSPACE] && del)
srcs//map_editor/input_field.c:131:		return (pop_dynarray(&box->str, false));
srcs//map_editor/input_field.c:133:	if (!env->events.keys[KEY_BACKSPACE])
srcs//map_editor/input_field.c:135:	if (ft_strlen((char*)box->str.c) >= 12)
srcs//map_editor/input_field.c:137:	if (add_char(&box->str, env->events.keys))
srcs//map_editor/input_field.c:138:		return (-1);
srcs//map_editor/input_field.c:139:	c_o = (t_point){box->b_o.x + (box->str.nb_cells * 17) + 3, box->b_o.y + 2};
srcs//map_editor/input_field.c:140:	draw_rectangle(env->mlx.img_data, c_o, (t_point){1, 26}, CURSOR_COLOR);
srcs//map_editor/input_field.c:152:	if ((refresh || first) && get_boxs(&env->ttfs, &boxs))
srcs//map_editor/input_field.c:153:		return (-1);
srcs//map_editor/input_field.c:165:	if (env->events.buttons[BUTTON_LCLIC])
Binary file srcs//map_editor/crosshair.o matches
srcs//play_sound.c:41:		alSourcei(source, AL_BUFFER, (ALint)sample->buffer);
Binary file srcs//setup.o matches
Binary file srcs//contexts/routines.o matches
Binary file srcs//contexts/routines_bis.o matches
Binary file srcs//contexts/switch_context.o matches
srcs//contexts/routines.c:19://	play_ambience(env->sound.samples[SA_TITLE_SCREEN_S], false, true, false);
srcs//contexts/routines.c:20://	loop_sample(env->sound.samples[SA_TITLE_SCREEN_L], false, true, false);
srcs//contexts/routines.c:25:	env->cmp_env.sub_context = CMP_SC_MENU;
srcs//contexts/routines.c:32:	env->scroll.o = (t_point){25, 100};
srcs//contexts/routines.c:33:	env->scroll.d = (t_point){350, 500};
srcs//contexts/switch_context.c:68:	if (i >= C_MAX || !gates[env->context][i])
srcs//contexts/switch_context.c:71:		return (-1);
srcs//contexts/switch_context.c:73:	if (routines[env->context][i])
srcs//contexts/switch_context.c:74:		routines[env->context][i](env);
srcs//contexts/switch_context.c:75:	env->context = i;
Binary file srcs//dev_events.o matches
Binary file srcs//text.o matches
Binary file srcs//archive/archive.o matches
srcs//archive/archive_tools.c:25:	return (-1);
srcs//archive/unarchive.c:21:	while ((size_t)(tmp - path) < ft_strlen(path))
srcs//archive/unarchive.c:25:			if (!(subPath = ft_strsub(path, 0, tmp - path)))
srcs//archive/unarchive.c:26:				return (-1);
srcs//archive/unarchive.c:62:		len -= tmp - archi;
srcs//archive/unarchive.c:65:			return (-1);
srcs//archive/unarchive.c:67:		if (createFolders(archi) == -1)
srcs//archive/unarchive.c:68:			return (-1);
srcs//archive/unarchive.c:70:			return (-1);
srcs//archive/unarchive.c:71:		len -= (tmp - archi) + 1;
srcs//archive/unarchive.c:74:		write(fd_file, archi, !tmp ? len - 1 : tmp - archi - 1);
srcs//archive/unarchive.c:89:		return(-1);
srcs//archive/archive.c:26:		return (-1);
srcs//archive/archive.c:47:		return (-1);
srcs//archive/archive.c:50:		if (!(path = ft_strnew(ft_strlen(dir_path) + dirent->d_namlen + 2)))
srcs//archive/archive.c:54:		ft_strcat(path, dirent->d_name);
srcs//archive/archive.c:55:		if ((dirent->d_type == DT_REG) && (*dirent->d_name == '.'))
srcs//archive/archive.c:57:		else if (dirent->d_type == DT_REG && concatFiles(path, fd_archi))
srcs//archive/archive.c:59:		else if (dirent->d_type == DT_DIR && (*dirent->d_name != '.'))
srcs//archive/archive.c:67:	return (errno == 0 ? 0 : -1);
srcs//archive/archive.c:77:		return(-1);
srcs//archive/archive.c:82:		return (-1);
Binary file srcs//archive/archive_tools.o matches
Binary file srcs//archive/unarchive.o matches
Binary file srcs//obj_parser/dependencies.o matches
srcs//obj_parser/tools.c:19:	if (line[j] == '-' || line[j] == '+')
srcs//obj_parser/tools.c:33:	if (tok[0] != start_sep || tok[ft_strlen(tok) - 1] != end_sep)
srcs//obj_parser/tools.c:54:	if (tok[0] != start_sep || tok[ft_strlen(tok) - 1] != end_sep)
Binary file srcs//obj_parser/check_formats.o matches
srcs//obj_parser/mapper_fts.c:13:	while (i < m->tris.nb_cells)
srcs//obj_parser/mapper_fts.c:15:		t = dyacc(&m->tris, i);
srcs//obj_parser/mapper_fts.c:16:		t->sp = -1;
srcs//obj_parser/mapper_fts.c:22:		while (i < m->tris.nb_cells)
srcs//obj_parser/mapper_fts.c:24:			t = dyacc(&m->tris, i);
srcs//obj_parser/mapper_fts.c:25:			if (t->textured)
srcs//obj_parser/mapper_fts.c:26:				t->color = 0xff007f;
srcs//obj_parser/mapper_fts.c:31:	if (tok[0] != '(' || tok[ft_strlen(tok) - 1] != ')')
srcs//obj_parser/mapper_fts.c:34:		return (-1);
srcs//obj_parser/mapper_fts.c:36:	if (!(path = ft_strndup(&tok[1], ft_strlen(&tok[1]) - 1)))
srcs//obj_parser/mapper_fts.c:37:		return (-1);
srcs//obj_parser/mapper_fts.c:38:	if (load_texture(&env->mlx, path, &sprite, true))
srcs//obj_parser/mapper_fts.c:39:		return (-1);
srcs//obj_parser/mapper_fts.c:41:	if ((!map->txts.byte_size && init_dynarray(&map->txts, sizeof(t_sprite), 0))
srcs//obj_parser/mapper_fts.c:42:		|| push_dynarray(&map->txts, &sprite, false))
srcs//obj_parser/mapper_fts.c:43:		return (-1);
srcs//obj_parser/mapper_fts.c:45:	while (i < m->tris.nb_cells)
srcs//obj_parser/mapper_fts.c:47:		t = dyacc(&m->tris, i);
srcs//obj_parser/mapper_fts.c:48:		if (t->textured)
srcs//obj_parser/mapper_fts.c:49:			t->sp = t->textured ? map->txts.nb_cells - 1 : -1;
srcs//obj_parser/mapper_fts.c:69:		return (-1);
srcs//obj_parser/mapper_fts.c:87:		return (-1);
srcs//obj_parser/mapper_fts.c:89:	m->corp.v = speed;
srcs//obj_parser/mapper_fts.c:100:		return (-1);
srcs//obj_parser/mapper_fts.c:102:		map->stats[m->index] = false;
srcs//obj_parser/mapper_fts.c:104:		map->stats[m->index] = true;
srcs//obj_parser/mapper_fts.c:108:		return (-1);
srcs//obj_parser/mapper_fts.c:110:	map->stats_cpy[m->index]= map->stats[m->index];
srcs//obj_parser/mapper_fts.c:121:	i = -1;
srcs//obj_parser/mapper_fts.c:125:	while (++i < map->meshs.nb_cells)
srcs//obj_parser/mapper_fts.c:127:		master = dyacc(&map->meshs, i);
srcs//obj_parser/mapper_fts.c:128:		if (!ft_strcmp(master->name, tok))
srcs//obj_parser/mapper_fts.c:131:	if (i == map->meshs.nb_cells || (!master->deps.byte_size
srcs//obj_parser/mapper_fts.c:132:		&& init_dynarray(&master->deps, sizeof(int), 0)))
srcs//obj_parser/mapper_fts.c:135:		return (-1);
srcs//obj_parser/mapper_fts.c:137:	if (push_dynarray(&master->deps, &m->index, false))
srcs//obj_parser/mapper_fts.c:138:		return (-1);
srcs//obj_parser/parse_map.c:27:			p->tstate = (char)i;
srcs//obj_parser/parse_map.c:28:			if (!states[(int)p->state][(int)p->tstate])
srcs//obj_parser/parse_map.c:29:				return (-1);
srcs//obj_parser/parse_map.c:30:			p->state = p->tstate;
srcs//obj_parser/parse_map.c:46:	if (!(p->toks = ft_strsplit(p->lines[i], "\n\t\r "))
srcs//obj_parser/parse_map.c:47:		|| get_line_type(p->toks[0], p, states))
srcs//obj_parser/parse_map.c:50:		return (-1);
srcs//obj_parser/parse_map.c:52:	if (p->state == PS_COMMENT)
srcs//obj_parser/parse_map.c:54:		ft_free_ctab(p->toks);
srcs//obj_parser/parse_map.c:57:	if (!(*init_parser()) && lines_fts[(int)p->state](map, p->toks))
srcs//obj_parser/parse_map.c:58:		return (-1);
srcs//obj_parser/parse_map.c:59:	ft_free_ctab(p->toks);
srcs//obj_parser/parse_map.c:67:	ft_memcpy(&new->points[0], dyacc(&map->pool, f->x - 1), sizeof(t_vec3d));
srcs//obj_parser/parse_map.c:68:	ft_memcpy(&new->points[1], dyacc(&map->pool, f->y - 1), sizeof(t_vec3d));
srcs//obj_parser/parse_map.c:69:	ft_memcpy(&new->points[2], dyacc(&map->pool, f->z - 1), sizeof(t_vec3d));
srcs//obj_parser/parse_map.c:70:	new->points[0].w = 1.0f;
srcs//obj_parser/parse_map.c:71:	new->points[1].w = 1.0f;
srcs//obj_parser/parse_map.c:72:	new->points[2].w = 1.0f;
srcs//obj_parser/parse_map.c:74:	if (f->textured)
srcs//obj_parser/parse_map.c:76:		t = dyacc(&map->txt_pool, f->tx - 1);
srcs//obj_parser/parse_map.c:77:		new->txt[0].u = t->u;
srcs//obj_parser/parse_map.c:78:		new->txt[0].v = t->v;
srcs//obj_parser/parse_map.c:79:		new->txt[0].w = 1.0f;
srcs//obj_parser/parse_map.c:81:		t = dyacc(&map->txt_pool, f->ty - 1);
srcs//obj_parser/parse_map.c:82:		new->txt[1].u = t->u;
srcs//obj_parser/parse_map.c:83:		new->txt[1].v = t->v;
srcs//obj_parser/parse_map.c:84:		new->txt[1].w = 1.0f;
srcs//obj_parser/parse_map.c:86:		t = dyacc(&map->txt_pool, f->tz - 1);
srcs//obj_parser/parse_map.c:87:		new->txt[2].u = t->u;
srcs//obj_parser/parse_map.c:88:		new->txt[2].v = t->v;
srcs//obj_parser/parse_map.c:89:		new->txt[2].w = 1.0f;
srcs//obj_parser/parse_map.c:91:		new->mesh = m;
srcs//obj_parser/parse_map.c:92:		new->textured = true;
srcs//obj_parser/parse_map.c:96:		new->textured = false;
srcs//obj_parser/parse_map.c:97:		if (map->mtls.nb_cells > 0)
srcs//obj_parser/parse_map.c:98:			new->color = f->color;
srcs//obj_parser/parse_map.c:100:			new->color = 0xffffff;
srcs//obj_parser/parse_map.c:112:	i = -1;
srcs//obj_parser/parse_map.c:113:	while (++i < map->nmesh)
srcs//obj_parser/parse_map.c:115:		j = -1;
srcs//obj_parser/parse_map.c:116:		if (!(m = dyacc(&map->meshs, i))
srcs//obj_parser/parse_map.c:117:			|| (init_dynarray(&m->tris, sizeof(t_triangle), m->faces.nb_cells)))
srcs//obj_parser/parse_map.c:118:			return (-1);
srcs//obj_parser/parse_map.c:119:		m->type = 1;
srcs//obj_parser/parse_map.c:120:		while (++j < m->faces.nb_cells)
srcs//obj_parser/parse_map.c:122:			if (!(f = dyacc(&m->faces, j)) || (f->x - 1 >= map->pool.nb_cells
srcs//obj_parser/parse_map.c:123:				|| f->y - 1 >= map->pool.nb_cells || f->z - 1 >= map->pool.nb_cells))
srcs//obj_parser/parse_map.c:124:				return (-1);
srcs//obj_parser/parse_map.c:129:			if (push_dynarray(&m->tris, &new, false))
srcs//obj_parser/parse_map.c:130:				return (-1);
srcs//obj_parser/parse_map.c:132:		free_dynarray(&m->faces);
srcs//obj_parser/parse_map.c:133:		//printf("mesh [%d] : %d triangles\n", i, m->tris.nb_cells);
srcs//obj_parser/parse_map.c:145:	map->nmesh = 0;
srcs//obj_parser/parse_map.c:146:	if ((fd = open(path, O_RDONLY)) == -1
srcs//obj_parser/parse_map.c:147:		|| !(parser->file = read_file(fd, &len)) || len == 0
srcs//obj_parser/parse_map.c:148:		|| !(parser->lines = ft_strsplit(parser->file, "\n"))
srcs//obj_parser/parse_map.c:149:		|| init_dynarray(&map->pool, sizeof(t_vec3d), 0)
srcs//obj_parser/parse_map.c:150:		|| init_dynarray(&map->txt_pool, sizeof(t_vec2d), 0)
srcs//obj_parser/parse_map.c:151:		|| init_dynarray(&map->meshs, sizeof(t_mesh), 0))
srcs//obj_parser/parse_map.c:152:		return (-1);
srcs//obj_parser/parse_map.c:153:	parser->state = PS_COMMENT;
srcs//obj_parser/parse_map.c:154:	while (parser->lines[i] && parser->state == PS_COMMENT)
srcs//obj_parser/parse_map.c:157:			return (-1);
srcs//obj_parser/parse_map.c:160:	if (!parser->lines[i]
srcs//obj_parser/parse_map.c:161:		|| (parser->state != PS_OBJ && parser->state != PS_MTLLIB))
srcs//obj_parser/parse_map.c:162:		return (-1);
srcs//obj_parser/parse_map.c:175:		return (-1);
srcs//obj_parser/parse_map.c:187:			return (-1);
srcs//obj_parser/parse_map.c:192:		|| !(map->stats = (bool*)malloc(sizeof(bool) * map->nmesh))
srcs//obj_parser/parse_map.c:193:		|| !(map->stats_cpy = (bool*)malloc(sizeof(bool) * map->nmesh)))
srcs//obj_parser/parse_map.c:194:		return (-1);
srcs//obj_parser/parse_map.c:195:	free_dynarray(&map->pool);
srcs//obj_parser/parse_map.c:196:	free_dynarray(&map->txt_pool);
srcs//obj_parser/mapper_values.c:10:		return (-1);
srcs//obj_parser/mapper_values.c:16:		return (-1);
srcs//obj_parser/mapper_values.c:18:	map->spawn = pos;
srcs//obj_parser/mapper_values.c:29:		return (-1);
srcs//obj_parser/mapper_values.c:35:		return (-1);
srcs//obj_parser/mapper_values.c:37:	map->cam_dir = dir;
srcs//obj_parser/mapper_values.c:52:			return (-1);
srcs//obj_parser/mtl_lines_fts.c:11:		return (-1);
srcs//obj_parser/mtl_lines_fts.c:18:				return (-1);
srcs//obj_parser/mtl_lines_fts.c:25:		return (-1);
srcs//obj_parser/mtl_lines_fts.c:36:	if (!(cm = dyacc(mtls, mtls->nb_cells - 1)) || ft_tablen(toks) != 4)
srcs//obj_parser/mtl_lines_fts.c:37:		return (-1);
srcs//obj_parser/mtl_lines_fts.c:38:	ft_memset(&cm->color, 0, sizeof(int));
srcs//obj_parser/mtl_lines_fts.c:42:			return (-1);
srcs//obj_parser/mtl_lines_fts.c:45:			return (-1);
srcs//obj_parser/mtl_lines_fts.c:46:		cm->color[i - 1] = (t * 255);
srcs//obj_parser/mtl_lines_fts.c:49:	swap_bytes(&cm->color[0], &cm->color[2]);
srcs//obj_parser/mtl_lines_fts.c:57:	if (!(cm = dyacc(mtls, mtls->nb_cells - 1)) || ft_tablen(toks) != 2)
srcs//obj_parser/mtl_lines_fts.c:58:		return (-1);
srcs//obj_parser/mtl_lines_fts.c:59:	if ((cm->alpha = ft_atof(toks[1])) < 0.0 || cm->alpha > 1.0f)
srcs//obj_parser/mtl_lines_fts.c:60:		return (-1);
srcs//obj_parser/mtl_lines_fts.c:70:	i = -1;
srcs//obj_parser/mtl_lines_fts.c:73:		j = -1;
srcs//obj_parser/mtl_lines_fts.c:76:				return (-1);
srcs//obj_parser/mtl_lines_fts.c:78:	if (!(cm = dyacc(mtls, mtls->nb_cells - 1)))
srcs//obj_parser/mtl_lines_fts.c:79:		return (-1);
srcs//obj_parser/mtl_lines_fts.c:80:	cm->textured = true;
Binary file srcs//obj_parser/load_face.o matches
Binary file srcs//obj_parser/parse_mtl.o matches
Binary file srcs//obj_parser/mapper.o matches
srcs//obj_parser/init_maps_features.c:13:		while (j < env->maps[i].meshs.nb_cells)
srcs//obj_parser/init_maps_features.c:15:			m = dyacc(&env->maps[i].meshs, j);
Binary file srcs//obj_parser/lines_fts.o matches
Binary file srcs//obj_parser/load_maps.o matches
Binary file srcs//obj_parser/tools.o matches
srcs//obj_parser/dependencies.c:9:	while (i < m->deps.nb_cells)
srcs//obj_parser/dependencies.c:11:		dep = *(int*)dyacc(&m->deps, i);
srcs//obj_parser/dependencies.c:12:		if (master->index == dep || seek_cycle(meshs, dyacc(meshs, dep), master))
srcs//obj_parser/dependencies.c:13:			return (-1);
srcs//obj_parser/dependencies.c:25:	while (i < meshs->nb_cells)
srcs//obj_parser/dependencies.c:30:			ft_putendl_fd(m->name, 2);
srcs//obj_parser/dependencies.c:31:			return (-1);
Binary file srcs//obj_parser/states.o matches
srcs//obj_parser/parse_mtl.c:22:		return (-1);
srcs//obj_parser/parse_mtl.c:23:	if (ft_strcmp(&file_name[size - 4], ".mtl"))
srcs//obj_parser/parse_mtl.c:24:		return (-1);
srcs//obj_parser/parse_mtl.c:41:		j = -1;
srcs//obj_parser/parse_mtl.c:66:			return (-1);
srcs//obj_parser/parse_mtl.c:82:			return (-1);
srcs//obj_parser/parse_mtl.c:86:				return (-1);
srcs//obj_parser/parse_mtl.c:102:	if ((fd = open_mtl_file(file_name)) == -1 || !(file = read_file(fd, &len))
srcs//obj_parser/parse_mtl.c:104:		return (-1);
srcs//obj_parser/parse_mtl.c:111:		return (-1);
Binary file srcs//obj_parser/mtl_lines_fts.o matches
srcs//obj_parser/load_face.c:56:		if (toks[i][j - 1] == '/') // __ dernier
srcs//obj_parser/load_face.c:68:	face->x = ft_atoi(toks[1]);
srcs//obj_parser/load_face.c:69:	if (face->textured)
srcs//obj_parser/load_face.c:72:		face->tx = ft_atoi(&toks[1][offset]);
srcs//obj_parser/load_face.c:74:	face->y = ft_atoi(toks[2]);
srcs//obj_parser/load_face.c:75:	if (face->textured)
srcs//obj_parser/load_face.c:78:		face->ty = ft_atoi(&toks[2][offset]);
srcs//obj_parser/load_face.c:80:	face->z = ft_atoi(toks[3]);
srcs//obj_parser/load_face.c:81:	if (face->textured)
srcs//obj_parser/load_face.c:84:		face->tz = ft_atoi(&toks[3][offset]);
srcs//obj_parser/load_face.c:95:		return (-1);
srcs//obj_parser/load_face.c:97:	if (!(m = dyacc(&map->meshs, map->nmesh - 1)))
srcs//obj_parser/load_face.c:98:		return (-1);
srcs//obj_parser/check_formats.c:13:		if ((tok[i] == '-' || tok[i] == '+') && i > 0)
srcs//obj_parser/check_formats.c:20:		else if (!ft_isdigit(tok[i]) && tok[i] != '-' && tok[i] != '+')
srcs//obj_parser/check_formats.c:24:	if (dots > 1 || last_dot >= i - 1)
Binary file srcs//obj_parser/parse_map.o matches
Binary file srcs//obj_parser/mapper_fts.o matches
Binary file srcs//obj_parser/mapper_values.o matches
srcs//obj_parser/load_maps.c:15:		if (parse_map(&env->maps[i], maps_paths(i), states) != 0)
srcs//obj_parser/load_maps.c:18:			return (-1);
srcs//obj_parser/load_maps.c:20:		*current_map() = &env->maps[i];
srcs//obj_parser/load_maps.c:21:		if (load_map_config(env, &env->maps[i], maps_paths(i)))
srcs//obj_parser/load_maps.c:22:			return (-1);
srcs//obj_parser/load_maps.c:23:		//printf("%s (%d meshs)\n", maps_paths(i), env->maps[i].nmesh);
srcs//obj_parser/load_maps.c:24:/*		for (int j = 0; j < env->maps[i].nmesh; j++)
srcs//obj_parser/load_maps.c:26:			m = dyacc(&env->maps[i].meshs, j);
srcs//obj_parser/load_maps.c:27:			printf("%s : %d triangles\n", m->name, m->tris.nb_cells);
srcs//obj_parser/load_maps.c:29:		ft_putchar(i == SCENE_MAX - 1 ? '\0' : '\r');
srcs//obj_parser/load_maps.c:30:		env->maps[i].index = i;
srcs//obj_parser/lines_fts.c:8:	map->cmtl = -1;
srcs//obj_parser/lines_fts.c:10:		return (-1);
srcs//obj_parser/lines_fts.c:11:	if (push_dynarray(&map->meshs, &zone[0], false)
srcs//obj_parser/lines_fts.c:12:		|| !(m = dyacc(&map->meshs, map->nmesh))
srcs//obj_parser/lines_fts.c:13:		|| !(m->name = ft_strdup(toks[1]))
srcs//obj_parser/lines_fts.c:14:		|| init_dynarray(&m->faces, sizeof(t_face), 0))
srcs//obj_parser/lines_fts.c:15:		return (-1);
srcs//obj_parser/lines_fts.c:16:	m->index = map->nmesh;
srcs//obj_parser/lines_fts.c:17:	map->nmesh++;
srcs//obj_parser/lines_fts.c:28:		return (-1);
srcs//obj_parser/lines_fts.c:32:	if (push_dynarray(&map->pool, &new, false))
srcs//obj_parser/lines_fts.c:33:		return (-1);
srcs//obj_parser/lines_fts.c:42:	if (!(m = dyacc(&map->meshs, map->nmesh - 1)) || ft_tablen(toks) != 3
srcs//obj_parser/lines_fts.c:44:		return (-1);
srcs//obj_parser/lines_fts.c:45:	m->textured = true;
srcs//obj_parser/lines_fts.c:48:	if (push_dynarray(&map->txt_pool, &txt_coor, false))
srcs//obj_parser/lines_fts.c:49:		return (-1);
srcs//obj_parser/lines_fts.c:61:		return (-1);
srcs//obj_parser/lines_fts.c:62:	if (map->cmtl >= 0)
srcs//obj_parser/lines_fts.c:64:		if (!(mtl = dyacc(&map->mtls, map->cmtl)))
srcs//obj_parser/lines_fts.c:65:			return (-1);
srcs//obj_parser/lines_fts.c:66:		mtl->color[3] = (1.0f - mtl->alpha) * 255;
srcs//obj_parser/lines_fts.c:67:		face.color = *(int*)&mtl->color[0];
srcs//obj_parser/lines_fts.c:68:		face.textured = mtl->textured;
srcs//obj_parser/lines_fts.c:71:		return (-1);
srcs//obj_parser/lines_fts.c:72:	if (!(m = dyacc(&map->meshs, map->nmesh - 1))
srcs//obj_parser/lines_fts.c:73:		|| push_dynarray(&m->faces, &face, false))
srcs//obj_parser/lines_fts.c:74:		return (-1);
srcs//obj_parser/lines_fts.c:99:	if (ft_tablen(toks) != 2 || (map->mtls.byte_size == 0
srcs//obj_parser/lines_fts.c:100:		&& init_dynarray(&map->mtls, sizeof(t_mtl), 0)))
srcs//obj_parser/lines_fts.c:101:		return (-1);
srcs//obj_parser/lines_fts.c:102:	if (parse_mtl(toks[1], &map->mtls))
srcs//obj_parser/lines_fts.c:103:		return (-1);
srcs//obj_parser/lines_fts.c:114:		return (-1);
srcs//obj_parser/lines_fts.c:115:	while (i < map->mtls.nb_cells)
srcs//obj_parser/lines_fts.c:117:		if ((m = dyacc(&map->mtls, i)) && !ft_strcmp(toks[1], m->name))
srcs//obj_parser/lines_fts.c:119:			map->cmtl = i;
srcs//obj_parser/lines_fts.c:124:	map->cmtl = -1;
srcs//obj_parser/lines_fts.c:125:	return (-1);
srcs//obj_parser/mapper.c:12:		return (-1);
srcs//obj_parser/mapper.c:18:		return (-1);
srcs//obj_parser/mapper.c:21:		return (-1);
srcs//obj_parser/mapper.c:22:	if ((fd = open(new_path, O_RDONLY)) == -1)
srcs//obj_parser/mapper.c:25:		return (-1);
srcs//obj_parser/mapper.c:53:		return (-1);
srcs//obj_parser/mapper.c:57:		return (-1);
srcs//obj_parser/mapper.c:90:	while (i < map->nmesh)
srcs//obj_parser/mapper.c:92:		m = dyacc(&map->meshs, i);
srcs//obj_parser/mapper.c:93:		if (!ft_strcmp(m->name, line[0]))
srcs//obj_parser/mapper.c:113:	if ((fd = open_mapconf(map_path)) == -1 || !(lines = get_file_lines(fd)))
srcs//obj_parser/mapper.c:120:			return (-1);
srcs//obj_parser/mapper.c:123:	if (check_deps_cycle(&map->meshs))
srcs//obj_parser/mapper.c:124:		return (-1);
Binary file srcs//custom_mode/play.o matches
Binary file srcs//custom_mode/setup.o matches
srcs//custom_mode/menu.c:7:	s = &env->scroll;
srcs//custom_mode/menu.c:9:	if (s->s_path)
srcs//custom_mode/menu.c:11:		if (import_maped_map(&env->edit_env, s->s_path))
srcs//custom_mode/menu.c:13:			printf("Parsing Failed for map |%s|\n", s->s_path);
srcs//custom_mode/menu.c:15:			return (-1);
srcs//custom_mode/menu.c:18:			return (-1);
srcs//custom_mode/menu.c:21:	ft_strdel(&s->s_path);
srcs//custom_mode/menu.c:30:	i = -1;
srcs//custom_mode/menu.c:32:		if (is_on_button(env->events.mouse_pos, env->edit_env.buttons[i]))
srcs//custom_mode/menu.c:34:			if (!env->events.buttons[BUTTON_LCLIC] && clic)
srcs//custom_mode/menu.c:41:			clic = env->events.buttons[BUTTON_LCLIC];
srcs//custom_mode/menu.c:42:			env->edit_env.buttons[i].is_hover = true;
srcs//custom_mode/menu.c:45:			env->edit_env.buttons[i].is_hover = false;
srcs//custom_mode/menu.c:52:	map_sprite(env->mlx.img_data, env->sprites[SP_CUSTOM_BACKGROUND], (t_point){0, 0});
srcs//custom_mode/menu.c:53:	render_button(env, env->edit_env.buttons[MAPED_MENU_BUTTON_MAIN_MENU]);
srcs//custom_mode/menu.c:55:		return (-1);
srcs//custom_mode/menu.c:56:	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
Binary file srcs//custom_mode/events_blocks.o matches
Binary file srcs//custom_mode/routines.o matches
Binary file srcs//custom_mode/events.o matches
Binary file srcs//custom_mode/player.o matches
srcs//custom_mode/events_blocks_funcs.c:8:	e = &env->events;
srcs//custom_mode/events_blocks_funcs.c:9:	if (block->id != BE_JUKEBOX)
srcs//custom_mode/events_blocks_funcs.c:11:	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) > EVENT_DIST)
srcs//custom_mode/events_blocks_funcs.c:13:		track = &block->param.c;
srcs//custom_mode/events_blocks_funcs.c:17:		if (e->keys[KEY_F])
srcs//custom_mode/events_blocks_funcs.c:18:			*track = *track >= 0 ? -1 : 0; // on / off
srcs//custom_mode/events_blocks_funcs.c:19:		else if (e->keys[KEY_LEFT])
srcs//custom_mode/events_blocks_funcs.c:20:			*track = *track == 0 ? MT_MAX - 1 : *track - 1; // previous
srcs//custom_mode/events_blocks_funcs.c:21:		else if (e->keys[KEY_RIGHT])
srcs//custom_mode/events_blocks_funcs.c:24:		//*track >= 0 ? play_ambience(env->) : 0; Play the new track
srcs//custom_mode/events_blocks_funcs.c:32:	if (block->id != BE_CHEST)
srcs//custom_mode/events_blocks_funcs.c:34:	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) > EVENT_DIST)
srcs//custom_mode/events_blocks_funcs.c:44:	if (block->id != BE_DOOR)
srcs//custom_mode/events_blocks_funcs.c:46:	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) > EVENT_DIST)
srcs//custom_mode/events_blocks_funcs.c:58:	if (block->id != BE_LAVA)
srcs//custom_mode/events_blocks_funcs.c:60:	if (vec3d_dist(env->cam.stats.pos, get_block_center(block)) > EVENT_DIST)
srcs//custom_mode/events_blocks_funcs.c:62:		delay--;
srcs//custom_mode/events_blocks_funcs.c:65:			env->player.hp--;
srcs//custom_mode/render.c:27:	custom_env = &env->custom_env;
srcs//custom_mode/render.c:33:		return (-1);
srcs//custom_mode/render.c:35:	if (routines[custom_env->sub_context][i])
srcs//custom_mode/render.c:36:		routines[custom_env->sub_context][i](env);
srcs//custom_mode/render.c:37:	env->custom_env.sub_context = i;
srcs//custom_mode/render.c:48:	if (env->events.keys[KEY_M])
srcs//custom_mode/render.c:50:	return (sub_contexts[env->custom_env.sub_context](env));
srcs//custom_mode/play.c:9:	map = &env->edit_env.map;
srcs//custom_mode/play.c:10:	f = vec_fmult(env->cam.stats.dir, MAPED_WALK_SPEED);
srcs//custom_mode/play.c:11:	r = (t_vec3d){f.z, 0, -f.x, f.w};
srcs//custom_mode/play.c:14:		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
srcs//custom_mode/play.c:15:		translate_mesh(map, &map->cam, vec_fmult(f, 3.0f));
srcs//custom_mode/play.c:19:		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
srcs//custom_mode/play.c:20:		translate_mesh(map, &map->cam, vec_fmult(f, -3.0f));
srcs//custom_mode/play.c:24:		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
srcs//custom_mode/play.c:25:		translate_mesh(map, &map->cam, vec_fmult(r, 3.0f));
srcs//custom_mode/play.c:29:		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));
srcs//custom_mode/play.c:30:		translate_mesh(map, &map->cam, vec_fmult(r, -3.0f));
srcs//custom_mode/play.c:36:	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]))
srcs//custom_mode/play.c:37:		move(env, e->keys);
srcs//custom_mode/play.c:45:	handle_keys(env, &env->events);
srcs//custom_mode/play.c:47:	env->mid.mesh = NULL;
srcs//custom_mode/play.c:49:	assert(!rasterizer(env, &env->edit_env.map, false));
srcs//custom_mode/play.c:53:	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
srcs//custom_mode/play.c:54:	env->events.buttons[BUTTON_SCROLL_UP] = false;
srcs//custom_mode/play.c:55:	env->events.buttons[BUTTON_SCROLL_DOWN] = false;
srcs//custom_mode/setup.c:5:	env->custom_env.env = env;
srcs//custom_mode/setup.c:6:	env->custom_env.sub_context = CUSTOM_SC_MENU;
srcs//custom_mode/events_blocks.c:7:	ret.x = block->x * 2.0f;
srcs//custom_mode/events_blocks.c:8:	ret.y = block->y * 2.0f;
srcs//custom_mode/events_blocks.c:9:	ret.z = block->z * 2.0f;
srcs//custom_mode/events_blocks.c:19:	c = &env->custom_env;
srcs//custom_mode/events_blocks.c:20:	id = map->map[p[0]][p[1]][p[2]];
srcs//custom_mode/events_blocks.c:26:		block.id = id - 160;
srcs//custom_mode/events_blocks.c:28:			env->custom_env.game.nb_spawners++;	
srcs//custom_mode/events_blocks.c:29:		if (c->events.byte_size == 0
srcs//custom_mode/events_blocks.c:30:				&& init_dynarray(&c->events, sizeof(t_event_block), 0))
srcs//custom_mode/events_blocks.c:31:			return (-1);
srcs//custom_mode/events_blocks.c:32:		if (c->events.byte_size > 0
srcs//custom_mode/events_blocks.c:33:			&& push_dynarray(&c->events, &block, false))
srcs//custom_mode/events_blocks.c:34:			return (-1);
srcs//custom_mode/events_blocks.c:46:	i = -1;
srcs//custom_mode/events_blocks.c:47:	map = &env->edit_env.new_map;
srcs//custom_mode/events_blocks.c:48:	while (++i < map->width)
srcs//custom_mode/events_blocks.c:50:		j = -1;
srcs//custom_mode/events_blocks.c:51:		while (++j < map->height)
srcs//custom_mode/events_blocks.c:53:			k = -1;
srcs//custom_mode/events_blocks.c:54:			while (++k < map->depth)
srcs//custom_mode/events_blocks.c:56:					return (-1);
srcs//custom_mode/events_blocks.c:73:	while (i < env->custom_env.events.nb_cells && (j = 1))
srcs//custom_mode/events_blocks.c:75:		block = dyacc(&env->custom_env.events, i);
srcs//custom_mode/events_blocks.c:80:			else if (ret == -1)
srcs//custom_mode/events_blocks.c:81:				return (-1);
srcs//custom_mode/routines.c:5:	if (init_dynarray(&env->custom_env.mobs, sizeof(t_enemy), MAX_CUSTOM_MOBS)
srcs//custom_mode/routines.c:6:		|| astar_init(env) || init_map_physics(&env->edit_env.map))
srcs//custom_mode/routines.c:7:		return (-1);
srcs//custom_mode/routines.c:8:	env->player.hp = START_HP;
srcs//custom_mode/routines.c:15:	free_dynarray(&env->custom_env.mobs);
srcs//custom_mode/routines.c:16:	free_dynarray(&env->astar.d_nodes);
srcs//custom_mode/routines.c:17:	free_dynarray(&env->astar.d_astar);
Binary file srcs//custom_mode/menu.o matches
srcs//custom_mode/events.c:60:	env->events.mouse_pos = (t_point){x, y};
Binary file srcs//custom_mode/events_blocks_funcs.o matches
Binary file srcs//custom_mode/render.o matches
srcs//custom_mode/player.c:9:	while (i < env->custom_env.mobs.nb_cells)
srcs//custom_mode/player.c:11:		mob = dyacc(&env->custom_env.mobs, i);
srcs//custom_mode/player.c:12:		if (vec3d_dist(env->cam->stats.pos, mob->pos) > EVENT_DIST)
srcs//custom_mode/player.c:14:			mob->peace--;
srcs//custom_mode/player.c:15:			if (mob->peace <= 0)
srcs//custom_mode/player.c:17:				mob->peace = MOB_PEACE_TIME;
srcs//custom_mode/player.c:30:	heal--;
srcs//custom_mode/player.c:33:		if (env->player.hp < START_HP)
srcs//custom_mode/player.c:34:			env->player.hp++;
Binary file srcs//weapons/shoot.o matches
Binary file srcs//weapons/shoot_animation.o matches
Binary file srcs//weapons/hud.o matches
srcs//weapons/weapons.c:8:	map = &env->edit_env.map;
srcs//weapons/weapons.c:9:	index = env->player.current->index;
srcs//weapons/weapons.c:10:	if (e->buttons[BUTTON_SCROLL_UP])
srcs//weapons/weapons.c:12:		index = (index == W_MAX - 1) ? 0 : index + 1;
srcs//weapons/weapons.c:13:		env->player.current = dyacc(&env->player.weapons, index);
srcs//weapons/weapons.c:15:	else if (e->buttons[BUTTON_SCROLL_DOWN])
srcs//weapons/weapons.c:17:		index = (index == 0) ? W_MAX - 1 : index - 1;
srcs//weapons/weapons.c:18:		env->player.current = dyacc(&env->player.weapons, index);
srcs//weapons/weapons.c:26:	if (w->shooting > 0)
srcs//weapons/weapons.c:29:		if (w->shoot_mode == SMODE_SBS)
srcs//weapons/weapons.c:30:			w->ready = false;
srcs//weapons/weapons.c:32:	if (w->reloading > 0)
srcs//weapons/weapons.c:35:		w->ready = false;
srcs//weapons/weapons.c:38:	if (w->shoot_mode == SMODE_FULL_AUTO)
srcs//weapons/weapons.c:40:		w->ready = (60 / since) < w->cadency; // Cap with time
srcs//weapons/weapons.c:41:		since = w->ready ? env->data.spent : since + env->data.spent;
srcs//weapons/weapons.c:43:	else if (w->shoot_mode == SMODE_SINGLE)
srcs//weapons/weapons.c:44:		w->ready = !env->events.buttons[BUTTON_LCLIC];
srcs//weapons/weapons.c:45:	else if (w->shoot_mode == SMODE_SBS)
srcs//weapons/weapons.c:46:		w->ready = !env->events.buttons[BUTTON_LCLIC]; // Cap with animation time
srcs//weapons/weapons.c:55:	w = env->player.current;
srcs//weapons/weapons.c:56:	scroll = (e->buttons[BUTTON_SCROLL_UP] || e->buttons[BUTTON_SCROLL_DOWN]);
srcs//weapons/weapons.c:59:		switch_current_weapon(env, &env->events);
srcs//weapons/weapons.c:62:	r = e->keys[KEY_R];
srcs//weapons/weapons.c:63:	if (((r && w->loaded < w->magazine) || w->loaded == 0) && w->ammos > 0)
srcs//weapons/weapons.c:65:	else if (e->buttons[BUTTON_LCLIC] && w->ready && w->loaded > 0)
srcs//weapons/weapons.c:72:	env->player.current->shot = false;
srcs//weapons/weapons.c:73:	raster_weapon(env, env->player.current->w_map);
srcs//weapons/weapons.c:74:	weapons_events(env, &env->events);
Binary file srcs//weapons/reload_animation.o matches
srcs//weapons/init_weapons.c:5:	const char	*names[W_MAX] = {"FAMAS", "AK-47", "Sawed-Off", "Glock-18",
srcs//weapons/init_weapons.c:6:									"AUG", "UMP45", "mag-7", "Galil",
srcs//weapons/init_weapons.c:7:									"Negev", "TEC-9"};
srcs//weapons/init_weapons.c:13:		if (!(env->weapons[i].name = ft_strdup((char*)names[i])))
srcs//weapons/init_weapons.c:14:			return (-1);
srcs//weapons/init_weapons.c:15:		env->weapons[i].index = (int)i;
srcs//weapons/init_weapons.c:24:	env->weapons[W_FAMAS].mesh = (t_mesh*)env->maps[SCENE_FAMAS].meshs.c;
srcs//weapons/init_weapons.c:25:	env->weapons[W_FAMAS].breech = dyacc(&env->maps[SCENE_FAMAS].meshs, 2);
srcs//weapons/init_weapons.c:26:	env->weapons[W_FAMAS].w_map = &env->maps[SCENE_FAMAS];
srcs//weapons/init_weapons.c:27://	printf("%s\n", env->weapons[W_FAMAS].mesh->name);
srcs//weapons/init_weapons.c:28:	env->weapons[W_AK47].mesh = (t_mesh*)env->maps[SCENE_AK47].meshs.c;
srcs//weapons/init_weapons.c:29:	env->weapons[W_AK47].breech = dyacc(&env->maps[SCENE_AK47].meshs, 1);
srcs//weapons/init_weapons.c:30:	env->weapons[W_AK47].w_map = &env->maps[SCENE_AK47];
srcs//weapons/init_weapons.c:31://	printf("%s\n", env->weapons[W_AK47].mesh->name);
srcs//weapons/init_weapons.c:32:	env->weapons[W_SAWED_OFF].mesh = (t_mesh*)env->maps[SCENE_SAWED_OFF].meshs.c;
srcs//weapons/init_weapons.c:33:	env->weapons[W_SAWED_OFF].breech = dyacc(&env->maps[SCENE_SAWED_OFF].meshs, 1);
srcs//weapons/init_weapons.c:34:	env->weapons[W_SAWED_OFF].w_map = &env->maps[SCENE_SAWED_OFF];
srcs//weapons/init_weapons.c:35://	printf("%s\n", env->weapons[W_SAWED_OFF].mesh->name);
srcs//weapons/init_weapons.c:36:	env->weapons[W_GLOCK_18].mesh = (t_mesh*)env->maps[SCENE_GLOCK_18].meshs.c;
srcs//weapons/init_weapons.c:37:	env->weapons[W_GLOCK_18].breech = dyacc(&env->maps[SCENE_GLOCK_18].meshs, 2);
srcs//weapons/init_weapons.c:38:	env->weapons[W_GLOCK_18].w_map = &env->maps[SCENE_GLOCK_18];
srcs//weapons/init_weapons.c:39://	printf("%s\n", env->weapons[W_GLOCK_18].mesh->name);
srcs//weapons/init_weapons.c:40:	env->weapons[W_AUG].mesh = (t_mesh*)env->maps[SCENE_AUG].meshs.c;
srcs//weapons/init_weapons.c:41:	env->weapons[W_AUG].breech = dyacc(&env->maps[SCENE_AUG].meshs, 2);
srcs//weapons/init_weapons.c:42:	env->weapons[W_AUG].w_map = &env->maps[SCENE_AUG];
srcs//weapons/init_weapons.c:43://	printf("%s\n", env->weapons[W_AUG].mesh->name);
srcs//weapons/init_weapons.c:44:	env->weapons[W_UMP45].mesh = (t_mesh*)env->maps[SCENE_UMP45].meshs.c;
srcs//weapons/init_weapons.c:45:	env->weapons[W_UMP45].breech = dyacc(&env->maps[SCENE_UMP45].meshs, 2);
srcs//weapons/init_weapons.c:46:	env->weapons[W_UMP45].w_map = &env->maps[SCENE_UMP45];
srcs//weapons/init_weapons.c:47://	printf("%s\n", env->weapons[W_UMP45].mesh->name);
srcs//weapons/init_weapons.c:48:	env->weapons[W_MAG7].mesh = (t_mesh*)env->maps[SCENE_MAG7].meshs.c;
srcs//weapons/init_weapons.c:49:	env->weapons[W_MAG7].breech = dyacc(&env->maps[SCENE_MAG7].meshs, 1);
srcs//weapons/init_weapons.c:50:	env->weapons[W_MAG7].w_map = &env->maps[SCENE_MAG7];
srcs//weapons/init_weapons.c:51://	printf("%s\n", env->weapons[W_MAG7].mesh->name);
srcs//weapons/init_weapons.c:52:	env->weapons[W_GALIL].mesh = (t_mesh*)env->maps[SCENE_GALIL].meshs.c;
srcs//weapons/init_weapons.c:53:	env->weapons[W_GALIL].breech = dyacc(&env->maps[SCENE_GALIL].meshs, 2);
srcs//weapons/init_weapons.c:54:	env->weapons[W_GALIL].w_map = &env->maps[SCENE_GALIL];
srcs//weapons/init_weapons.c:55://	printf("%s\n", env->weapons[W_GALIL].mesh->name);
srcs//weapons/init_weapons.c:56:	env->weapons[W_NEGEV].mesh = (t_mesh*)env->maps[SCENE_NEGEV].meshs.c;
srcs//weapons/init_weapons.c:57:	env->weapons[W_NEGEV].breech = dyacc(&env->maps[SCENE_NEGEV].meshs, 2);
srcs//weapons/init_weapons.c:58:	env->weapons[W_NEGEV].w_map = &env->maps[SCENE_NEGEV];
srcs//weapons/init_weapons.c:59://	printf("%s\n", env->weapons[W_NEGEV].mesh->name);
srcs//weapons/init_weapons.c:60:	env->weapons[W_TEC9].mesh = (t_mesh*)env->maps[SCENE_TEC9].meshs.c;
srcs//weapons/init_weapons.c:61:	env->weapons[W_TEC9].breech = dyacc(&env->maps[SCENE_TEC9].meshs, 2);
srcs//weapons/init_weapons.c:62:	env->weapons[W_TEC9].w_map = &env->maps[SCENE_TEC9];
srcs//weapons/init_weapons.c:63://	printf("%s\n", env->weapons[W_TEC9].mesh->name);
srcs//weapons/init_weapons.c:68:	env->weapons[W_FAMAS].shoot = &env->sound.samples[SA_FAMAS_FIRE];
srcs//weapons/init_weapons.c:69:	env->weapons[W_AK47].shoot = &env->sound.samples[SA_AK47_FIRE];
srcs//weapons/init_weapons.c:70:	env->weapons[W_SAWED_OFF].shoot = &env->sound.samples[SA_SAWED_OFF_FIRE];
srcs//weapons/init_weapons.c:71:	env->weapons[W_GLOCK_18].shoot = &env->sound.samples[SA_GLOCK_FIRE];
srcs//weapons/init_weapons.c:72:	env->weapons[W_AUG].shoot = &env->sound.samples[SA_AUG_FIRE];
srcs//weapons/init_weapons.c:73:	env->weapons[W_UMP45].shoot = &env->sound.samples[SA_UMP45_FIRE];
srcs//weapons/init_weapons.c:74:	env->weapons[W_MAG7].shoot = &env->sound.samples[SA_MAG7_FIRE];
srcs//weapons/init_weapons.c:75:	env->weapons[W_GALIL].shoot = &env->sound.samples[SA_GALIL_FIRE];
srcs//weapons/init_weapons.c:76:	env->weapons[W_NEGEV].shoot = &env->sound.samples[SA_NEGEV_FIRE];
srcs//weapons/init_weapons.c:77:	env->weapons[W_TEC9].shoot = &env->sound.samples[SA_TEC9_FIRE];
srcs//weapons/init_weapons.c:79:	env->weapons[W_FAMAS].reload = &env->sound.samples[SA_FAMAS_RELOAD];
srcs//weapons/init_weapons.c:80:	env->weapons[W_AK47].reload = &env->sound.samples[SA_AK47_RELOAD];
srcs//weapons/init_weapons.c:81:	env->weapons[W_SAWED_OFF].reload = &env->sound.samples[SA_SAWED_OFF_FILL];
srcs//weapons/init_weapons.c:82:	env->weapons[W_GLOCK_18].reload = &env->sound.samples[SA_GLOCK_RELOAD];
srcs//weapons/init_weapons.c:83:	env->weapons[W_AUG].reload = &env->sound.samples[SA_AUG_RELOAD];
srcs//weapons/init_weapons.c:84:	env->weapons[W_UMP45].reload = &env->sound.samples[SA_UMP45_RELOAD];
srcs//weapons/init_weapons.c:85:	env->weapons[W_MAG7].reload = &env->sound.samples[SA_MAG7_RELOAD];
srcs//weapons/init_weapons.c:86:	env->weapons[W_GALIL].reload = &env->sound.samples[SA_GALIL_RELOAD];
srcs//weapons/init_weapons.c:87:	env->weapons[W_NEGEV].reload = &env->sound.samples[SA_NEGEV_RELOAD];
srcs//weapons/init_weapons.c:88:	env->weapons[W_TEC9].reload = &env->sound.samples[SA_TEC9_RELOAD];
srcs//weapons/init_weapons.c:94:		return (-1);
srcs//weapons/init_weapons.c:98:	if (init_dynarray(&env->player.weapons, sizeof(t_weapon), 0))
srcs//weapons/init_weapons.c:99:		return (-1);
srcs//weapons/stats.c:5:	env->weapons[W_FAMAS].damages = 30;
srcs//weapons/stats.c:6:	env->weapons[W_AK47].damages = 50;
srcs//weapons/stats.c:7:	env->weapons[W_SAWED_OFF].damages = 90;
srcs//weapons/stats.c:8:	env->weapons[W_GLOCK_18].damages = 30;
srcs//weapons/stats.c:9:	env->weapons[W_AUG].damages = 40;
srcs//weapons/stats.c:10:	env->weapons[W_UMP45].damages = 30;
srcs//weapons/stats.c:11:	env->weapons[W_MAG7].damages = 80;
srcs//weapons/stats.c:12:	env->weapons[W_GALIL].damages = 25;
srcs//weapons/stats.c:13:	env->weapons[W_NEGEV].damages = 60;
srcs//weapons/stats.c:14:	env->weapons[W_TEC9].damages = 45;
srcs//weapons/stats.c:16:	env->weapons[W_FAMAS].accuracy = 0.8f;
srcs//weapons/stats.c:17:	env->weapons[W_AK47].accuracy = 0.6f;
srcs//weapons/stats.c:18:	env->weapons[W_SAWED_OFF].accuracy = 0.3f;
srcs//weapons/stats.c:19:	env->weapons[W_GLOCK_18].accuracy = 0.5f;
srcs//weapons/stats.c:20:	env->weapons[W_AUG].accuracy = 0.8f;
srcs//weapons/stats.c:21:	env->weapons[W_UMP45].accuracy = 0.5;
srcs//weapons/stats.c:22:	env->weapons[W_MAG7].accuracy = 0.4;
srcs//weapons/stats.c:23:	env->weapons[W_GALIL].accuracy = 0.6;
srcs//weapons/stats.c:24:	env->weapons[W_NEGEV].accuracy = 0.4;
srcs//weapons/stats.c:25:	env->weapons[W_TEC9].accuracy = 0.8;
srcs//weapons/stats.c:30:	env->weapons[W_FAMAS].magazine = 25;
srcs//weapons/stats.c:31:	env->weapons[W_AK47].magazine = 30;
srcs//weapons/stats.c:32:	env->weapons[W_SAWED_OFF].magazine = 6;
srcs//weapons/stats.c:33:	env->weapons[W_GLOCK_18].magazine = 18;
srcs//weapons/stats.c:34:	env->weapons[W_AUG].magazine = 30;
srcs//weapons/stats.c:35:	env->weapons[W_UMP45].magazine = 32;
srcs//weapons/stats.c:36:	env->weapons[W_MAG7].magazine = 6;
srcs//weapons/stats.c:37:	env->weapons[W_GALIL].magazine = 35;
srcs//weapons/stats.c:38:	env->weapons[W_NEGEV].magazine = 100;
srcs//weapons/stats.c:39:	env->weapons[W_TEC9].magazine = 18;
srcs//weapons/stats.c:41:	env->weapons[W_FAMAS].reticle = 20;
srcs//weapons/stats.c:42:	env->weapons[W_AK47].reticle = 24;
srcs//weapons/stats.c:43:	env->weapons[W_SAWED_OFF].reticle = 32;
srcs//weapons/stats.c:44:	env->weapons[W_GLOCK_18].reticle = 16;
srcs//weapons/stats.c:45:	env->weapons[W_AUG].reticle = 20;
srcs//weapons/stats.c:46:	env->weapons[W_UMP45].reticle = 22;
srcs//weapons/stats.c:47:	env->weapons[W_MAG7].reticle = 30;
srcs//weapons/stats.c:48:	env->weapons[W_GALIL].reticle = 22;
srcs//weapons/stats.c:49:	env->weapons[W_NEGEV].reticle = 30;
srcs//weapons/stats.c:50:	env->weapons[W_TEC9].reticle = 20;
srcs//weapons/stats.c:55:	env->weapons[W_FAMAS].cadency = 1000;
srcs//weapons/stats.c:56:	env->weapons[W_AK47].cadency = 600;
srcs//weapons/stats.c:57:	env->weapons[W_SAWED_OFF].cadency = 200;
srcs//weapons/stats.c:58:	env->weapons[W_GLOCK_18].cadency = 300;
srcs//weapons/stats.c:59:	env->weapons[W_AUG].cadency = 650;
srcs//weapons/stats.c:60:	env->weapons[W_UMP45].cadency = 600;
srcs//weapons/stats.c:61:	env->weapons[W_MAG7].cadency = 250;
srcs//weapons/stats.c:62:	env->weapons[W_GALIL].cadency = 650;
srcs//weapons/stats.c:63:	env->weapons[W_NEGEV].cadency = 850;
srcs//weapons/stats.c:64:	env->weapons[W_TEC9].cadency = 300;
srcs//weapons/stats.c:66:	env->weapons[W_FAMAS].shoot_mode = SMODE_FULL_AUTO;
srcs//weapons/stats.c:67:	env->weapons[W_AK47].shoot_mode = SMODE_FULL_AUTO;
srcs//weapons/stats.c:68:	env->weapons[W_SAWED_OFF].shoot_mode = SMODE_SBS;
srcs//weapons/stats.c:69:	env->weapons[W_GLOCK_18].shoot_mode = SMODE_SINGLE;
srcs//weapons/stats.c:70:	env->weapons[W_AUG].shoot_mode = SMODE_FULL_AUTO;
srcs//weapons/stats.c:71:	env->weapons[W_UMP45].shoot_mode = SMODE_FULL_AUTO;
srcs//weapons/stats.c:72:	env->weapons[W_MAG7].shoot_mode = SMODE_SBS;
srcs//weapons/stats.c:73:	env->weapons[W_GALIL].shoot_mode = SMODE_FULL_AUTO;
srcs//weapons/stats.c:74:	env->weapons[W_NEGEV].shoot_mode = SMODE_FULL_AUTO;
srcs//weapons/stats.c:75:	env->weapons[W_TEC9].shoot_mode = SMODE_SINGLE;
srcs//weapons/stats.c:80:	env->weapons[W_FAMAS].recoil = 0.1f;
srcs//weapons/stats.c:81:	env->weapons[W_AK47].recoil = 0.05f;
srcs//weapons/stats.c:82:	env->weapons[W_SAWED_OFF].recoil = 0.3f;
srcs//weapons/stats.c:83:	env->weapons[W_GLOCK_18].recoil = 0.05;
srcs//weapons/stats.c:84:	env->weapons[W_AUG].recoil = 0.1f;
srcs//weapons/stats.c:85:	env->weapons[W_UMP45].recoil = 0.1f;
srcs//weapons/stats.c:86:	env->weapons[W_MAG7].recoil = 0.3f;
srcs//weapons/stats.c:87:	env->weapons[W_GALIL].recoil = 0.1f;
srcs//weapons/stats.c:88:	env->weapons[W_NEGEV].recoil = 0.1f;
srcs//weapons/stats.c:89:	env->weapons[W_TEC9].recoil = 0.05f;
srcs//weapons/reticule.c:10:	pre_bound = (size * (1.2f - spread));
srcs//weapons/reticule.c:11:	bound = data->half_hgt + size;
srcs//weapons/reticule.c:12:	x = data->half_wdt;
srcs//weapons/reticule.c:13:	y = data->half_hgt - size - 1;
srcs//weapons/reticule.c:15:		if (fabsf(y - data->half_hgt) >= pre_bound)
srcs//weapons/reticule.c:17:			draw_pixel(mlx->img_data, x, y, hover ? 0xff0000 : 0x00ff00);
srcs//weapons/reticule.c:18:			draw_pixel(mlx->img_data, x - 1, y, hover ? 0xff0000 : 0x00ff00);
srcs//weapons/reticule.c:29:	pre_bound = (size * (1.2f - spread));
srcs//weapons/reticule.c:30:	bound = data->half_wdt + size;
srcs//weapons/reticule.c:31:	x = data->half_wdt - size - 1;
srcs//weapons/reticule.c:32:	y = data->half_hgt;
srcs//weapons/reticule.c:34:		if (fabsf(x - data->half_wdt) >= pre_bound)
srcs//weapons/reticule.c:36:			draw_pixel(mlx->img_data, x, y, hover ? 0xff0000 : 0x00ff00);
srcs//weapons/reticule.c:37:			draw_pixel(mlx->img_data, x, y - 1, hover ? 0xff0000 : 0x00ff00);
srcs//weapons/reticule.c:48:	data = &env->data;
srcs//weapons/reticule.c:49:	mlx = &env->mlx;
srcs//weapons/reticule.c:50:	pl = &env->player;
srcs//weapons/reticule.c:51:	line_size = env->player.current->reticle;
srcs//weapons/reticule.c:53://	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt, 0x00ff00);
srcs//weapons/reticule.c:54://	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt, 0x00ff00);
srcs//weapons/reticule.c:55://	draw_pixel(mlx->img_data, data->half_wdt, data->half_hgt - 1, 0x00ff00);
srcs//weapons/reticule.c:56://	draw_pixel(mlx->img_data, data->half_wdt - 1, data->half_hgt - 1, 0x00ff00);
srcs//weapons/reticule.c:58:	draw_vertical(data, mlx, line_size, pl->current->accuracy, pl->hover);
srcs//weapons/reticule.c:59:	draw_horizontal(data, mlx, line_size, pl->current->accuracy, pl->hover);
Binary file srcs//weapons/ammos.o matches
srcs//weapons/shoot.c:16:	data = &env->data;
srcs//weapons/shoot.c:17:	max = env->player.current->accuracy * ACC_START;
srcs//weapons/shoot.c:18:	x = (rand() % max) - max / 2;
srcs//weapons/shoot.c:19:	y = (rand() % max) - max / 2;
srcs//weapons/shoot.c:20:	env->player.shoot = (t_point){data->half_wdt + x, data->half_hgt + y};
srcs//weapons/shoot.c:30:	w = env->player.current;
srcs//weapons/shoot.c:31:	sbs = w->shoot_mode == SMODE_SBS;
srcs//weapons/shoot.c:32:	single = w->shoot_mode == SMODE_SINGLE;
srcs//weapons/shoot.c:33:	full_auto = w->shoot_mode == SMODE_FULL_AUTO;
srcs//weapons/shoot.c:36:		w->ready = false;
srcs//weapons/shoot.c:37:		w->loaded--;
srcs//weapons/shoot.c:38:		if (w->shoot)
srcs//weapons/shoot.c:39:			stop_n_play(w->shoot);
srcs//weapons/shoot.c:41:	w->shooting = 60.0f / w->cadency;
srcs//weapons/shoot.c:43:	w->shot = true;
srcs//weapons/shoot.c:52:	w = env->player.current;
srcs//weapons/shoot.c:53:	if (w->loaded == 0 && w->ammos >= w->magazine) // Chargeur vide
srcs//weapons/shoot.c:55:		w->loaded += w->magazine;
srcs//weapons/shoot.c:56:		w->ammos -= w->magazine;
srcs//weapons/shoot.c:58:	else if ((need = w->magazine - w->loaded) <= w->ammos) // R
srcs//weapons/shoot.c:60:		w->loaded += need;
srcs//weapons/shoot.c:61:		w->ammos -= need;
srcs//weapons/shoot.c:65:		w->loaded += w->ammos;
srcs//weapons/shoot.c:66:		w->ammos = 0;
srcs//weapons/shoot.c:68:	if (w->reload)
srcs//weapons/shoot.c:69:		stop_n_play(w->reload);
srcs//weapons/shoot.c:70:	w->reloading = RELOAD_TIME;
srcs//weapons/shoot.c:71:	w->start = w->w_map->spawn;
srcs//weapons/shoot_animation.c:9:		w->w_map->spawn.z += w->recoil;
srcs//weapons/shoot_animation.c:11:		w->w_map->spawn.z -= w->recoil;
srcs//weapons/shoot_animation.c:12:	if (reset || w->w_map->spawn.y < w->start.y)
srcs//weapons/shoot_animation.c:13:		w->w_map->spawn = w->start;
srcs//weapons/shoot_animation.c:20:	w->shooting -= env->data.spent;
srcs//weapons/shoot_animation.c:21:	progress = 1 - (w->shooting / (60.0f / w->cadency));
srcs//weapons/hud.c:10:	if (!(moulaga = ft_itoa(env->custom_env.game.moula)))
srcs//weapons/hud.c:12:	ft_strcpy((char*)conf->s, moulaga);
srcs//weapons/hud.c:13:	conf->size = 16;
srcs//weapons/hud.c:14:	o = (t_point){1000 - conf->size / 2, 200};
srcs//weapons/hud.c:15:	draw_rectangle(env->mlx.img_data, o,
srcs//weapons/hud.c:16:		(t_point){conf->size * ft_strlen(moulaga), conf->size}, 0x770000);
srcs//weapons/hud.c:18:	o.x += conf->size / 2;
srcs//weapons/hud.c:19:	o.y += conf->size;
srcs//weapons/hud.c:20:	my_string_put(env, env->mlx.img_data, o, FONT_COOLVETICA);
srcs//weapons/hud.c:28:	hm = env->sprites[SP_HITMARKER];
srcs//weapons/hud.c:29:	o.x = env->data.half_wdt - (hm.wdt / 2);
srcs//weapons/hud.c:30:	o.y = env->data.half_hgt - (hm.hgt / 2);
srcs//weapons/hud.c:31:	map_sprite(env->mlx.img_data, hm, o);
srcs//weapons/hud.c:37:	if (env->player.current)
srcs//weapons/hud.c:39:	if (print_ammos(env, env->player.current))
srcs//weapons/hud.c:40:		return (-1);
srcs//weapons/hud.c:41:	if (env->player.hitmarker > 0)
Binary file srcs//weapons/weapons.o matches
Binary file srcs//weapons/reticule.o matches
srcs//weapons/ammos.c:10:	if (!(l = ft_itoa(w->loaded)))
srcs//weapons/ammos.c:11:		return (-1);
srcs//weapons/ammos.c:15:		return (-1);
srcs//weapons/ammos.c:18:	if (!(m  = ft_itoa(w->ammos)))
srcs//weapons/ammos.c:21:		return (-1);
srcs//weapons/ammos.c:27:		return (-1);
srcs//weapons/ammos.c:41:	if (make_string(w, conf->s))
srcs//weapons/ammos.c:42:		return (-1);
srcs//weapons/ammos.c:43:	conf->size = AMMO_FONT_SIZE;
srcs//weapons/ammos.c:44:	my_string_put(env, env->mlx.img_data, (t_point){900, 670}, FONT_AMMOS);
srcs//weapons/ammos.c:45:	conf->size = W_NAME_FONT_SIZE;
srcs//weapons/ammos.c:46:	ft_strcpy((char*)conf->s, w->name);
srcs//weapons/ammos.c:47:	my_string_put(env, env->mlx.img_data, (t_point){900, 630}, FONT_ARIAL);
Binary file srcs//weapons/stats.o matches
srcs//weapons/reload_animation.c:7:		w->w_map->spawn.y -= RELOAD_SPEED;
srcs//weapons/reload_animation.c:8:		w->w_map->spawn.z -= RELOAD_SPEED;
srcs//weapons/reload_animation.c:12:		w->w_map->spawn.y += RELOAD_SPEED;
srcs//weapons/reload_animation.c:13:		w->w_map->spawn.z += RELOAD_SPEED;
srcs//weapons/reload_animation.c:15:	if (reset || w->w_map->spawn.y < w->start.y)
srcs//weapons/reload_animation.c:16:		w->w_map->spawn = w->start;
srcs//weapons/reload_animation.c:23:	w->reloading -= env->data.spent;
srcs//weapons/reload_animation.c:24:	if (!ft_inbounds(env->scene, W_FAMAS, W_MAX - 1)) // Protection
srcs//weapons/reload_animation.c:26:	progress = w->reloading / RELOAD_TIME;
Binary file srcs//weapons/init_weapons.o matches
Binary file srcs//physic_engine/init_engine.o matches
Binary file srcs//physic_engine/engine.o matches
srcs//physic_engine/color_collides.c:22:	for (int i = 0; i < env->maps[env->scene].nmesh; i++)
srcs//physic_engine/color_collides.c:24:		mesh = dyacc(&env->maps[env->scene].meshs, i);
srcs//physic_engine/color_collides.c:25:		for (int j = 0; j < mesh->tris.nb_cells; j++)
srcs//physic_engine/color_collides.c:27:			t = dyacc(&mesh->tris, j);
srcs//physic_engine/color_collides.c:28:			t->color = 0xffffff;
srcs//physic_engine/color_collides.c:31:	for (int i = 0; i < env->phy_env.collides.nb_cells; i++)
srcs//physic_engine/color_collides.c:33:		m = dyacc(&env->phy_env.collides, i);
srcs//physic_engine/color_collides.c:34:		for (int j = 0; j < m->a->tris.nb_cells; j++)
srcs//physic_engine/color_collides.c:36:			t = dyacc(&m->a->tris, j);
srcs//physic_engine/color_collides.c:37:			t->color = 0xff0000;
srcs//physic_engine/color_collides.c:39:		for (int j = 0; j < m->b->tris.nb_cells; j++)
srcs//physic_engine/color_collides.c:41:			t = dyacc(&m->b->tris, j);
srcs//physic_engine/color_collides.c:42:			t->color = 0xff0000;
srcs//physic_engine/color_collides.c:53:	for (int i = 0; i < env->maps[env->scene].nmesh; i++)
srcs//physic_engine/color_collides.c:55:		mesh = dyacc(&env->maps[env->scene].meshs, i);
srcs//physic_engine/color_collides.c:56:		for (int j = 0; j < mesh->tris.nb_cells; j++)
srcs//physic_engine/color_collides.c:58:			t = dyacc(&mesh->tris, j);
srcs//physic_engine/color_collides.c:59:			t->color = 0xffffff;
srcs//physic_engine/color_collides.c:63:	for (int i = 0; i < env->phy_env.collides_cam.nb_cells; i++)
srcs//physic_engine/color_collides.c:65:		m = dyacc(&env->phy_env.collides_cam, i);
srcs//physic_engine/color_collides.c:66:		for (int j = 0; j < m->a->tris.nb_cells; j++)
srcs//physic_engine/color_collides.c:68:			t = dyacc(&m->a->tris, j);
srcs//physic_engine/color_collides.c:69:			t->color = 0xff0000;
srcs//physic_engine/color_collides.c:71:		for (int j = 0; j < m->b->tris.nb_cells; j++)
srcs//physic_engine/color_collides.c:73:			t = dyacc(&m->b->tris, j);
srcs//physic_engine/color_collides.c:74:			t->color = 0xff0000;
Binary file srcs//physic_engine/phy_update.o matches
Binary file srcs//physic_engine/phy_tool.o matches
Binary file srcs//physic_engine/report_collisions.o matches
Binary file srcs//physic_engine/init_bounding_boxs.o matches
Binary file srcs//physic_engine/phy_gravity.o matches
Binary file srcs//physic_engine/move_mesh.o matches
srcs//physic_engine/engine.c:19:	e = &env->events;
srcs//physic_engine/engine.c:28://	if (e->keys[KEY_P])
srcs//physic_engine/engine.c:31:	clear_dynarray(&env->phy_env.collides);
Binary file srcs//physic_engine/color_collides.o matches
srcs//physic_engine/init_engine.c:23:	while (i < m->tris.nb_cells)
srcs//physic_engine/init_engine.c:25:		if (!(t = dyacc(&m->tris, i)))
srcs//physic_engine/init_engine.c:26:			return (-1);
srcs//physic_engine/init_engine.c:27:		average = vec_add(average, t->points[0]);
srcs//physic_engine/init_engine.c:28:		average = vec_add(average, t->points[1]);
srcs//physic_engine/init_engine.c:29:		average = vec_add(average, t->points[2]);
srcs//physic_engine/init_engine.c:32:	m->corp.pos = vec_fdiv(average, (float)i);
srcs//physic_engine/init_engine.c:33:	m->corp.pos = vec_fdiv(m->corp.pos, 3.0f);
srcs//physic_engine/init_engine.c:43:	while (i < map->nmesh)
srcs//physic_engine/init_engine.c:45:		if (!(m = dyacc(&map->meshs, i))
srcs//physic_engine/init_engine.c:48:			return (-1);
srcs//physic_engine/init_engine.c:62:		if (init_map_physics(&env->maps[i]))
srcs//physic_engine/init_engine.c:63:			return (-1);
srcs//physic_engine/init_engine.c:64:		ft_putchar(i == SCENE_MAX - 1 ? '\0' : '\r');
srcs//physic_engine/init_engine.c:67:	env->phy_env.gravity = 0.0000981;
srcs//physic_engine/phy_update.c:21:	while (i < env->maps[env->scene].meshs.nb_cells)
srcs//physic_engine/phy_update.c:23:		m = dyacc(&env->maps[env->scene].meshs, i);		
srcs//physic_engine/phy_update.c:24:		if (env->maps[env->scene].stats[i] == false)
srcs//physic_engine/phy_update.c:26:			if (nonzero_vector(m->corp.v))
srcs//physic_engine/phy_update.c:27:				vec3d_swap(&m->corp.v, &m->corp.v_cpy); // cancel v and save in vec_cpy
srcs//physic_engine/phy_update.c:30:				vec3d_swap(&m->corp.v_cpy, &m->corp.v); // swap in v and cancel the vec_cpy
srcs//physic_engine/phy_update.c:31:				m->corp.v_cpy = zero_vector();
srcs//physic_engine/phy_update.c:33:			if (env->phy_env.gravity != 0)
srcs//physic_engine/phy_update.c:34:				env->phy_env.gravity = 0;
srcs//physic_engine/phy_update.c:36:				env->phy_env.gravity = 0.0000981;
srcs//physic_engine/phy_update.c:52:	c = dyacc(&env->phy_env.collides, index);
srcs//physic_engine/phy_update.c:53:	v = c->a->corp.v;
srcs//physic_engine/phy_update.c:54:	norm = c->b->corp.norm;
srcs//physic_engine/phy_update.c:56:	c->dot = vec_dot(norm, v);
srcs//physic_engine/phy_update.c:58:		v2 = (t_vec3d){-v.x * frott, v.y, v.z, 0.0f}; 
srcs//physic_engine/phy_update.c:61:		v2 = (t_vec3d){v.x * frott, -(v.y) * frott, v.z * frott, 0.0f};
srcs//physic_engine/phy_update.c:64:			env->phy_env.tps = 0;							//stop gravity
srcs//physic_engine/phy_update.c:65:			env->maps[env->scene].stats[c->i_a] = true;		//turn to static
srcs//physic_engine/phy_update.c:70:		v2 = (t_vec3d){v.x, v.y, -v.z * frott, 0.0f};
srcs//physic_engine/phy_update.c:82:	n_mesh = env->maps[env->scene].nmesh;
srcs//physic_engine/phy_update.c:84:	while (i < env->phy_env.collides.nb_cells) //if collides but no camera ! 
srcs//physic_engine/phy_update.c:86:		c = dyacc(&env->phy_env.collides,i);
srcs//physic_engine/phy_update.c:87:		c->a->corp.v = update_angle(env, i);
srcs//physic_engine/phy_update.c:98:	n_mesh = env->maps[env->scene].nmesh;
srcs//physic_engine/phy_update.c:100:	while (i < env->phy_env.collides_cam.nb_cells) //if collides but no camera ! 
srcs//physic_engine/phy_update.c:102:		c = dyacc(&env->phy_env.collides_cam, i);
srcs//physic_engine/phy_update.c:103:		env->maps[env->scene].cam_floor = *c;
srcs//physic_engine/phy_update.c:109:		env->cam.stats.onfloor = 0;
srcs//physic_engine/phy_update.c:110:		env->cam.stats.onplan = 0;
srcs//physic_engine/phy_update.c:111:		env->events.keys[KEY_E] = false;
srcs//physic_engine/phy_update.c:121:	e = &env->events;
srcs//physic_engine/phy_update.c:123:	while (i < env->maps[env->scene].nmesh)
srcs//physic_engine/phy_update.c:125:		m = dyacc(&env->maps[env->scene].meshs, i);		
srcs//physic_engine/phy_update.c:126:		if (env->maps[env->scene].stats[i] == false)
srcs//physic_engine/phy_update.c:129:			translate_mesh(&env->maps[env->scene], m, m->corp.v);
srcs//physic_engine/phy_update.c:139:	cam = &env->maps[env->scene].cam;
srcs//physic_engine/phy_update.c:140:	if (env->cam.stats.onfloor == 0 && 
srcs//physic_engine/phy_update.c:141:			env->cam.stats.onplan == 0)
srcs//physic_engine/phy_update.c:143:		phy_gravitax_cam(env, cam, &env->cam.stats);
srcs//physic_engine/phy_update.c:144:		env->cam.stats.pos = vec_add(env->cam.stats.pos, cam->corp.v);
srcs//physic_engine/phy_update.c:145:		cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims, 2.0f));
srcs//physic_engine/phy_tool.c:17:	if ((fabs(c->a->corp.norm.x) == 1 || fabs(c->a->corp.norm.z) == 1) && c->i_a != 0)
srcs//physic_engine/phy_tool.c:19:		env->maps[env->scene].cam_wall = *c;
srcs//physic_engine/phy_tool.c:20:		env->cam.stats.onwall = 1;
srcs//physic_engine/phy_tool.c:24:		test_distance_camplan(env->maps[env->scene].cam_floor, &env->cam.stats.pos);
srcs//physic_engine/phy_tool.c:25:		c->b->corp.v = zero_vector(); //stop gravity
srcs//physic_engine/phy_tool.c:26:		env->phy_env.tps = 0;			// need to be variable by mesh 
srcs//physic_engine/phy_tool.c:27:		env->cam.stats.onwall = 0;
srcs//physic_engine/phy_tool.c:28:		if (c->a->corp.norm.y == 1 || c->i_a == 0)
srcs//physic_engine/phy_tool.c:30:			env->cam.stats.onfloor = 1; //2 
srcs//physic_engine/phy_tool.c:31:			env->cam.stats.onplan = 0;
srcs//physic_engine/phy_tool.c:35:			env->cam.stats.onplan = 1; //3
srcs//physic_engine/phy_tool.c:36:			env->cam.stats.onfloor = 0; // save the main collide
srcs//physic_engine/report_collisions.c:37:	printf("%s <-> %s\n", c.a->name, c.b->name);
srcs//physic_engine/report_collisions.c:38:	printf("------\n%s\n------\n", c.a->name);
srcs//physic_engine/report_collisions.c:41:	printf("------\n%s\n------\n\n", c.b->name);
srcs//physic_engine/report_collisions.c:78:	c->a = a;
srcs//physic_engine/report_collisions.c:79:	c->b = b;
srcs//physic_engine/report_collisions.c:80://	printf("%s (%f %f %f) <-> %s (%f %f %F)\n", c->a->name, c->a->corp.pos.x, c->a->corp.pos.y, c->a->corp.pos.z, c->b->name, c->b->corp.pos.x, c->b->corp.pos.y, c->b->corp.pos.z);
srcs//physic_engine/report_collisions.c:82:	return (aabb_collision(a->corp.o, b->corp.o, a->corp.dims, b->corp.dims));
srcs//physic_engine/report_collisions.c:91:	c->a = a;
srcs//physic_engine/report_collisions.c:92:	c->b = cam;
srcs//physic_engine/report_collisions.c:93://	printf("%s (%f %f %f) <-> %s (%f %f %F)\n", c->a->name, c->a->corp.pos.x, c->a->corp.pos.y, c->a->corp.pos.z, c->b->name, c->b->corp.pos.x, c->b->corp.pos.y, c->b->corp.pos.z);
srcs//physic_engine/report_collisions.c:95:	return (aabb_collision(a->corp.o, cam->corp.o, a->corp.dims, cam->corp.dims));
srcs//physic_engine/report_collisions.c:105:	cam = &env->maps[env->scene].cam;
srcs//physic_engine/report_collisions.c:106:	if (init_dynarray(&env->phy_env.collides_cam,
srcs//physic_engine/report_collisions.c:107:		sizeof(t_collide), env->maps[env->scene].nmesh)) //pas la peine de mettre autant de case
srcs//physic_engine/report_collisions.c:108:		return (-1);
srcs//physic_engine/report_collisions.c:110:	while (i < env->maps[env->scene].nmesh)
srcs//physic_engine/report_collisions.c:112:		if (check_coll_cam(&env->maps[env->scene].meshs, i, cam, &c))
srcs//physic_engine/report_collisions.c:115:			if (push_dynarray(&env->phy_env.collides_cam, &c, false))
srcs//physic_engine/report_collisions.c:116:					return (-1);
srcs//physic_engine/report_collisions.c:130:	if (env->phy_env.collides.byte_size == 0
srcs//physic_engine/report_collisions.c:131:		&& init_dynarray(&env->phy_env.collides,
srcs//physic_engine/report_collisions.c:132:		sizeof(t_collide), env->maps[env->scene].nmesh))
srcs//physic_engine/report_collisions.c:133:		return (-1);
srcs//physic_engine/report_collisions.c:134:	while (i < env->maps[env->scene].nmesh)
srcs//physic_engine/report_collisions.c:136:		j = -1;
srcs//physic_engine/report_collisions.c:137:		while (++j < env->maps[env->scene].nmesh)
srcs//physic_engine/report_collisions.c:138:			if (i != j && !env->maps[env->scene].stats[i]
srcs//physic_engine/report_collisions.c:139:				&& check_coll(&env->maps[env->scene].meshs, i, j, &c))
srcs//physic_engine/report_collisions.c:143:				if (push_dynarray(&env->phy_env.collides, &c, false))
srcs//physic_engine/report_collisions.c:144:					return (-1);
srcs//physic_engine/report_collisions.c:149://	printf("%d collisions\n", env->phy_env.collides.nb_cells);
srcs//physic_engine/init_bounding_boxs.c:17:	if (p.x - pos.x < min->x)
srcs//physic_engine/init_bounding_boxs.c:18:		min->x = p.x - pos.x;
srcs//physic_engine/init_bounding_boxs.c:19:	else if (p.x - pos.x > max->x)
srcs//physic_engine/init_bounding_boxs.c:20:		max->x = p.x - pos.x;
srcs//physic_engine/init_bounding_boxs.c:22:	if (p.y - pos.y < min->y)
srcs//physic_engine/init_bounding_boxs.c:23:		min->y = p.y - pos.y;
srcs//physic_engine/init_bounding_boxs.c:24:	else if (p.y - pos.y > max->y)
srcs//physic_engine/init_bounding_boxs.c:25:		max->y = p.y - pos.y;
srcs//physic_engine/init_bounding_boxs.c:27:	if (p.z - pos.z < min->z)
srcs//physic_engine/init_bounding_boxs.c:28:		min->z = p.z - pos.z;
srcs//physic_engine/init_bounding_boxs.c:29:	else if (p.z - pos.z > max->z)
srcs//physic_engine/init_bounding_boxs.c:30:		max->z = p.z - pos.z;
srcs//physic_engine/init_bounding_boxs.c:43:	max = (t_vec3d){-INFINITY, -INFINITY, -INFINITY, -INFINITY};
srcs//physic_engine/init_bounding_boxs.c:44:	while (i < m->tris.nb_cells)
srcs//physic_engine/init_bounding_boxs.c:47:		if (!(t = dyacc(&m->tris, i)))
srcs//physic_engine/init_bounding_boxs.c:48:			return (-1);
srcs//physic_engine/init_bounding_boxs.c:51:			cmp_xyz(m->corp.pos, t->points[j], &min, &max);
srcs//physic_engine/init_bounding_boxs.c:56:	m->corp.dims = vec_sub(max, min);
srcs//physic_engine/init_bounding_boxs.c:63:		return (-1);
srcs//physic_engine/init_bounding_boxs.c:64:	m->corp.o = vec_sub(m->corp.pos, vec_fdiv(m->corp.dims, 2.0f));
srcs//physic_engine/bounce.c:23:	while (i < env->maps[env->scene].meshs.nb_cells)
srcs//physic_engine/bounce.c:25:		m = dyacc(&env->maps[env->scene].meshs, i);		
srcs//physic_engine/bounce.c:26:		v = m->corp.v;
srcs//physic_engine/bounce.c:27:		if (env->maps[env->scene].stats[i] == false && vec_norm(v) > 900)
srcs//physic_engine/bounce.c:29:			env->maps[env->scene].stats[i] = true;
srcs//physic_engine/bounce.c:31:			env->phy_env.tps = 0;
srcs//physic_engine/bounce.c:43:		printf("name = %s\n", m->name);
srcs//physic_engine/bounce.c:44:		printf("------v%f %f %f-------\n",m->corp.v.x, m->corp.v.y, m->corp.v.z);
srcs//physic_engine/bounce.c:45:		printf("------vo %f %f %f-------\n",m->corp.vo.x, m->corp.vo.y, m->corp.vo.z);
srcs//physic_engine/bounce.c:46:		printf("------pos %f %f %f-------\n",m->corp.pos.x, m->corp.pos.y, m->corp.pos.z);
srcs//physic_engine/bounce.c:48:		printf("state = %d\n", env->maps[env->scene].stats[i]);
srcs//physic_engine/bounce.c:60:	delta = vec_fmult(delta, -1);
srcs//physic_engine/bounce.c:69:	i = -1;
srcs//physic_engine/bounce.c:75:	//	printf("------------------------\n");
srcs//physic_engine/bounce.c:76:	//	printf("m_face = %s \n",m_face->name);
srcs//physic_engine/bounce.c:77:	//	printf("m.x = %f m.y = %f m.z = %f\n",m->corp.pos.x, m->corp.pos.y, m->corp.pos.z);
srcs//physic_engine/bounce.c:78:	//	printf("m_face.x = %f m_face.y = %f m_face.z = %f\n",m_face->corp.pos.x, m_face->corp.pos.y, m_face->corp.pos.z);
srcs//physic_engine/bounce.c:93:	pos = &m->corp.pos;
srcs//physic_engine/bounce.c:95: 	while (i < env->maps[env->scene].meshs.nb_cells)
srcs//physic_engine/bounce.c:97:		m_face = dyacc(&env->maps[env->scene].meshs, i);
srcs//physic_engine/bounce.c:98:		dif = vec_sub(m_face->corp.pos, *pos);
srcs//physic_engine/bounce.c:99:		if (env->maps[env->scene].stats[i] == true && j != i
srcs//physic_engine/bounce.c:109:	if (m->corp.pos.y > 0)
srcs//physic_engine/bounce.c:123:	m = dyacc(&env->maps[env->scene].meshs, c->i_b);
srcs//physic_engine/bounce.c:124:	if (c->dot > 0 && m->corp.norm.y == 1.0f)
srcs//physic_engine/move_mesh.c:22:	while (i < m->tris.nb_cells)
srcs//physic_engine/move_mesh.c:24:		tri = dyacc(&m->tris, i);
srcs//physic_engine/move_mesh.c:25:		tri->points[0] = vec_add(tri->points[0], t);
srcs//physic_engine/move_mesh.c:26:		tri->points[1] = vec_add(tri->points[1], t);
srcs//physic_engine/move_mesh.c:27:		tri->points[2] = vec_add(tri->points[2], t);
srcs//physic_engine/move_mesh.c:31:	while (map && i < m->deps.nb_cells)
srcs//physic_engine/move_mesh.c:33:		d = dyacc(&map->meshs, *(int*)dyacc(&m->deps, i));
srcs//physic_engine/move_mesh.c:37:	m->corp.pos = vec_add(m->corp.pos, t);
srcs//physic_engine/move_mesh.c:38:	m->corp.o = vec_add(m->corp.o, t);
srcs//physic_engine/move_mesh.c:47:	while (i < m->tris.nb_cells)
srcs//physic_engine/move_mesh.c:49:		tri = dyacc(&m->tris, i);
srcs//physic_engine/move_mesh.c:50:		print_vec(tri->points[0]);
srcs//physic_engine/move_mesh.c:51:		print_vec(tri->points[1]);
srcs//physic_engine/move_mesh.c:52:		print_vec(tri->points[2]);
srcs//physic_engine/move_mesh.c:55:	if (i == m->tris.nb_cells)
srcs//physic_engine/move_mesh.c:67:	diff = vec_sub(m->corp.pos, p);
srcs//physic_engine/move_mesh.c:68:	while (i < m->tris.nb_cells)
srcs//physic_engine/move_mesh.c:70:		tri = dyacc(&m->tris, i);
srcs//physic_engine/move_mesh.c:71:		tri->points[0] = vec_add(tri->points[0], diff);
srcs//physic_engine/move_mesh.c:72:		tri->points[1] = vec_add(tri->points[1], diff);
srcs//physic_engine/move_mesh.c:73:		tri->points[2] = vec_add(tri->points[2], diff);
srcs//physic_engine/move_mesh.c:76:	m->corp.pos = p;
srcs//physic_engine/move_mesh.c:77:	m->corp.o = vec_add(m->corp.o, diff);
srcs//physic_engine/phy_gravity.c:20:	gravitax = (t_vec3d){0, env->phy_env.tps * env->phy_env.gravity * 50 , 0 ,0};
srcs//physic_engine/phy_gravity.c:21:	m->corp.v = vec_sub(m->corp.v, gravitax);
srcs//physic_engine/phy_gravity.c:22:	if (env->phy_env.tps < 10)
srcs//physic_engine/phy_gravity.c:23:		env->phy_env.tps += 2.5;
srcs//physic_engine/phy_gravity.c:26:		if (stats->pos.y < -10)
srcs//physic_engine/phy_gravity.c:28:			env->phy_env.tps = 0;
srcs//physic_engine/phy_gravity.c:29:			stats->pos = zero_vector();
srcs//physic_engine/phy_gravity.c:30:			m->corp.v = zero_vector();
srcs//physic_engine/phy_gravity.c:40:	gravitax = (t_vec3d){0, env->phy_env.tps * env->phy_env.gravity , 0 ,0};
srcs//physic_engine/phy_gravity.c:41:	if (env->maps[env->scene].stats[i] == false)
srcs//physic_engine/phy_gravity.c:43:		m->corp.v = vec_sub(m->corp.v, gravitax);
srcs//physic_engine/phy_gravity.c:44:		if (env->phy_env.tps < 900)
srcs//physic_engine/phy_gravity.c:45:			env->phy_env.tps++;
Binary file srcs//vectors/vec3d_ops.o matches
srcs//vectors/vec3d_tools.c:28:	ret.x = (a.y * b.z) - (a.z * b.y);
srcs//vectors/vec3d_tools.c:29:	ret.y = (a.z * b.x) - (a.x * b.z);
srcs//vectors/vec3d_tools.c:30:	ret.z = (a.x * b.y) - (a.y * b.x);
srcs//vectors/vec3d_tools.c:95:	tmp = (v.x - o.x);
srcs//vectors/vec3d_tools.c:97:	tmp = (v.y - o.y);
srcs//vectors/vec3d_tools.c:99:	tmp = (v.z - o.z);
Binary file srcs//vectors/vectors.o matches
srcs//vectors/vec3d_ops.c:29:	ret.x = a.x - b.x;
srcs//vectors/vec3d_ops.c:30:	ret.y = a.y - b.y;
srcs//vectors/vec3d_ops.c:31:	ret.z = a.z - b.z;
Binary file srcs//vectors/vec3d_tools.o matches
Binary file srcs//vectors/vec2d_tools.o matches
srcs//vectors/vectors.c:14:	plane_d = -vec_dot(plane_n, plane_p);
srcs//vectors/vectors.c:18:	t = (-plane_d - ad) / (bd - ad);
srcs//vectors/vectors.c:32:	ret -= vec_dot(plane_n, plane_p);
srcs//openal.c:12:		alGenBuffers(1, &s->buffer);
srcs//openal.c:13:		alBufferData(s->buffer, s->format, s->sample, s->nb_samples * (int)sizeof(ALshort), s->sample_rate);
srcs//openal.c:15:			return (-1);
srcs//openal.c:29:			return (-1);
srcs//openal.c:32:			return (-1);
srcs//openal.c:62:		ft_putchar(i == SA_MAX - 1 ? '\0' : '\r');
srcs//openal.c:74:	if (!(env->device = alcOpenDevice(NULL)))
srcs//openal.c:77:		return (-1);
srcs//openal.c:79:	if (!(env->context = alcCreateContext(env->device, NULL)))
srcs//openal.c:82:		return (-1);
srcs//openal.c:84:	if (!(alcMakeContextCurrent(env->context)))
srcs//openal.c:87:		return (-1);
srcs//openal.c:90:	if (!(env->samples = load_samples()))
srcs//openal.c:91:		return (-1);
Binary file srcs//play_sound.o matches
srcs//setup.c:18:	gettimeofday(&data->time, NULL);
srcs//setup.c:19:	data->half_wdt = (float)WDT / 2;
srcs//setup.c:20:	data->half_hgt = (float)HGT / 2;
srcs//setup.c:21:	data->data_size = WDT * HGT * sizeof(int);
srcs//setup.c:27:		return (-1);
srcs//setup.c:29:		return (-1);
srcs//setup.c:31:		return (-1);
srcs//setup.c:33:		return (-1);
srcs//setup.c:42:		return (-1);
srcs//setup.c:44:	if (init_mlx(env) != 0 || !(env->sprites = load_sprites(&env->mlx))
srcs//setup.c:45:		|| init_openal(&env->sound) != 0 || load_maps(env) != 0
srcs//setup.c:47:		|| init_camera(env, &env->cam) || load_fonts(env)
srcs//setup.c:49:		return (-1);
srcs//setup.c:50:	load_values(env, &env->data);
Binary file srcs//resources_paths.o matches
srcs//dev_handle_events.c:29:	i = -1;
srcs//dev_handle_events.c:33:		diff = vec_sub(cam_stat.pos, tri->points[i]);
srcs//dev_handle_events.c:47:	u = vec_sub(tri->points[0], tri->points[1]);
srcs//dev_handle_events.c:49:	v = vec_sub(tri->points[1], tri->points[2]);
srcs//dev_handle_events.c:51:	w = vec_sub(tri->points[2], tri->points[0]);
srcs//dev_handle_events.c:61:	i = -1;
srcs//dev_handle_events.c:62:	printf("nb_triangle %d \n",m->tris.nb_cells);
srcs//dev_handle_events.c:63:	while (++i < m->tris.nb_cells)
srcs//dev_handle_events.c:66:		print_vect_face(dyacc(&m->tris, i), cam_stat);	
srcs//dev_handle_events.c:85:	tri = dyacc(&m->tris, 0);
srcs//dev_handle_events.c:86:	x = tri->points[0];
srcs//dev_handle_events.c:87:	y = tri->points[1];
srcs//dev_handle_events.c:88:	z = tri->points[2];
srcs//dev_handle_events.c:103:	new_dir->y = step_dir.y;
srcs//dev_handle_events.c:116:	b = c->a;
srcs//dev_handle_events.c:125:	diff = cam_vec->y - c.a->corp.pos.y;
srcs//dev_handle_events.c:128:		cam_vec->y += 0.1;
srcs//dev_handle_events.c:137:	cam_stats = env->cam.stats;
srcs//dev_handle_events.c:142:		f = fps_move_print(&env->maps[env->scene].cam_floor, env->cam.stats.dir, cam_stats);
srcs//dev_handle_events.c:155:	cam = c->b;
srcs//dev_handle_events.c:156:	wall = *(c->a);
srcs//dev_handle_events.c:158:	if (vec_dot(f, norm_wall) < 0 && c->i_a != 0)
srcs//dev_handle_events.c:172:	cam = &env->maps[env->scene].cam;
srcs//dev_handle_events.c:174:	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, 0}, env->cam.stats.aspect_ratio);
srcs//dev_handle_events.c:182:		f = vec_add(f, vec_fmult(f, -3.0f));
srcs//dev_handle_events.c:186:		f = vec_add(f, vec_fmult(r, -3.0f));
srcs//dev_handle_events.c:187:	if (env->cam.stats.onwall == 1)
srcs//dev_handle_events.c:188:		f =	test_dist_wall(env, &env->maps[env->scene].cam_wall, f);
srcs//dev_handle_events.c:189:	env->cam.stats.pos = vec_add(env->cam.stats.pos, f);
srcs//dev_handle_events.c:190:	cam->corp.o = vec_sub(env->cam.stats.pos, vec_fdiv(cam->corp.dims, 2.0f));
srcs//dev_handle_events.c:191:	cam->corp.v = f;
srcs//dev_handle_events.c:208:	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
srcs//dev_handle_events.c:209:	r = vec_fdiv((t_vec3d){f.z, 0, -f.x, f.w}, env->cam.stats.aspect_ratio); 
srcs//dev_handle_events.c:211:		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
srcs//dev_handle_events.c:213:		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
srcs//dev_handle_events.c:215:		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
srcs//dev_handle_events.c:217:		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));
srcs//dev_handle_events.c:230:	cam_stats = env->cam.stats;
srcs//dev_handle_events.c:231:	cam = &env->maps[env->scene].cam;
srcs//dev_handle_events.c:232:	dir = env->cam.stats.dir;
srcs//dev_handle_events.c:233:	pos = env->cam.stats.pos;
srcs//dev_handle_events.c:234:	print_vec(cam->corp.dims);
srcs//dev_handle_events.c:235:	if (key_move(e->keys)  &&  move_i == 1)
srcs//dev_handle_events.c:236:		move(env, e->keys);
srcs//dev_handle_events.c:238:		fake_move(env, e->keys);
srcs//dev_handle_events.c:240:	printf("----------dir---------\n");
srcs//dev_handle_events.c:242:	printf("----------pos---------\n");
srcs//dev_handle_events.c:250:	e = &env->events;
Binary file srcs//scroll_file.o matches
srcs//main.c:17://	system("leaks doom-nukem");
srcs//main.c:33:		return (-1);
srcs//main.c:37:		env->weapons[i].ammos = 100;
srcs//main.c:38:		push_dynarray(&env->player.weapons, &env->weapons[i], false);
srcs//main.c:41:	env->player.current = dyacc(&env->player.weapons, W_FAMAS);
srcs//main.c:43:	env->context = C_TITLE_SCREEN;
srcs//main.c:44:	env->scene = 0;
srcs//main.c:45:	mlx_mouse_move(env->mlx.mlx_win, WDT / 2, HGT / 2);
srcs//main.c:46:	mlx_do_key_autorepeatoff(env->mlx.mlx_ptr);
srcs//free.c:17:	if (m->name)
srcs//free.c:18:		free(m->name);
srcs//free.c:19:	if (m->tris.byte_size)
srcs//free.c:20:		free_dynarray(&m->tris);
srcs//free.c:21:	if (m->deps.byte_size)
srcs//free.c:22:		free_dynarray(&m->deps);
srcs//free.c:32:	while (i < map->meshs.nb_cells)
srcs//free.c:34:		m = dyacc(&map->meshs, i);
srcs//free.c:39:	while (i < map->mtls.nb_cells)
srcs//free.c:41:		mtl = dyacc(&map->mtls, i);
srcs//free.c:42:		free(mtl->name);
srcs//free.c:50:	if (map->meshs.byte_size)
srcs//free.c:51:		free_dynarray(&map->meshs);
srcs//free.c:52:	if (map->txts.byte_size)
srcs//free.c:53:		free_dynarray(&map->txts);
srcs//free.c:54:	if (map->mtls.byte_size)
srcs//free.c:55:		free_dynarray(&map->mtls);
srcs//free.c:56:	if (map->stats)
srcs//free.c:57:		free(map->stats);
srcs//free.c:58:	if (map->stats_cpy)
srcs//free.c:59:		free(map->stats_cpy);
srcs//free.c:66:	if (cam->clip_arrs[0].byte_size)
srcs//free.c:68:		i = -1;
srcs//free.c:70:			free_dynarray(&cam->clip_arrs[i]);
srcs//free.c:72:	if (cam->to_clip.byte_size)
srcs//free.c:73:		free_dynarray(&cam->to_clip);
srcs//free.c:74:	if (cam->to_raster.byte_size)
srcs//free.c:75:		free_dynarray(&cam->to_raster);
srcs//free.c:76:	if (cam->z_buffer)
srcs//free.c:77:		free(cam->z_buffer);
srcs//free.c:87:		free(env->ttfs.fields[i].name);
srcs//free.c:88:		free_dynarray(&env->ttfs.fields[i].str);
srcs//free.c:100:	while (i < p->weapons.nb_cells)
srcs//free.c:102:		w = dyacc(&p->weapons, i);
srcs//free.c:103:		free(w->name);
srcs//free.c:106:	if (p->weapons.byte_size)
srcs//free.c:107:		free_dynarray(&p->weapons);
srcs//free.c:117:	free_player(&env->player);
srcs//free.c:118:	if (env->custom_env.mobs.byte_size)
srcs//free.c:119:		free_dynarray(&env->custom_env.mobs);
srcs//free.c:120:	if (env->astar.d_nodes.byte_size)
srcs//free.c:121:		free_dynarray(&env->astar.d_nodes);
srcs//free.c:122:	if (env->astar.d_astar.byte_size)
srcs//free.c:123:		free_dynarray(&env->astar.d_astar);
srcs//free.c:124:	if (env->edit_env.map.meshs.byte_size)
srcs//free.c:125:		free_map(&env->edit_env.map);
srcs//free.c:130:	if (env->edit_env.map.meshs.byte_size)
srcs//free.c:131:		free_map(&env->edit_env.map);
srcs//free.c:143:	free_cam(&env->cam);
srcs//free.c:148:			free_map(&env->maps[i]);
srcs//free.c:149:		mlx_destroy_image(env->mlx.mlx_ptr, env->sprites[i].img_ptr);
srcs//free.c:153:	if (free_context[env->context])
srcs//free.c:154:		free_context[env->context](env);
srcs//campaign/game.c:8:	f = vec_fmult(env->cam.stats.dir, WALK_SPEED);
srcs//campaign/game.c:9:	r = (t_vec3d){f.z, 0, -f.x, f.w};
srcs//campaign/game.c:11:		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(f, 3.0f));
srcs//campaign/game.c:13:		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(f, 3.0f));
srcs//campaign/game.c:15:		env->cam.stats.pos = vec_add(env->cam.stats.pos, vec_fmult(r, 3.0f));
srcs//campaign/game.c:17:		env->cam.stats.pos = vec_sub(env->cam.stats.pos, vec_fmult(r, 3.0f));
srcs//campaign/game.c:22:	if ((e->keys[KEY_W] || e->keys[KEY_S] || e->keys[KEY_A] || e->keys[KEY_D]))
srcs//campaign/game.c:23:		move(env, e->keys);
srcs//campaign/game.c:29:	e->buttons[BUTTON_SCROLL_UP] = false;
srcs//campaign/game.c:30:	e->buttons[BUTTON_SCROLL_DOWN] = false;
srcs//campaign/game.c:37:	e = &env->events;
srcs//campaign/game.c:49:	cmp_env = &env->cmp_env;
srcs//campaign/game.c:50:	env->scene = cmp_env->sectors[cmp_env->sector].map;
srcs//campaign/game.c:55:	assert(!rasterizer(env, &env->maps[env->scene], false));
srcs//campaign/game.c:57:	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
srcs//campaign/game.c:59:	translate_mesh(env->player.current->w_map,
srcs//campaign/game.c:60:		env->player.current->w_map->meshs.c,
srcs//campaign/sectors.c:7:	cmp_env = &env->cmp_env;
srcs//campaign/sectors.c:8:	cmp_env->sectors[SECTOR_AXIS].map = SCENE_AXIS;
srcs//campaign/sectors.c:9:	cmp_env->sectors[SECTOR_CUBE].map = SCENE_CUBE;
srcs//campaign/sectors.c:10:	cmp_env->sectors[SECTOR_TEST].map = SCENE_MAP_TEST;
srcs//campaign/sectors.c:11:	cmp_env->sectors[SECTOR_SLENDER].map = SCENE_SLENDER;
srcs//campaign/sectors.c:13:	cmp_env->sectors[SECTOR_FAMAS].map = SCENE_FAMAS;
srcs//campaign/sectors.c:14:	cmp_env->sectors[SECTOR_AK47].map = SCENE_AK47;
srcs//campaign/sectors.c:15:	cmp_env->sectors[SECTOR_SAWED_OFF].map = SCENE_SAWED_OFF;
srcs//campaign/sectors.c:16:	cmp_env->sectors[SECTOR_GLOCK_18].map = SCENE_GLOCK_18;
srcs//campaign/sectors.c:17:	cmp_env->sectors[SECTOR_AUG].map = SCENE_AUG;
srcs//campaign/sectors.c:18:	cmp_env->sectors[SECTOR_UMP45].map = SCENE_UMP45;
srcs//campaign/sectors.c:19:	cmp_env->sectors[SECTOR_MAG7].map = SCENE_MAG7;
srcs//campaign/sectors.c:20:	cmp_env->sectors[SECTOR_GALIL].map = SCENE_GALIL;
srcs//campaign/sectors.c:21:	cmp_env->sectors[SECTOR_NEGEV].map = SCENE_NEGEV;
srcs//campaign/sectors.c:22:	cmp_env->sectors[SECTOR_TEC9].map = SCENE_TEC9;
srcs//campaign/sectors.c:23:	cmp_env->sectors[SECTOR_UGLY].map = SCENE_UGLY;
srcs//campaign/sectors.c:24:	//cmp_env->sectors[SECTOR_].map = SCENE_;
srcs//campaign/sectors.c:37:		dist = cmp_env->sectors[cmp_env->sector].doors[i].max_dist;
srcs//campaign/sectors.c:38:		door_pos = cmp_env->sectors[cmp_env->sector].doors[i].pos;
srcs//campaign/sectors.c:39://		if (vec_sdist(env->cam.stats.pos,  door_pos) < dist)
srcs//campaign/setup_cmp.c:21:	cmp_env = &env->cmp_env;
srcs//campaign/setup_cmp.c:22:	b = &cmp_env->buttons[CMP_BUTTON_MAIN_MENU];
srcs//campaign/setup_cmp.c:23:	sps[0] = &env->sprites[SP_CP_BUTTON_1C];
srcs//campaign/setup_cmp.c:24:	sps[1] = &env->sprites[SP_CP_BUTTON_1H];
srcs//campaign/setup_cmp.c:25:	sps[2] = &env->sprites[SP_CP_BUTTON_1O];
srcs//campaign/setup_cmp.c:28:	b = &cmp_env->buttons[CMP_BUTTON_NEW_GAME];
srcs//campaign/setup_cmp.c:29:	sps[0] = &env->sprites[SP_CP_BUTTON_2C];
srcs//campaign/setup_cmp.c:30:	sps[1] = &env->sprites[SP_CP_BUTTON_2H];
srcs//campaign/setup_cmp.c:31:	sps[2] = &env->sprites[SP_CP_BUTTON_2O];
srcs//campaign/setup_cmp.c:37:	env->ts_env.env = env;
srcs//campaign/menu.c:8:	i = -1;
srcs//campaign/menu.c:9:	if (env->events.keys[KEY_ESCAPE])
srcs//campaign/menu.c:12:		if (is_on_button(env->events.mouse_pos, env->cmp_env.buttons[i]))
srcs//campaign/menu.c:14:			if (!env->events.buttons[BUTTON_LCLIC] && clic)
srcs//campaign/menu.c:23:			clic = env->events.buttons[BUTTON_LCLIC];
srcs//campaign/menu.c:24:			env->cmp_env.buttons[i].is_hover = true;
srcs//campaign/menu.c:27:			env->cmp_env.buttons[i].is_hover = false;
srcs//campaign/menu.c:33:	render_button(env, env->cmp_env.buttons[CMP_BUTTON_MAIN_MENU]);
srcs//campaign/menu.c:34:	render_button(env, env->cmp_env.buttons[CMP_BUTTON_NEW_GAME]);
srcs//campaign/menu.c:43:	if (env->events.keys[KEY_M])
srcs//campaign/menu.c:46:	map_sprite(env->mlx.img_data, env->sprites[SP_CMP_TS_BACKGROUND], (t_point){0, 0});
srcs//campaign/menu.c:47:	map_sprite(env->mlx.img_data, env->sprites[SP_CMP_MENU_TXT], (t_point){0, 0});
srcs//campaign/menu.c:50:	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
Binary file srcs//campaign/routines.o matches
Binary file srcs//campaign/events.o matches
srcs//campaign/render.c:27:	cmp_env = &env->cmp_env;
srcs//campaign/render.c:33:		return (-1);
srcs//campaign/render.c:35:	if (cmp_routines[cmp_env->sub_context][i])
srcs//campaign/render.c:36:		cmp_routines[cmp_env->sub_context][i](env);
srcs//campaign/render.c:37:	cmp_env->sub_context = i;
srcs//campaign/render.c:48:	return (cmp_sub_contexts[env->cmp_env.sub_context](env));
Binary file srcs//campaign/game.o matches
Binary file srcs//campaign/sectors.o matches
Binary file srcs//campaign/menu.o matches
Binary file srcs//campaign/setup_cmp.o matches
srcs//campaign/events.c:23:		env->cmp_env.sector++;
srcs//campaign/events.c:24:		if (env->cmp_env.sector == SECTOR_MAX)
srcs//campaign/events.c:25:			env->cmp_env.sector = 0;
srcs//campaign/events.c:44:	env = &((t_env*)param)->cmp_env;
srcs//campaign/events.c:69:	env->events.mouse_pos = (t_point){x, y};
Binary file srcs//campaign/render.o matches
srcs//text.c:17:		pos = ((o.y + (y - 1)) * WDT + o.x) * 4;
srcs//text.c:21:		while (x < bmp.pitch - 3)
srcs//text.c:53:		while (x < bmp.pitch - 3)
srcs//text.c:82:	if (!(ttf->kernings[font].left_pad = (float*)malloc(sizeof(float) * 127))
srcs//text.c:83:		|| !(ttf->kernings[font].right_pad = (float*)malloc(sizeof(float) * 127)))
srcs//text.c:84:		return (-1);
srcs//text.c:89:		slot = face->glyph;
srcs//text.c:90:		ttf->kernings[font].left_pad[(int)c] = INFINITY;
srcs//text.c:91:		ttf->kernings[font].right_pad[(int)c] = -INFINITY;
srcs//text.c:92:		get_glyph_pads(&ttf->kernings[font].left_pad[(int)c],
srcs//text.c:93:			&ttf->kernings[font].right_pad[(int)c], slot->bitmap);
srcs//text.c:108:	ttf = &env->ttfs;
srcs//text.c:109:	FT_Set_Char_Size(ttf->faces[font], conf->size * 96, conf->size * 64, 160, 80);
srcs//text.c:110:	while (conf->s[i])
srcs//text.c:112:		if (i == 0 || conf->s[i - 1] != conf->s[i])
srcs//text.c:113:			if (FT_Load_Char(ttf->faces[font], conf->s[i], FT_LOAD_RENDER) && ++i)
srcs//text.c:115:		slot = ttf->faces[font]->glyph;
srcs//text.c:116:		if (conf->s[i] == 'j')
srcs//text.c:117:			o.x += conf->size / 2;
srcs//text.c:118:		map_letter(img, slot->bitmap,
srcs//text.c:119:			(t_point){o.x + slot->bitmap_left, o.y - slot->bitmap_top});
srcs//text.c:120:		if (conf->s[i] == ' ')
srcs//text.c:121:			o.x += conf->size;
srcs//text.c:123:			o.x += slot->bitmap.width * ttf->kernings[font].right_pad[(int)conf->s[i]] + conf->size / 3;
srcs//text.c:124:		o.y += slot->advance.y >> 6;
srcs//text.c:136:	conf->size = 20;
srcs//text.c:137:	ft_strcpy((char*)conf->s, "Press ");
srcs//text.c:138:	ft_strncat((char*)conf->s, &button, 1);
srcs//text.c:139:	ft_strcat((char*)conf->s, " to ");
srcs//text.c:140:	ft_strcat((char*)conf->s, action);
srcs//text.c:142:	x_offset = (ft_strlen((char*)conf->s)) / 2 * conf->size;
srcs//text.c:143:	o.x = env->data.half_wdt - x_offset;
srcs//text.c:144:	o.y = HGT / 3 + (index * conf->size * 2);
srcs//text.c:146:	my_string_put(env, env->mlx.img_data, o, FONT_TXT_HINT);
srcs//text.c:156:	ttf = &env->ttfs;
srcs//text.c:157:	if (FT_Init_FreeType(&env->ttfs.fontlib)
srcs//text.c:159:		return (-1);
srcs//text.c:160:	while (i < FONT_MAX - 1)
srcs//text.c:162:		if ((err = FT_New_Face(ttf->fontlib,
srcs//text.c:163:			fonts_paths(i), 0, &ttf->faces[i])))
srcs//text.c:167:			return (-1);
srcs//text.c:169:		if (compute_kernings(ttf, ttf->faces[i], i))
srcs//text.c:170:			return (-1);
srcs//dev_events.c:11:		env->context = C_TITLE_SCREEN;
srcs//dev_events.c:14:		env->scene++;
srcs//dev_events.c:15:		if (env->scene == SCENE_MAX)
srcs//dev_events.c:16:			env->scene = 0;
srcs//dev_events.c:55:	env->events.mouse_pos.x = x;
srcs//dev_events.c:56:	env->events.mouse_pos.y = y;
srcs//dev_events.c:71:	//printf("%f %f\n", env->cam.stats.pitch, env->cam.stats.yaw);
srcs//dev_events.c:72:	//printf("%f %f %f | %f %f\n", env->cam.stats.pos.x, env->cam.stats.pos.y, env->cam.stats.pos.z, env->cam.stats.yaw, env->cam.stats.pitch);
srcs//dev_events.c:76:	if (rasterizer(env, &env->maps[env->scene], false))
srcs//dev_events.c:79:	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
Binary file srcs//mlx/sprites_effects.o matches
srcs//mlx/term_loading_bar.c:29:		ft_putchar('-');
srcs//mlx/term_loading_bar.c:35:	while (j < max - 1)
Binary file srcs//mlx/bresenham.o matches
Binary file srcs//mlx/hooks.o matches
srcs//mlx/basics.c:68:		return (-1);
srcs//mlx/basics.c:70:		return (-1);
Binary file srcs//mlx/events.o matches
srcs//mlx/sprites.c:65:		while (x < wdt - 1)
srcs//mlx/sprites.c:83:	if (!(txt->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &txt->wdt, &txt->hgt)))
srcs//mlx/sprites.c:86:		return (-1);
srcs//mlx/sprites.c:88:	if (!(txt->img_data = mlx_get_data_addr(txt->img_ptr, &t, &t, &t)))
srcs//mlx/sprites.c:89:		return (-1);
srcs//mlx/sprites.c:108:		if (!(dest[i].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, sprites_paths(i), &dest[i].wdt, &dest[i].hgt)))
srcs//mlx/sprites.c:112:		if (i < SP_MAX - 1)
srcs//mlx/render.c:25:		return ((double)(clock() - start) / CLOCKS_PER_SEC);
srcs//mlx/render.c:40:	data = &env->data;
srcs//mlx/render.c:42:	data->spent = (t.tv_sec - data->time.tv_sec) * 1000;
srcs//mlx/render.c:43:	data->spent += (t.tv_usec - data->time.tv_usec) / 1000;
srcs//mlx/render.c:44:	data->spent /= 1000;
srcs//mlx/render.c:45:	gettimeofday(&data->time, NULL);
srcs//mlx/render.c:47:	fps += 1 / data->spent;
srcs//mlx/render.c:52:		//system("leaks doom-nukem");
srcs//mlx/render.c:57:	if (env->events.keys[KEY_ESCAPE])
srcs//mlx/render.c:59:	return (render_fts[((t_env*)param)->context](param));
srcs//mlx/init_mlx.c:20:	if (!(env->mlx.mlx_ptr = mlx_init())
srcs//mlx/init_mlx.c:22:		return (-1);
srcs//mlx/init_mlx.c:23:	if (!(env->mlx.mlx_win = mlx_new_window(env->mlx.mlx_ptr, WDT, HGT, WINDOW_NAME))
srcs//mlx/init_mlx.c:25:		return (-1);
srcs//mlx/init_mlx.c:26:	if (!(env->mlx.img_ptr = mlx_new_image(env->mlx.mlx_ptr, WDT, HGT))
srcs//mlx/init_mlx.c:28:		return (-1);
srcs//mlx/init_mlx.c:29:	if (!(env->mlx.img_data = mlx_get_data_addr(env->mlx.img_ptr, &t, &t, &t))
srcs//mlx/init_mlx.c:31:		return (-1);
srcs//mlx/sprites_effects.c:11:	while (i < txt->hgt)
srcs//mlx/sprites_effects.c:13:		j = i * txt->wdt * 4;
srcs//mlx/sprites_effects.c:14:		k = j + (txt->wdt * 4) - 4;
srcs//mlx/sprites_effects.c:17:			pixel = *(int*)&txt->img_data[j];
srcs//mlx/sprites_effects.c:18:			ft_memcpy(&txt->img_data[j], &txt->img_data[k], 4);
srcs//mlx/sprites_effects.c:19:			ft_memcpy(&txt->img_data[k], &pixel, 4);
srcs//mlx/sprites_effects.c:21:			k -= 4;
srcs//mlx/sprites_effects.c:34:	data_size = txt->hgt * txt->wdt * 4;
srcs//mlx/sprites_effects.c:36:	j = data_size - 4;
srcs//mlx/sprites_effects.c:39:		pixel = *(int*)&txt->img_data[i];
srcs//mlx/sprites_effects.c:40:		ft_memcpy(&txt->img_data[i], &txt->img_data[j], 4);
srcs//mlx/sprites_effects.c:41:		ft_memcpy(&txt->img_data[j], &pixel, 4);
srcs//mlx/sprites_effects.c:43:		j -= 4;
srcs//mlx/bresenham.c:10:	delta.x = abs(s.x - f.x);
srcs//mlx/bresenham.c:11:	delta.y = abs(s.y - f.y);
srcs//mlx/bresenham.c:12:	sign.x = f.x < s.x ? 1 : -1;
srcs//mlx/bresenham.c:13:	sign.y = f.y < s.y ? 1 : -1;
srcs//mlx/bresenham.c:14:	error[0] = delta.x - delta.y;
srcs//mlx/bresenham.c:18:		draw_pixel(mlx->img_data, cur.x, cur.y, color);
srcs//mlx/bresenham.c:19:		if ((error[1] = error[0] * 2) > -delta.y)
srcs//mlx/bresenham.c:21:			error[0] -= delta.y;
srcs//mlx/hooks.c:25:	win = env->mlx.mlx_win;
srcs//mlx/hooks.c:32:	mlx_loop_hook(env->mlx.mlx_ptr, (int(*)(void))render, env);
srcs//mlx/hooks.c:33:	mlx_loop(env->mlx.mlx_ptr);
Binary file srcs//mlx/term_loading_bar.o matches
Binary file srcs//mlx/sprites.o matches
srcs//mlx/events.c:23:	env->events.keys[key] = true;
srcs//mlx/events.c:24:	return (key_press_fts[env->context](key, param));
srcs//mlx/events.c:33:	env->events.keys[key] = false;
srcs//mlx/events.c:34:	return (key_release_fts[env->context](key, param));
srcs//mlx/events.c:43:	env->events.buttons[button] = true;
srcs//mlx/events.c:44:	return (mouse_press_fts[env->context](button, x, y, param));
srcs//mlx/events.c:53:	env->events.buttons[button] = false;
srcs//mlx/events.c:54:	return (mouse_release_fts[env->context](button, x, y, param));
srcs//mlx/events.c:63:	env->events.mouse_pos = (t_point){x, y};
srcs//mlx/events.c:64:	return (mouse_position_fts[env->context](x, y, param));
Binary file srcs//mlx/basics.o matches
Binary file srcs//mlx/init_mlx.o matches
Binary file srcs//mlx/shapes.o matches
Binary file srcs//mlx/render.o matches
Binary file srcs//openal.o matches
Binary file srcs//title_screen/animation.o matches
srcs//title_screen/buttons.c:17:	button->l_up.x = o.x;
srcs//title_screen/buttons.c:18:	button->l_up.y = o.y;
srcs//title_screen/buttons.c:20:	button->r_up.x = o.x + sp[0]->wdt;
srcs//title_screen/buttons.c:21:	button->r_up.y = o.y;
srcs//title_screen/buttons.c:23:	button->l_down.x = o.x;
srcs//title_screen/buttons.c:24:	button->l_down.y = o.y + sp[0]->hgt;
srcs//title_screen/buttons.c:26:	button->r_down.x = o.x + sp[0]->wdt;
srcs//title_screen/buttons.c:27:	button->r_down.y = o.y + sp[0]->hgt;
srcs//title_screen/buttons.c:29:	button->on = sp[0];
srcs//title_screen/buttons.c:30:	button->hover = sp[1];
srcs//title_screen/buttons.c:31:	button->off = sp[2];
srcs//title_screen/buttons.c:33:	button->is_hover = false;
srcs//title_screen/buttons.c:52:		if (env->events.buttons[BUTTON_LCLIC])
srcs//title_screen/buttons.c:55:			map_sprite(env->mlx.img_data, *sprite, (t_point){button.l_up.x, button.l_up.y});
srcs//title_screen/buttons.c:64:		map_sprite(env->mlx.img_data, *sprite, (t_point){button.l_up.x, button.l_up.y});
Binary file srcs//title_screen/events.o matches
srcs//title_screen/render.c:8:	i = -1;
srcs//title_screen/render.c:10:		if (is_on_button(env->events.mouse_pos, env->ts_env.buttons[i]))
srcs//title_screen/render.c:12:			if (!env->events.buttons[BUTTON_LCLIC] && clic)
srcs//title_screen/render.c:22:			clic = env->events.buttons[BUTTON_LCLIC];
srcs//title_screen/render.c:23:			env->ts_env.buttons[i].is_hover = true;
srcs//title_screen/render.c:26:			env->ts_env.buttons[i].is_hover = false;
srcs//title_screen/render.c:37:		render_button(env, env->ts_env.buttons[i]);
srcs//title_screen/render.c:47:	usleep(13500 - t);
srcs//title_screen/render.c:61:	//loop_sample(env->sound.samples[SA_PNL], frame == 0, false, frame > 0);
srcs//title_screen/render.c:63:	map_sprite(env->mlx.img_data, env->sprites[SP_TS_BACKGROUND], (t_point){0, 0});
srcs//title_screen/render.c:68:		map_sprite(env->mlx.img_data, env->sprites[SP_TS_LOGO], (t_point){180, 50});
srcs//title_screen/render.c:72:	mlx_put_image_to_window(env->mlx.mlx_ptr, env->mlx.mlx_win, env->mlx.img_ptr, 0, 0);
srcs//title_screen/render.c:76:	anim--;
Binary file srcs//title_screen/setup_ts.o matches
srcs//title_screen/animation.c:30:	button->l_up.y += 30;
srcs//title_screen/animation.c:31:	button->l_down.y += 30;
srcs//title_screen/animation.c:32:	button->r_up.y += 30;
srcs//title_screen/animation.c:33:	button->r_down.y += 30;
srcs//title_screen/animation.c:34:	if (check_place(button->l_up, i))
srcs//title_screen/animation.c:35:		button->in_place = true;
srcs//title_screen/animation.c:40:	static int	i = TS_BUTTON_MAX - 1;
srcs//title_screen/animation.c:42:	if (i == -1)
srcs//title_screen/animation.c:44:	if (env->ts_env.buttons[i].in_place)
srcs//title_screen/animation.c:45:		i--;
srcs//title_screen/animation.c:47:		cross_step(&env->ts_env.buttons[i], i);
srcs//title_screen/events.c:52:	env->events.mouse_pos = (t_point){x, y};
Binary file srcs//title_screen/buttons.o matches
srcs//title_screen/setup_ts.c:22:	sp = env->sprites;
srcs//title_screen/setup_ts.c:23:	y_offset = -100;
srcs//title_screen/setup_ts.c:26:		init_button(&env->ts_env.buttons[i],
srcs//title_screen/setup_ts.c:35:	env->ts_env.env = env;
Binary file srcs//title_screen/render.o matches
srcs//enemies/enemies_damages.c:14:	sound = &env->sound.samples[SA_DEATHMONSTER];
srcs//enemies/enemies_damages.c:16:	alSourcei(source, AL_BUFFER, (ALint)sound->buffer);
srcs//enemies/enemies_damages.c:22:	mob->hp -= env->player.current->damages;
srcs//enemies/enemies_damages.c:23:	if (mob->hp < 1)
srcs//enemies/enemies_damages.c:25:		mob->dead = 1;
srcs//enemies/enemies_damages.c:26:		++env->custom_env.game.kill_count;
srcs//enemies/enemies_damages.c:28:		if (env->custom_env.game.kill_delay == 0)
srcs//enemies/enemies_damages.c:29:			env->custom_env.game.kill_delay = KILL_DELAY;
srcs//enemies/enemies_damages.c:33:	env->custom_env.game.moula += mob->dead ? KILL_REWARD : HIT_REWARD;
srcs//enemies/enemies_damages.c:34:	env->player.hitmarker = HITMARKER_T;
srcs//enemies/enemies_damages.c:43:	index = env->mid.mesh->index;
srcs//enemies/enemies_damages.c:44:	i = -1;
srcs//enemies/enemies_damages.c:45:	while (++i < env->custom_env.mobs.nb_cells)
srcs//enemies/enemies_damages.c:47:		mob = dyacc(&env->custom_env.mobs, i);
srcs//enemies/enemies_damages.c:48:		if (index >= mob->map_start && index < mob->map_end)
srcs//enemies/enemies_damages.c:50:			env->player.hover = true;
srcs//enemies/enemies_damages.c:51:			if (env->player.current->shot && !mob->dead)
srcs//enemies/nodes.c:8:    astar_sort_dynarray(&env->d_nodes, nodes_compare);
srcs//enemies/nodes.c:9:    i = -1;
srcs//enemies/nodes.c:10:    while (++i < env->d_nodes.nb_cells)
srcs//enemies/nodes.c:12:        node = dyacc(&env->d_nodes, i);
srcs//enemies/nodes.c:24:    node.i = nodes_3d_1d(env->dim, node.pos);
srcs//enemies/nodes.c:27:    i = -1;
srcs//enemies/nodes.c:29:        node.nghbr[i] = -1;
srcs//enemies/nodes.c:30:    return (push_dynarray(&env->d_nodes, &node, 0));
srcs//enemies/nodes.c:37:    if (init_dynarray(&env->d_nodes, sizeof(t_node),
srcs//enemies/nodes.c:39:        return (-1);
srcs//enemies/nodes.c:40:    env->dim = (t_vec3d){ map.width, map.height, map.depth, 0 };
srcs//enemies/nodes.c:41:    pos[0] = -1;
srcs//enemies/nodes.c:44:        pos[1] = -1;
srcs//enemies/nodes.c:47:            pos[2] = -1;
srcs//enemies/nodes.c:51:                    return (-1);
srcs//enemies/astar_quick_sort.c:5:    return (((t_node *)a)->globalgoal < ((t_node *)b)->globalgoal);
srcs//enemies/astar_quick_sort.c:10:    return (((t_node *)a)->i < ((t_node *)b)->i);
srcs//enemies/astar_quick_sort.c:21:    i = low - 1;
srcs//enemies/astar_quick_sort.c:22:    j = low - 1;
srcs//enemies/astar_quick_sort.c:40:        quicksort(arr, low, pivot - 1, compare);
srcs//enemies/astar_quick_sort.c:48:    quicksort(arr, 0, arr->nb_cells - 1, compare);
srcs//enemies/create_mob.c:15:	enemy->hp = hps[(int)type];
srcs//enemies/create_mob.c:16:	enemy->damages = damages[(int)type];
srcs//enemies/create_mob.c:17:	enemy->speed = speeds[(int)type];
srcs//enemies/create_mob.c:33:	i = -1;
srcs//enemies/create_mob.c:34:	if (!map->txts.byte_size)
srcs//enemies/create_mob.c:36:	while (++i < map->txts.nb_cells)
srcs//enemies/create_mob.c:37:		if (!ft_memcmp(sprite, dyacc(&map->txts, i), sizeof(t_sprite)))
srcs//enemies/create_mob.c:39:			new->sp = i;
srcs//enemies/create_mob.c:52:	if (!map->txts.byte_size && init_dynarray(&map->txts, sizeof(t_sprite), 0))
srcs//enemies/create_mob.c:53:		return (-1);
srcs//enemies/create_mob.c:54:	while (i < m->tris.nb_cells)
srcs//enemies/create_mob.c:56:		ft_memcpy(&t, dyacc(&m->tris, i), sizeof(t_triangle));
srcs//enemies/create_mob.c:59:		if (!handle_texture(map, dyacc(&mob->txts, t.sp), &t))
srcs//enemies/create_mob.c:61:			sprite = dyacc(&mob->txts, t.sp);
srcs//enemies/create_mob.c:62:			if (push_dynarray(&map->txts, sprite, false))
srcs//enemies/create_mob.c:63:				return (-1);
srcs//enemies/create_mob.c:64:			t.sp = map->txts.nb_cells - 1;
srcs//enemies/create_mob.c:67:		if (push_dynarray(&new->tris, &t, false))
srcs//enemies/create_mob.c:68:			return (-1);
srcs//enemies/create_mob.c:81:	enemy->map_start = map->meshs.nb_cells;
srcs//enemies/create_mob.c:82:	enemy->map_end = enemy->map_start + mob->meshs.nb_cells;
srcs//enemies/create_mob.c:83:	while (i < mob->meshs.nb_cells)
srcs//enemies/create_mob.c:86:		m = dyacc(&mob->meshs, i);
srcs//enemies/create_mob.c:88:		new.index = map->nmesh;
srcs//enemies/create_mob.c:91:			|| push_dynarray(&map->meshs, &new, false))
srcs//enemies/create_mob.c:92:			return (-1);
srcs//enemies/create_mob.c:93:		assign_meshs(dyacc(&map->meshs, map->nmesh));
srcs//enemies/create_mob.c:94:		translate_mesh(map, dyacc(&map->meshs, map->nmesh), enemy->pos);
srcs//enemies/create_mob.c:95:		map->nmesh++;
srcs//enemies/create_mob.c:108:	i = mob->map_start - 1;
srcs//enemies/create_mob.c:109:	while (++i < mob->map_end)
srcs//enemies/create_mob.c:111:		mesh = dyacc(&mob->map->meshs, i);
srcs//enemies/create_mob.c:112:		j = -1;
srcs//enemies/create_mob.c:113:		while (++j < mesh->tris.nb_cells)
srcs//enemies/create_mob.c:115:			tri = dyacc(&mesh->tris, j);
srcs//enemies/create_mob.c:116:			tri->points[0] = vec_add(tri->points[0], mob->offset);
srcs//enemies/create_mob.c:117:			tri->points[1] = vec_add(tri->points[1], mob->offset);
srcs//enemies/create_mob.c:118:			tri->points[2] = vec_add(tri->points[2], mob->offset);
srcs//enemies/create_mob.c:136:	enemy.i = nodes_3d_1d(env->astar.dim, vec_fdiv(pos, 2));
srcs//enemies/create_mob.c:139:	if (copy_mob_to_scene(map, &env->maps[enemy_map_mapper(type)], &enemy)
srcs//enemies/create_mob.c:141:		|| push_dynarray(&env->custom_env.mobs, &enemy, false))
srcs//enemies/create_mob.c:142:		return (-1);
srcs//enemies/tools.c:8:    cross = a.x * b.z - a.z * b.x;
srcs//enemies/tools.c:28:    i = -1;
srcs//enemies/tools.c:29:    while (++i < arr->nb_cells)
srcs//enemies/tools.c:32:        tmp = astar_distance(pos, d->pos);
srcs//enemies/tools.c:48:	while (i < m->tris.nb_cells)
srcs//enemies/tools.c:50:		t = dyacc(&m->tris, i);
srcs//enemies/tools.c:51:		t->mesh = m;
Binary file srcs//enemies/enemies_death.o matches
Binary file srcs//enemies/nodes_neighbourgs.o matches
Binary file srcs//enemies/enemies_do_movement.o matches
srcs//enemies/enemies_movements.c:8:	i = -1;
srcs//enemies/enemies_movements.c:11:		node = dyacc(&a->d_nodes, mob->end->nghbr[i]);
srcs//enemies/enemies_movements.c:12:		if (node && node->bobstacle == 0)
srcs//enemies/enemies_movements.c:13:			mob->end = node;
srcs//enemies/enemies_movements.c:19:	return (pos.x < 0 || pos.x > dim.x - 1
srcs//enemies/enemies_movements.c:20:		|| pos.y < 0 || pos.y > dim.y - 1
srcs//enemies/enemies_movements.c:21:		|| pos.z < 0 || pos.z > dim.z - 1);
srcs//enemies/enemies_movements.c:28:	while (astar_distance(mob->goal->pos, mob->end->pos) > 3)
srcs//enemies/enemies_movements.c:30:		end.x = (int)(mob->end->pos.x / 2 + mob->goal->pos.x / 2);
srcs//enemies/enemies_movements.c:31:		end.y = (int)(mob->end->pos.y / 2 + mob->goal->pos.y / 2);
srcs//enemies/enemies_movements.c:32:		end.z = (int)(mob->end->pos.z / 2 + mob->goal->pos.z / 2);
srcs//enemies/enemies_movements.c:33:		if (enemies_vec_outrange(a->dim, end))
srcs//enemies/enemies_movements.c:34:			return (-1);
srcs//enemies/enemies_movements.c:35:		mob->end = dyacc(&a->d_nodes, nodes_3d_1d(a->dim, end));
srcs//enemies/enemies_movements.c:36:		if (mob->end == NULL)
srcs//enemies/enemies_movements.c:37:			return (-1);
srcs//enemies/enemies_movements.c:39:	if (mob->end->bobstacle == 1)
srcs//enemies/enemies_movements.c:41:	return (mob->end->bobstacle);
srcs//enemies/enemies_movements.c:46:	a->end = NULL;
srcs//enemies/enemies_movements.c:47:	mob->end = NULL;
srcs//enemies/enemies_movements.c:48:	if (mob->goal == NULL)
srcs//enemies/enemies_movements.c:53:	if (enemies_vec_outrange(a->dim, cam))
srcs//enemies/enemies_movements.c:55:	if (astar_distance(a->start->pos, cam) < 3)
srcs//enemies/enemies_movements.c:57:	mob->end = dyacc(&a->d_nodes, nodes_3d_1d(a->dim, cam));
srcs//enemies/enemies_movements.c:58:	if (mob->end == NULL)
srcs//enemies/enemies_movements.c:61:		mob->end = NULL;
srcs//enemies/enemies_movements.c:62:	a->end = mob->end;
srcs//enemies/enemies_movements.c:70:	i = -1;
srcs//enemies/enemies_movements.c:71:	while (++i < env->custom_env.mobs.nb_cells)
srcs//enemies/enemies_movements.c:73:		mob = dyacc(&env->custom_env.mobs, i);
srcs//enemies/enemies_movements.c:74:		if (mob->hp < 1)
srcs//enemies/enemies_movements.c:76:		a->start = dyacc(&a->d_nodes, mob->i);
srcs//enemies/enemies_movements.c:77:		if (mob->end == NULL || mob->i == mob->end->i)
srcs//enemies/enemies_movements.c:79:			mob->goal = a->start;
srcs//enemies/enemies_movements.c:80:			enemies_get_end(a, mob, env->cam.stats.pos);
srcs//enemies/enemies_movements.c:82:			if (a->end == NULL || mob->end == NULL || mob->goal == NULL)
srcs//enemies/enemies_movements.c:84:				enemies_last_rotation(mob, env->cam.stats.pos);
srcs//enemies/enemies_movements.c:85:				mob->end = NULL;
Binary file srcs//enemies/enemies_kills_annoucements.o matches
Binary file srcs//enemies/enemies.o matches
srcs//enemies/astar_tools.c:8:	astar = &env->astar;
srcs//enemies/astar_tools.c:9:	map = env->edit_env.new_map;
srcs//enemies/astar_tools.c:10:	if (init_dynarray(&astar->d_astar, sizeof(t_node), 1))
srcs//enemies/astar_tools.c:11:		return (-1);
srcs//enemies/astar_tools.c:13:		return (-1);
srcs//enemies/astar_tools.c:21:    i = -1;
srcs//enemies/astar_tools.c:22:    while (++i < arr->nb_cells)
srcs//enemies/astar_tools.c:24:        if (((t_node *)dyacc(arr, i))->bvisited)
srcs//enemies/astar_tools.c:38:	conv.i = 0x5f3759df - (conv.i >> 1);
srcs//enemies/astar_tools.c:39:	conv.f *= (threehalfs - (i * conv.f * conv.f));
srcs//enemies/astar_tools.c:45:    return (1 / astar_rsqrt((a.x - b.x) * (a.x - b.x)
srcs//enemies/astar_tools.c:46:        + (a.y - b.y) * (a.y - b.y)
srcs//enemies/astar_tools.c:47:        + (a.z - b.z) * (a.z - b.z)));
srcs//enemies/astar_tools.c:55:    i = -1;
srcs//enemies/astar_tools.c:56:    while (++i < env->d_nodes.nb_cells)
srcs//enemies/astar_tools.c:58:        node = dyacc(&env->d_nodes, i);
srcs//enemies/astar_tools.c:59:        node->bvisited = 0;
srcs//enemies/astar_tools.c:60:        node->globalgoal = INFINITY;
srcs//enemies/astar_tools.c:61:        node->localgoal = INFINITY;
srcs//enemies/astar_tools.c:62:        node->parent = NULL;
srcs//enemies/astar_tools.c:64:    clear_dynarray(&env->d_astar);
Binary file srcs//enemies/astar.o matches
Binary file srcs//enemies/enemies_rotations.o matches
Binary file srcs//enemies/nodes.o matches
Binary file srcs//enemies/enemies_damages.o matches
srcs//enemies/enemies_do_movement.c:5:	return (mob->end->parent->parent
srcs//enemies/enemies_do_movement.c:6:		&& mob->end->parent->parent->i == mob->end->i);
srcs//enemies/enemies_do_movement.c:13:	goal = vec_add(mob->goal->pos, mob->goal->pos);
srcs//enemies/enemies_do_movement.c:14:	mob->pitch.x = (goal.x - mob->pos.x) * mob->speed;
srcs//enemies/enemies_do_movement.c:15:	mob->pitch.y = (goal.y - mob->pos.y) * mob->speed;
srcs//enemies/enemies_do_movement.c:16:	mob->pitch.z = (goal.z - mob->pos.z) * mob->speed;
srcs//enemies/enemies_do_movement.c:17:	goal = vec_add(mob->end->pos, mob->end->pos);
srcs//enemies/enemies_do_movement.c:18:	goal = vec_sub(goal, mob->pos);
srcs//enemies/enemies_do_movement.c:19:	mob->yaw = enemies_xz_angle(mob->head, goal) * mob->speed;
srcs//enemies/enemies_do_movement.c:24:	while (mob->end && mob->end->i != mob->goal->i)
srcs//enemies/enemies_do_movement.c:26:		if (mob->end->parent == NULL)
srcs//enemies/enemies_do_movement.c:28:		if (mob->end->parent->i == mob->goal->i)
srcs//enemies/enemies_do_movement.c:30:			mob->goal = mob->end;
srcs//enemies/enemies_do_movement.c:36:			mob->end = NULL;
srcs//enemies/enemies_do_movement.c:39:		mob->end = mob->end->parent;
srcs//enemies/enemies_do_movement.c:48:	if (mob->i == mob->goal->i)
srcs//enemies/enemies_do_movement.c:50:	mob->pos = vec_add(mob->pos, mob->pitch);
srcs//enemies/enemies_do_movement.c:51:	fcos = cos(mob->yaw);
srcs//enemies/enemies_do_movement.c:52:	fsin = sin(mob->yaw);
srcs//enemies/enemies_do_movement.c:60:	mob->goal->bobstacle = 0;
srcs//enemies/enemies_do_movement.c:61:	if (mob->i == mob->goal->i)
srcs//enemies/enemies_do_movement.c:63:	if (mob->end == NULL)
srcs//enemies/enemies_do_movement.c:66:	goal = vec_add(mob->goal->pos, mob->goal->pos);
srcs//enemies/enemies_do_movement.c:67:	if (astar_distance(goal, mob->pos) < 0.1f)
srcs//enemies/enemies_do_movement.c:68:		mob->i = mob->goal->i;
srcs//enemies/enemies_do_movement.c:69:	mob->goal->bobstacle = 1;
Binary file srcs//enemies/tools.o matches
srcs//enemies/enemies_death.c:8:	i = mob->map_start;
srcs//enemies/enemies_death.c:9:	while (i < mob->map_end)
srcs//enemies/enemies_death.c:11:		m = dyacc(&mob->map->meshs, i);
srcs//enemies/enemies_death.c:12:		m->index -= delta;
srcs//enemies/enemies_death.c:25:	i = mob->map_start - 1;
srcs//enemies/enemies_death.c:26:	while (++i < mob->map_end)
srcs//enemies/enemies_death.c:28:		mesh = dyacc(&mob->map->meshs, mob->map_start);
srcs//enemies/enemies_death.c:30:		extract_dynarray(&mob->map->meshs, mob->map_start);
srcs//enemies/enemies_death.c:31:		--mob->map->nmesh;
srcs//enemies/enemies_death.c:33:	tmp = mob->map_end - mob->map_start;
srcs//enemies/enemies_death.c:35:	while (index < mobs->nb_cells)
srcs//enemies/enemies_death.c:38:		m->map_start -= tmp;
srcs//enemies/enemies_death.c:39:		m->map_end -= tmp;
srcs//enemies/enemies_death.c:52:	if (mob->sum_angle < 1.5f)
srcs//enemies/enemies_death.c:55:		mob->sum_angle += angle;
srcs//enemies/enemies_death.c:58:	if (mob->pos.y > 0)
srcs//enemies/enemies_death.c:60:		mob->pos.y -= 0.3f;
srcs//enemies/enemies_death.c:71:	i = -1;
srcs//enemies/enemies_death.c:72:	while (++i < mobs->nb_cells)
srcs//enemies/enemies_death.c:75:		if (mob->hp < 1)
srcs//enemies/nodes_neighbourgs.c:9:    x = node->pos.x;
srcs//enemies/nodes_neighbourgs.c:10:    y = node->pos.y;
srcs//enemies/nodes_neighbourgs.c:11:    z = node->pos.z;
srcs//enemies/nodes_neighbourgs.c:13:        node->nghbr[6] = nodes_3d_1d(dim, (t_vec3d){ x - 1, y - 1, z, 0 });
srcs//enemies/nodes_neighbourgs.c:14:    if (x < dim.x - 1 && y < dim.y - 1)
srcs//enemies/nodes_neighbourgs.c:15:        node->nghbr[7] = nodes_3d_1d(dim, (t_vec3d){ x + 1, y + 1, z, 0 });
srcs//enemies/nodes_neighbourgs.c:16:    if (x < dim.x - 1 && y > 0)
srcs//enemies/nodes_neighbourgs.c:17:        node->nghbr[8] = nodes_3d_1d(dim, (t_vec3d){ x + 1, y - 1, z, 0 });
srcs//enemies/nodes_neighbourgs.c:18:    if (x > 0 && y < dim.y - 1)
srcs//enemies/nodes_neighbourgs.c:19:        node->nghbr[9] = nodes_3d_1d(dim, (t_vec3d){ x - 1, y + 1, z, 0 });
srcs//enemies/nodes_neighbourgs.c:28:    x = node->pos.x;
srcs//enemies/nodes_neighbourgs.c:29:    y = node->pos.y;
srcs//enemies/nodes_neighbourgs.c:30:    z = node->pos.z;
srcs//enemies/nodes_neighbourgs.c:32:        node->nghbr[10] = nodes_3d_1d(dim, (t_vec3d){ x - 1, y, z - 1, 0 });
srcs//enemies/nodes_neighbourgs.c:33:    if (x < dim.x - 1 && z < dim.z - 1)
srcs//enemies/nodes_neighbourgs.c:34:        node->nghbr[11] = nodes_3d_1d(dim, (t_vec3d){ x + 1, y, z + 1, 0 });
srcs//enemies/nodes_neighbourgs.c:35:    if (x < dim.x - 1 && z > 0)
srcs//enemies/nodes_neighbourgs.c:36:        node->nghbr[12] = nodes_3d_1d(dim, (t_vec3d){ x + 1, y, z - 1, 0 });
srcs//enemies/nodes_neighbourgs.c:37:    if (x > 0 && z < dim.z - 1)
srcs//enemies/nodes_neighbourgs.c:38:        node->nghbr[13] = nodes_3d_1d(dim, (t_vec3d){ x - 1, y, z + 1, 0 }); 
srcs//enemies/nodes_neighbourgs.c:47:    x = node->pos.x;
srcs//enemies/nodes_neighbourgs.c:48:    y = node->pos.y;
srcs//enemies/nodes_neighbourgs.c:49:    z = node->pos.z;
srcs//enemies/nodes_neighbourgs.c:51:        node->nghbr[14] = nodes_3d_1d(dim, (t_vec3d){ x, y - 1, z - 1, 0 });
srcs//enemies/nodes_neighbourgs.c:52:    if (y < dim.y - 1 && z < dim.z - 1)
srcs//enemies/nodes_neighbourgs.c:53:        node->nghbr[15] = nodes_3d_1d(dim, (t_vec3d){ x, y + 1, z + 1, 0 });
srcs//enemies/nodes_neighbourgs.c:54:    if (y < dim.y - 1 && z > 0)
srcs//enemies/nodes_neighbourgs.c:55:        node->nghbr[16] = nodes_3d_1d(dim, (t_vec3d){ x, y + 1, z - 1, 0 });
srcs//enemies/nodes_neighbourgs.c:56:    if (y > 0 && z < dim.z - 1)
srcs//enemies/nodes_neighbourgs.c:57:        node->nghbr[17] = nodes_3d_1d(dim, (t_vec3d){ x, y - 1, z + 1, 0 });
srcs//enemies/nodes_neighbourgs.c:74:    x = node->pos.x;
srcs//enemies/nodes_neighbourgs.c:75:    y = node->pos.y;
srcs//enemies/nodes_neighbourgs.c:76:    z = node->pos.z;
srcs//enemies/nodes_neighbourgs.c:77:    dim = env->dim;
srcs//enemies/nodes_neighbourgs.c:79:        node->nghbr[0] = nodes_3d_1d(dim, (t_vec3d){ x - 1, y, z, 0 });
srcs//enemies/nodes_neighbourgs.c:80:    if (x < dim.x - 1)
srcs//enemies/nodes_neighbourgs.c:81:        node->nghbr[1] = nodes_3d_1d(dim, (t_vec3d){ x + 1, y, z, 0 });
srcs//enemies/nodes_neighbourgs.c:83:        node->nghbr[2] = nodes_3d_1d(dim, (t_vec3d){ x, y - 1, z, 0 });
srcs//enemies/nodes_neighbourgs.c:84:    if (y < dim.y - 1)
srcs//enemies/nodes_neighbourgs.c:85:        node->nghbr[3] = nodes_3d_1d(dim, (t_vec3d){ x, y + 1, z, 0 });
srcs//enemies/nodes_neighbourgs.c:87:        node->nghbr[4] = nodes_3d_1d(dim, (t_vec3d){ x, y, z - 1, 0 });
srcs//enemies/nodes_neighbourgs.c:88:    if (z < dim.z - 1)
srcs//enemies/nodes_neighbourgs.c:89:        node->nghbr[5] = nodes_3d_1d(dim, (t_vec3d){ x, y, z + 1, 0 });
Binary file srcs//enemies/create_mob.o matches
Binary file srcs//enemies/astar_quick_sort.o matches
srcs//enemies/enemies_kills_annoucements.c:9:	if (delay == KILL_DELAY - 1)
srcs//enemies/enemies_kills_annoucements.c:22:	alSourcei(source, AL_BUFFER, (ALint)sound->buffer);
srcs//enemies/enemies_kills_annoucements.c:31:	if (env->custom_env.game.kill_delay > 0)
srcs//enemies/enemies_kills_annoucements.c:32:		--env->custom_env.game.kill_delay;
srcs//enemies/enemies_kills_annoucements.c:33:	if (env->custom_env.game.kill_delay == 0)
srcs//enemies/enemies_kills_annoucements.c:35:		env->custom_env.game.kill_count = 0;
srcs//enemies/enemies_kills_annoucements.c:38:	if (env->custom_env.game.kill_count == 2)
srcs//enemies/enemies_kills_annoucements.c:39:		sound = &env->sound.samples[SA_DOUBLEKILL];
srcs//enemies/enemies_kills_annoucements.c:40:	else if (env->custom_env.game.kill_count == 3)
srcs//enemies/enemies_kills_annoucements.c:41:		sound = &env->sound.samples[SA_TRIPLEKILL];
srcs//enemies/enemies_kills_annoucements.c:42:	else if (env->custom_env.game.kill_count == 4)
srcs//enemies/enemies_kills_annoucements.c:43:		sound = &env->sound.samples[SA_RAMPAGE];
srcs//enemies/enemies_kills_annoucements.c:44:	else if (env->custom_env.game.kill_count == 5)
srcs//enemies/enemies_kills_annoucements.c:45:		sound = &env->sound.samples[SA_GODLIKE];
srcs//enemies/enemies_kills_annoucements.c:46:	else if (env->custom_env.game.kill_count > 5)
srcs//enemies/enemies_kills_annoucements.c:47:		sound = &env->sound.samples[SA_WICKEDSICK];
srcs//enemies/enemies_kills_annoucements.c:48:	play_sound(sound, env->custom_env.game.kill_delay);
Binary file srcs//enemies/enemies_movements.o matches
srcs//enemies/enemies_rotations.c:8:	x = (v->x - m.x) * fcos - (v->z - m.z) * fsin;
srcs//enemies/enemies_rotations.c:9:	z = (v->x - m.x) * fsin + (v->z - m.z) * fcos;
srcs//enemies/enemies_rotations.c:10:	v->x = x + m.x;
srcs//enemies/enemies_rotations.c:11:	v->z = z + m.z;
srcs//enemies/enemies_rotations.c:19:	y = (v->y - m.y) * fcos - (v->z - m.z) * fsin;
srcs//enemies/enemies_rotations.c:20:	z = (v->y - m.y) * fsin + (v->z - m.z) * fcos;
srcs//enemies/enemies_rotations.c:21:	v->y = y + m.y;
srcs//enemies/enemies_rotations.c:22:	v->z = z + m.z;
srcs//enemies/enemies_rotations.c:34:	middle = vec_add(mob->pos, mob->offset);
srcs//enemies/enemies_rotations.c:35:	rotation(&mob->head, (t_vec3d){}, fcos, fsin);
srcs//enemies/enemies_rotations.c:36:	i = mob->map_start - 1;;
srcs//enemies/enemies_rotations.c:37:	while (++i < mob->map_end)
srcs//enemies/enemies_rotations.c:39:		mesh = dyacc(&mob->map->meshs, i);
srcs//enemies/enemies_rotations.c:40:		j = -1;
srcs//enemies/enemies_rotations.c:41:		while (++j < mesh->tris.nb_cells)
srcs//enemies/enemies_rotations.c:43:			tri = dyacc(&mesh->tris, j);
srcs//enemies/enemies_rotations.c:44:			rotation(&tri->points[0], middle, fcos, fsin);
srcs//enemies/enemies_rotations.c:45:			rotation(&tri->points[1], middle, fcos, fsin);
srcs//enemies/enemies_rotations.c:46:			rotation(&tri->points[2], middle, fcos, fsin);
srcs//enemies/enemies_rotations.c:57:	goal = vec_sub(cam, mob->pos);
srcs//enemies/enemies_rotations.c:58:	mob->yaw = enemies_xz_angle(mob->head, goal) * 0.5f;
srcs//enemies/enemies_rotations.c:59:	fcos = cos(mob->yaw);
srcs//enemies/enemies_rotations.c:60:	fsin = sin(mob->yaw);
srcs//enemies/enemies.c:10:	i = -1;
srcs//enemies/enemies.c:11:	while (++i < mobs->nb_cells)
srcs//enemies/enemies.c:14:		j = mob->map_start - 1;
srcs//enemies/enemies.c:15:		while (++j < mob->map_end)
srcs//enemies/enemies.c:17:			m = dyacc(&mob->map->meshs, j);
srcs//enemies/enemies.c:18:			translate_mesh(mob->map, m, vec_sub(mob->pos, m->corp.pos));
srcs//enemies/enemies.c:31:	while (i < events->nb_cells)
srcs//enemies/enemies.c:34:		if (block->id == BE_MOB_SPAWNER)
srcs//enemies/enemies.c:38:			sp[0] = block->x;
srcs//enemies/enemies.c:39:			sp[1] = block->y;
srcs//enemies/enemies.c:40:			sp[2] = block->z;
srcs//enemies/enemies.c:54:	game = &env->custom_env.game;
srcs//enemies/enemies.c:55:	if (game->nb_spawners == 0)
srcs//enemies/enemies.c:57:	index = rand() % game->nb_spawners + 1;
srcs//enemies/enemies.c:58:	find_random_spawner(&env->custom_env.events, p, index);
srcs//enemies/enemies.c:62:	return (create_mob(env, &env->edit_env.map, ENEMY_CUBE, pos));
srcs//enemies/enemies.c:67:	env->player.hover = false;
srcs//enemies/enemies.c:68:	env->player.hitmarker--;
srcs//enemies/enemies.c:69:	if (env->custom_env.spawner <= 0.0f)
srcs//enemies/enemies.c:71:		if (env->custom_env.mobs.nb_cells < MAX_ENEMIES && spawn_mob(env))
srcs//enemies/enemies.c:72:			return (-1);
srcs//enemies/enemies.c:73:		env->custom_env.spawner = RESPAWN_DELAY;
srcs//enemies/enemies.c:76:		env->custom_env.spawner -= env->data.spent;
srcs//enemies/enemies.c:77:	if (env->custom_env.mobs.nb_cells)
srcs//enemies/enemies.c:79:		if (env->mid.mesh)
srcs//enemies/enemies.c:81:		enemies_movements(env, &env->astar);
srcs//enemies/enemies.c:82:		enemies_death(&env->custom_env.mobs);
srcs//enemies/enemies.c:83:		enemies_to_scene(&env->custom_env.mobs);
Binary file srcs//enemies/astar_tools.o matches
srcs//enemies/astar.c:7:    i = -1;
srcs//enemies/astar.c:8:    while (++i < arr->nb_cells)
srcs//enemies/astar.c:10:        if (((t_node *)dyacc(arr, i))->i == ngbhr->i)
srcs//enemies/astar.c:21:    nghbr = dyacc(&env->d_nodes, (*c)->nghbr[i]);
srcs//enemies/astar.c:24:    plowergoal = (*c)->localgoal + astar_distance((*c)->pos, nghbr->pos);
srcs//enemies/astar.c:25:    if (plowergoal < nghbr->localgoal)
srcs//enemies/astar.c:27:        nghbr->localgoal = plowergoal;
srcs//enemies/astar.c:28:        nghbr->globalgoal = nghbr->localgoal
srcs//enemies/astar.c:29:            + astar_distance(nghbr->pos, env->end->pos);
srcs//enemies/astar.c:30:        nghbr->parent = dyacc(&env->d_nodes, (*c)->i);
srcs//enemies/astar.c:32:    if (nghbr->bvisited == 0 && nghbr->bobstacle == 0)
srcs//enemies/astar.c:33:        astar_stock_neighbour(&env->d_astar, nghbr);
srcs//enemies/astar.c:34:    *c = env->d_astar.c;
srcs//enemies/astar.c:39:    if (astar_distance(env->start->pos, current->pos) > 3)
srcs//enemies/astar.c:41:        env->end = NULL;
srcs//enemies/astar.c:44:    return (current->i == env->end->i
srcs//enemies/astar.c:45:        || env->d_astar.nb_cells < 1);
srcs//enemies/astar.c:52:    astar_sort_dynarray(&env->d_astar, astar_compare);
srcs//enemies/astar.c:53:    astar_delvisited_nodes(&env->d_astar);
srcs//enemies/astar.c:54:    c = env->d_astar.c;
srcs//enemies/astar.c:55:    c->bvisited = 1;
srcs//enemies/astar.c:56:    ((t_node *)dyacc(&env->d_nodes, c->i))->bvisited = 1;
srcs//enemies/astar.c:59:    i = -1;
srcs//enemies/astar.c:69:    if (env->start == NULL || env->end == NULL)
srcs//enemies/astar.c:72:    push_dynarray(&env->d_astar, env->start, 0);
srcs//enemies/astar.c:73:    current = env->d_astar.c;
srcs//enemies/astar.c:76:    current->localgoal = 0;
srcs//enemies/astar.c:77:    current->globalgoal = astar_distance(env->start->pos, env->end->pos);
Binary file srcs//singletons.o matches
