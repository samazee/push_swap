/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:04:18 by azgor             #+#    #+#             */
/*   Updated: 2026/04/07 20:04:19 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;

	top = stack->a;
	bottom = get_bottom_a(stack);
	stack->a = top->next;
	bottom->next = top;
	top->next = NULL;
	return (1);
}

int	rra(t_stack *stack)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*current;

	top = stack->a;
	bottom = get_bottom_a(stack);
	current = stack->a;
	while (current->next != bottom)
		current = current->next;
	current->next = NULL;
	stack->a = bottom;
	stack->a->next = top;
	return (1);
}

int	rr(t_stack *stack)
{
	return (ra(stack) && rb(stack));
}
