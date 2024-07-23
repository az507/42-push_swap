/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:33:30 by achak             #+#    #+#             */
/*   Updated: 2024/02/24 18:10:09 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int i)
{
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = find_last_node(*a);
	temp->next = *a;
	*a = (*a)->next;
	temp->next->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int i)
{
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = find_last_node(*b);
	(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int i)
{
	if (*a == NULL || (*a)->next == NULL
		|| *b == NULL || (*b)->next == NULL)
		return ;
	ra(a, 0);
	rb(b, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
