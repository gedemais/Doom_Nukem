/***********************************************/

# define WDT 1080
# define HGT 720

typedef union		u_float4
{
	float4	v;
	float	vec[4];
}					t_float4;

typedef union		u_float3
{
	float3	v;
	float	vec[3];
}					t_float3;

typedef struct	s_triangle
{
	bool		textured;
	float		illum;
	float4		normal;
	float4		points[3];
	float3		txt[3];
	int			color;
	char		sp[8];
	int			sp_id;
	float		alpha;
	char		mesh[8];
}				t_triangle;

typedef struct	s_texturizer
{
	float		txt_u;
	float		txt_v;
	float		txt_w;
	float		t_step;
	float		ax;
	float		bx;
	float		txt_su;
	float		txt_sv;
	float		txt_sw;
	float		txt_eu;
	float		txt_ev;
	float		txt_ew;
	float		dx1;
	float		dx2;
	float		dy1;
	float		dy2;
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
}				t_texturizer;

/***********************************************/

static void	swap_float4(float4 *a, float4 *b, int ai, int bi)
{
	float	va[4];
	float	vb[4];
	float	t;

	memcpy(va, a, sizeof(float4));
	memcpy(vb, b, sizeof(float4));
	t = va[ai];
	va[ai] = vb[bi];
	vb[bi] = t;
}

static void	swap_float3(float3 *a, float3 *b, int ai, int bi)
{
	t_float3	va;
	t_float3	vb;
	float		t;

	memcpy(&va, a, sizeof(float3));
	memcpy(&vb, b, sizeof(float3));
	t = va.vec[ai];
	va.vec[ai] = vb.vec[bi];
	vb.vec[bi] = t;
}
/*
static void	starting_swap(t_triangle *t)
{
	if (t->points[1].y < t->points[0].y)
	{
		swap_float4(&t->points[0], &t->points[1], 1, 1);
		swap_float4(&t->points[0], &t->points[1], 0, 0);
		t->textured ? swap_float3(&t->txt[0], &t->txt[1], 0, 0) : 0;
		t->textured ? swap_float3(&t->txt[0], &t->txt[1], 1, 1) : 0;
		swap_float3(&t->txt[0], &t->txt[1], 2, 2);
	}
	if (t->points[2].y < t->points[0].y)
	{
		swap_float4(&t->points[2], &t->points[0], 1, 1);
		swap_float4(&t->points[2], &t->points[0], 0, 0);
		t->textured ? swap_float3(&t->txt[2], &t->txt[0], 0, 0) : 0;
		t->textured ? swap_float3(&t->txt[2], &t->txt[0], 1, 1) : 0;
		swap_float3(&t->txt[2], &t->txt[0], 2, 2);
	}
	if (t->points[2].y < t->points[1].y)
	{
		swap_float4(&t->points[2], &t->points[1], 1, 1);
		swap_float4(&t->points[2], &t->points[1], 0, 0);
		t->textured ? swap_float3(&t->txt[2], &t->txt[1], 0, 0) : 0;
		t->textured ? swap_float3(&t->txt[2], &t->txt[1], 1, 1) : 0;
		swap_float3(&t->txt[2], &t->txt[1], 2, 2);
	}
}*/

__kernel void		rasterizer(__global int *buff,
								__global t_triangle *tris,
								__global float *z_buff)
{
	const int		index = get_global_id(0);
	t_triangle		t = tris[index];
//	t_texturizer	txt = (t_texturizer){};

	if (index == 0)
	{
		printf("%f %f %f\n", t.points[0].x, t.points[0].y, t.points[0].z);
		swap_float4(&t.points[0], &t.points[0], 0, 1);
		printf("then : %f %f %f\n", t.points[0].x, t.points[0].y, t.points[0].z);
	}
/*	if (index == 0)
	{
		printf("-------------- START -------------\n");
		printf("triangle 0 :\n");
		printf("%f %f %f\n", t.points[0].x, t.points[0].y, t.points[0].z);
		printf("%f %f %f\n", t.points[1].x, t.points[1].y, t.points[1].z);
		printf("%f %f %f\n", t.points[2].x, t.points[2].y, t.points[2].z);
	}
	starting_swap(&t);
	if (index == 0)
	{
		printf("------------ SWAPPED --------------\n");
		printf("triangle 0 :\n");
		printf("%f %f %f\n", t.points[0].x, t.points[0].y, t.points[0].z);
		printf("%f %f %f\n", t.points[1].x, t.points[1].y, t.points[1].z);
		printf("%f %f %f\n", t.points[2].x, t.points[2].y, t.points[2].z);
	}*/
}
