/*

/*
static void	stop_speed(t_env *env)
{
	t_mesh *m;
	t_vec3d		v;
	int		i;

	i = 0;
	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m = dyacc(&env->maps[env->scene].meshs, i);		
		v = m->corp.v;
		if (env->maps[env->scene].stats[i] == false && vec_norm(v) > 900)
		{
			env->maps[env->scene].stats[i] = true;
			v = (t_vec3d){0, 0, 0, 0};
			env->phy_env.tps = 0;
		}
		i++;
	}
}


  
  
  
   static void	print_update(t_env *env, t_mesh *m, int i)
{
		printf("name = %s\n", m->name);
		printf("------v%f %f %f-------\n",m->corp.v.x, m->corp.v.y, m->corp.v.z);
		printf("------vo %f %f %f-------\n",m->corp.vo.x, m->corp.vo.y, m->corp.vo.z);
		printf("------pos %f %f %f-------\n",m->corp.pos.x, m->corp.pos.y, m->corp.pos.z);
		printf("numero = %d\n", i);
		printf("state = %d\n", env->maps[env->scene].stats[i]);
}  
   
   
static t_vec3d mini_delta(t_vec3d dif)
{
	t_vec3d delta;

	delta = dif;
	delta.x = (fabs(delta.x) > 0.5) ? 0 : delta.x;
	delta.y = (fabs(delta.y) > 0.5) ? 0 : delta.y;
	delta.z = (fabs(delta.z) > 0.5) ? 0 : delta.z;
	delta = vec_fmult(delta, -1);
	return (delta);
	
}

static int cloth_enaugh(t_vec3d dif)
{
	int i;
	
	i = -1;
		
	if (fabs(dif.x) > 1 && fabs(dif.y) > 1)
		return (0);
	else
	{
	//	printf("------------------------\n");
	//	printf("m_face = %s \n",m_face->name);
	//	printf("m.x = %f m.y = %f m.z = %f\n",m->corp.pos.x, m->corp.pos.y, m->corp.pos.z);
	//	printf("m_face.x = %f m_face.y = %f m_face.z = %f\n",m_face->corp.pos.x, m_face->corp.pos.y, m_face->corp.pos.z);
	//	printf("diff.x = %f diff.y = %f diff.z = %f\n",dif.x, dif.y, dif.z);
		return (1);
	}


}

static void	off_plan(t_env *env, t_mesh *m, int j)
{
	t_vec3d *pos;
	t_mesh	*m_face;
	t_vec3d	dif;
	int		i;

	pos = &m->corp.pos;
	i = 0; 
 	while (i < env->maps[env->scene].meshs.nb_cells)
	{
		m_face = dyacc(&env->maps[env->scene].meshs, i);
		dif = vec_sub(m_face->corp.pos, *pos);
		if (env->maps[env->scene].stats[i] == true && j != i
				&& cloth_enaugh(dif) > 0)
			translate_mesh(m, mini_delta(dif));
		i++;
	}
}
*/
/*
static int wh_in_pos(t_env *env, t_mesh *m)
{
	if (m->corp.pos.y > 0)
		
		printf()
		translate_mesh(m, (t_vec3d){0,0.1,0,0});
}
*/



/*
static int	test_choc_vertical(t_env *env, t_collide	*c)
{
	t_mesh *m;

	m = dyacc(&env->maps[env->scene].meshs, c->i_b);
	if (c->dot > 0 && m->corp.norm.y == 1.0f)
		return (1);
	else
		return (0);
}*/

