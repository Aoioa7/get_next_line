/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aichida <aichida@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:58:49 by aichida           #+#    #+#             */
/*   Updated: 2024/06/27 13:22:55 by aichida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// don't forget free

static char	*update_save(int fd, char *buf, char *save)
{
	int		check;
	char	*temp;

	check = 1;
	while (1)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check == -1)
			return (NULL);
		else if (check == 0)
			break ;
		buf[check] = '\0';
		if (!save)
			save = ft_strdup("");
		temp = save;
		save = (ft_strjoin(temp, buf));
		if (!save)
			return (NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (save);
}

// temp[0] <- substr

static char	*cut_forward(char *line)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	temp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!temp)
		return (NULL);
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (temp);
}

// a lot of null guard
// look save as line

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = update_save(fd, buf, save);
	free(buf);
	if (!line)
	{
		if (save)
			*save = 0;
		return (NULL);
	}
	save = cut_forward(line);
	if (!save && line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* main function

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("test.txt",O_RDOONLY);
	while(line)
	{
		line = get_next_line(fd);
		printf("%s",line);
		free(line);
	}
	return (0);
}

*/

/* test example

aaa\nbbb\nccc\n
aaabbbccc

a
a\n

xxxxxxxxxxxxxxxxxxxxxxxxxx
xxxxxxxxxxxxxxxxxxxxxxxxxx\n

\0
\n

*/

/* test2 example
hih3h9h3f
	uh3   3f3o
	wo3

3i3o38er3

	jbuebc
	ee
	e

	op3

	z@z@dp@//36 s

*/
