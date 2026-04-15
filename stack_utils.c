/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 21:02:10 by azgor             #+#    #+#             */
/*   Updated: 2026/04/11 21:13:12 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*curr;

	curr = stack->a;
	while (curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

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

t_stack	*parse_stack(int args_len, char **args)
{
	t_stack	*stack;
	t_node	**current;
	int		i;

	if (validate(args_len, args))
	{
		stack = init_stack(args_len);
		if (!stack)
			return (NULL);
		current = &(stack->a);
		i = 0;
		while (*current)
		{
			(*current)->value = ft_atol(args[i]);
			current = &((*current)->next);
			i++;
		}
		index_stack(stack);
		return (stack);
	}
	return (NULL);
}
