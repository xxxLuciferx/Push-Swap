CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: push_swap.c
		${CC} push_swap.c ft_split.c ft_strjoin.c ft_atoi.c ft_lst.c \
			swaps.c swaps2.c magic.c algorithmes.c list_to_stack.c -o push_swap 


clean: all
		make
		${RM} push_swap
fclean: all
		make clean
		${RM} push_swap

bonus : all
		${CC} $(CFLAGS) checker.c ft_split.c ft_strjoin.c ft_atoi.c ft_lst.c \
			swaps.c swaps2.c magic.c algorithmes.c list_to_stack.c bonus_files1.c bonus_files2.c bonus_files3.c  \
			get_next_line.c get_next_line_utils.c -o checker