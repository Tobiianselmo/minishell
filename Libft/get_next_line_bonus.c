/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:39:36 by tanselmo          #+#    #+#             */
/*   Updated: 2024/03/27 12:10:34 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_save_line_gnl(char *new_line)
{
	char	*aux;
	int		i;
	int		count;

	i = 0;
	if (!new_line)
		return (NULL);
	while (new_line[i] != '\n' && new_line[i])
		i++;
	if (!new_line[i])
	{
		free(new_line);
		return (NULL);
	}
	aux = (char *)malloc(sizeof(char) * (ft_len(new_line) - i + 1));
	if (!aux)
		return (ft_free_gnl(new_line), NULL);
	i += 1;
	count = 0;
	while (new_line[i])
		aux[count++] = new_line[i++];
	aux[count] = '\0';
	return (ft_free_gnl(new_line), aux);
}

static char	*ft_copy_line_gnl(char *new_line)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!new_line[i])
		return (NULL);
	while (new_line[i] && new_line[i++] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (new_line[i] != '\n' && new_line[i] != '\0')
	{
		line[i] = new_line[i];
		i++;
	}
	if (new_line[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_read_fd_gnl(int fd, char *new_line)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	if (!new_line)
		new_line = ft_strdup_gnl("");
	while (!ft_strchr_gnl(new_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (ft_free_gnl(new_line), NULL);
		}
		buffer[bytes_read] = '\0';
		new_line = ft_strjoin_gnl(buffer, new_line);
	}
	free(buffer);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*new_line[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line[fd] = ft_read_fd_gnl(fd, new_line[fd]);
	if (!new_line[fd])
		return (NULL);
	line = ft_copy_line_gnl(new_line[fd]);
	new_line[fd] = ft_save_line_gnl(new_line[fd]);
	return (line);
}
