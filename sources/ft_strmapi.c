/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:51:18 by jeserran          #+#    #+#             */
/*   Updated: 2021/05/12 22:42:49 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*m;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	m = (char *)malloc(sizeof(char) * (len + 1));
	if (m == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		m[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	m[i] = '\0';
	return (m);
}
