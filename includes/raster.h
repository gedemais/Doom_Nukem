#ifndef RASTER_H
# define RASTER_H

# define MIN_TO_RASTER 16384
# define MIN_TO_CLIP 256
# define NB_OBJ_TYPES 4
# define OBJS_MAX 10000

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_vec2d
{
	float		u;
	float		v;
	float		w;
}				t_vec2d;

typedef struct	s_vec3d
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec3d;

typedef struct	s_triangle
{
	t_vec3d		points[3];
	t_vec2d		txt[3];
	float		illum;
	int			color;
	bool		textured;
	void		*mesh;
}				t_triangle;

typedef struct	s_mesh
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
}				t_mesh;

typedef struct	s_filler
{
	float		m0;
	float		m1;
	float		x0;
	float		x1;
	float		xstart;
	float		xend;
	float		ystart;
	float		yend;
}				t_filler;

typedef struct	s_texturizer
{
	int			ax;
	int			bx;

	float		txt_su;
	float		txt_sv;
	float		txt_sw;
	float		txt_eu;
	float		txt_ev;
	float		txt_ew;
	float		txt_u;
	float		txt_v;
	float		txt_w;

	int			dx1;
	int			dx2;
	int			dy1;
	int			dy2;

	float		du1;
	float		dv1;
	float		du2;
	float		dv2;
	float		dw1;
	float		dw2;

	float		ax_step;
	float		bx_step;
	float		u1_step;
	float		v1_step;
	float		w1_step;
	float		u2_step;
	float		v2_step;
	float		w2_step;
	float		t_step;
}				t_texturizer;

typedef struct	s_clipper
{
	t_vec3d		in[3];
	t_vec3d		out[3];
	t_vec2d		txt_in[3];
	t_vec2d		txt_out[3];
	int			txt_inside;
	int			txt_outside;
	int			inside;
	int			outside;
	float		d0;
	float		d1;
	float		d2;
}				t_clipper;

typedef struct	s_rasthread
{
	void		*env;
	pthread_t	thread;
	t_dynarray	*tris;
	int			start;
	int			end;
	bool		done;
	bool		mono;
	int			index;
	int			id;
}				t_rasthread;

typedef struct	s_cam
{
	float		w_m[4][4];
	float		t_m[4][4];
	float		c_m[4][4];
	float		cr_m[4][4];
	float		crx_m[4][4];
	float		cry_m[4][4];
	float		v_m[4][4];
	float		p_m[4][4];
	float		rx_m[4][4];
	float		ry_m[4][4];
	float		rz_m[4][4];
	t_dynarray	to_clip;
	t_dynarray	to_raster;
	t_dynarray	clip_arrs[4];
	float		*z_buffer;
	t_vec3d		pos;
	t_vec3d		dir;
	float		yaw;
	float		pitch;
	t_vec3d		light;
	float		aspect_ratio;
	float		fnear;
	float		ffar;
	float		fdelta;
	float		fovd;
	float		fovr;
}				t_cam;

void	triangle_pipeline(t_env *env, t_triangle t, t_dynarray *tris);
void	project_triangle(t_env *env, t_triangle t, t_vec3d normal, t_dynarray *tris);

void			init_matrices(t_cam *cam);
void			update_xrotation_matrix(float m[4][4], float theta);
void			update_yrotation_matrix(float m[4][4], float theta);
void			update_zrotation_matrix(float m[4][4], float theta);
t_vec3d			multiply_matrix(float m[4][4], t_vec3d o);
t_vec3d			matrix_mult_vec(float m[4][4], t_vec3d i);
void			matrix_mult_matrix(float m1[4][4], float m2[4][4], float ret[4][4]);
void			translation_matrix(float m[4][4], t_vec3d v);
void			matrix_pointat(float m[4][4], t_vec3d pos, t_vec3d target, t_vec3d up);
void			inverse_matrix(float m[4][4], float ret[4][4]);
int				raster_triangles(void *env, t_dynarray *arr);
void			monothread_raster(void *env);
void			*rasthreader(void *param);
void			draw_triangle(void *mlx, t_point a, t_point b, t_point c);

int				clip_triangle(t_vec3d plane_p, t_vec3d plane_n, t_triangle in, t_triangle out[2]);
void			clip_mesh_triangles(t_dynarray *tris, t_dynarray *to_raster, t_dynarray arrs[4]);
int				allocate_clipping_arrays(t_dynarray arrays[4]);
void			print_matrix(float m[4][4]);

t_vec3d			vec_add(t_vec3d a, t_vec3d b);
t_vec3d			vec_sub(t_vec3d a, t_vec3d b);
t_vec3d			vec_mult(t_vec3d a, t_vec3d b);
t_vec3d			vec_fdiv(t_vec3d a, float n);
t_vec3d			vec_fmult(t_vec3d a, float n);
void			vec3d_swap(t_vec3d *a, t_vec3d *b);
void			vec2d_swap(t_vec2d *a, t_vec2d *b);
t_vec3d			vec_cross(t_vec3d a, t_vec3d b);
void			vec_normalize(t_vec3d *vec);
float			vec_dot(t_vec3d a, t_vec3d b);
float			distance_to_plane(t_vec3d plane_n, t_vec3d plane_p, t_vec3d p);
float			vec_sdist(t_vec3d o, t_vec3d v);
t_vec3d			vec_intersect_plane(t_vec3d plane_p, t_vec3d plane_n,
													t_vec3d s_e[2], float *tmp);

#endif
