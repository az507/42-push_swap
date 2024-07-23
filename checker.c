/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:18:53 by achak             #+#    #+#             */
/*   Updated: 2024/02/27 15:53:08 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	exit_gnl(char *s, t_stack **a, t_stack **b)
{
	free(s);
	free_stack(a);
	free_stack(b);
	print_error();
}

void	read_instructions(char *s, t_stack **a, t_stack **b)
{
	if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		sa(a, 0);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		sb(b, 0);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		ss(a, b, 0);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		pa(a, b, 0);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		pb(a, b, 0);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		ra(a, 0);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		rb(b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		rr(a, b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rra(a, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rrb(b, 0);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		rrr(a, b, 0);
	else
		exit_gnl(s, a, b);
}

void	checker_write(t_stack *a, t_stack *b)
{
	if (check_sorted(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&a);
	free_stack(&b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*s;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	put_arguments_in_stack(ac, av, &a);
	if (check_dups(a))
	{
		free_stack(&a);
		print_error();
	}
	s = get_next_line(0);
	while (s)
	{
		read_instructions(s, &a, &b);
		free(s);
		s = get_next_line(0);
	}
	checker_write(a, b);
}

/*
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
*/
