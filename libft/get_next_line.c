/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:16:55 by arecce            #+#    #+#             */
/*   Updated: 2022/03/29 11:16:55 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reading(int fd, char *save)
{
	char	*tmp;
	int		i;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (0);
	i = 1;
	while (!gnl_strchr(save, '\n') && i != 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
		{
			free(tmp);
			return (0);
		}
		tmp[i] = '\0';
		save = gnl_strjoin(save, tmp);
	}
	free(tmp);
	return (save);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_backup(char *save)
{
	int		i;
	int		j;
	char	*backup;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	backup = (char *)malloc(sizeof(char) * (gnl_strlen(save) - i + 1));
	if (!backup)
		return (0);
	i++;
	j = 0;
	while (save[i])
		backup[j++] = save[i++];
	backup[j] = '\0';
	free(save);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_reading(fd, save);
	if (!save)
		return (0);
	line = ft_get_line(save);
	save = ft_backup(save);
	return (line);
}
