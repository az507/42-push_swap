/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:12:22 by achak             #+#    #+#             */
/*   Updated: 2024/02/24 13:35:30 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack *ptr_b, t_stack **a, t_stack **b)
{
	if ((float)ptr_b->target <= median(*a)
		&& (float)ptr_b->index <= median(*b))
		rarb_both(ptr_b, a, b);
	else if ((float)ptr_b->target > median(*a)
		&& (float)ptr_b->index > median(*b))
		rrarrb_both(ptr_b, a, b);
	else if ((float)ptr_b->target <= median(*a)
		&& (float)ptr_b->index > median(*b))
		rarrb_both(ptr_b, a, b);
	else if ((float)ptr_b->target > median(*a)
		&& (float)ptr_b->index <= median(*b))
		rrarb_both(ptr_b, a, b);
	pa(a, b, 1);
}

t_stack	*find_min_steps(t_stack *b)
{
	int		min;
	t_stack	*temp;

	min = INT_MAX;
	temp = b;
	while (temp)
	{
		if (temp->steps < min)
			min = temp->steps;
		temp = temp->next;
	}
	while (b)
	{
		if (b->steps == min)
			return (b);
		b = b->next;
	}
	return (b);
}

void	sort_3_nbrs(t_stack **a)
{
	if ((*a)->nbr == find_max(*a))
		ra(a, 1);
	else if ((*a)->next->nbr == find_max(*a))
		rra(a, 1);
	if ((*a)->nbr != find_min(*a))
		sa(a, 1);
}

int	min_pos_in_stack(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	assign_index(stack, NULL);
	min = find_min(stack);
	while (stack)
	{
		if (stack->nbr == min)
			return (stack->index);
		stack = stack->next;
	}
	return (-1);
}

void	sort_stack(t_stack **a)
{
	t_stack	*b;
	t_stack	*temp_b;

	b = NULL;
	while (size_of_stack(*a) > 3)
		pb(a, &b, 1);
	sort_3_nbrs(a);
	while (b)
	{
		assign_index(*a, b);
		temp_b = b;
		while (temp_b)
		{
			assign_target(*a, temp_b);
			calc_steps(*a, b, temp_b);
			temp_b = temp_b->next;
		}
		rotate_both(find_min_steps(b), a, &b);
	}
	if ((float)min_pos_in_stack(*a) > median(*a))
		while ((*a)->nbr != find_min(*a))
			rra(a, 1);
	else
		while ((*a)->nbr != find_min(*a))
			ra(a, 1);
}

/*
	printf("===stack a===\n");
	while (*a)
	{
		printf("a->nbr %d\n", (*a)->nbr);
		*a = (*a)->next;
	}
	printf("===stack b===\n");
	while (b)
	{
		printf("b->nbr = %d\n", b->nbr);
		b = b->next;
	}
*/
