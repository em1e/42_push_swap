/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:14:43 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/07 09:36:10 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s, char c)
{
	int		words;

	if (!s)
		return (0);
	words = 1;
	while (*s)
	{
		if (*s == c)
			++words;
		++s;
	}
	return (words);
}

char	*next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			word_len;
	int			i;

	word_len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + word_len] != c) && s[cursor + word_len])
		++word_len;
	next_word = malloc((size_t)word_len * sizeof(char) + 1);
	if (!next_word)
		return (0);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	int		words;
	char	**array;
	int		i;

	i = 0;
	words = count_words(s, c);
	array = malloc(sizeof(char *) * (size_t)(words + 2));
	if (!array)
		return (0);
	while (words-- > 0)
	{
		array[i] = next_word(s, c);
		if (!array[i])
			return (0);
		i++;
	}
	array[i] = 0;
	return (array);
}
