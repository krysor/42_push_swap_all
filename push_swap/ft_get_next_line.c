/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:35:38 by kkaczoro          #+#    #+#             */
/*   Updated: 2022/12/29 10:49:28 by kkaczoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*ft_new_line(char *buffer, char *new_line);
static char	*ft_no_new_line(int fd, char *buffer);
static char	*ft_fuse(char *temp, char *new_line);

char	*ft_get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*new_line;

	if (BUFFER_SIZE <= 0 || fd < 0
		|| (ft_strlen(buffer) == 0 && read(fd, buffer, BUFFER_SIZE) <= 0))
		return (NULL);
	new_line = ft_memchr(buffer, '\n', BUFFER_SIZE);
	if (new_line)
		return (ft_new_line(buffer, new_line));
	else
		return (ft_no_new_line(fd, buffer));
}

static char	*ft_new_line(char *buffer, char *new_line)
{
	char	*next_line;
	int		len_next;

	new_line++;
	next_line = malloc(sizeof(char) * (new_line - buffer) + 1);
	if (next_line == NULL)
		return (NULL);
	(void)ft_strlcpy(next_line, buffer, new_line - buffer + 1);
	next_line[new_line - buffer] = '\0';
	len_next = ft_strlen(next_line);
	(void)ft_memmove(buffer, buffer + (new_line - buffer),
		BUFFER_SIZE - len_next);
	(void)ft_memset(buffer + (BUFFER_SIZE - len_next), '\0', len_next);
	return (next_line);
}

static char	*ft_no_new_line(int fd, char *buffer)
{
	char	*temp;
	int		len_read;
	char	*new_line;

	temp = malloc(sizeof(char) * (ft_strlen(buffer)) + 1);
	if (temp == NULL)
		return (NULL);
	(void)ft_strlcpy(temp, buffer, ft_strlen(buffer) + 1);
	len_read = read(fd, buffer, BUFFER_SIZE);
	if (len_read <= 0)
	{
		(void)ft_memset(buffer, '\0', BUFFER_SIZE);
		return (temp);
	}
	if (len_read <= BUFFER_SIZE)
		(void)ft_memset(buffer + len_read, '\0', BUFFER_SIZE - len_read);
	new_line = ft_get_next_line(fd);
	if (new_line == NULL)
	{
		new_line = malloc(sizeof(char));
		if (new_line == NULL)
			return (NULL);
		new_line[0] = '\0';
	}
	return (ft_fuse(temp, new_line));
}

static char	*ft_fuse(char *temp, char *new_line)
{
	int		len_temp;
	int		len_new;
	char	*next_line;

	len_temp = ft_strlen(temp);
	len_new = ft_strlen(new_line);
	next_line = malloc(sizeof(char) * (len_temp + len_new) + 1);
	if (next_line == NULL)
	{
		free (temp);
		free (new_line);
		return (NULL);
	}
	(void)ft_strlcpy(next_line, temp, BUFFER_SIZE + 1);
	(void)ft_strlcpy(next_line + len_temp, new_line, len_new + 1);
	free (temp);
	free (new_line);
	return (next_line);
}
