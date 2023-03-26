/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:36:28 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/24 17:06:56 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	int		content;
	t_list	*ptr;

	if (stack->size <= 1)
		return ;
	ptr = stack->ptr;
	content = pop(stack);
	push(stack, content);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	int		content;
	t_list	*ptr;

	if (stack->size <= 1)
		return ;
	ptr = stack->ptr;
	content = pop(stack);
	push(stack, content);
	write(1, "rb\n", 3);
}

void	rr(t_tools *tools)
{
	int		content;
	t_list	*ptr;

	if (tools->stack_a->size <= 1 || tools->stack_b->size <= 1)
		return ;
	ptr = tools->stack_a->ptr;
	content = pop(tools->stack_a);
	push(tools->stack_a, content);
	ptr = tools->stack_b->ptr;
	content = pop(tools->stack_b);
	push(tools->stack_b, content);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack *stack)
{
	t_list	*last_node;
	t_list	*blast_node;

	blast_node = stack->ptr;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&stack->ptr, last_node);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack)
{
	t_list	*last_node;
	t_list	*blast_node;

	blast_node = stack->ptr;
	while (blast_node->next->next)
		blast_node = blast_node->next;
	last_node = blast_node->next;
	blast_node->next = NULL;
	ft_lstadd_front(&stack->ptr, last_node);
	write(1, "rrb\n", 4);
}
