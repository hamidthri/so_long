/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:49:42 by htaheri           #+#    #+#             */
/*   Updated: 2023/08/12 16:54:04 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	wall_check(t_map *map_struct)
{
	size_t		i;

	i = 0;
	while (i < map_struct->width)
	{
		if (map_struct->grid[0][i] != '1')
			error_message("There isn't a wall around map");
		if (map_struct->grid[map_struct->height - 1][i] != '1')
			error_message("There isn't a wall around map");
		i++;
	}
	i = 0;
	while (i < map_struct->height)
	{
		if (map_struct->grid[i][0] != '1')
			error_message("There isn't a wall around map");
		if (map_struct->grid[i][map_struct->width - 1] != '1')
			error_message("There isn't a wall around map");
		i++;
	}
}

int	free_mem(int k, char **grid)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (0);
}

int	check_rout(t_point *cur, size_t y, size_t x)
{
	if (cur->grid[y][x] == '1')
		return (0);
	if (cur->grid[y][x] == 'C')
		cur->n_rupees--;
	if (cur->grid[y][x] == 'E')
	{
		cur->exit = 1;
		return (0);
	}
	cur->grid[y][x] = '1';
	if (check_rout(cur, y + 1, x))
		return (1);
	if (check_rout(cur, y - 1, x))
		return (1);
	if (check_rout(cur, y, x + 1))
		return (1);
	if (check_rout(cur, y, x - 1))
		return (1);
	return (0);
}

void	flood_fill(t_map *map, char **tab)
{
	t_point	begin;

	begin.x = map->p_x;
	begin.y = map->p_y;
	begin.n_rupees = map->rupees;
	begin.exit = 0;
	begin.grid = tab;
	check_rout(&begin, begin.y, begin.x);
	free_mem(map->height, tab);
	if (!(begin.exit == 1 && begin.n_rupees == 0))
		error_message("No valid rout available");
}

void	valid_rout(t_map *map)
{
	char	**new;
	size_t	y;

	y = 0;
	new = malloc (sizeof(char *) * map->height);
	while (y < map->height)
	{
		new[y] = ft_strdup(map->grid[y]);
		y++;
	}
	flood_fill(map, new);
}
