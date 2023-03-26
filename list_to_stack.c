/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:08:42 by khaimer           #+#    #+#             */
/*   Updated: 2023/03/26 20:01:55 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int valid_arg(char *str)
{
    int i = 0;
    while(str && str[i])
    {
		if((str[i] != ' ' && str[i] != '+' && str[i] != '-') && (str[i] < '0' || str[i] > '9'))
			ft_crush();
		if((str[i] == '+' || str[i] == '-') && (str[i + 1] < '0' || str[i + 1] > '9'))
			ft_crush();
        i++;
		if((str[i - 1] >= '0' && str[i - 1] <= '9') && (str[i] == '+' || str[i] == '-'))
			ft_crush();		
    }
    return 1;
}

char	**split_args(char **str)
{
	int		i;
	char	*string;
	char	**tab;

	i = 1;
	string = (char *)malloc(sizeof(char) * 2);
	if (!string)
		return (0);
	string[1] = '\0';
	while (str[i])
	{
		string = ft_strjoin(string, str[i]);
		string = ft_strjoin(string, " ");
		i++;
	}
	tab = ft_split(string, ' ');
	free(string);
	return (tab);
}

int	ft_intcmp(char *s1, char *s2)
{
	if (ft_atoi(s1) == ft_atoi(s2))
		return (1);
	return (0);
}

void	check_double(t_tools *tools)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tools->tab[i])
	{
		j = i + 1;
		while (tools->tab[j])
		{
			if (ft_intcmp(tools->tab[i], tools->tab[j]) == 1)
				ft_crush();
			j++;
		}
		i++;
	}
	i = 0;
	while (tools->tab[i])
	{
		tools->int_atoi = ft_atoi(tools->tab[i]);
		ft_lstadd_back(&tools->l_numbers, ft_lstnew(tools->int_atoi));
		i++;
	}
}
