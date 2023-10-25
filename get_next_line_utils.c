/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:08:14 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/25 18:33:50 by crmanzan         ###   ########.fr       */
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

/*char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	res = malloc (sizeof(char) * ((ft_strlen(s1) + 1) + (ft_strlen(s2))));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}*/

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

/*char	*ft_strchr(const char *s, int c)
{
	char		a;
	const char	*x;
	int			i;

	a = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == a)
		{
			x = &s[i];
			return ((char *)x);
		}
		i++;
	}
	if (a == '\0')
		return ((char *)&s[i]);
	return (0);
}*/

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (NULL);
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

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*sub;

	if (!s || len == 0)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	if (start >= size)
		return (NULL);
	else if (size - start < len)
		sub = malloc((size - start + 1) * (sizeof(char)));
	else
		sub = malloc((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	i = 0;
	len += start;
	while (s[start] && start < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}*/
