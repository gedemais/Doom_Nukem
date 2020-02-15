#ifndef RASTER_H
# define RASTER_H

# define MIN_TO_RASTER 16384
# define MIN_TO_CLIP 256
# define NB_OBJ_TYPES 4
# define OBJS_MAX 10000

struct	s_point
{
	int			x;
	int			y;
};

struct	s_filler
{
	float		m0;
	float		m1;
	float		x0;
	float		x1;
	float		xstart;
	float		xend;
	float		ystart;
	float		yend;
};

struct	s_texturizer
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
};

struct	s_clipper
{
	t_vec3d		in[3];
	t_vec3d		out[3];
	t_vec2d		txt_in[3];
	t_vec2d		txt_out[3];
	int			txt_inside;
	int			txt_outside;
	int			inside;
	int			outside;
	float		d[3];
};

struct	s_rasthread
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
};

struct	s_cam_stats
{
	t_vec3d		pos;
	t_vec3d		dir;
	float		yaw;
	float		pitch;
	float		aspect_ratio;
	float		fnear;
	float		ffar;
	float		fdelta;
	float		fovd;
	float		fovr;
};

struct	s_cam
{
	t_cam_stats	stats;
	t_dynarray	to_clip;
	t_dynarray	to_raster;
	t_dynarray	clip_arrs[4];
	t_vec3d		light;
	float		*z_buffer;
	float		w_m[4][4];
	float		c_m[4][4];
	float		cr_m[4][4];
	float		crx_m[4][4];
	float		cry_m[4][4];
	float		v_m[4][4];
	float		p_m[4][4];
	float		rx_m[4][4];
	float		ry_m[4][4];
	float		rz_m[4][4];
};

int				triangle_pipeline(t_env *env, t_triangle t, t_dynarray *tris);
int				raster_triangles(void *env, t_dynarray *arr);
void			monothread_raster(void *env);
void			*rasthreader(void *param);
int				rasterizer(t_env *env, int scene);

/*
** Clipping
*/
int				allocate_clipping_arrays(t_dynarray arrays[4]);
void			classify_triangle(t_clipper *clip, t_triangle in);
bool			is_triangle_in_screen(t_triangle t);
int				refactor_triangle(t_clipper *clip, t_triangle out[2], t_vec3d planes[2], t_triangle t);
void			clip_mesh_triangles(t_dynarray *tris, t_dynarray *to_raster, t_dynarray arrs[4]);
int				clip_triangle(t_vec3d plane_p, t_vec3d plane_n, t_triangle in, t_triangle out[2]);

/*
** Matrices
*/
void			init_matrices(t_cam *cam);
void			translation_matrix(float m[4][4], t_vec3d v);
void			update_xrotation_matrix(float m[4][4], float theta);
void			update_yrotation_matrix(float m[4][4], float theta);
void			update_zrotation_matrix(float m[4][4], float theta);
t_vec3d			multiply_matrix(float m[4][4], t_vec3d o);
t_vec3d			matrix_mult_vec(float m[4][4], t_vec3d i);
void			matrix_mult_matrix(float m1[4][4], float m2[4][4], float ret[4][4]);
void			matrix_pointat(float m[4][4], t_vec3d pos, t_vec3d target, t_vec3d up);
void			inverse_matrix(float m[4][4], float ret[4][4]);

/*
** Texturing
*/
void			starting_swap(t_triangle *t);
void			compute_steps(t_texturizer *txt);
void			compute_gradients(t_texturizer *txt, t_triangle t, bool fbot);
void			set_line_bounds_top(t_texturizer *txt, t_triangle t, float cur);
void			set_line_bounds_bot(t_texturizer *t, t_triangle e, float c[2]);
void			fill_triangle_texture(t_env *env, t_triangle t);

/*
** Tools
*/
void			draw_triangle(void *mlx, t_triangle t);
void			compute_rotation_matrices(t_env *env, t_mesh m);
void			compute_view_matrice(t_env *env);
void			swap_floats(float *a, float *b);

#endif
