/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:04:36 by mtacunan          #+#    #+#             */
/*   Updated: 2022/03/22 12:14:04 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ther_is_jump(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_buffer(char *mem, int fd)
{
	char	*buffer;
	int		rd;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while ((!mem || !ther_is_jump(mem)) && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (mem)
			buffer = ft_strjoin(buffer, mem);
		if (!*buffer || rd == -1)
		{
			free (buffer);
			free (mem);
			return (NULL);
		}
		buffer[rd] = '\0';
		mem = ft_strjoin(mem, buffer);
	}
	free (buffer);
	return (mem);
}

char	*get_mem(char *mem)
{
	int		start;
	int		end;
	char	*res;

	if (!mem)
		return (NULL);
	start = size_malloc(mem) + 1;
	end = ft_strlen(mem);
	res = ft_substr(mem, start, end - start + 1);
	free (mem);
	return (res);
}

char	*get_line(char *buffer)
{
	char	*res;
	int		len;

	if (!buffer)
		return (NULL);
	len = size_malloc(buffer);
	res = ft_substr(buffer, 0, len);
	res[len] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*mem;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!mem)
		mem = ft_strdup("");
	mem = get_buffer(mem, fd);
	if (!mem)
		return (NULL);
	if (!*mem)
	{
		free(mem);
		return (NULL);
	}
	line = get_line(mem);
	if (!*line)
	{
		free (line);
		return (NULL);
	}
	mem = get_mem(mem);
	return (line);
}
