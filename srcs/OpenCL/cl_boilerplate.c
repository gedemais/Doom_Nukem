#include "main.h"

static void	print_gpu_stats(t_opencl *env)
{
	char	s[1024];
	cl_uint	cores;
	cl_uint	mem;

	clGetDeviceInfo(env->id, CL_DEVICE_NAME, sizeof(s), &s, NULL);
	ft_putendl("GPU device :");
	ft_putstr(s);
	clGetDeviceInfo(env->id, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cores), &cores, NULL);
	ft_putstr(" (");
	ft_putnbr(cores);
	ft_putstr(" cores, ");
	clGetDeviceInfo(env->id, CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(mem), &mem, NULL);
	ft_putnbr(mem / 1048576);
	ft_putendl(" Mo VRAM)");
}

int		get_device_id(t_opencl *env)
{
	cl_int	err_code;

	err_code = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &env->id, NULL);
	if (err_code == CL_DEVICE_NOT_FOUND)
	{
		ft_putendl_fd("GPU not found\n", 2);
		return (-1);
	}
	else
		print_gpu_stats(env);
	return (0);
}

int		create_context(t_opencl *env)
{
	cl_int	err_code;

	env->context = clCreateContext(NULL, 1, &env->id, NULL, NULL, &err_code);
	if (err_code != CL_SUCCESS)
	{
		ft_putendl_fd("Context creation failure", 2);
		return (-1);
	}
	return (0);
}

int		create_command_queue(t_opencl *env)
{
	cl_int	err_code;

	env->queue = clCreateCommandQueue(env->context, env->id,
		(cl_command_queue_properties)0, &err_code);
	if (err_code != CL_SUCCESS)
	{
		ft_putendl_fd("Command queue creation failure", 2);
		return (-1);
	}
	return (0);
}

void	compilation_error(t_opencl *env)
{
	char	*msg;
	size_t	size;

	if (!(msg = ft_strnew(ERR_MSG_SIZE)))
		exit(EXIT_FAILURE);
	clGetProgramBuildInfo(env->program, env->id, CL_PROGRAM_BUILD_LOG, ERR_MSG_SIZE, (void*)msg, &size);
	write(2, msg, size);
	free(msg);
}

int		compile_kernel(t_opencl *env, char *kernel_src, unsigned int index)
{
	char	*names[K_MAX] = {"rasterizer", "flush"};
	cl_int	err_code;

	env->program = clCreateProgramWithSource(env->context, 1,
		(const char**)&kernel_src, NULL, &err_code);
	if (err_code != CL_SUCCESS)
	{
		ft_putendl_fd("Program creation failure", 2);
		return (-1);
	}
	clBuildProgram(env->program, 1, &env->id, NULL, NULL, NULL);
	env->kernels[index] = clCreateKernel(env->program, names[index], &err_code);
	if (err_code != CL_SUCCESS)
	{
		ft_putendl_fd("Kernel compilation failed :\n", 2);
		compilation_error(env);
		exit(EXIT_FAILURE);
		return (-1);
	}
	return (0);
}
