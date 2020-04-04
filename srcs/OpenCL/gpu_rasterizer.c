#include "main.h"

static inline int	update_kernel_data(t_env *env, t_opencl *cl_env)
{
	void	*ptr;
	size_t	cb;

	ptr = env->cam.to_raster.c;
	cb = env->cam.to_raster.nb_cells;
	if (clEnqueueWriteBuffer(cl_env->queue, cl_env->triangles, CL_FALSE, 0, WDT * HGT * 4,
		ptr, 0, NULL, NULL) != CL_SUCCESS)
		return (-1);
	return (0);
}

static inline void	set_kernel_args(t_env *env, t_opencl *cl_env)
{
	(void)env;
	clSetKernelArg(cl_env->kernels[K_RASTERIZER], 0, sizeof(cl_mem), (void*)&cl_env->buff);
	clSetKernelArg(cl_env->kernels[K_RASTERIZER], 1, sizeof(cl_mem), (void*)&cl_env->triangles);
	clSetKernelArg(cl_env->kernels[K_RASTERIZER], 2, sizeof(cl_mem), (void*)&cl_env->z_buff);

	clSetKernelArg(cl_env->kernels[K_FLUSH], 0, sizeof(cl_mem), (void*)&cl_env->z_buff);
}

static int			enqueue_kernels(t_opencl *cl_env, t_dynarray *to_raster)
{
	size_t		dim;

	(void)to_raster;
	dim = HGT * WDT;
	if (clEnqueueNDRangeKernel(cl_env->queue, cl_env->kernels[K_FLUSH], 1, NULL,
		&dim, NULL, 0, NULL, NULL) != CL_SUCCESS)
		return (-1);

	dim = to_raster->nb_cells;
	if (clEnqueueNDRangeKernel(cl_env->queue, cl_env->kernels[K_RASTERIZER], 1, NULL,
		&dim, NULL, 0, NULL, NULL) != CL_SUCCESS)
		return (-1);
	return (0);
}

int					gpu_raster_triangles(t_env *env, t_dynarray *to_raster)
{
	t_opencl	*cl_env;

	cl_env = &env->cl_env;
	set_kernel_args(env, cl_env);
	update_kernel_data(env, cl_env);

//	printf("%d triangles to raster\n", to_raster->nb_cells);

	if (enqueue_kernels(cl_env, to_raster))
	{
		ft_putendl_fd("Kernel execution failed", 2);
		return (-1);
	}

	if (clEnqueueReadBuffer(cl_env->queue, cl_env->buff, CL_TRUE, 0, WDT * HGT * 4,
			env->mlx.img_data, 0, NULL, NULL) != CL_SUCCESS)
	{
		ft_putstr_fd("Copy from GPU failed\n", 2);
		return (-1);
	}
	return (0);
}
