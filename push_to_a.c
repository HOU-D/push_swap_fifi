/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:01:34 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/04 20:01:34 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_index_max(t_list **pile)
{
    t_list  *tmp;
    int     max;
    int     index_min;

    indice(*pile);
    tmp = *pile;
    max = tmp->data;
    index_min = 0;
    while (tmp)
    {
        if (max < tmp->data)
        {
            max = tmp->data;
            index_min = tmp->index;
        }
        tmp = tmp->next;
    }
    return (index_min);}


static	int	last_data_a(t_list *pile)
{
	if (!pile)
		return (0);
	while (pile->next)
		pile = pile->next;
	return (pile->data);
}

static	int	get_max(t_list *pile)
{
	int	max;

	if (!pile)
		return (0);
	max = pile->data;
	while (pile)
	{
		if (max < pile->data)
			max = pile->data;
		pile = pile->next;
	}
	return (max);
}

static	void	min_puch_to_a_inf_mid(t_list **a, t_list **b,int *down)
{
	while (get_index_max(b))
	{
		if (!*down || last_data_a(*a) < (*b)->data)
		{
			pa(a, b);
			ra(a);
			(*down)++;
		}
		else
			rb(b);
	}
}

static	void	min_puch_to_a_sup_mid(t_list **a, t_list **b,
	int *down)
{
	while (get_index_max(b))
	{
		if (!*down || last_data_a(*a) < (*b)->data)
		{
			pa(a,b);
			ra(a);
			(*down)++;
		}
		else
			rrb(b);
	}
}

void	push_to_a(t_list **a, t_list **b)
{
	int	down;
	int	mid;

	down = 0;
	indice(*b);
	while (*b)
	{
		mid = ft_lstsize(*b) / 2;
		if (get_index_max(b) > mid)
			min_puch_to_a_sup_mid(a, b, &down);
		else
			min_puch_to_a_inf_mid(a, b, &down);
		pa(a,b);
		while (down && get_max(*b) < last_data_a(*a))
		{
			rra(a);
			down--;
		}
	}
	while (down)
	{
		rra(a);
		down--;
	}
}