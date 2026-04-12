/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 20:29:44 by azgor             #+#    #+#             */
/*   Updated: 2026/04/11 20:45:57 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

int	is_valid_char(char c)
{
	return (is_whitespace(c) || is_digit(c) || is_sign(c));
}

int	is_valid_arglist(char *s)
{
	if (!*s)
		return (0);
	while (*s)
	{
		if (!is_valid_char(*s)
			|| (*(s + 1) && is_digit(*s) && is_sign(*(s + 1)))
			|| (*(s + 1) && is_sign(*s) && is_whitespace(*(s + 1)))
			|| (*(s + 1) && is_sign(*s) && is_sign(*(s + 1))))
			return (0);
		s++;
	}
	return (1);
}
