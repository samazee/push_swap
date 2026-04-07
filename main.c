/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:03:40 by azgor             #+#    #+#             */
/*   Updated: 2026/04/07 20:03:43 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = parse_stack(argc, argv);
	if (!stack)
	{
		println("Error");
		return (1);
	}
	push_swap(stack);
	free_stack(stack);
	return (0);
}
