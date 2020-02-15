#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

# define BUFF_READ 4194304
# define NB_LINE_TYPES 6

enum	e_pstate
{
	PS_OBJ,
	PS_VERTEXS,
	PS_TXT_VERTEXS,
	PS_END_VERTEXS,
	PS_FACES,
	PS_COMMENT,
	PS_MAX
};

enum	e_scene_id
{
	SCENE_TEST,
	SCENE_MAX
};

struct	s_face
{
	int				x;
	int				y;
	int				z;
	int				tx;
	int				ty;
	int				tz;
};

struct	s_triangle
{
	t_vec3d		points[3];
	t_vec2d		txt[3];
	float		illum;
	int			color;
	bool		textured;
	void		*mesh;
};

struct	s_mesh
{
	t_dynarray	tris;
	t_dynarray	txts;
	t_dynarray	faces;
	float		yaw;
	float		pitch;
	float		roll;
	bool		textured;
	char		*name;
	int			nb_tris;
};

struct	s_map
{
	t_dynarray		meshs;
	t_dynarray		pool;
	t_dynarray		txt_pool;
	int				nmesh;
};

struct	s_parser
{
	char			**lines;
	char			**toks;
	char			state;
	char			tstate;
	int				tri;
};


char				*read_file(int fd);
char				*maps_paths(unsigned int index);
void				init_states(char states[NB_LINE_TYPES][NB_LINE_TYPES]);
int					parse_map(t_map *map, char *path, char states[PS_MAX][PS_MAX]);
int					load_face(char **toks, t_map *map, t_face *face);

bool				check_float(char *tok);
bool				check_number(char *tok);

int					new_mesh(t_map *map, char **toks);
int					new_vertex(t_map *map, char **toks);
int					new_txt_vertex(t_map *map, char **toks);
int					new_face(t_map *map, char **toks);
int					vertex_end(t_map *map, char **toks);
int					comment(t_map *map, char **toks);

#endif
