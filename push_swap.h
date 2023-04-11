/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoakoumi <hoakoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:07:40 by hoakoumi          #+#    #+#             */
/*   Updated: 2023/04/09 17:28:13 by hoakoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_list
{
	int data;
	int index;
	struct s_list *next;
}t_list;

#include <unistd.h>
#include<stdlib.h>
#include<stdio.h>
void	free_table(char **a);
char	**ft_split(char	const	*s, char c);
int		ft_check(char *str);
int		arg_to_int(char **arg, t_list **a);
int		initialisation(int ac, char **av, t_list **a);
int		arg_to_a(int valeur, t_list **a);
int		is_digit(char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
void	sa(t_list **a);
void	sb(t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	ft_pa(t_list **a, t_list **b);
void	ft_pb(t_list **a, t_list **b);
void	ss(t_list **a, t_list **b);
int		ft_atoi(const	char	*str);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	sorting(t_list **a,t_list **b);
void	ra(t_list **a);
void	rra(t_list **a);
t_list	*ft_lstnew(int content);
void	sort_3(t_list **a);
void	sort_2(t_list **a);
int		ft_lstsize(t_list *lst);
int		check_is_sorted(t_list **a);
void    rra(t_list **a);
int     search_min(t_list **list) ;
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	sort_4_5(t_list **a, t_list **b);
int		get_index_min(t_list **list);
void	indice(t_list *list);
int	indice1(t_list *list);
int *tab_list(t_list **a, int size);
// void sort_500(t_list **a,  t_list **b, int n);
void    ft_swap(int *a, int *b);
void tri_selection (int *Tab, int size);
// size_t	ft_strlen1(int *s);
void push_to_b(t_list **a, t_list **b, int div);
void    rrb(t_list **b);
void push_to_a(t_list **a, t_list **b);
int *tab_list(t_list **a, int size);
void sort_100(t_list **a, t_list **b);
void sort_500(t_list **a, t_list **b);

#endif