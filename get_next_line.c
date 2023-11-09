/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:09:10 by crmanzan          #+#    #+#             */
/*   Updated: 2023/11/07 16:59:20 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(char **storage)
{
	free(*storage);
	*storage = NULL;
	return (NULL);
}

static char	*update_storage(char *storage)
{
	char	*new;
	int		i;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	i++;
	new = ft_substr(storage, i, ft_strlen(storage));
	free(storage);
	return (new);
}

static char	*get_storage(int fd, char *storage)
{
	char	*buffer;
	int		num_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_all(&storage));
	buffer[0] = '\0';
	num_bytes = 1;
	while (num_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buffer);
			return (free_all(&storage));
		}
		if (num_bytes > 0)
		{
			buffer[num_bytes] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	return (storage);
}

static char	*the_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = get_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = the_line(storage);
	if (!line)
	{
		return (free_all(&storage));
	}
	storage = update_storage(storage);
	return (line);
}
//  int main()
//  {
//      int fd;
//      char    *line;
//  	int i = 1;
//      fd = open("text.txt", O_RDONLY);
//      while((line = get_next_line(fd)) != NULL)
//      {
//         printf("LINE %i: %s", i, line);
//         free(line);
//  	   i++;
//      }
//          return(0);
//  }
