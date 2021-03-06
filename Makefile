CC = gcc
CFLAG = -Wall -Wextra -Werror
SRC = main.c print_line.c get_anthill.c check_nbant.c strlen_space.c get_room.c \
ch_room_format.c mk_lstroom.c del_line.c del_room.c print_r_lst.c ch_pipe_format.c\
diff_room.c diff_pipe.c get_pipe.c mk_lstpipe.c del_pipe.c print_p_lst.c\
print_hill.c mk_anthill.c get_antlst.c del_ant.c del_hill.c print_ant.c\
init_xion.c init_ant.c print_xion.c path_finder.c del_xion.c print_path.c\
xion_cpy.c mk_antseek_lst.c print_antseek.c solver.c get_comb.c print_comb.c\
del_path.c mk_comb.c brute_fcomb.c path_cpy.c print_move.c print_estate.c\
check_opt.c get_data.c free_all.c init_main.c deal_move.c get_max_queue.c
SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
HDIR = include
LIB = libft/libft.a ft_printf/libftprintf.a
L_H = -L libft -lft -L ft_printf -lftprintf
FILE = 
NAME = lem_in
.PHONY: re run rr clean fclean all

all: $(LIB) $(NAME)

%.a:
	@make -C $(dir $@)

clean_lib:
	@make fclean -C libft
	@make fclean -C ft_printf

$(NAME): $(OBJ_DIR) $(OBJ_O)
	@$(CC) -o $@ -I $(HDIR) $(L_H) $(OBJ_O) $(CFLAG)
	@echo "\033[32m$(NAME) done\033[0m"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

clean:
	@rm -rf $(OBJ_O)
	@rm -rf $(OBJ_DIR)
	@echo "\033[31m$(NAME) object files removed\033[0m"

fclean: clean clean_lib
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) removed\033[0m"

re: fclean all

run:
	@./$(NAME) $(FILE) | cat -e

rr: re run
