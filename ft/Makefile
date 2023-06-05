
NAME		=	../lib/libft.a

CC			=	gcc -Wall -Wextra -Werror

AR			=	ar rcs

OBJ_DIR		=	obj

RM_OBJ		=	rm -rf $(OBJ_DIR)
RM_NAME		=	rm -f $(NAME)

SRCS		=	ft_abs.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_contains_num.c \
				ft_count_words.c \
				ft_free_strings.c \
				ft_in_range.c \
				ft_log.c \
				ft_memcpy.c \
				ft_max_num.c \
				ft_min_num.c \
				ft_num_if.c \
				ft_put_str.c \
				ft_split.c \
				ft_str_cmp.c \
				ft_str_len.c

OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:	%.c
				@$(CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@echo Compiling libft
				@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@echo Cleaning libft
				@$(RM_OBJ)

fclean:			clean
				@$(RM_NAME)

re:				fclean all

.PHONY:			all clean fclean re
