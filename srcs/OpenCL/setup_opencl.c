#include "main.h"


static void	write_buffers(t_env *env, t_opencl *cl_env)
{
	(void)env;
	(void)cl_env;
	//clEnqueueWriteBuffer(cl_env->queue, cl_env->objs, CL_FALSE, 0, env->scene.n_objs * sizeof(t_obj), (void*)env->scene.objs, 0, NULL, NULL);
}

static int	allocate_buffers(t_opencl *cl_env, cl_int err_code[NB_BUFFERS])
{
	cl_env->buff = clCreateBuffer(cl_env->context, CL_MEM_WRITE_ONLY,
			HGT * WDT * sizeof(int), NULL, &err_code[0]);

	cl_env->triangles = clCreateBuffer(cl_env->context, CL_MEM_READ_ONLY,
			MAX_TRIANGLES * sizeof(t_triangle), NULL, &err_code[1]);

	cl_env->z_buff = clCreateBuffer(cl_env->context, CL_MEM_READ_WRITE,
			HGT * WDT * sizeof(float), NULL, &err_code[2]);
	return (0);
}

static int	create_buffers(t_env *env, t_opencl *cl_env)
{
	cl_int			err_code[NB_BUFFERS];
	int				i;

	i = -1;
	allocate_buffers(cl_env, err_code);
	while (++i < NB_BUFFERS) // twice
		if (err_code[i] != CL_SUCCESS)
		{
			ft_putendl_fd("GPU memory allocation failed\n", 2);
			return (-1);
		}
	write_buffers(env, cl_env);
	return (0);
}

static int	read_kernels(char *kernels_srcs[K_MAX])
{
	int			kernels_fds[K_MAX];
	char		*paths[SP_MAX] = {	"srcs/OpenCL/rasterizer.cl",
										"srcs/OpenCL/flush.cl"};
	int	 i;

	i = -1;
	while (++i < K_MAX)
		if ((kernels_fds[i] = open(paths[i], O_RDONLY)) == -1)
		{
			ft_putstr_fd(paths[i], 2);
			ft_putendl_fd(": No such file or directory", 2);
			return (-1);
		}
	i = -1;
	while (++i < K_MAX)
		if (!(kernels_srcs[i] = read_file(kernels_fds[i])))
		{
			ft_putstr_fd(paths[i], 2);
			ft_putendl_fd(": read error", 2);
			return (-1);
		}
	return (0);
}

static int	compile_kernels(char *kernels_srcs[K_MAX], t_opencl *env)
{
	unsigned int	i;

	i = 0;
	while (i < K_MAX)
	{
		if (compile_kernel(env, kernels_srcs[i], i))
			return (-1);
		i++;
	}
	return (0);
}

int		setup_opencl(t_env *env, t_opencl *cl_env)
{
	char	*kernels_srcs[K_MAX];

	if (get_device_id(cl_env)
		|| create_context(cl_env)
		|| create_command_queue(cl_env)
		|| read_kernels(kernels_srcs)
		|| compile_kernels(kernels_srcs, cl_env)
		|| create_buffers(env, &env->cl_env))
		return (-1);
	return (0);
}
