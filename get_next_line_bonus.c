/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:21:22 by marias-e          #+#    #+#             */
/*   Updated: 2022/10/07 11:49:42 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_aux_stash(char *stash, char *buffer, int count);

static char	*ft_fill_stash(char *stash, int fd);

static char	*ft_fill_line(char *stash);

static char	*ft_fix_stash(char *stash, size_t len);

char	*get_next_line(int fd)
{
	char			*line;
	static char		**stash;

	if (!stash[fd])
		stash = malloc(256 * sizeof(char *));
	if (fd < 0)
		return (0);
	stash[fd] = ft_fill_stash(stash[fd], fd);
	if (!stash[fd])
		return (0);
	line = ft_fill_line(stash[fd]);
	if (!line)
		return (0);
	stash[fd] = ft_fix_stash(stash[fd], (ft_strlen(line)));
	return (line);
}

static char	*ft_fill_stash(char *stash, int fd)
{
	char	*buffer;
	int		count;

	count = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		stash = ft_aux_stash(stash, buffer, count);
		if (!stash)
		{
			free(buffer);
			return (0);
		}
		if (ft_strchr(stash, '\n') != -1)
			break ;
	}
	if (buffer)
		free(buffer);
	return (stash);
}

static char	*ft_aux_stash(char *stash, char *buffer, int count)
{
	char	*temp;

	if (count == -1 || (count == 0 && !stash))
	{
		if (stash)
			free(stash);
		return (0);
	}
	if (count == 0 && stash)
		return (stash);
	buffer[count] = 0;
	if (!stash)
		stash = ft_strdup("");
	temp = stash;
	stash = ft_strjoin(stash, buffer);
	free(temp);
	return (stash);
}

static char	*ft_fill_line(char *stash)
{
	char	*line;
	int		n;

	n = ft_strchr(stash, '\n');
	if (n >= 0)
		line = ft_substr(stash, 0, n + 1);
	else
		line = ft_strdup(stash);
	return (line);
}

static char	*ft_fix_stash(char *stash, size_t len)
{
	char	*temp;

	if (ft_strchr(stash, '\n') == -1
		|| (unsigned int)ft_strchr(stash, '\n') == ft_strlen(stash) - 1)
	{
		free(stash);
		stash = 0;
	}
	else
	{
		temp = stash;
		stash = ft_substr(stash, len, ft_strlen(stash));
		free(temp);
	}
	return (stash);
}
/*
int main(void)
{
	int fd;
	int fd2;

	fd = open("text.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	printf("fd = %d -- %s", fd2,  get_next_line(fd2));
	printf("fd = %d -- %s", fd,  get_next_line(fd));
	printf("fd = %d -- %s", fd,  get_next_line(fd));
	printf("fd = %d -- %s", fd2,  get_next_line(fd2));
}*/
