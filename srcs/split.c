/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:14:43 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/05 18:06:14 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s, char c)
{
	int		words;

	if (!s)
		return (0);
	words = 0;
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

	word_len = 1;
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
	int		words_count;
	char	**result_array;
	int		i;

	i = 0;
	// ft_printf("A test\n");
	words_count = count_words(s, c);
	if (words_count == 0)
		return (0);
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	// ft_printf("words_count: %d\n", words_count);
	if (!result_array)
		return (0);
	// ft_printf("B test\n");
	while (words_count-- > 0)
	{
		result_array[i] = next_word(s, c);
		if (!result_array[i])
		{
			// free_split(result_array);
			return NULL;
		}
		// ft_printf("result_array[%d]: %s\n", i, result_array[i]);
		i++;
	}
	// words_count = 0;
	// result_array[0] = "./push_swap";
	result_array[i] = 0;
	// while (words_count < i)
	// {
	// 	ft_printf("word %d: %s\n", words_count, result_array[words_count]);
	// 	++words_count;
	// }
	return (result_array);
}
