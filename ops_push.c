/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:05:00 by azgor             #+#    #+#             */
/*   Updated: 2026/04/07 20:05:01 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *stack)
{
	t_node	*top_b;
	t_node	*top_a;
	t_node	*next_b;

	top_b = stack->b;
	top_a = stack->a;
	if (!top_b)
		return (0);
	next_b = top_b->next;
	top_b->next = top_a;
	stack->a = top_b;
	stack->b = next_b;
	stack->len_a++;
	stack->len_b--;
	return (1);
}

int	pb(t_stack *stack)
{
	t_node	*top_b;
	t_node	*top_a;
	t_node	*next_a;

	top_b = stack->b;
	top_a = stack->a;
	if (!top_a)
		return (0);
	next_a = top_a->next;
	top_a->next = top_b;
	stack->b = top_a;
	stack->a = next_a;
	stack->len_b++;
	stack->len_a--;
	return (1);
}

int	sa(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->a;
	second = first->next;
	if (!second)
		return (0);
	third = second->next;
	stack->a = second;
	second->next = first;
	first->next = third;
	return (1);
}

int	sb(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->b;
	second = first->next;
	if (!second)
		return (0);
	third = second->next;
	stack->b = second;
	second->next = first;
	first->next = third;
	return (1);
}

int	ss(t_stack *stack)
{
	return (sa(stack) && sb(stack));
}
