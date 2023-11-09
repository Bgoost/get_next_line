/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:08:14 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/27 13:42:44 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sfin;
	int		i;
	int		n;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	sfin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = -1;
	n = 0;
	if (!sfin)
		return (free_all(&s1));
	while (s1[++i] != '\0')
	{
		sfin[i] = s1[i];
	}
	while (s2[n] != '\0')
		sfin[i++] = s2[n++];
	sfin[i] = '\0';
	free(s1);
	return (sfin);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (((char *)s)[i] != '\0' && flag == 0)
	{
		if (((char *)s)[i] == (char)c)
		{
			return ((char *)&s[i]);
			flag = 1;
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (!s || len == 0)
		return (NULL);
	while (s[size])
		size++;
	if (start >= size)
		return (NULL);
	if (len > size - start)
		s2 = (char *)malloc((size - start + 1) * sizeof(char));
	else
		s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	len += start;
	while (s[start] && start < len)
		s2[i++] = s[start++];
	s2[i] = '\0';
	return (s2);
}
