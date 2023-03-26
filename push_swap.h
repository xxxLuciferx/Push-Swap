#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h> // DELETE THIS
# include <fcntl.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	t_list *ptr;
	int size;
}	t_stack ;

typedef struct s_tools
{
	char **tab;
	int int_atoi;
	int range_max;
	int range_min;
	int node_index;
	t_list *l_numbers;
	t_stack *stack_a;
	t_stack *stack_b;
} t_tools;



int valid_arg(char *str);

//List_to_Stack
void	freed(char **tab);
int		string_validator(char *str);
char	**split_args(char **str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	check_double(t_tools *tools);
void	list_to_stack(t_stack *stack, t_list *l_numbers);
void    sorting_list(t_list *l_numbers);
void	ft_crush();

//swaps
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rr(t_tools *rools);
void	push_a(t_tools *tools);
void	push_b(t_tools *tools);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack);
void	rrr(t_tools *tools);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	ss(t_tools *tools);


void	push(t_stack *stack, int content);
int		pop(t_stack *head);
void	sort_3(t_stack *stack);
void	sort_5(t_tools *tools);

//tools
int		ft_atoi(const char *str);
int		index_bigest(t_stack *stack);
int		get_index(t_tools *tools);
int		bigest(t_stack *stack_a);
int		smallest(t_stack *stack);
void	push_to_a(t_stack *stack, int content);

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);



//Magic

void	sorting_algorithmes(t_tools *tools);
int		index_smallest(t_stack *stack);
void	push_to_b(t_stack *stack, int content);


//BONUS
void	bonus_rotate_a(t_stack *stack);
void	bonus_rotate_b(t_stack *stack);
void	bonus_rr(t_tools *rools);
void	bonus_push_a(t_tools *tools);
void	bonus_push_b(t_tools *tools);
void	bonus_swap_a(t_stack *stack_a);
void	bonus_swap_b(t_stack *stack);
void	bonus_rrr(t_tools *tools);
void	bonus_reverse_rotate_b(t_stack *stack);
void	bonus_reverse_rotate_a(t_stack *stack);
void	bonus_ss(t_tools *tools);

//GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_strchr(char *string, char c);
char	*my_strjoin(char *s1, char *s2);
int		my_strlen(char *str);
char	*get_first(char *static_string);
char	*get_last(char *static_string);
char	*get_next_line(int fd);

#endif