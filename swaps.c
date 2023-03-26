/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:50:27 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/24 16:55:24 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	swap;

	if(stack->size <= 1)
		return;
	swap = stack->ptr->content;
	stack->ptr->content = stack->ptr->next->content;
	stack->ptr->next->content = swap;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	int	swap;

	if(stack->size <= 1)
		return;
	swap = stack->ptr->content;
	stack->ptr->content = stack->ptr->next->content;
	stack->ptr->next->content = swap;
	write(1, "sb\n", 3);
}

void	ss(t_tools *tools)
{
	int swap;
	
	if(tools->stack_a->size <= 1)
		return;
	swap = tools->stack_a->ptr->content;
	tools->stack_a->ptr->content = tools->stack_a->ptr->next->content;
	tools->stack_a->ptr->next->content = swap;
	swap = tools->stack_b->ptr->content;
	tools->stack_b->ptr->content = tools->stack_b->ptr->next->content;
	tools->stack_b->ptr->next->content = swap;
	write(1, "ss\n", 3);
}

void	push_a(t_tools *tools)
{
	if(tools->stack_b->size == 0)
		return ;
	push_to_a(tools->stack_a, pop(tools->stack_b));
	write(1, "pa\n", 3);
}

void	push_b(t_tools *tools)
{
	if(tools->stack_a->size == 0)
		return ;
	push_to_b(tools->stack_b, pop(tools->stack_a));
	write(1, "pb\n", 3);
}
