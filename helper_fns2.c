/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fns2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:03:52 by achak             #+#    #+#             */
/*   Updated: 2024/02/24 17:33:45 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (b)
	{
		b->index = i++;
		b = b->next;
	}
	i = 0;
	while (a)
	{
		a->index = i++;
		a = a->next;
	}
}

void	assign_target2(t_stack *a, t_stack *b)
{
	t_stack	*temp1;
	t_stack	*temp2;
	int		i;

	temp1 = a;
	temp2 = a->next;
	i = 0;
	while (temp2->next)
	{
		if (b->nbr > temp1->nbr && b->nbr < temp2->nbr)
		{
			b->target = ++i;
			return ;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
		i++;
	}
	if (b->nbr > temp2->nbr)
		b->target = 0;
	else
		b->target = ++i;
}

void	assign_target(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	if ((b->nbr < find_min(a)) || (b->nbr > find_max(a)))
	{
		while (a->nbr != find_min(a))
		{
			i++;
			a = a->next;
		}
		b->target = i;
	}
	else if (a->next)
		assign_target2(a, b);
}

void	calc_steps(t_stack *head_a, t_stack *head_b, t_stack *b)
{
	int	steps;

	steps = 0;
	if (b->index <= median(head_b) && b->target <= median(head_a))
	{
		if (b->index > b->target)
			steps = b->index;
		else
			steps = b->target;
	}
	else if (b->index > median(head_b) && b->target > median(head_a))
	{
		if ((size_of_stack(head_b) - b->index) > (size_of_stack(head_a)
				- b->target))
			steps = size_of_stack(head_b) - b->index;
		else
			steps = size_of_stack(head_a) - b->target;
	}
	else if (b->index > median(head_b) && b->target <= median(head_a))
		steps = (size_of_stack(head_b) - b->index) + b->target;
	else if (b->index <= median(head_b) && b->target > median(head_a))
		steps = (size_of_stack(head_a) - b->target) + b->index;
	if (steps < 0)
		steps *= -1;
	b->steps = steps;
}
