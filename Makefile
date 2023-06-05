
NAME		=	push_swap
NAME_BONUS	=	checker

CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror

RM_OBJ		=	rm -rf $(OBJ_DIR)

SRC_DIR		=	src/
BONUS_DIR	=	bonus/
OBJ_DIR		=	obj
LIB_DIR		=	lib
FT_DIR		=	ft/
ST_DIR		=	stack/
AC_DIR		=	actions/
SG_DIR		=	stackgroup/
SORT_DIR	=	sort/

FT_LIB		=	lib/libft.a
ST_LIB		=	lib/libstack.a
AC_LIB		=	lib/libactions.a
SG_LIB		=	lib/libstackgroup.a
SORT_LIB	=	lib/libsort.a

SRCS		=	push_swap.c \
				parse_numbers.c

BONUS_SRCS	=	checker_bonus.c \
				parse_numbers_bonus.c \
				gnl_bonus.c \
				gnl_utils_bonus.c \
				operate_stack_bonus.c

OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

BONUS_OBJS	=	$(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)

all:			make_libs $(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				@echo Compiling push_swap
				@$(CC) $(OBJS) $(SORT_LIB) $(SG_LIB) $(AC_LIB) $(ST_LIB) $(FT_LIB) -o $(NAME)

bonus:			make_libs $(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_DIR) $(BONUS_OBJS)
				@echo Compiling checker
				@$(CC) $(BONUS_OBJS) $(SG_LIB) $(AC_LIB) $(ST_LIB) $(FT_LIB) -o $(NAME_BONUS)

make_libs:
				@mkdir -p $(LIB_DIR)
				@$(MAKE) -C $(FT_DIR) all
				@$(MAKE) -C $(ST_DIR) all
				@$(MAKE) -C $(AC_DIR) all
				@$(MAKE) -C $(SG_DIR) all
				@$(MAKE) -C $(SORT_DIR) all

$(OBJ_DIR):
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)%.c
				@$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:	$(BONUS_DIR)%.c
				@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
				@$(RM_OBJ)
				@$(MAKE) -C $(FT_DIR) fclean
				@$(MAKE) -C $(ST_DIR) fclean
				@$(MAKE) -C $(AC_DIR) fclean
				@$(MAKE) -C $(SG_DIR) fclean
				@$(MAKE) -C $(SORT_DIR) fclean

fclean:			clean
				@rm -f $(NAME)
				@rm -f $(NAME_BONUS)

re:				fclean all

.PHONY:			all bonus clean fclean re
