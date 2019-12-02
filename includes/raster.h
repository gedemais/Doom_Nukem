#ifndef RASTER_H
# define RASTER_H

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
}				t_vec3d;

typedef struct	s_triangle
{
	t_vec3d		points[3];
}				t_triangle;

typedef struct	s_mesh
{
	t_triangle	*tris;
}				t_mesh;

typedef struct	s_cam
{
	float		p_m[4][4];
	float		rx_m[4][4];
	float		rz_m[4][4];
	t_vec3d		dir;
	float		aspect_ratio;
	float		fnear;
	float		ffar;
	float		fdelta;
	float		fovd;
	float		fovr;
}				t_cam;

void			init_matrices(t_cam *cam);
void			update_xrotation_matrix(t_cam *cam, float theta);
void			update_zrotation_matrix(t_cam *cam, float theta);
t_vec3d			multiply_matrix(float m[4][4], t_vec3d o);

t_vec3d		vec_add(t_vec3d a, t_vec3d b);
t_vec3d		vec_sub(t_vec3d a, t_vec3d b);

#endif
