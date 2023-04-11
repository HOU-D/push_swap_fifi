/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:11:13 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/10 23:42:48 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (is_digit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// static void	free_table(char **a)
// {
// 	int	i;

// 	i = 0;
// 	while (a[i])
// 	{
// 		free(a[i]);
// 		i++;
// 	}
// 	free(a);


int	arg_to_int(char **arg, t_list **a)
{
	int	j;
	int	tmp;

	j = 0;
	while (arg[j])
	{
		if (ft_check(arg[j]) == 0)
			return (0);
		else
		{
			tmp = ft_atoi(arg[j]);
			if (arg_to_a(tmp, a) == 0)
				return (0);
			j++;
		}
	}
	return (1);
}

int	initialisation(int ac, char **av, t_list **a)
{
	char	**arg;
	int		i;

	i = 1;
	while (i < ac)
	{
		arg = ft_split(av[i++], ' ');
		if (!arg[0])
			return (0);
		if (arg_to_int(arg, a) == 0)
			return (0);
		free_table(arg);
	}
	return (1);
}
