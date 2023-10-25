/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:09:10 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/25 17:51:43 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *update_storage(char *storage)
{
    char    *new;
    int     i;

    i = 0;
    if (!storage)
        return (NULL);
    while (storage[i] != '\n' && storage[i] != '\0')
        i++;
    i++;
    new = ft_substr(storage, i, ft_strlen(storage));
//    printf("storage is %s\n", storage);
    free(storage);
 //   printf("new is %s\n", new);
    return (new);
}

/*char    *get_storage(int fd, char *storage)
{
    char    *buffer;
    int     num_bytes;
    
    buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    buffer[0] = '\0';
    num_bytes = 1;
    while (num_bytes > 0 && !ft_strchr(buffer, '\n'))
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        if (num_bytes == -1)
        {
            free(buffer);
            return(NULL);
        }
        if (num_bytes > 0)
        {
            printf("fahdsjkhh");
            buffer[num_bytes] = '\0';
            storage = ft_strjoin(storage, buffer);
        }
    }
    free(buffer);
    //printf("%s\n", storage);
    return (storage);

}*/

char	*get_storage(int fd, char *storage)
{
	int		num_bytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	num_bytes = 1;
	while (num_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buffer);
			return (NULL);
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

char    *get_line(char *storage)
{
    char    *line;
    int     i;

    i = 0;
    if (!storage)
        return (NULL);
    while (storage[i] != '\n' && storage[i] != '\0')
        i++;
    i++;
    line = ft_substr(storage, 0, i);
    return (line);
    
}

char    *get_next_line(int fd)
{
    static char *storage = NULL;
    char        *line;

    storage = get_storage(fd, storage);
    if (!storage)
        return (NULL);
    line = get_line(storage);
    if (!line)
    {
        free(storage);
        storage = NULL;
        return (NULL);
    }
 //   printf("old storage is : %s\n", storage);
    storage = update_storage(storage);
//    printf("new storage is : %s\n", storage);
    return (line);
}

int main()
{
    int fd;
    char    *line;

    fd = open("text.txt", O_RDONLY);
 // line = get_next_line(fd);
  while ((line = get_next_line(fd)) != NULL)
	{
			printf("FIRST LINE IS : %s\n", line);
			free(line);}
		/*	printf("SECOND LINE IS : %s\n", line);
			free(line);
			printf("THIRD LINE IS : %s\n", line);
			free(line);
	}*/

    //while((line = get_next_line(fd)) != NULL)
    //{

      //  printf("%s/n", line);
      //  free(line);
    //}
        return(0);
}
