/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:09:10 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/24 18:06:06 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_storage(int fd, char *storage)
{
    char    *buffer;
    int     num_bytes;
    
    buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    num_bytes = 1;
    buffer[0] = '\0';
    while(num_bytes > 0 && !ft_strchr(buffer, '\n'))
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        if (num_bytes == -1)
        {
            free(buffer);
            return(NULL);
        }
        if (num_bytes > 0)
        {
            buffer[num_bytes] = '\0';
            storage = ft_strjoin(storage, buffer);
        }
    }
    free(buffer);
    //printf("%s\n", storage);
    return (storage);

}

char    *get_line(char *storage)
{
    char    *line;
    size_t  len;

    len = ft_strlen(storage);
    line = (char *)malloc(sizeof(char) * len);
    if (!line)
        retunr (NULL);
    while()
}

/*char    *update_storage(char *storage)
{
    
}*/

char    *get_next_line(int fd)
{
    static char *storage = NULL;
    char        *line;

    storage = get_storage(fd, storage);
    /*if (!storage)
        return (NULL);
    line = get_line(storage);
    if (!line)
        return (NULL);
    storage = update_storage(storage);*/
    return (storage);
}

int main()
{
    int fd;
    char    *line;

    fd = open("text.txt", O_RDONLY);
    line = get_next_line(fd);
        printf("%s/n", line);
        free(line);
    return(0);
}
