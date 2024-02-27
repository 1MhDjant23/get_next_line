/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:37:43 by mait-taj          #+#    #+#             */
/*   Updated: 2024/02/25 15:16:57 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	str_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	search_ch(char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (-1);
	while (str[n])
	{
		if (str[n] == '\n')
			return (n);
		n++;
	}
	return (-1);
}

char	*sub_str(char *line)
{
	int		i;
	char	*sub_line;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (search_ch(line) >= 0)
		sub_line = malloc((sizeof(char) * i) + 2);
	else
		sub_line = malloc((sizeof(char) * i) + 1);
	if (!sub_line)
		return (ft_free(&line));
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		sub_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		sub_line[i++] = '\n';
	sub_line[i] = '\0';
	return (sub_line);
}

char	*static_if_null(char *st)
{
	char	*jo_in;
	int		n;

	n = 0;
	jo_in = malloc(sizeof(char ) * str_len(st) + 1);
	if (!jo_in)
		return (ft_free(&st));
	while (st[n])
	{
		jo_in[n] = st[n];
		n++;
	}
	jo_in[n] = '\0';
	return (jo_in);
}

char	*join_str(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1)
		return (static_if_null(s2));
	join = malloc((sizeof(char) * (str_len(s1) + str_len(s2)) + 1));
	if (!join)
		return (ft_free(&s1), ft_free(&s2));
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	ft_free(&s1);
	return (join);
}
