/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:14:44 by htaheri           #+#    #+#             */
/*   Updated: 2023/08/26 13:09:44 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	error_message(char	*msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

size_t	count_height(char **col)
{
	size_t	i;

	i = 0;
	while (col[i])
		i++;
	return (i);
}

t_pos	player_pos(t_map *map_details)
{
	t_pos	pos;

	pos.y_pos = 0;
	while (pos.y_pos < map_details->height)
	{
		pos.x_pos = 0;
		while (pos.x_pos < map_details->width)
		{
			if (map_details->grid[pos.y_pos][pos.x_pos] == 'P')
				return (pos);
			pos.x_pos++;
		}
		pos.y_pos++;
	}
	pos.x_pos = 0;
	pos.y_pos = 0;
	return (pos);
}

t_pos	exit_pos(t_map *map_details)
{
	t_pos	pos;

	pos.y_pos = 0;
	while (pos.y_pos < map_details->height)
	{
		pos.x_pos = 0;
		while (pos.x_pos < map_details->width)
		{
			if (map_details->grid[pos.y_pos][pos.x_pos] == 'E')
				return (pos);
			pos.x_pos++;
		}
		pos.y_pos++;
	}
	pos.x_pos = 0;
	pos.y_pos = 0;
	return (pos);
}

size_t	count_rupees(t_map *game)
{
	size_t	y;
	size_t	x;
	size_t	i;

	y = 0;
	i = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->grid[y][x] == 'C')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}
