NAME		= libft.a
SRCS		= $(addprefix ft_printf/, ft_printf_conv_hex_sharp.c ft_printf_prec.c ft_printf.c ft_printf_conv_csp.c ft_printf_conv_iud.c ft_printf_utils.c) \
				get_next_line.c ft_jointab.c ft_strcountc.c ft_tab_add.c ft_tab_print.c gc_add.c ft_strlower.c ft_tab_size.c ft_atoi.c ft_freejoin.c ft_abs.c ft_atoi.c ft_deg_to_rad.c ft_int_memset.c ft_atoi_base.c ft_bzero.c ft_max.c ft_calloc.c ft_freetab.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_SRCS	= 
OBJS		= $(SRCS:.c=.o)
CC			= gcc
HEADER		= libft.h
FLAGS		= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus