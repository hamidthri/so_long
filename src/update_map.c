/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:13:07 by htaheri           #+#    #+#             */
/*   Updated: 2023/09/20 12:15:19 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_status(t_map *map)
{
	if (map->collected == map->rupees)
	{
		if (mlx_image_to_window(map->mlx, map->images->exit_open, \
			map->e_x * PIXELS, map->e_y * PIXELS) < 0)
			error_message("Failed to put image to window");
		map->grid[map->e_y][map->e_x] = '0';
		if (map->p_x == map->e_x && map->p_y == map->e_y)
		{
			mlx_close_window(map->mlx);
			printf("YOU WON.\n");
		}
	}
}

void	remove_collectible(t_map *map, int y, int x)
{
	size_t	collect;

	collect = 0;
	x = x * PIXELS + PIXELS / 4 + 8;
	y = y * PIXELS + PIXELS / 4;
	while (collect < map->images->collectible->count)
	{
		if (map->images->collectible->instances[collect].x == x \
			&& map->images->collectible->instances[collect].y == y)
			map->images->collectible->instances[collect].enabled = false;
		collect++;
	}
}

void	move_player(t_map *map, char dir)
{
	if (dir == 'u')
		move_up(map);
	else if (dir == 'r')
		move_right(map);
	else if (dir == 'd')
		move_down(map);
	else
		move_left(map);
	load_link(map, dir);
}

void	move_map(mlx_key_data_t key, void *game)
{
	t_map	*map;

	map = (t_map *) game;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		move_player(map, 'u');
	if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		move_player(map, 'd');
	if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		move_player(map, 'r');
	if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		move_player(map, 'l');
}
