// The only purpose of this kernel is to flush z_buffer to -INFINITY

__kernel void	flush(__global float *z_buff)
{
	const int	index = get_global_id(0);

	z_buff[index] = -INFINITY;
}
