/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:06:35 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/22 13:03:59 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
//#include <stddef.h>
//#include <stdlib.h>
# include "inc/ft_printf/ft_printf.h"

typedef struct t_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct t_stack_node	*target_node;
	struct t_stack_node	*next;
	struct t_stack_node	*prev;
}						t_stack_node;
//error handelr
int						syntax_error(char *str_n);
int						dup_error(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a);
int						ft_isdigit(int c);

void					init_stack_a(t_stack_node **a, char **argv);
char					**split(char *s, char c);

void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
void					current_index(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
t_stack_node			*get_cheapest(t_stack_node *stack);
void					prep_for_push(t_stack_node **s, t_stack_node *n,
							char c);

int						stack_len(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
//commands
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);

void					sort_mini(t_stack_node **a);
void					min_on_top(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
