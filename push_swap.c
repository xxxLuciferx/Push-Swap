/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:52:45 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/24 19:45:18 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_all(t_tools *tools)
{
	while (tools->stack_b->size > 0)
	{
		tools->node_index = index_bigest(tools->stack_b);
		while (tools->stack_b->ptr->content != bigest(tools->stack_b))
		{
			if (tools->node_index < (tools->stack_b->size / 2))
				rotate_b(tools->stack_b);
			else
				reverse_rotate_b(tools->stack_b);
		}
		if (tools->stack_b->ptr->content == bigest(tools->stack_b))
			push_a(tools);
	}
}

void	sort_range(t_tools *tools)
{
	tools->range_min = 0;
	tools->range_max = 20;
	if (tools->stack_a->size >= 250)
		tools->range_max = 30;
	while (tools->stack_a->ptr)
	{
		tools->node_index = get_index(tools);
		if ((tools->node_index >= tools->range_min)
			&& tools->node_index <= tools->range_max)
		{
			push_b(tools);
			tools->range_max++;
			tools->range_min++;
		}
		else if (tools->node_index >= tools->range_max)
			rotate_a(tools->stack_a);
		else if (tools->node_index <= tools->range_min)
		{
			push_b(tools);
			rotate_b(tools->stack_b);
			tools->range_max++;
			tools->range_min++;
		}
	}
}

int	ft_is_sorted(t_tools *tools)
{
	t_list	*ptr;

	ptr = tools->stack_a->ptr;
	while (ptr && ptr->next)
	{
		if (ptr->content > ptr->next->content)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	sorting_algorithm(t_tools *tools)
{
	if (ft_is_sorted(tools))
		return ;
	if (tools->stack_a->size <= 3)
		sort_3(tools->stack_a);
	else if (tools->stack_a->size > 3 && tools->stack_a->size <= 6)
		sort_5(tools);
	else if (tools->stack_a->size > 5)
	{
		sort_range(tools);
		sort_all(tools);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_tools	*tools;

	i = 1;
	tools = malloc(sizeof(t_tools));
	if (argc > 1)
	{
		while (i < argc)
		{
			if (!valid_arg(argv[i]))
				ft_crush();
			i++;
		}
		tools->tab = split_args(argv);
		check_double(tools);
		tools->stack_b = malloc(sizeof(t_stack));
		tools->stack_a = malloc(sizeof(t_stack));
		if (!tools->stack_a || !tools->stack_b)
			return (0);
		tools->stack_b->ptr = NULL;
		list_to_stack(tools->stack_a, tools->l_numbers);
		sorting_list(tools->l_numbers);
		sorting_algorithm(tools);
	}
	return (0);
}
