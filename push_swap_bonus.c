/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:27:26 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/11 00:45:50 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	arg_to_at(int valeur, t_list **a)
{
	t_list	*tmp;
	t_list	*new;

	tmp = (*a);
	while (tmp)
	{
		if (tmp->data == valeur)
			return (0);
		tmp = tmp->next;
	}
	new = ft_lstnew(valeur);
	ft_lstadd_back(a, new);
	return (1);
}

static int	is_digitt(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
} 
static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1)
		return (1);
	i = 0;
	while ((s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i]-s2[i]);
}

static void	printferror(void)
{
	write(1, "error\n", 6);
}

static int	ft_checker_min(t_list **a, t_list **b, char *str)
{
	
	if (!ft_strcmp(str , "sa\n"))
	{
		sa(a);
	}
	else if (!ft_strcmp(str, "sb\n"))
		sb(b);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(str, "rr\n"))
		ra(a);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(str, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(str, "pb\n"))
		pb(a, b);
	else
	{
		printferror();
		exit(0);
	}
	return (1);
}
static void	free_tablet(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

static int	arg_to_intt(char **arg, t_list **a)
{
	int	j;
	int	tmp;

	j = 0;
	while (arg[j])
	{
		if (ft_checck(arg[j]) == 0)
			return(0);
		else
		{
			tmp = ft_atoi(arg[j]);
			if (arg_to_at(tmp, a) == 0)
			    return(0);
			j++;
		}
	}
	return (1);
}



static int	initialisation(int ac, char **av, t_list **a)
{
	char	**arg;
	int		i;

	i = 1;
	while (i < ac)
	{
		arg = ft_split(av[i++], ' ');
		if (!arg[0])
			return(0);
		if (arg_to_intt(arg, a) == 0)
			return(0);
			
		free_tablet(arg);
	}
	return (1);
}

int	ft_checck(char *str)
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
		if (is_digitt(str[i]) == 0)
			return(0);
		i++;
	}
	return (1);
}
static void	ft_checker(t_list **a, t_list **b)
{
	int		i;
	char	*str;

	i = 1;
	
	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			break ;
		}
			
		ft_checker_min(a, b, str);
		free(str);
	}
	if (check_is_sorted(a) && !ft_lstsize(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_list	*b;
	t_list	*a;
	int		coef;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		coef= initialisation(ac, av, &a);
		if (coef == 0)
		{
			write(1, "error\n", 6);
			exit(0);
		}
		else
		ft_checker(&a, &b);
	}
	return (0);
}