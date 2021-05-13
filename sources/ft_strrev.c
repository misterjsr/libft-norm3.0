/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 00:45:46 by jeserran          #+#    #+#             */
/*   Updated: 2021/05/13 01:20:24 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	int		a;
	int		b;
	char	c;

	a = 0;
	b = 0;
	while (str[a] != '\0')
		a++;
	a = a - 1;
	while (a > b)
	{
		c = str[a];
		str[a] = str[b];
		str[b] = c;
		b++;
		a--;
	}
	return (str);
}
