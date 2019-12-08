#include "main.h"

static int			count_meshs(char *file, int indexes[OBJS_MAX])
{
	char			*obj_ids[NB_OBJ_TYPES] = {"o Cylinder", "o Cube", "o Cone", "o Sphere"};
	unsigned int	i;
	unsigned int	j;
	int				ret;
	size_t			len;

	i = 0;
	ret = 0;
	while (!cross_line(file, &i) && file[i + 1] == '#')
		i++;
	while (!cross_line(file, &i))
	{
		i++;
		j = 0;
		while (j < NB_OBJ_TYPES)
		{
			len = ft_strlen(obj_ids[j]);
			if (!ft_strncmp(&file[i], obj_ids[j], len))
			{
				indexes[ret] = i;
				ret++;
			}
			j++;
		}
	}
	printf("%d\n", ret);
	return (ret);
}

static int			count_vertexs(char *obj)
{
	unsigned int	i;
	int				ret;

	i = 0;
	ret = 0;
	if (cross_line(obj, &i))
		return (-1);
	i++;
	while (!cross_line(obj, &i) && obj[i + 1] == 'v')
	{
		ret++;
		i++;
	}
	return (ret);
}

static int			load_pool(char *obj, t_vec3d *pool, int *i, int max)
{
	unsigned int	j;
	int				k;

	cross_line(obj, (unsigned int *)i);
	j = (unsigned)*i;
	k = 0;
	while (!cross_line(obj, &j) && obj[j + 1] == 'v' && k < max)
	{
		j += 2;
		cross_whites(obj, &j);
		pool[k].x = atof(&obj[j]);
		cross_floats(obj, &j);
		cross_whites(obj, &j);
		pool[k].y = atof(&obj[j]);
		cross_floats(obj, &j);
		cross_whites(obj, &j);
		pool[k].z = atof(&obj[j]);
		k++;
	}
	*i = j + 1;
	return (0);
}

static int			load_vertexs(char *obj, t_vec3d *pool, unsigned int i, t_triangle *t)
{
	int		j;

	j = 0;
	cross_line(obj, (unsigned int*)&i);
	i++;
	while (!cross_line(obj, (unsigned int*)&i) && obj[++i] == 'f')
	{
		i++;
		cross_whites(obj, &i);
		printf("%lld ", ft_atoi(&obj[i]));
		ft_memcpy(&t[j].points[0], &pool[ft_atoi(&obj[i]) - 1], sizeof(t_vec3d));
		cross_floats(obj, &i);
		cross_whites(obj, &i);
		printf("%lld ", ft_atoi(&obj[i]));
		ft_memcpy(&t[j].points[1], &pool[ft_atoi(&obj[i]) - 1], sizeof(t_vec3d));
		cross_floats(obj, &i);
		cross_whites(obj, &i);
		printf("%lld\n", ft_atoi(&obj[i]));
		ft_memcpy(&t[j].points[2], &pool[ft_atoi(&obj[i]) - 1], sizeof(t_vec3d));
		i++;
		j++;
	}
	return (j);
}

static t_triangle	*load_triangles(char *obj, int *nb_tris)
{
	t_triangle	*dest;
	t_vec3d		*pool;
	int			i;
	int			n;

	i = 0;
	if ((n = count_vertexs(obj)) <= 0
		|| !(pool = (t_vec3d*)malloc(sizeof(t_vec3d) * (n + 1)))
		|| !(dest = (t_triangle*)malloc(sizeof(t_triangle) * (n * 3))))
		return (NULL);
	if (load_pool(obj, pool, &i, n) != 0
		|| (*nb_tris = load_vertexs(obj, pool, (unsigned)i, dest)) <= 0)
		return (NULL);
	printf("%d triangles\n", *nb_tris);
	return (dest);
}

static t_mesh		*parse_objects(t_mesh *s, char *file)
{
	int				indexes[OBJS_MAX];
	int				i;
	int				n;

	i = 0;
	if ((n = count_meshs(file, indexes)) <= 0
		|| !(s = (t_mesh*)malloc(sizeof(t_mesh) * n)))
		return (NULL);
	while (i < n)
	{
		if (!(s[i].tris = load_triangles(&file[indexes[i]], &s[i].nb_tris)))
			return (NULL);
		i++;
	}
	return (s);
}

t_mesh	*load_objects(char *path)
{
	t_mesh	*dest;
	char	*file;
	int		fd;

	dest = NULL;
	if ((fd = open(path, O_RDONLY)) == -1 || !(file = read_file(fd)))
	{
		// err
		return (NULL);
	}
	if (!(dest = parse_objects(dest, file)))
	{
		// err
		free(file);
		return (NULL);
	}
	return (dest);
}
