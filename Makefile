NAME=doom-nukem

CC=gcc
FLAGS= -Wall -Werror -Wextra

# Flags variables
DEBUG ?= 0
ifeq ($(DEBUG), 1)
    FLAGS += -g3 -fsanitize=address -fno-common -pg
endif

OPTI ?= 0
ifeq ($(OPTI), 1)
    FLAGS += -Ofast -march=native
endif

# Source code files
SRCS_NAME=	main.c\
			setup.c\
			render.c\
			handle_events.c\
			openal.c\
			play_sound.c\
			resources_paths.c\
			dev_events.c\
			\
			obj_parser/parser_utils.c\
			obj_parser/load_maps.c\
			obj_parser/obj_lines.c\
			\
			rasterizer/fill_triangle_unit.c\
			rasterizer/rasterizer.c\
			rasterizer/camera.c\
			rasterizer/matrices.c\
			rasterizer/matrix_ops.c\
			rasterizer/vectors.c\
			\
			mlx/init_mlx.c\
			mlx/sprites.c\
			mlx/events.c\
			mlx/basics.c\
			mlx/bresenham.c\
			mlx/hooks.c\
			\
			title_screen/events.c\
			title_screen/render.c

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
	$(CC) $(FLAGS) -I $(INCS_PATH) -I $(MLX_PATH) -I $(LIB_PATH) -o $(NAME) $(OBJS) $(MLX) $(LIB) -lsndfile -framework OpenAL -framework OpenGL -framework AppKit

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
