#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

# define NB_LINES_TYPE 5

enum				e_pstate
{
	PS_OBJ,
	PS_VERTEXS,
	PS_END_VERTEXS,
	PS_FACES,
	PS_MAX
};

enum			e_scene_id
{
	SCENE_TEST,
	SCENE_UT,
	SCENE_MAX
};

typedef struct		s_map
{
	t_dynarray		meshs;
	t_dynarray		pool;
	int				nmesh;
	int				tri;
	char			pstate;
}					t_map;

bool				cross_whites(char *line, unsigned int *i);
bool				cross_floats(char *line, unsigned int *i);

#endif
