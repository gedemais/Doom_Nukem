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
			if (env->player.current->shot && !mob->dead)
			{
				mob->hp -= env->player.current->damages;
				env->custom_env.game.moula += (mob->hp > 0)
					? HIT_REWARD : KILL_REWARD;
				mob->dead = (mob->hp <= 0);
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

static void		find_random_spawner(t_dynarray *events, int sp[3], int index)
{
	t_event_block	*block;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < events->nb_cells)
	{
		block = dyacc(events, i);
		if (block->id == BE_MOB_SPAWNER)
			j++;
		if (j == index)
		{
			sp[0] = block->x;
			sp[1] = block->y;
			sp[2] = block->z;
			return ;
		}
		i++;
	}
}

static int		spawn_mob(t_env *env)
{
	t_custom_game	*game;
	int				index;
	int				p[3];
	t_vec3d			pos;

	game = &env->custom_env.game;
	index = rand() % game->nb_spawners + 1;
	find_random_spawner(&env->custom_env.events, p, index);
	pos.x = p[0] * 2;
	pos.y = p[1] * 2;
	pos.z = p[2] * 2;
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
