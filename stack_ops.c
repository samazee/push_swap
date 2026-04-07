/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:05:18 by azgor             #+#    #+#             */
/*   Updated: 2026/04/07 20:05:19 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int len)
{
	t_stack	*s;
	t_node	**current;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->len_a = 0;
	s->len_b = 0;
	current = &(s->a);
	while (s->len_a < len)
	{
		*current = malloc(sizeof(t_node));
		if (!*current)
			return (NULL);
		(*current)->index = -1;
		current = &((*current)->next);
		s->len_a++;
	}
	*current = NULL;
	s->b = NULL;
	return (s);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->a)
	{
		tmp = stack->a;
		stack->a = stack->a->next;
		free(tmp);
	}
	while (stack->b)
	{
		tmp = stack->b;
		stack->b = stack->b->next;
		free(tmp);
	}
	free(stack);
}

t_node	*get_bottom_a(t_stack *stack)
{
	t_node	*current;

	current = stack->a;
	while (current->next)
		current = current->next;
	return (current);
}

t_node	*get_bottom_b(t_stack *stack)
{
	t_node	*current;

	current = stack->b;
	while (current->next)
		current = current->next;
	return (current);
}
