/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_files3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:54:14 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/26 21:00:41 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bonus_rotate_a(t_stack *stack)
{
	int		content;
	t_list	*ptr;

	if (stack->size <= 1)
		return ;
	ptr = stack->ptr;
	content = pop(stack);
	push(stack, content);
}
