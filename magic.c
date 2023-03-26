/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:34:39 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/18 23:21:13 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *stack, int content)
{
	t_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_front(&stack->ptr, node);
	stack->size++;
}

void	push_to_b(t_stack *stack, int content)
{
	t_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_front(&stack->ptr, node);
	stack->size++;
}

int	get_index(t_tools *tools)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = tools->l_numbers;
	while (ptr)
	{
		if (ptr->content == tools->stack_a->ptr->content)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	index_smallest(t_stack *stack)
{
	int		i;
	t_list	*ptr;

	i = 1;
	ptr = stack->ptr;
	while (ptr)
	{
		if (ptr->content == smallest(stack))
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	index_bigest(t_stack *stack)
{
	int		i;
	t_list	*ptr;

	i = 1;
	ptr = stack->ptr;
	while (ptr)
	{
		if (ptr->content == bigest(stack))
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (i);
}
