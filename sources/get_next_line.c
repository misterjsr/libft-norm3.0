/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:52:58 by jeserran          #+#    #+#             */
/*   Updated: 2021/05/13 19:49:32 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*locate(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[j] != '\n' && str[j])
		j++;
	tmp = malloc((sizeof(char) * j) + 1);
	if (!tmp)
		return (NULL);
	while (i < j)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	join(char *buffer, char **save, char **line, int fd)
{
	char	*tmp;
	char	*s;

	s = save[fd];
	save[fd] = ft_strjoin(save[fd], buffer);
	free(s);
	tmp = save[fd];
	s = ft_strchr(save[fd], '\n');
	if (s)
	{
		*line = locate(save[fd]);
		save[fd] = ft_strdup(s);
		free(tmp);
		return (1);
	}
	return (0);
}

int	rest(char **line, char **save, int fd)
{
	char	*tmp;
	char	*s;

	tmp = save[fd];
	s = ft_strchr(save[fd], '\n');
	if (s)
	{
		*line = locate(save[fd]);
		save[fd] = ft_strdup(s);
		free(tmp);
		return (1);
	}
	else if (save[fd])
	{
		*line = save[fd];
		save[fd] = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*save[MAX_FD];
	int				i;
	char			*buffer;

	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (fd < 0 || !line || BUFFER_SIZE < 0 || fd > MAX_FD || !buffer)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strdup("");
	i = read(fd, buffer, BUFFER_SIZE);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		if (join(buffer, save, line, fd))
		{
			free(buffer);
			return (1);
		}
	}
	free(buffer);
	if (i < 0)
		return (-1);
	return (rest(line, save, fd));
}
