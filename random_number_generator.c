/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_number_generator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:21:32 by achak             #+#    #+#             */
/*   Updated: 2023/12/07 15:39:13 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int	count_digits(long nbr)
{
	int	digits;

	digits = 1;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		digits++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(long nbr)
{
	char	*str;
	int		digits;

	digits = count_digits(nbr);
	str = malloc(sizeof(char) * (digits + 2));
	if (str == NULL)
		return (NULL);
	str[digits + 1] = '\0';
	str[digits] = ' ';
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	while (digits-- > 0)
	{
		if (nbr == 0)
			break ;
		str[digits] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

int	ai(char *str)
{
	long	nbr;
	int		check;

	nbr = 0;
	check = 1;
	while (*str == 32 || *str == '\n' || *str == '\f' || *str == '\r'
		|| *str == '\v' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			check = -1;
	}
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
		nbr = nbr * 10 + (*str++ - '0');
	if ((nbr * check) > 2147483647 || (nbr * check) < -2147483648)
	{
		write(2, "Invalid nbr\n", 12);
		exit(1);
	}
	return ((int)(nbr * check));
}

int	check_repeated(int newnumber, int *arr, int i, int c)
{
	while (i <= c)
	{
		if (arr[i] == newnumber)
			return (0);
		else if (arr[i] != newnumber)
			i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	*arr;
	int	i;
	int	c;
	int	newnumber;

	c = 0;
	srand(time(0));
	arr = malloc(sizeof(int) * (ai(av[1]) + 1));
	arr[ai(av[1])] = '\0';
	while (c < ai(av[1]) && ac == 4)
	{
		newnumber = ((rand() % (ai(av[3]) - ai(av[2]) + 1)) + ai(av[2]));
		i = 0;
		if (check_repeated(newnumber, arr, i, c) == 1)
		{
			arr[c] = newnumber;
			write(1, ft_itoa(arr[c]), count_digits(arr[c]) + 1);
			c++;
		}
	}
	return (0);
}
