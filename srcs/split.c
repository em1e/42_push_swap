/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:14:43 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/12 10:42:43 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s, char c)
{
	int		words;
	int		i;

	i = 0;
	words = 1;
	if (!s)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			i++;
		if (ft_isdigit(s[i]) == 0 && s[i] != c)
		{
			error();
			return (-1);
		}
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	i = 0;
	return (words);
}

char	*next_word(char *s, char c)
{
	static int	index = 0;
	char		*next_word;
	int			word_len;
	int			new_i;

	word_len = 0;
	new_i = 0;
	while (s[index] == c)
		++index;
	while ((s[index + word_len] != c) && s[index + word_len])
		++word_len;
	next_word = malloc((size_t)word_len * sizeof(char) + 1);
	if (!next_word)
		return (0);
	while ((s[index] != c) && s[index])
		next_word[new_i++] = s[index++];
	next_word[new_i] = '\0';
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
