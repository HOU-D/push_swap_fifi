/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:06:56 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/10 21:14:21 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void h(t_list **a)
{
	int q;
	while((*a))
	{
		q = (*a)->data;
		printf("%d\n", q);
		(*a)=(*a)->next;
	}
}

int	main(int ac, char **av)
{
	int		coef;
	t_list	*a;
	t_list	*b;

	if (ac > 1)
	{
		a = NULL;
		b = NULL;
		coef= initialisation(ac, av, &a);
		// h(&a);
		if (coef == 0)
			write(1, "error\n", 6);
		else
			sorting(&a, &b);
		return (0);
	}
	
	return (0);
	//system("leaks push_swap");
}



int	arg_to_a(int valeur, t_list **a)
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

int	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}