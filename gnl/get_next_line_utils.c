/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacunan <mtacunan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:04:45 by mtacunan          #+#    #+#             */
/*   Updated: 2021/12/07 22:20:32 by mtacunan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	size_malloc(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sol;
	unsigned int	i;
	unsigned int	lim;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	lim = ft_strlen(&s[start]);
	if (len > lim)
		len = lim;
	sol = malloc ((int)len + 1 * sizeof(char));
	if (!sol)
		return (NULL);
	while (i < (unsigned int)len && s[start] != '\0')
	{
		sol[i] = s[start];
		i++;
		start++;
	}
	sol[i] = '\0';
	return (sol);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_1;
	int		len_2;
	int		i;
	char	*sol;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	sol = malloc((len_1 + len_2 + 1) * sizeof(char));
	if (!sol)
		return (NULL);
	while (++i < len_1)
		sol[i] = s1[i];
	while (i < len_1 + len_2)
	{
		sol[i] = *s2;
		s2++;
		i++;
	}
	sol[i] = '\0';
	free (s1);
	return (sol);
}

char	*ft_strdup(const char *s1)
{
	char	*address;
	int		i;

	i = 0;
	address = malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (! address)
		return (NULL);
	while (*s1)
	{
		address[i] = *s1;
		s1++;
		i++;
	}
	address[i] = '\0';
	return (address);
}
