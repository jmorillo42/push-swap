
NAME		=	../lib/libstack.a

CC			=	gcc -Wall -Wextra -Werror

AR			=	ar rcs

RM_OBJ		=	rm -rf $(OBJ_DIR)
RM_NAME		=	rm -f $(NAME)

SRCS		=	st_add.c \
				st_create.c \
				st_destroy.c \
				st_find.c \
				st_find_next.c \
				st_is_sorted.c \
				st_max.c \
				st_min.c \
				st_node.c \
				st_number.c \
				st_push.c \
				st_rotate.c \
				st_rrotate.c \
				st_swap.c

OBJ_DIR		=	obj
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:	%.c
				@$(CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@echo Compiling libstack
				@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@echo Cleaning libstack
				@$(RM_OBJ)

fclean:			clean
				@$(RM_NAME)

re:				fclean all

.PHONY:			all clean fclean re
