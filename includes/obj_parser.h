#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

# define BUFF_READ 4194304

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
	SCENE_MAX
};

struct	s_mtl
{
	char	*name;
	unsigned char	color[4];
	float	alpha;
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
};

struct	s_triangle
{
	bool		textured;
	float		illum;
	t_vec3d		points[3];
	t_vec2d		txt[3];
	int			color;
	float		alpha;
	void		*mesh;
};

struct	s_mesh
{
	t_dynarray	tris;
	t_dynarray	txts;
	t_dynarray	faces;
	t_vec3d		new_pos;
	t_corp		corp;
	float		yaw;
	float		pitch;
	float		roll;
	bool		textured;
	bool		phy;
	char		*name;
	int			nb_tris;
};

struct	s_map
{
	t_dynarray		meshs;
	t_dynarray		pool;
	t_dynarray		txt_pool;
	t_dynarray		mtls;
	int				cmtl;
	int				nmesh;
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


char				*read_file(int fd);
char				*maps_paths(unsigned int index);
void				init_states(char states[PS_MAX][PS_MAX]);
int					parse_map(t_map *map, char *path, char states[PS_MAX][PS_MAX]);
int					load_face(char **toks, t_map *map, t_face *face);

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

#endif
