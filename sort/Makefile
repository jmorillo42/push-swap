
NAME		=	../lib/libsort.a

CC			=	gcc -Wall -Wextra -Werror

AR			=	ar rcs

OBJ_DIR		=	obj

RM_OBJ		=	rm -rf $(OBJ_DIR)
RM_NAME		=	rm -f $(NAME)

SRCS		=	sgt_align_stack.c \
				sgt_push_back.c \
				sgt_push_chunks.c \
				sort_greater_three.c \
				sort_three.c \
				sort_two.c \
				sort.c

OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)


$(OBJ_DIR)/%.o:	%.c
				@$(CC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@echo Compiling libsort
				@$(AR) $(NAME) $(OBJS)

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

clean:
				@echo Cleaning libsort
				@$(RM_OBJ)

fclean:			clean
				@$(RM_NAME)

re:				fclean all

.PHONY:			all clean fclean re
