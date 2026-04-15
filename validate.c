/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 21:02:10 by azgor             #+#    #+#             */
/*   Updated: 2026/04/11 21:13:12 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_empty_arg(int argc, char **argv)
{
	int	i;
	int	j;
	int	has_char;

	i = 1;
	while (i < argc)
	{
		j = 0;
		has_char = 0;
		while (argv[i][j])
		{
			if (!is_whitespace(argv[i][j]))
				has_char = 1;
			j++;
		}
		if (!has_char)
			return (1);
		i++;
	}
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 0)
		return (0);
	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		if (is_overflow(argv[i]))
			return (0);
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	println(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	write(1, "\n", 1);
}
