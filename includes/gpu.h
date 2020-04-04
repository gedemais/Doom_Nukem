#ifndef GPU_H
# define GPU_H

# define ERR_MSG_SIZE 1048576
# define NB_BUFFERS 3
# define MAX_TRIANGLES 100000

# include <OpenCL/opencl.h>

enum	e_kernels
{
	K_RASTERIZER,
	K_FLUSH,
	K_MAX
};

struct	s_opencl
{
	cl_device_id		id;
	cl_context			context;
	cl_command_queue	queue;
	cl_program			program;
	cl_kernel			kernels[K_MAX];
	cl_mem				buff;
	cl_mem				triangles;
	cl_mem				z_buff;
};

int		gpu_raster_triangles(t_env *env, t_dynarray *to_raster);

int		setup_opencl(t_env *env, t_opencl *cl_env);
int		compile_kernel(t_opencl *env, char *kernel_src, unsigned int index);
int		gpu_raytracing(t_env *env);

/*
** Setup
*/
int		get_device_id(t_opencl *env);
int		create_context(t_opencl *env);
int		create_command_queue(t_opencl *env);
void	compilation_error(t_opencl *env);

#endif
