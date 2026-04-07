/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:03:21 by azgor             #+#    #+#             */
/*   Updated: 2026/04/07 20:03:22 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;

	top = stack->b;
	bottom = get_bottom_b(stack);
	stack->b = top->next;
	bottom->next = top;
	top->next = NULL;
	return (1);
}

int	rrb(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*current;

	top = stack->b;
	bottom = get_bottom_b(stack);
	current = stack->b;
	while (current->next != bottom)
		current = current->next;
	current->next = NULL;
	stack->b = bottom;
	stack->b->next = top;
	return (1);
}

int	rrr(t_stack *stack)
{
	return (rra(stack) && rrb(stack));
}
