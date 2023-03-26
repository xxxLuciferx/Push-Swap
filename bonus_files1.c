/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_files1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:19:21 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/24 19:54:12 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	bonus_swap_a(t_stack *stack)
{
	int	swap;
	
	if(stack->size <= 1)
		return;
	swap = stack->ptr->content;
	stack->ptr->content = stack->ptr->next->content;
	stack->ptr->next->content = swap;
}

void	bonus_swap_b(t_stack *stack)
{
	int	swap;
	
	if(stack->size <= 1)
		return;
	swap = stack->ptr->content;
	stack->ptr->content = stack->ptr->next->content;
	stack->ptr->next->content = swap;
}

void	bonus_ss(t_tools *tools)
{
	int	swap;

	if(tools->stack_a->size <= 1)
		return;
	swap = tools->stack_a->ptr->content;
	tools->stack_a->ptr->content = tools->stack_a->ptr->next->content;
	tools->stack_a->ptr->next->content = swap;
	swap = tools->stack_b->ptr->content;
	tools->stack_b->ptr->content = tools->stack_b->ptr->next->content;
	tools->stack_b->ptr->next->content = swap;
}

void	bonus_push_a(t_tools *tools)
{
	if(tools->stack_b->size == 0)
		return ;
	push_to_a(tools->stack_a, pop(tools->stack_b));
}

void	bonus_push_b(t_tools *tools)
{
	if(tools->stack_a->size == 0)
		return ;
	push_to_b(tools->stack_b, pop(tools->stack_a));
}

