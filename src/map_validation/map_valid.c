/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:55:07 by htaheri           #+#    #+#             */
/*   Updated: 2023/08/26 15:49:13 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*map_as_string(char *map)
{
	int		fd;
	char	*map_str;
	char	*line;
	char	*temp;

	map_str = (char *) ft_calloc(1, sizeof(char));
	if (!map_str)
		return (NULL);
	fd = open(map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			temp = map_str;
			map_str = ft_strjoin(map_str, line);
			free (line);
			free (temp);
		}
		else
			break ;
	}
	close (fd);
	return (map_str);
}

void	is_empty(char *map)
{
	if (!*map)
		error_message("Map is empty");
}

void	is_empty_line(char *map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		if ((map[i] == '\n' && map[i + 1] == '\n') || map[0] == '\n')
			error_message("There is empty line");
		i++;
	}
}

void	map_content(char *map)
{
	size_t		c;
	size_t		p;
	size_t		e;

	c = 0;
	p = 0;
	e = 0;
	while (*map)
	{
		if (*map == 'P')
			p++;
		else if (*map == 'C')
			c++;
		else if (*map == 'E')
			e++;
		else if (*map != '\n' && *map != '0' && *map != '1' && *map != 'X')
			error_message("Invalid content");
		map++;
	}
	if (p != 1 || c < 1 || e != 1)
		error_message ("Invalid content");
}

void	is_rec_map(char **map)
{
	size_t		i;
	int			j;

	if (!*map)
		return ;
	i = ft_strlen(map[0]);
	j = 0;
	while (map[j])
	{
		if (ft_strlen(map[j]) != i)
			error_message("Map is not a rectangular one");
		j++;
	}
}
