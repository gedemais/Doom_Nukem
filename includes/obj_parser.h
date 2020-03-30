#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

# define BUFF_READ 4194304

enum	e_mapper
{
	MAPPER_NAME,
	MAPPER_POSITION,
	MAPPER_SPEED,
	MAPPER_STATIC,
	MAPPER_TEXTURE,
	MAPPER_SPAWN,
	MAPPER_CAMDIR,
	MAPPER_MAX
};

enum	e_mtl
{
	MTL_COMMENT,
	MTL_NEW,
	MTL_NS,
	MTL_KA,
	MTL_KD,
	MTL_KS,
	MTL_KE,
	MTL_NI,
	MTL_D,
	MTL_ILLUM,
	MTL_MAP_KD,
	MTL_MAX
};

enum	e_pstate
{
	PS_OBJ,
	PS_VERTEXS,
	PS_TXT_VERTEXS,
	PS_END_VERTEXS,
	PS_FACES,
	PS_COMMENT,
	PS_MTLLIB,
	PS_USEMTL,
	PS_MAX
};

enum	e_scene_id
{
	SCENE_A,
	SCENE_B,
	SCENE_C,
	SCENE_D,
	SCENE_MAX
};

struct	s_mtl
{
	char	*name;
	char	color[4];
	float	alpha;
	bool	textured;
};

struct	s_face
{
	int				x;
	int				y;
	int				z;
	int				tx;
	int				ty;
	int				tz;
	int				color;
	bool			textured;
};

struct	s_triangle
{
	bool		textured;
	float		illum;
	t_vec3d		normal;
	t_vec3d		points[3];
	t_vec2d		txt[3];
	int			color;
	t_sprite	*sp;
	float		alpha;
	void		*mesh;
};

struct	s_mesh
{
	t_dynarray	tris;
	t_dynarray	txts;
	t_dynarray	deps;
	t_sprite	sprite;
	t_corp		corp;
	float		yaw;
	float		pitch;
	float		roll;
	bool		textured;
	bool		phy;
	int			nb_tris;
	char		*name;
	int			index;
	t_dynarray	faces;
};

struct	s_map
{
	t_dynarray		meshs;
	t_dynarray		pool;
	t_dynarray		txt_pool;
	t_dynarray		mtls;
	t_vec3d			spawn;
	t_vec2d			cam_dir;
	bool			*colls;
	bool			*stats;
	bool			*stats_cpy;
	int				cmtl;
	int				nmesh;
	t_collide		cam_floor;
};

struct	s_parser
{
	char			**lines;
	char			**toks;
	char			*file;
	char			state;
	char			tstate;
	int				tri;
};

int					check_line(t_env *env, t_mesh *m, char **stats);
t_mesh				*find_mesh(t_map *map, char **line, bool *prop);

char				*read_file(int fd);
char				*maps_paths(unsigned int index);
void				init_states(char states[PS_MAX][PS_MAX]);
int					parse_map(t_map *map, char *path, char states[PS_MAX][PS_MAX]);
int					load_face(char **toks, t_map *map, t_face *face);

int					load_map_config(t_env *env, t_map *map, char *map_path);

bool				check_float(char *tok);
bool				check_number(char *tok);

/*
** Lines functions
*/
int					new_mesh(t_map *map, char **toks);
int					new_vertex(t_map *map, char **toks);
int					new_txt_vertex(t_map *map, char **toks);
int					new_face(t_map *map, char **toks);
int					vertex_end(t_map *map, char **toks);
int					comment(t_map *map, char **toks);
int					mtllib(t_map *map, char **toks);
int					usemtl(t_map *map, char **toks);

/*
** Materials
*/
int					parse_mtl(char *file_name, t_dynarray *mtls);
int					get_material_color(t_mesh *m);

int					mtl_new(char **toks, t_dynarray *mtl);
int					mtl_color(char **toks, t_dynarray *mtl);
int					mtl_alpha(char **toks, t_dynarray *mtl);
int					mtl_map_texture(char **toks, t_dynarray *mtls);

int					get_spawn_position(t_map *map, char **line);
int					get_cam_direction(t_map *map, char **line);

/*
** Parser tools
*/
int					cross_whitespaces(char *line, int *i);
int					cross_floats(char *line, int *i);
t_vec3d				read_vec3d(char *tok, char start_sep, char end_sep);
t_vec2d				read_vec2d(char *tok, char start_sep, char end_sep);
int					assign_triangle_texture(t_mesh *m , void *ptr);

/*
** Mapper functions
*/
int					mapper_texture(t_env *env, t_mesh *m, char *tok);
int					mapper_position(t_env *env, t_mesh *m, char *tok);
int					mapper_speed(t_env *env, t_mesh *m, char *tok);
int					mapper_static(t_env *env, t_mesh *m, char *tok);
int					mapper_deps(t_env *env, t_mesh *m, char *tok);

int					check_deps_cycle(t_dynarray *meshs);

t_map				**current_map(void);

#endif
