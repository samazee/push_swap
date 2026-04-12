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

static int	allocate_nodes(t_stack *s, int len)
{
	t_node	**current;

	current = &(s->a);
	while (s->len_a < len)
	{
		*current = malloc(sizeof(t_node));
		if (!*current)
			return (0);
		(*current)->index = -1;
		(*current)->next = NULL;
		current = &((*current)->next);
		s->len_a++;
	}
	*current = NULL;
	return (1);
}

t_stack	*init_stack(int len)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->a = NULL;
	s->b = NULL;
	s->len_a = 0;
	s->len_b = 0;
	if (!allocate_nodes(s, len))
	{
		free_stack(s);
		return (NULL);
	}
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
