/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 16:55:05 by lbartels      #+#    #+#                 */
/*   Updated: 2023/11/15 17:45:36 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*set_buffer(int fd, char *array)
{
	char		*buffer;
	int			len;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	len = 1;
	while (!check_new_line(array) && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(array);
			free(buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		array = ft_strjoin(array, buffer);
	}
	free(buffer);
	return (array);
}

char	*get_next_line(int fd)
{
	char			*next_line;
	static char		*array[8192];

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	array[fd] = set_buffer(fd, array[fd]);
	if (!array[fd])
		return (NULL);
	next_line = set_next_line(array[fd]);
	array[fd] = new_str(array[fd]);
	return (next_line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main()
// {
// 	int	fd1 = open("test.txt", O_RDONLY);
// 	int	fd2 = open("test2.txt", O_RDONLY);
// 	for (char *array = ""; array != NULL; )
// 	{
// 		array = get_next_line(fd1);
// 		printf("%s", array);
// 		free(array);
// 		array = get_next_line(fd2);
// 		printf("%s", array);
// 		free(array);
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
