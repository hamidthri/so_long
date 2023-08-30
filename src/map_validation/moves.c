/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:56:40 by htaheri           #+#    #+#             */
/*   Updated: 2023/08/26 18:23:35 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_link(t_map *map, char dir)
{
	mlx_delete_image(map->mlx, map->images->link);
	if (dir == 'u')
	{
		map->images->link = mlx_texture_to_image(map->mlx, map->link_up);
		mlx_image_to_window(map->mlx, map->images->link, \
			map->p_x * PIXELS, map->p_y * PIXELS);
	}
	else if (dir == 'r')
	{
		map->images->link = mlx_texture_to_image(map->mlx, map->link_right);
		mlx_image_to_window(map->mlx, map->images->link, \
			map->p_x * PIXELS, map->p_y * PIXELS);
	}
	else if (dir == 'd')
	{
		map->images->link = mlx_texture_to_image(map->mlx, map->link_down);
		mlx_image_to_window(map->mlx, map->images->link, \
			map->p_x * PIXELS, map->p_y * PIXELS);
	}
	else
	{
		map->images->link = mlx_texture_to_image(map->mlx, map->link_left);
		mlx_image_to_window(map->mlx, map->images->link, \
			map->p_x * PIXELS, map->p_y * PIXELS);
	}
}

void	move_up(t_map *map)
{
	if (map->grid[map->p_y - 1][map->p_x] != '1' \
		&& map->grid[map->p_y - 1][map->p_x] != 'E')
	{
		if (map->grid[map->p_y - 1][map->p_x] == 'C')
		{
			remove_collectible(map, map->p_y - 1, map->p_x);
			map->collected += 1;
			map->grid[map->p_y - 1][map->p_x] = '0';
		}
		load_link(map, 'u');
		map->p_y -= 1;
		map->steps += 1;
		map->images->link->instances[0].y -= 1 * PIXELS;
		printf("steps: %zu\n", map->steps);
	}
	map_status(map);
}

void	move_down(t_map	*map)
{
	if (map->grid[map->p_y + 1][map->p_x] != '1' \
		&& map->grid[map->p_y + 1][map->p_x] != 'E')
	{
		if (map->grid[map->p_y + 1][map->p_x] == 'C')
		{
			remove_collectible(map, map->p_y + 1, map->p_x);
			map->collected += 1;
			map->grid[map->p_y + 1][map->p_x] = '0';
		}
		load_link(map, 'd');
		map->p_y += 1;
		map->steps += 1;
		map->images->link->instances[0].y += 1 * PIXELS;
		printf("steps: %zu\n", map->steps);
	}
	map_status(map);
}

void	move_right(t_map *map)
{
	if (map->grid[map->p_y][map->p_x + 1] != '1' \
		&& map->grid[map->p_y][map->p_x + 1] != 'E')
	{
		if (map->grid[map->p_y][map->p_x + 1] == 'C')
		{
			remove_collectible(map, map->p_y, map->p_x + 1);
			map->collected += 1;
			map->grid[map->p_y][map->p_x + 1] = '0';
		}
		load_link(map, 'r');
		map->p_x += 1;
		map->steps += 1;
		map->images->link->instances[0].x += 1 * PIXELS;
		printf("steps: %zu\n", map->steps);
	}
	map_status(map);
}

void	move_left(t_map *map)
{
	if (map->grid[map->p_y][map->p_x - 1] != '1' \
		&& map->grid[map->p_y][map->p_x - 1] != 'E')
	{
		if (map->grid[map->p_y][map->p_x - 1] == 'C')
		{
			remove_collectible(map, map->p_y, map->p_x - 1);
			map->grid[map->p_y][map->p_x - 1] = '0';
			map->collected += 1;
		}
		load_link(map, 'l');
		map->p_x -= 1;
		map->steps += 1;
		map->images->link->instances[0].x -= 1 * PIXELS;
		printf("steps: %zu\n", map->steps);
	}
	map_status(map);
}
