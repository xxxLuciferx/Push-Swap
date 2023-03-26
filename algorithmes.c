/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 14:56:12 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/26 21:29:58 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	if (stack->size <= 2)
	{
		if (stack->ptr->content > stack->ptr->next->content)
		{
			rotate_a(stack);
			exit(0);
		}
	}
	if (stack->ptr->content == bigest(stack))
		rotate_a(stack);
	if (stack->ptr->next->content == bigest(stack))
		reverse_rotate_a(stack);
	if (stack->size > 2)
		if (stack->ptr->next->content == smallest(stack) && \
		stack->ptr->next->next->content == bigest(stack))
			swap_a(stack);
}

void	sort_5(t_tools *tools)
{
	int	index;

	index = index_smallest(tools->stack_a);
	while (tools->stack_a->size > 3)
	{
		while (tools->stack_a->ptr->content != smallest(tools->stack_a))
		{
			if (index > tools->stack_a->size / 2)
				reverse_rotate_a(tools->stack_a);
			else
				rotate_a(tools->stack_a);
		}
		push_b(tools);
	}
	sort_3(tools->stack_a);
	while (tools->stack_b->size > 0)
		push_a(tools);
}

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
	if (tools->stack_a->size >= 90)
		tools->range_max = 15;
	if (tools->stack_a->size >= 150)
		tools->range_max = 35;
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
