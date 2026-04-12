/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgor <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:35:52 by azgor             #+#    #+#             */
/*   Updated: 2026/04/11 20:49:52 by azgor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	size_t			a_len;

	i = 0;
	a_len = ft_strlen(s) - start;
	if (len < a_len)
		a_len = len;
	substr = malloc((a_len + 1) * sizeof(char));
	if (!s || !substr)
		return (NULL);
	while (i < a_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

int	word_count(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && !is_whitespace(s[i]))
			|| (i > 0 && !is_whitespace(s[i]) && is_whitespace(s[i - 1])))
			count++;
		i++;
	}
	return (count);
}

static void	free_words(char **words, int iw)
{
	int	j;

	j = 0;
	while (j < iw)
	{
		free(words[j]);
		j++;
	}
	free(words);
}

static char	*get_next_word(char *s, int *i)
{
	int		start;

	while (s[*i] && is_whitespace(s[*i]))
		(*i)++;
	start = *i;
	while (s[*i] && !is_whitespace(s[*i]))
		(*i)++;
	return (ft_substr(s, start, *i - start));
}

char	**ft_split(char *s)
{
	char	**words;
	int		iw;
	int		i;

	iw = 0;
	i = 0;
	words = malloc((word_count(s) + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (iw < word_count(s))
	{
		words[iw] = get_next_word(s, &i);
		if (!words[iw])
		{
			free_words(words, iw);
			return (NULL);
		}
		iw++;
	}
	words[iw] = NULL;
	return (words);
}
