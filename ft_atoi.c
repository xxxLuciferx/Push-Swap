/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:48:01 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/24 19:49:37 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		a;
	long	res;
	int		sign;
	int		result;

	res = 0;
	a = 0;
	sign = 1;
	while (str[a] == ' ' || (str[a] <= 13 && str[a] >= 9))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign = sign * -1;
		a++;
	}
	while (str[a] <= '9' && str[a] >= '0')
	{
		res = str[a] - '0' + (res * 10);
		if ((res > INT_MAX && sign == 1) || (res > 2147483648 && sign == -1))
			ft_crush();
		a++;
	}
	result = res;
	return (result * sign);
}

void	list_to_stack(t_stack *stack, t_list *l_numbers)
{
	t_list	*ptr;

	ptr = l_numbers;
	
	while (ptr)
	{
		ft_lstadd_back(&stack->ptr, ft_lstnew(ptr->content));
		ptr = ptr->next;
	}
	stack->size = ft_lstsize(stack->ptr);
}

void	push(t_stack *stack, int content)
{
	t_list	*node;

	node = ft_lstnew(content);
	ft_lstadd_back(&stack->ptr, node);
	stack->size++;
}

int	pop(t_stack *stack)
{
	int		content;
	t_list	*ptr;
	
	content = stack->ptr->content;
	ptr = stack->ptr;
	if(stack->size >= 1)
	{
		stack->ptr = stack->ptr->next;
		stack->size--;
	}
	free(ptr);
	return (content);
}

void	rrr(t_tools *tools)
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
	write(1, "rrr\n", 4);
}
