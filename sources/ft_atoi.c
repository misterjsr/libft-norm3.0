/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchi <chuchi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:43:57 by jeserran          #+#    #+#             */
/*   Updated: 2020/02/14 20:11:03 by chuchi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int long	res;
	int			neg;
	const char	*s;

	s = str;
	while (*s && ft_isspace(*s))
		s++;
	neg = 1;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			neg = -1;
	res = 0;
	while (ft_isdigit(*s))
	{
		res = res * 10 + neg * (*s++ - 48);
		if (res > 2147483647 && neg == 1)
			return (-1);
		if (res > 2147483648 && neg == -1)
			return (0);
	}
	return (res);
}
