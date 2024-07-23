/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:46:22 by achak             #+#    #+#             */
/*   Updated: 2024/01/09 13:12:39 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rarb_both(t_stack *ptr_b, t_stack **a, t_stack **b)
{
	while ((*a)->index != ptr_b->target && (*b)->index != ptr_b->index)
		rr(a, b, 1);
	while ((*a)->index != ptr_b->target)
		ra(a, 1);
	while ((*b)->index != ptr_b->index)
		rb(b, 1);
}

void	rrarrb_both(t_stack *ptr_b, t_stack **a, t_stack **b)
{
	while ((*a)->index != ptr_b->target && (*b)->index != ptr_b->index)
		rrr(a, b, 1);
	while ((*a)->index != ptr_b->target)
		rra(a, 1);
	while ((*b)->index != ptr_b->index)
		rrb(b, 1);
}

void	rarrb_both(t_stack *ptr_b, t_stack **a, t_stack **b)
{
	while ((*a)->index != ptr_b->target)
		ra(a, 1);
	while ((*b)->index != ptr_b->index)
		rrb(b, 1);
}

void	rrarb_both(t_stack *ptr_b, t_stack **a, t_stack **b)
{
	while ((*a)->index != ptr_b->target)
		rra(a, 1);
	while ((*b)->index != ptr_b->index)
		rb(b, 1);
}
