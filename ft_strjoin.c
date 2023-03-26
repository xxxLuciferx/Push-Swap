/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:17:01 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/23 17:46:24 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		str1;
	int		str2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	res = (char *)malloc(str1 + str2 + 1);
	if (!res)
		return (NULL);
	while (++j < str1)
		res[j] = s1[j];
	while (++i < str2)
		res[i + j] = s2[i];
	res[i + j] = '\0';
	free(s1);
	return (res);
}

void	sorting_list(t_list *l_numbers)
{
	int		swap;
	t_list	*ptr_sorted;

	ptr_sorted = l_numbers;
	while (l_numbers && l_numbers->next)
	{
		if (l_numbers->content > l_numbers->next->content)
		{
			swap = l_numbers->content;
			l_numbers->content = l_numbers->next->content;
			l_numbers->next->content = swap;
			l_numbers = ptr_sorted;
		}
		else if (l_numbers->content <= l_numbers->next->content)
			l_numbers = l_numbers->next;
	}
}

int	bigest(t_stack *stack)
{
	int		biggest_number;
	t_list	*ptr;

	biggest_number = stack->ptr->content;
	ptr = stack->ptr->next;
	while (ptr)
	{
		if (biggest_number < ptr->content)
			biggest_number = ptr->content;
		ptr = ptr->next;
	}
	return (biggest_number);
}

int	smallest(t_stack *stack)
{
	int		smallest_number;
	t_list	*ptr;

	ptr = stack->ptr;
	smallest_number = ptr->content;
	while (ptr->next)
	{
		if (smallest_number > ptr->next->content)
			smallest_number = ptr->next->content;
		ptr = ptr->next;
	}
	return (smallest_number);
}
