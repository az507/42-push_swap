/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:08:18 by achak             #+#    #+#             */
/*   Updated: 2024/02/27 12:31:30 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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
		create_new_node(a, ft_atoi(arr[i++]));
	free_arr(arr, i);
}

void	put_arguments_in_stack(int ac, char **av, t_stack **a)
{
	if (ac < 2)
		print_error();
	else if (ac == 2)
		put_arguments_in_stack2(av[1], a);
	else
		while (*++av)
			create_new_node(a, ft_atoi(*av));
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
*/

int	main(int ac, char **av)
{
	t_stack	*a;

	a = NULL;
	if (ac == 1)
		return (1);
	put_arguments_in_stack(ac, av, &a);
	if (!a)
		print_error();
	if (check_dups(a))
	{
		free_stack(&a);
		print_error();
	}
	if (check_sorted(a))
		sort_stack(&a);
	free_stack(&a);
}

/*	main to test instructions
int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	a = NULL;
	b = NULL;
	put_arguments_in_stack(ac, av, &a);
	if (check_dups(a))
	{
		free_stack(&a);
		print_error();
	}
	pb(&a, &b, 1);
	pb(&a, &b, 1);
	pb(&a, &b, 1);
	pb(&a, &b, 1);
	pb(&a, &b, 1);
	printf("===stack a===\n");
	temp_a = a;
	while (temp_a)
	{
		printf("a->nbr %d\n", temp_a->nbr);
		temp_a = temp_a->next;
	}
	printf("===stack b===\n");
	temp_b = b;
	while (temp_b)
	{
		printf("b->nbr = %d\n", temp_b->nbr);
		temp_b = temp_b->next;
	}
	rrr(&a, &b, 1);
	rrr(&a, &b, 1);
	rrr(&a, &b, 1);
	printf("\nafter rrr\n");
	printf("===stack a===\n");
	while (a)
	{
		printf("a->nbr %d\n", a->nbr);
		a = a->next;
	}
	printf("===stack b===\n");
	while (b)
	{
		printf("b->nbr = %d\n", b->nbr);
		b = b->next;
	}
}
*/
