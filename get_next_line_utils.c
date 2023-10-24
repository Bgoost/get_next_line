/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:08:14 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/24 17:54:20 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

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
	i = 0;
	n = 0;
	if (!sfin)
		return (0);
	while (s1[i] != '\0')
	{
		sfin[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		sfin[i] = s2[n];
		i++;
		n++;
	}
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

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)s1;
	s2 = (char *)malloc(ft_strlen(s1)+ 1);
	if (!s2)
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = tmp[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (0);
	while (s[i] != '\0' && i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
