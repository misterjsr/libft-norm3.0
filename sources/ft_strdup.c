/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:00:38 by jeserran          #+#    #+#             */
/*   Updated: 2021/05/12 22:43:45 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		s;
	int		i;

	s = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * s + 1);
	if (!(dest))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}
