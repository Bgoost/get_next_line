/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:09:10 by crmanzan          #+#    #+#             */
/*   Updated: 2023/10/23 16:44:15 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <unistd.h> 
  
extern int errno; 
int main() 
{ 
    // if file does not have in directory 
    // then file foo.txt is created. 
    int fd = open("foo.txt", O_RDONLY | O_CREAT); 
  
    printf("fd = %d\n", fd); 
  
    if (fd == -1) { 
        // print which type of error have in a code 
        printf("Error Number % d\n", errno); 
  
        // print program detail "Success or failure" 
        perror("Program"); 
    } 
    return 0; 
}
