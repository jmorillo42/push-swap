
NAME		=	../lib/libactions.a

CC			=	gcc -Wall -Wextra -Werror

AR			=	ar rcs

RM_OBJ		=	rm -rf $(OBJ_DIR)
RM_NAME		=	rm -f $(NAME)

SRCS		=	ac_add.c \
				ac_clean.c \
				ac_create.c \
				ac_destroy.c \
				ac_find_opposite.c \
				ac_find_reverse.c \
				ac_opposite.c \
				ac_remove.c \
				ac_reverse.c

OBJ_DIR		=	obj
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o:	%.c
				@$(CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@echo Compiling libactions
				@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@echo Cleaning libactions
				@$(RM_OBJ)

fclean:			clean
				@$(RM_NAME)

re:				fclean all

.PHONY:			all clean fclean re
