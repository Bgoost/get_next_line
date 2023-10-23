/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:03:24 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/23 19:15:16 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

size_t  ft_strlen(const char *s);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s1);
char    *ft_substr(const char *s, unsigned int start, size_t len);


#endif

