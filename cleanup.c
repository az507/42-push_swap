/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:35:58 by achak             #+#    #+#             */
/*   Updated: 2024/02/27 15:06:53 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	clean_prior_mallocs(t_stack **a, char **arr_split)
{
	t_stack	*temp;

	if (arr_split)
		free_array(arr_split);
	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
	print_error();
}

void	free_stack(t_stack **head)
{
	t_stack	*temp;

	while (*head)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
}
