/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:02:54 by azgor             #+#    #+#             */
/*   Updated: 2026/04/11 20:44:19 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	long			value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				len_a;
	int				len_b;
	t_node			*a;
	t_node			*b;
}					t_stack;

t_stack	*init_stack(int len);
void	free_stack(t_stack *stack);

void	push_swap(t_stack *stack);
void	print_op(char *op);
int		pa(t_stack *stack);
int		pb(t_stack *stack);
int		sa(t_stack *stack);
int		sb(t_stack *stack);
int		ss(t_stack *stack);
int		ra(t_stack *stack);
int		rb(t_stack *stack);
int		rr(t_stack *stack);
int		rra(t_stack *stack);
int		rrb(t_stack *stack);
int		rrr(t_stack *stack);

t_node	*get_bottom_a(t_stack *stack);
t_node	*get_bottom_b(t_stack *stack);

t_stack	*parse_stack(int argc, char **argv);
t_stack	*parse_string(char *str);
void	println(char *str);
int		ft_strlen(char *str);
long	ft_atol(const char *str);
char	**ft_split(char	*str);
int		is_overflow(const char *str);
int		is_number(char *str);
int		is_whitespace(char c);
int		is_valid_arglist(char *str);
int		word_count(char	*s);
int		validate(int argc, char **argv);
void	radix_sort(t_stack *stack);

#endif
