/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:05:40 by azgor             #+#    #+#             */
/*   Updated: 2026/04/07 20:05:41 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int		max;
	t_node	*tmp;

	max = 0;
	tmp = stack->a;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

static void	radix_pass(t_stack *stack, int bit)
{
	int		j;
	int		size;

	j = 0;
	size = stack->len_a;
	while (j < size)
	{
		if (((stack->a->index >> bit) & 1) == 0)
		{
			pb(stack);
			print_op(PB);
		}
		else
		{
			ra(stack);
			print_op(RA);
		}
		j++;
	}
	while (stack->len_b > 0)
	{
		pa(stack);
		print_op(PA);
	}
}

void	radix_sort(t_stack *stack)
{
	int		max;
	int		max_bits;
	int		i;

	max = get_max_bits(stack);
	max_bits = 0;
	while ((max >> max_bits) > 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		radix_pass(stack, i);
		i++;
	}
}
