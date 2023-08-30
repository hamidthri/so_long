/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:07:49 by htaheri           #+#    #+#             */
/*   Updated: 2023/08/29 15:49:00 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	fill_background(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (mlx_image_to_window(map->mlx, map->images->grass, \
				x * PIXELS, y * PIXELS) < 0)
				error_message("Failed to put image to window");
			x++;
		}
		y++;
	}
}

void	image_select(t_map *map, size_t y, size_t x)
{
	if (map->grid[y][x] == '1')
		if (mlx_image_to_window(map->mlx, map->images->bush, \
			x * PIXELS, y * PIXELS) < 0)
			error_message("Failed to put image to window");
	if (map->grid[y][x] == 'C')
		if (mlx_image_to_window(map->mlx, map->images->collectible, \
		x * PIXELS + PIXELS / 4 + 8, y * PIXELS + PIXELS / 4) < 0)
			error_message("Failed to put image to window");
	if (map->grid[y][x] == 'P')
		if (mlx_image_to_window(map->mlx, map->images->link, \
			x * PIXELS, y * PIXELS) < 0)
			error_message("Failed to put image to window");
	if (map->grid[y][x] == 'E')
		if (mlx_image_to_window(map->mlx, map->images->exit_closed, \
			x * PIXELS, y * PIXELS) < 0)
			error_message("Failed to put image to window");
	if (map->grid[y][x] == 'X')
		if (mlx_image_to_window(map->mlx, map->images->enemy, \
			x * PIXELS, y * PIXELS) < 0)
			error_message("Failed to put image to window");
}

void	render_map(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			image_select(map, y, x);
			x++;
		}
		y++;
	}
}
