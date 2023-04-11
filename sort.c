/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:16:41 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/08 17:49:26 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_list **a)
{
    if (!*a)
        return ;
    sa(a);
}

void sort_3(t_list **a)
{
	if(!*a)
		return;
	if ((*a)->data > (*a)->next->data && (*a)->next->data < (*a)->next->next->data && (*a)->data < (*a)->next->next->data ) 
        sa(a);
    else if ((*a)->data < (*a)->next->data &&  (*a)->next->data > (*a)->next->next->data && (*a)->data > (*a)->next->next->data)
        rra(a);
    else if ((*a)->data > (*a)->next->data && (*a)->next->data < (*a)->next->next->data && (*a)->data > (*a)->next->next->data )
        ra(a);
    else if ((*a)->data > (*a)->next->data &&( *a)->next->data > (*a)->next->next->data )
    {
        sa(a);
        rra(a);
    }
    else if ((*a)->data < (*a)->next->data && (*a)->next->data > (*a)->next->next->data && (*a)->data < (*a)->next->next->data )
    {
        sa(a);
        ra(a);
    }
}

void	sort_4_5(t_list **a, t_list **b)
{
	int	moit;
    int index;
    // int i;
    index = get_index_min(a);
	moit = ft_lstsize(*a) / 2;
	while (ft_lstsize(*a) > 3)
	{
		if (get_index_min(a) > moit)
		{
            while(get_index_min(a))
				rra(a);
		}
		else
		{
             while(get_index_min(a))
                ra(a);
		}
		pb(a, b);
	}
	sort_3(a);
    pa(a, b);
    pa(a, b);
}


