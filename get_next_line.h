/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:03:24 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/27 13:42:31 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int  ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s1);
char    *ft_substr(const char *s, unsigned int start, size_t len);
char    *get_next_line(int fd);
char    *free_all(char **storage);

//char    *get_line(char *storage);
//char    *get_storage(int fd, char *storage);
//char    *update_storage(char *storage);

#endif

