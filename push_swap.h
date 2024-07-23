/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achak <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 09:24:27 by achak             #+#    #+#             */
/*   Updated: 2024/02/27 15:34:45 by achak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				target;
	int				steps;
	struct s_stack	*next;
}	t_stack;

void	create_new_node(t_stack **a, int nbr);
void	put_arguments_in_stack(int ac, char **av, t_stack **a);
void	put_arguments_in_stack2(char *av, t_stack **a);

int		count_words(char *s, char sep);
int		word_len(char *s, char sep);
void	free_arr(char **arr, int j);
void	split_words(char **arr, char *str, char sep);
char	**ft_split(char *str, char sep);

int		ft_atoi(char *s, t_stack **a, char **arr_split);
void	print_error(void);
int		size_of_stack(t_stack *stack);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);

void	pb(t_stack **a, t_stack **b, int i);
void	pa(t_stack **a, t_stack **b, int i);
void	sa(t_stack **a, int i);
void	sb(t_stack **b, int i);
void	ss(t_stack **a, t_stack **b, int i);

void	ra(t_stack **a, int i);
void	rb(t_stack **b, int i);
void	rr(t_stack **a, t_stack **b, int i);

void	rra(t_stack **a, int i);
void	rrb(t_stack **b, int i);
void	rrr(t_stack **a, t_stack **b, int i);

int		min_pos_in_stack(t_stack *stack);
void	sort_stack(t_stack **a);
void	sort_3_nbrs(t_stack **a);
t_stack	*find_min_steps(t_stack *b);
void	rotate_both(t_stack *ptr_b, t_stack **a, t_stack **b);

void	assign_index(t_stack *a, t_stack *b);
void	assign_target2(t_stack *a, t_stack *b);
void	assign_target(t_stack *a, t_stack *b);
void	calc_steps(t_stack *head_a, t_stack *head_b, t_stack *b);

void	rarb_both(t_stack *ptr_b, t_stack **a, t_stack **b);
void	rrarrb_both(t_stack *ptr_b, t_stack **a, t_stack **b);
void	rarrb_both(t_stack *ptr_b, t_stack **a, t_stack **b);
void	rrarb_both(t_stack *ptr_b, t_stack **a, t_stack **b);

void	read_instructions(char *s, t_stack **a, t_stack **b);
void	checker_write(t_stack *a, t_stack *b);
void	exit_gnl(char *s, t_stack **a, t_stack **b);

void	clean_prior_mallocs(t_stack **a, char **arr_split);
void	free_array(char **arr);
void	free_stack(t_stack **head);

int		check_sorted(t_stack *a);
int		check_dups(t_stack *head_a);
float	median(t_stack *head);
t_stack	*find_2ndlastnode(t_stack *ptr);
t_stack	*find_last_node(t_stack *ptr);

#endif
