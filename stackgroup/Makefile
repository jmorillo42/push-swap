
NAME		=	../lib/libstackgroup.a

CC			=	gcc -Wall -Wextra -Werror

AR			=	ar rcs

RM_OBJ		=	rm -rf $(OBJ_DIR)
RM_NAME		=	rm -f $(NAME)

SRCS		=	sg_create.c \
				sg_destroy.c \
				sg_print.c \
				sg_push.c \
				sg_rotate.c \
				sg_rotate_count.c \
				sg_rrotate.c \
				sg_swap.c

OBJ_DIR		=	obj
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:	%.c
				@$(CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@echo Compiling libstackgroup
				@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@echo Cleaning libstackgroup
				@$(RM_OBJ)

fclean:			clean
				@$(RM_NAME)

re:				fclean all

.PHONY:			all clean fclean re
