/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:16:35 by jeserran          #+#    #+#             */
/*   Updated: 2021/05/12 22:46:00 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = -1;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (++i < n && *(str1 + i) == *(str2 + i))
		;
	if (i == n)
		return (0);
	return (*(str1 + i) - *(str2 + i));
}
