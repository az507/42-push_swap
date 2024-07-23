/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:29:50 by achak             #+#    #+#             */
/*   Updated: 2024/02/27 15:54:27 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_atoi(char *s, t_stack **a, char **arr_split)
{
	long	nbr;
	int		check;
	int		flag;

	nbr = 0;
	check = 1;
	flag = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			check = -1;
	while (*s >= '0' && *s <= '9')
	{
		flag = 0;
		nbr = nbr * 10 + (*s++ - '0');
	}
	if ((check == -1 && check * nbr < INT_MIN) || (check == 1 && nbr
			> INT_MAX) || *s || flag == 1)
		clean_prior_mallocs(a, arr_split);
	return ((int)(check * nbr));
}

/*
int	ft_atoi(char *s)
{
	long	nbr;
	int		check;
	int		flag;

	nbr = 0;
	check = 1;
	flag = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			check = -1;
	while (*s >= '0' && *s <= '9')
	{
		flag = 0;
		nbr = nbr * 10 + (*s++ - '0');
	}
	if ((check == -1 && check * nbr < INT_MIN) || (check == 1 && nbr > INT_MAX)
		|| *s || flag == 1)
		print_error();
	return ((int)(check * nbr));
}
*/

int	size_of_stack(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_max(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (max < stack->nbr)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (min > stack->nbr)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
}

/*
int	main(void)
{
	printf("%d\n", ft_atoi("123 1 2"));
}
*/
