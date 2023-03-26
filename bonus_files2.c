/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_files2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:52:25 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/24 19:53:18 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_rotate_b(t_stack *stack)
{
	int		content;
	t_list	*ptr;

	if(stack->size <= 1)
		return ;
	ptr = stack->ptr;
	content = pop(stack);
	push(stack, content);
}

void	bonus_rr(t_tools *tools)
{
	int		content;
	t_list	*ptr;

	if(tools->stack_a->size <= 1 || tools->stack_b->size <= 1)
		return ;
	ptr = tools->stack_a->ptr;
	content = pop(tools->stack_a);
	push(tools->stack_a, content);

	ptr = tools->stack_b->ptr;
	content = pop(tools->stack_b);
	push(tools->stack_b, content);
}

void	bonus_reverse_rotate_a(t_stack *stack)
{
	t_list	*last_node;
	t_list	*blast_node;

	if(stack->size <= 1)
		return ;
	blast_node = stack->ptr;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&stack->ptr, last_node);
}

void	bonus_reverse_rotate_b(t_stack *stack)
{
	t_list	*last_node;
	t_list	*blast_node;
	
	if(stack->size <= 1)
		return ;
	blast_node = stack->ptr;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&stack->ptr, last_node);
}

void	bonus_rrr(t_tools *tools) //SHOULD BE FIXED
{
	t_list	*last_node;
	t_list	*blast_node;

	if(tools->stack_a->size <= 1 || tools->stack_b->size <= 1)
		return;
	blast_node = tools->stack_a->ptr;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&tools->stack_a->ptr, last_node);
	blast_node = tools->stack_b->ptr;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&tools->stack_b->ptr, last_node);
}