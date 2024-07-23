/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:56:26 by achak             #+#    #+#             */
/*   Updated: 2024/02/27 15:53:32 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_new_node(t_stack **a, int nbr)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	if (!*a)
		*a = new_node;
	else
		find_last_node(*a)->next = new_node;
	new_node->nbr = nbr;
	new_node->index = 0;
	new_node->target = 0;
	new_node->steps = 0;
	new_node->next = NULL;
}

void	put_arguments_in_stack2(char *av, t_stack **a)
{
	char	**arr;
	int		i;

	arr = ft_split(av, ' ');
	i = 0;
	while (arr[i])
		create_new_node(a, ft_atoi(arr[i++], a, arr));
	free_arr(arr, i);
}

void	put_arguments_in_stack(int ac, char **av, t_stack **a)
{
	if (ac == 2)
		put_arguments_in_stack2(av[1], a);
	else if (*(av + 1))
		while (*++av)
			create_new_node(a, ft_atoi(*av, a, NULL));
	if (!*a)
		print_error();
}
