/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 13:08:49 by lbartels      #+#    #+#                 */
/*   Updated: 2023/11/15 15:16:55 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*set_buffer(int fd, char *str);
int		check_new_line(char *str);
char	*ft_strjoin(char *str, char const *buffer);
char	*set_next_line(char *str);
char	*new_str(char *str);
size_t	ft_strlen(const char *s);

#endif