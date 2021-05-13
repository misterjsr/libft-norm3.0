/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:49:55 by jeserran          #+#    #+#             */
/*   Updated: 2021/05/13 00:54:13 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int nbr)
{
	size_t	i;
	char	*ret;
	int		sign;

	i = 0;
	ret = ft_strnew(ft_numlen(nbr));
	if (!ret)
		return (0);
	if (nbr == 0)
	{
		free(ret);
		return (ft_strdup("0"));
	}
	sign = nbr < 0;
	while (nbr != 0)
	{
		ret[i++] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign)
		ret[i++] = '-';
	ret[i++] = '\0';
	return (ft_strrev(ret));
}
