CC = cc -g
NAME = push_swap
NAME_BONUS = checker

#FLAGS
FLAGS = -I./$(LIB_DIR) -Wall -Werror -Wextra

# Color variables
RED = \033[0;31m
GRN = \033[0;32m
YEL = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYN = \033[0;36m
WHT = \033[0;37m
RES = \033[0m

# PATHS
INC_DIR = include/
LIB_DIR = Libft/
SRC_DIR = src/
INS_DIR = instructions/
BON_DIR = bonus/
OBJ_DIR = obj/

# FILES
LIBFT = $(LIB_DIR)/libft.a

SRCS =		$(SRC_DIR)000_main.c  $(SRC_DIR)010_parsing.c\
			$(SRC_DIR)015_multiple_args_parsing.c  $(SRC_DIR)020_handle_errors.c\
			$(SRC_DIR)030_organize_array.c  $(SRC_DIR)040_org_arr_utils.c\
			$(SRC_DIR)100_quicksort.c  $(SRC_DIR)110_push2b.c\
			$(SRC_DIR)120_sort3.c  $(SRC_DIR)125_sort5.c\
			$(SRC_DIR)130_double_sort3.c  $(SRC_DIR)140_sort6.c\
			$(SRC_DIR)150_get_mediane.c  $(SRC_DIR)160_issorted.c\
			$(SRC_DIR)200_sort.c  $(SRC_DIR)210_org_b.c\
			$(SRC_DIR)220_split_chunk_utils.c $(SRC_DIR)$(INS_DIR)instruction_utils.c\
			$(SRC_DIR)$(INS_DIR)push.c  $(SRC_DIR)$(INS_DIR)reverse_rotate.c\
			$(SRC_DIR)$(INS_DIR)rotate.c  $(SRC_DIR)$(INS_DIR)swap.c

SRCS_BNS =	$(BON_DIR)main_bonus.c  $(BON_DIR)checker_bonus.c  $(SRC_DIR)010_parsing.c\
			$(SRC_DIR)015_multiple_args_parsing.c  $(SRC_DIR)020_handle_errors.c\
			$(SRC_DIR)030_organize_array.c  $(SRC_DIR)040_org_arr_utils.c\
			$(SRC_DIR)100_quicksort.c  $(SRC_DIR)110_push2b.c\
			$(SRC_DIR)120_sort3.c  $(SRC_DIR)125_sort5.c\
			$(SRC_DIR)130_double_sort3.c  $(SRC_DIR)140_sort6.c\
			$(SRC_DIR)150_get_mediane.c  $(SRC_DIR)160_issorted.c\
			$(SRC_DIR)200_sort.c  $(SRC_DIR)210_org_b.c\
			$(SRC_DIR)220_split_chunk_utils.c $(SRC_DIR)$(INS_DIR)instruction_utils.c\
			$(SRC_DIR)$(INS_DIR)push.c  $(SRC_DIR)$(INS_DIR)reverse_rotate.c\
			$(SRC_DIR)$(INS_DIR)rotate.c  $(SRC_DIR)$(INS_DIR)swap.c

OBJ = $(SRCS:.c=.o)
OBJ_BON = $(SRCS_BNS:.c=.o)

#PHONY TARGETS
.PHONY: all bonus clean fclean re

#RULES
all: ${NAME}
bonus: ${NAME_BONUS}

${NAME}:		${SRCS} ${LIBFT} $(OBJ)
					@${CC} ${FLAGS} ${OBJ} ${LIBFT} -o $(NAME)
					@echo "$(GRN)push_swap compiled successfully.$(RES)"

${NAME_BONUS}:	$(OBJ_BON) $(LIBFT)

					@$(CC) ${FLAGS} ${OBJ_BON} ${LIBFT} -o ${NAME_BONUS}
					@echo "$(GRN)checker compiled successfully.$(RES)"

${LIBFT}:
			@echo "$(WHT)Compiling libft...$(RES)"
			@make --silent -C ./$(LIB_DIR)

%.o: %.c
		@${CC} -c $< -o $@ -Wall -Werror -Wextra

clean:
		@rm -f ${OBJ}
		@rm -f ${OBJ_BON}
		@rm -f $(LIB_DIR)/*.o
		@echo "$(WHT)Clean command executed.$(RES)"

fclean: clean
		@rm -f ${NAME}
		@rm -f ${NAME_BONUS}
		@rm -f ${LIBFT}

re: fclean all
