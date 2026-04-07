/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:02:44 by azgor             #+#    #+#             */
/*   Updated: 2026/04/07 20:06:29 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_pos_overflow(long res, int digit)
{
	if (res > LONG_MAX / 10)
		return (1);
	if (res == LONG_MAX / 10 && digit > LONG_MAX % 10)
		return (1);
	return (0);
}

static int	check_neg_overflow(long res, int digit)
{
	if (res > -(LONG_MIN / 10))
		return (1);
	if (res == -(LONG_MIN / 10) && digit > -(LONG_MIN % 10))
		return (1);
	return (0);
}

static int	has_overflow(long res, int is_neg, int digit)
{
	if (!is_neg)
		return (check_pos_overflow(res, digit));
	return (check_neg_overflow(res, digit));
}

static int	parse_overflow(const char *str, long start)
{
	long	res;
	long	i;
	int		digit;

	res = 0;
	i = start;
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if (has_overflow(res, (str[0] == '-'), digit))
			return (1);
		res = res * 10 + digit;
		i++;
	}
	return (0);
}

int	is_overflow(const char *str)
{
	long	i;

	if (!str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (parse_overflow(str, i));
}
