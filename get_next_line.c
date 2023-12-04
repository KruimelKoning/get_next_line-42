/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 16:55:05 by lbartels      #+#    #+#                 */
/*   Updated: 2023/11/21 14:35:16 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_buffer(int fd, char *str)
{
	char		*buffer;
	int			len;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	len = 1;
	while (!check_new_line(str) && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*next_line;
	static char		*str;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	str = set_buffer(fd, str);
	if (!str)
		return (NULL);
	next_line = set_next_line(str);
	str = new_str(str);
	return (next_line);
}

#include <string.h>
#include <stdio.h>

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < 4; i++)
	{
		char *str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}
