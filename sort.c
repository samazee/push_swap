/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:05:57 by azgor             #+#    #+#             */
/*   Updated: 2026/04/07 20:05:57 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *op)
{
	println(op);
}

static void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->a->index;
	second = stack->a->next->index;
	third = stack->a->next->next->index;
	if (first > second && second < third && first < third)
		print_op(SA);
	else if (first > second && second < third && first > third)
		print_op(RA);
	else if (first < second && second > third && first < third)
	{
		print_op(RRA);
		print_op(SA);
	}
	else if (first < second && second > third && first > third)
		print_op(RRA);
	else if (first > second && second > third)
	{
		print_op(SA);
		print_op(RRA);
	}
}

static void	sort_five(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		while (stack->a->index != i)
		{
			ra(stack);
			print_op(RA);
		}
		pb(stack);
		print_op(PB);
		i++;
	}
	if (stack->len_a == 3)
		sort_three(stack);
	else if (stack->len_a == 2)
	{
		if (stack->a->index > stack->a->next->index)
			print_op(SA);
	}
	pa(stack);
	print_op(PA);
	pa(stack);
	print_op(PA);
}

static void	sort_small(t_stack *stack)
{
	if (stack->len_a == 2)
	{
		if (stack->a->index > stack->a->next->index)
			print_op(SA);
	}
	else if (stack->len_a == 3)
		sort_three(stack);
	else if (stack->len_a <= 5)
		sort_five(stack);
	else
		radix_sort(stack);
}

void	push_swap(t_stack *stack)
{
	if (stack->len_a <= 1)
		return ;
	sort_small(stack);
}
