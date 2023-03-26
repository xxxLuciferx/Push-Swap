/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:07:37 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/19 14:45:01 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_crush(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*d;

	if (!lst || !new)
		return ;
	d = *lst;
	if (*lst)
	{
		while (d -> next)
			d = d -> next;
		d -> next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new -> next = *lst;
		*lst = new;
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*file;

	file = (t_list *)malloc(sizeof(t_list));
	if (!file)
		return (NULL);
	file -> content = content;
	file -> next = NULL;
	return (file);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
