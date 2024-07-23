/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:45:40 by achak             #+#    #+#             */
/*   Updated: 2024/01/04 13:15:03 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
	if (i == 1)
		write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
	if (i == 1)
		write(1, "pa\n", 3);
}

void	sa(t_stack **a, int i)
{
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int i)
{
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int i)
{
	if (*a == NULL || (*a)->next == NULL
		|| *b == NULL || (*b)->next == NULL)
		return ;
	sa(a, 0);
	sb(b, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}
