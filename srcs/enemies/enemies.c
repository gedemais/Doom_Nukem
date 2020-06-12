#include "main.h"

static void		enemies_damages(t_env *env)
{
	t_enemy		*mob;
	int			index;
	int			i;

	i = 0;
	index = env->mid.mesh->index;
	while (i < env->mobs.nb_cells)
	{
		mob = dyacc(&env->mobs, i);
		if (index >= mob->map_start && index < mob->map_end)
		{
			env->player.hover = true;
			if (env->player.current->shot)
			{
				mob->hp -= env->player.current->damages;
				env->player.hitmarker = HITMARKER_T;
			}
			return ;
		}
		i++;
	}
}

static void		enemies_to_scene(t_dynarray *mobs)
{
	int		i;
	int		j;
	t_mesh	*m;
	t_enemy	*mob;

	i = -1;
	while (++i < mobs->nb_cells)
	{
		mob = dyacc(mobs, i);
		j = mob->map_start - 1;
		while (++j < mob->map_end)
		{
			m = dyacc(&mob->map->meshs, j);
			translate_mesh(mob->map, m, vec_sub(mob->pos, m->corp.pos));
		}
	}
}

static int		spawn_mob(t_env *env)
{
	int			i;
	t_vec3d		pos;

	i = rand() % (env->astar.d_nodes.nb_cells - 1);
	while (((t_node *)dyacc(&env->astar.d_nodes, i))->bobstacle == 1)
		i = rand() % (env->astar.d_nodes.nb_cells - 1);
	pos = ((t_node *)dyacc(&env->astar.d_nodes, i))->pos;
	return (create_mob(env, &env->edit_env.map, ENEMY_CUBE, pos));
}

int				handle_enemies(t_env *env)
{
	env->player.hover = false;
	env->player.hitmarker--;
	if (env->custom_env.spawner <= 0.0f)
	{
		if (env->mobs.nb_cells < MAX_ENEMIES && spawn_mob(env))
			return (-1);
		env->custom_env.spawner = RESPAWN_DELAY;
	}
	else
		env->custom_env.spawner -= env->data.spent;
	if (env->mobs.nb_cells)
	{
		if (env->mid.mesh)
			enemies_damages(env);
		enemies_movements(env, &env->astar);
		enemies_death(&env->mobs);
		enemies_to_scene(&env->mobs);
	}
	return (0);
}
