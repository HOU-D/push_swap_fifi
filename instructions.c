/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:14:37 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/08 23:11:14 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	int	tmp;

	if (!*a || ft_lstsize(*a) < 2) 
		return ;
	tmp = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp;
	write(1, "sa\n", 3);
	return;
}

void	sb(t_list **b)
{
	int	tmp;

	if (!*b || ft_lstsize(*b) < 2)
		return ;
	tmp = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = tmp;
	write(1, "sb\n", 3);
	return;
}

void	ss(t_list **a, t_list **b)
{
	if (!(*a) || ft_lstsize(*a) < 2 || !(*b) || ft_lstsize(*b) < 2)
		return ;
	sa(a);
	sa(b);
	write(1, "ss\n", 3);
}

void	ra(t_list **a)
{
	t_list	*tmp;

	if (!(*a) || ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	write(1, "ra\n", 3);
	return;
}

void	rb(t_list **b)
{
	t_list	*tmp;

	if (!(*b) || ft_lstsize(*b) < 2)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
	write(1, "rb\n", 3);
	return;
}

void	rr(t_list **a, t_list **b)
{
	if (!(*a) || ft_lstsize(*a) < 2 || !(*b) || ft_lstsize(*b) < 2)
		return;
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b || ft_lstsize(*b) < 1)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a || ft_lstsize(*a) < 1)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_front(b, tmp);
	write(1, "pb\n", 3);
}

void    rra(t_list **a)
{
    t_list  *tmp;
    t_list  *tmp1;

    if (!(*a) || ft_lstsize(*a) < 2)
        return ;
    tmp = (*a);
    while (tmp->next->next)
        tmp = tmp->next;
    tmp1 = tmp->next;
    tmp->next = NULL;
    tmp1->next = NULL;
    ft_lstadd_front(a, tmp1);
    write(1, "rra\n", 4);
    return ;
}

void    rrb(t_list **b)
{
    t_list  *tmp;
    t_list  *tmp1;

    if (!(*b) || ft_lstsize(*b) < 2)
        return ;
    tmp = (*b);
    while (tmp->next->next)
        tmp = tmp->next;
    tmp1 = tmp->next;
    tmp->next = NULL;
    tmp1->next = NULL;
    ft_lstadd_front(b, tmp1);
    write(1, "rrb\n", 4);
    return ;
}

void    rrr(t_list**a, t_list **b)
{
	if (!(*a) || ft_lstsize(*a) < 2 || !(*b) || ft_lstsize(*b) < 2)
		return ;
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}
