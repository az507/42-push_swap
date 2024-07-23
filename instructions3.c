/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:28:34 by achak             #+#    #+#             */
/*   Updated: 2024/02/24 16:59:26 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, int i)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp1 = find_last_node(*a);
	temp2 = find_2ndlastnode(*a);
	temp2->next = NULL;
	temp1->next = *a;
	*a = temp1;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int i)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp1 = find_last_node(*b);
	temp2 = find_2ndlastnode(*b);
	temp2->next = NULL;
	temp1->next = *b;
	*b = temp1;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int i)
{
	if (*a == NULL || (*a)->next == NULL
		|| *b == NULL || (*b)->next == NULL)
		return ;
	rra(a, 0);
	rrb(b, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
