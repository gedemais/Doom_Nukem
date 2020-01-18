#ifndef RASTER_H
# define RASTER_H

# define NB_OBJ_TYPES 4
# define OBJS_MAX 10000

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

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
}				t_triangle;

typedef struct	s_mesh
{
	t_dynarray	tris;
	t_dynarray	faces;
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

typedef struct	s_clipper
{
	t_vec3d		*in[3];
	t_vec3d		*out[3];
	int			inside;
	int			outside;
	float		d0;
	float		d1;
	float		d2;
}				t_clipper;

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

t_vec3d			vec_add(t_vec3d a, t_vec3d b);
t_vec3d			vec_sub(t_vec3d a, t_vec3d b);
t_vec3d			vec_mult(t_vec3d a, t_vec3d b);
t_vec3d			vec_fmult(t_vec3d a, float n);
void			vec_swap(t_vec3d *a, t_vec3d *b);
t_vec3d			vec_cross(t_vec3d a, t_vec3d b);
void			vec_normalize(t_vec3d *vec);
float			vec_dot(t_vec3d a, t_vec3d b);
float			distance_to_plane(t_vec3d plane_n, t_vec3d plane_p, t_vec3d p);
t_vec3d			vec_intersect_plane(t_vec3d plane_p, t_vec3d plane_n,
												t_vec3d l_start, t_vec3d l_end);

#endif
