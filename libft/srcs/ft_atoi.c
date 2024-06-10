/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:11:58 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/10 12:58:28 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i] == '\f' || s[i] == '\t' || s[i] == ' '
		|| s[i] == '\n' || s[i] == '\r' || s[i] == '\v' )
		i++;
	sign = 1;
	if (s[i] == '-')
		sign *= -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] != '\0' && ft_isdigit(s[i]))
		res = (res * 10) + s[i++] - '0';
	res = res * sign;
	return (res);
}
