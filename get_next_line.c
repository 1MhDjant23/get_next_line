/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 00:47:12 by mait-taj          #+#    #+#             */
/*   Updated: 2024/02/27 22:11:11 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*new_rest_line(char *rest_line, int x)
{
	char	*str;
	int		i;

	i = 0;
	if (x == -1 && rest_line[0] != '\n')
		return (ft_free(&rest_line));
	x++;
	str = malloc(sizeof(char ) * (str_len(rest_line + x) + 1));
	if (!str)
		return (ft_free(&rest_line));
	while (rest_line[x])
	{
		str[i] = rest_line[x];
		i++;
		x++;
	}
	str[i] = '\0';
	ft_free(&rest_line);
	return (str);
}

char	*check_rest_line(char **line_rest)
{
	char	*line;

	if (*line_rest)
	{
		line = sub_str(*line_rest);
		*line_rest = new_rest_line(*line_rest, search_ch(*line_rest));
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rest_line;
	char		*buffer;
	ssize_t		read_bytes;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
		return (ft_free(&rest_line));
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while ((read_bytes != 0) && search_ch(rest_line) == -1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (ft_free(&buffer), ft_free(&rest_line));
		buffer[read_bytes] = '\0';
		rest_line = join_str(rest_line, buffer);
	}
	ft_free(&buffer);
	if (rest_line[0] == '\0')
		return (ft_free(&rest_line));
	return (check_rest_line(&rest_line));
}
