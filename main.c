/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 21:02:10 by azgor             #+#    #+#             */
/*   Updated: 2026/04/11 21:13:12 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

static int	get_total_len(int argc, char **argv)
{
	int	len;
	int	i;

	len = 0;
	i = 1;
	while (i < argc)
		len += ft_strlen(argv[i++]) + 1;
	return (len);
}

char	*join_args(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	str = malloc(get_total_len(argc, argv) * sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		len = 0;
		while (argv[i][len])
			str[j++] = argv[i][len++];
		if (i < argc - 1)
			str[j++] = ' ';
		i++;
	}
	str[j] = '\0';
	return (str);
}

static t_stack	*parse_joined(char *joined, char ***args_out)
{
	t_stack	*stack;
	int		args_len;

	*args_out = ft_split(joined);
	if (!*args_out)
	{
		free(joined);
		return (NULL);
	}
	args_len = word_count(joined);
	free(joined);
	stack = parse_stack(args_len, *args_out);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**args;
	char	*joined;

	if (argc < 2)
		return (0);
	joined = join_args(argc, argv);
	if (!joined || !is_valid_arglist(joined))
	{
		if (joined)
			free(joined);
		println("Error");
		return (1);
	}
	stack = parse_joined(joined, &args);
	if (!stack)
	{
		free_args(args);
		println("Error");
		return (1);
	}
	push_swap(stack);
	free_stack(stack);
	free_args(args);
	return (0);
}
