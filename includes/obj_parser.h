#ifndef OBJ_PARSER_H
# define OBJ_PARSER_H

# define BUFF_READ 4194304
# define NB_LINE_TYPES 5

enum				e_pstate
{
	PS_OBJ,
	PS_VERTEXS,
	PS_END_VERTEXS,
	PS_FACES,
	PS_COMMENT,
	PS_MAX
};

enum			e_scene_id
{
	SCENE_TEST,
	SCENE_MAX
};

typedef struct		s_face
{
	int				x;
	int				y;
	int				z;
}					t_face;

typedef struct		s_map
{
	t_dynarray		meshs;
	t_dynarray		pool;
	int				nmesh;
}					t_map;

typedef struct		s_parser
{
	char			**lines;
	char			**toks;
	char			state;
	char			tstate;
	int				tri;
}					t_parser;


char				*read_file(int fd);
void				init_states(char states[NB_LINE_TYPES][NB_LINE_TYPES]);
int					parse_map(t_map *map, char *path, char states[PS_MAX][PS_MAX]);

bool				check_float(char *tok);
bool				check_number(char *tok);

int					new_mesh(t_parser *p, t_map *map, char **toks);
int					new_vertex(t_parser *p, t_map *map, char **toks);
int					new_face(t_parser *p, t_map *map, char **toks);
int					vertex_end(t_parser *p, t_map *map, char **toks);
int					comment(t_parser *p, t_map *map, char **toks);

#endif
