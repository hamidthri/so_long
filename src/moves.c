/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:56:40 by htaheri           #+#    #+#             */
/*   Updated: 2023/09/25 14:42:05 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			print_rupees(map);
			map->collected += 1;
			map->grid[map->p_y - 1][map->p_x] = '0';
		}
		load_link(map, 'u');
		print_moves(map);
		map->p_y -= 1;
		map->steps += 1;
		map->images->link->instances[0].y -= 1 * PIXELS;
		ft_putstr_fd("Number of Steps: ", 1);
		ft_putnbr_fd(map->steps, 1);
		ft_putchar_fd('\n', 1);
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
			print_rupees(map);
			map->collected += 1;
			map->grid[map->p_y + 1][map->p_x] = '0';
		}
		load_link(map, 'd');
		print_moves(map);
		map->p_y += 1;
		map->steps += 1;
		map->images->link->instances[0].y += 1 * PIXELS;
		ft_putstr_fd("Number of Steps: ", 1);
		ft_putnbr_fd(map->steps, 1);
		ft_putchar_fd('\n', 1);
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
			print_rupees(map);
			map->collected += 1;
			map->grid[map->p_y][map->p_x + 1] = '0';
		}
		load_link(map, 'r');
		print_moves(map);
		map->p_x += 1;
		map->steps += 1;
		map->images->link->instances[0].x += 1 * PIXELS;
		ft_putstr_fd("Number of Steps: ", 1);
		ft_putnbr_fd(map->steps, 1);
		ft_putchar_fd('\n', 1);
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
			print_rupees(map);
			map->grid[map->p_y][map->p_x - 1] = '0';
			map->collected += 1;
		}
		load_link(map, 'l');
		print_moves(map);
		map->p_x -= 1;
		map->steps += 1;
		map->images->link->instances[0].x -= 1 * PIXELS;
		ft_putstr_fd("Number of Steps: ", 1);
		ft_putnbr_fd(map->steps, 1);
		ft_putchar_fd('\n', 1);
	}
	map_status(map);
}
