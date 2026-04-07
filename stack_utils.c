/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:03:59 by azgor             #+#    #+#             */
/*   Updated: 2026/04/07 20:03:59 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_next_min(t_stack *stack)
{
	t_node	*a;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	a = stack->a;
	while (a)
	{
		if ((a->index == -1) && (!has_min || a->value < min->value))
		{
			min = a;
			has_min = 1;
		}
		a = a->next;
	}
	return (min);
}

void	index_stack(t_stack *stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

t_stack	*parse_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_node	**current;
	int		i;

	if (validate(argc, argv))
	{
		stack = init_stack(argc - 1);
		if (!stack)
			return (NULL);
		current = &(stack->a);
		i = 0;
		while (*current)
		{
			(*current)->value = ft_atol(argv[i++ + 1]);
			current = &((*current)->next);
		}
		index_stack(stack);
		return (stack);
	}
	return (NULL);
}
