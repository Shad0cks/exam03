NAME		= cub3D
OBJDIR		= obj/
INCDIR		= inc/
VPATH		= src/
INC			= $(addprefix ${INCDIR}, cub3D.h)

SRC			= 	main.c 			\
				utils.c			\
				move.c			\
				

OBJ			= $(addprefix ${OBJDIR}, $(SRC:.c=.o))
MINILIBX_PATH    = libs/minilibx
MINILIBX        =    $(MINILIBX_PATH)/libmlx.a
MLXFLAGS        =    -L $(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit
LIB_FILE	= libs/libft/libft.a
CC			= gcc
FLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3
#FLAGS		+= -fsanitize=address -g

all: ${OBJDIR} ${NAME}

${OBJDIR}:
	@mkdir -p ${OBJDIR}

${NAME}: ${OBJ} ${LIB_FILE} $(MINILIBX)
	${CC} ${FLAGS} $(MINILIBX) $(MLXFLAGS) $^ -o ${NAME}

${OBJDIR}%.o: %.c ${INC} Makefile
	${CC} ${FLAGS} -c $< -o $@

libs/libft/libft.a:
	make -C libs/libft

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_PATH)

clean:
	make clean -C libs/libft
	make clean -C $(MINILIBX_PATH) clean
	rm -rf ${OBJDIR}

fclean:
	make fclean -C libs/libft
	rm -rf ${OBJDIR}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
