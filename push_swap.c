/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:52:45 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/26 20:41:24 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(count * size);
	if (!s)
		return (NULL);
	while (i < (count * size))
	{
		s[i] = 0;
		i++;
	}
	return (s);
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
		exit(0);
	if (tools->stack_a->size <= 3)
		sort_3(tools->stack_a);
	else if (tools->stack_a->size > 3 && tools->stack_a->size <= 5)
		sort_5(tools);
	else
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
	tools = ft_calloc(1, sizeof(t_tools));
	if (!tools || argc > 1)
	{
		while (i < argc)
		{
			if (!valid_arg(argv[i]))
				ft_crush();
			i++;
		}
		tools->tab = split_args(argv);
		check_double(tools);
		tools->stack_b = ft_calloc(1, sizeof(t_stack));
		tools->stack_a = ft_calloc(1, sizeof(t_stack));
		if (!tools->stack_a || !tools->stack_b)
			return (0);
		tools->stack_b->ptr = NULL;
		list_to_stack(tools->stack_a, tools->l_numbers);
		sorting_list(tools->l_numbers);
		sorting_algorithm(tools);
	}
	return (0);
}
