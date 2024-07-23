/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:07:34 by achak             #+#    #+#             */
/*   Updated: 2024/02/27 16:01:09 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *a)
{
	int	num;

	if (!a)
		return (1);
	while (a->next)
	{
		num = a->nbr;
		a = a->next;
		if (num >= a->nbr)
			return (1);
	}
	return (0);
}

int	check_dups(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		while (temp->next)
		{
			temp = temp->next;
			if (temp->nbr == stack->nbr)
				return (1);
		}
		stack = stack->next;
	}
	return (0);
}

float	median(t_stack *head)
{
	return ((float)size_of_stack(head) / 2.0);
}

t_stack	*find_2ndlastnode(t_stack *ptr)
{
	while (ptr->next->next)
		ptr = ptr->next;
	return (ptr);
}

t_stack	*find_last_node(t_stack *ptr)
{
	if (!ptr)
		return (NULL);
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
