NAME=doom-nukem

CC=gcc
FLAGS= -Wall -Werror -Wextra

# Flags variables
DEBUG ?= 0
ifeq ($(DEBUG), 1)
    FLAGS += -g3 -fsanitize=address -fno-common
endif

OPTI ?= 0
ifeq ($(OPTI), 1)
    FLAGS += -Ofast -march=native
endif

# Source code files
SRCS_NAME=	main.c\
			dev_events.c\
			dev_handle_events.c\
			free.c\
			openal.c\
			play_sound.c\
			resources_paths.c\
			setup.c\
			\
			campaign/render.c\
			campaign/events.c\
			\
			contexts/switch_context.c\
			contexts/routines.c\
			contexts/routines_bis.c\
			\
			custom_mode/render.c\
			custom_mode/events.c\
			\
			map_editor/render.c\
			map_editor/events.c\
			\
			obj_parser/load_maps.c\
			obj_parser/load_face.c\
			obj_parser/lines_fts.c\
			obj_parser/check_formats.c\
			obj_parser/parse_map.c\
			obj_parser/parse_mtl.c\
			obj_parser/mtl_lines_fts.c\
			obj_parser/states.c\
			obj_parser/read_file.c\
			\
			physic_engine/init_engine.c\
			physic_engine/report_collisions.c\
			physic_engine/move_mesh.c\
			\
			rasterizer/clipping.c\
			rasterizer/clipping_bis.c\
			rasterizer/fill_triangle_unit.c\
			rasterizer/fill_triangle_texture.c\
			rasterizer/fill_triangle_texture_bis.c\
			rasterizer/rasterizer.c\
			rasterizer/raster_tools.c\
			rasterizer/triangle_pipeline.c\
			rasterizer/raster_triangles.c\
			rasterizer/camera.c\
			rasterizer/rotation_matrices.c\
			rasterizer/matrices.c\
			rasterizer/matrix_ops.c\
			rasterizer/matrix_tools.c\
			\
			mlx/init_mlx.c\
			mlx/sprites.c\
			mlx/render.c\
			mlx/term_loading_bar.c\
			mlx/events.c\
			mlx/basics.c\
			mlx/bresenham.c\
			mlx/hooks.c\
			\
			title_screen/animation.c\
			title_screen/setup_ts.c\
			title_screen/buttons.c\
			title_screen/events.c\
			title_screen/render.c\
			\
			vectors/vectors.c\
			vectors/vec2d_ops.c\
			vectors/vec2d_tools.c\
			vectors/vec3d_ops.c\
			vectors/vec3d_tools.c

SRCS_PATH=srcs/
SRCS=$(addprefix $(SRCS_PATH), $(SRCS_NAME))

INCS_NAME=main.h
INCS_PATH=includes/
INCS=$(addprefix $(INCS_PATH), $(INCS_NAME))

OBJS=$(SRCS:.c=.o)

########################## Librarys ######################
MLX_PATH = mlx_opengl/
MLX = $(MLX_PATH)libmlx.a
MLX_OBJS_NAME = mlx_init_loop.o\
				mlx_int_str_to_wordtab.o\
				mlx_new_image.o\
				mlx_new_window.o\
				mlx_shaders.o\
				mlx_xpm.o

LIB_PATH = libft/
LIB = libft/libft.a

LDYNARRAY_PATH = dynarray/
LDYNARRAY = $(LDYNARRAY_PATH)ldynarray.a
##########################################################

all: $(NAME)

$(NAME): $(LIB) $(MLX) $(OBJS)
	$(CC) $(FLAGS) -I $(INCS_PATH) -I $(MLX_PATH) -I $(LIB_PATH) -o $(NAME) $(OBJS) $(MLX) $(LIB) -lsndfile -lpthread -framework OpenAL -framework OpenGL -framework AppKit

$(SRCS_PATH)%.o: $(SRCS_PATH)%.c $(INCS)
	$(CC) $(FLAGS) -I$(INCS_PATH) -I$(MLX_PATH) -I$(LIB_PATH) -o $@ -c $<

$(MLX): $(MLX_PATH)
	make -C $(MLX_PATH)

$(LIB): $(LIB_PATH)
	make -C $(LIB_PATH)

clean:
	rm -rf $(OBJS)
	make -C $(LIB_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all
