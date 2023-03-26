/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:05:35 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/26 20:52:55 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == s2[i])
		return (1);
	return (0);
}

int	check_if_sorted(t_tools *tools)
{
	t_list	*stack;
	t_list	*stack_sorted;

	stack = tools->stack_a->ptr;
	stack_sorted = tools->l_numbers;
	while (stack && stack_sorted)
	{
		if (stack->content == stack_sorted->content
			&& tools->stack_b->size == 0)
		{
			stack = stack->next;
			stack_sorted = stack_sorted->next;
		}
		else
		{
			write(1, "KO\n", 3);
			exit(0);
		}
	}
	return (1);
}

void	instruction(t_tools *tools, char *str)
{
	if (ft_strcmp(str, "sa\n"))
		bonus_swap_a(tools->stack_a);
	else if (ft_strcmp(str, "sb\n"))
		bonus_swap_b(tools->stack_b);
	else if (ft_strcmp(str, "ss\n"))
		bonus_ss(tools);
	else if (ft_strcmp(str, "pa\n"))
		bonus_push_a(tools);
	else if (ft_strcmp(str, "pb\n"))
		bonus_push_b(tools);
	else if (ft_strcmp(str, "ra\n"))
		bonus_rotate_a(tools->stack_a);
	else if (ft_strcmp(str, "rb\n"))
		bonus_rotate_b(tools->stack_b);
	else if (ft_strcmp(str, "rr\n"))
		bonus_rr(tools);
	else if (ft_strcmp(str, "rra\n"))
		bonus_reverse_rotate_a(tools->stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		bonus_reverse_rotate_b(tools->stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		bonus_rrr(tools);
	else
		ft_crush();
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!valid_arg(argv[i]))
			ft_crush();
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*array;
	t_tools	*tools;

	tools = malloc(sizeof(t_tools));
	if (!tools || argc > 1)
	{
		tools->tab = split_args(argv);
		check_double(tools);
		tools->stack_b = malloc(sizeof(t_stack));
		tools->stack_a = malloc(sizeof(t_stack));
		if (!tools->stack_a || !tools->stack_b)
			return (0);
		list_to_stack(tools->stack_a, tools->l_numbers);
		sorting_list(tools->l_numbers);
		array = get_next_line(0);
		while (array)
		{
			instruction(tools, array);
			free(array);
			array = get_next_line(0);
		}
		if (check_if_sorted(tools))
			write(1, "OK\n", 3);
	}
	return (0);
}
