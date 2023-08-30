/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:09:45 by htaheri           #+#    #+#             */
/*   Updated: 2023/08/29 15:59:53 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_status(const t_map *game)
{
	size_t	count;

	count = 0;
	while (count < game->images->enemy->count)
	{
		if (game->p_x * PIXELS
			== (size_t)game->images->enemy->instances[count].x
			&& game->p_y * PIXELS
			== (size_t)game->images->enemy->instances[count].y)
		{
			sleep(1);
			mlx_close_window(game->mlx);
			printf ("Ow no! player got killed\n");
			printf ("Try again!\n");
		}
		count++;
	}
}

static void	move_all(const t_map *game, int count)
{
	t_var			var;

	var.x = &game->images->enemy->instances[count].x;
	var.y = &game->images->enemy->instances[count].y;
	var.ran_x = (rand() % 3 - 1) * PIXELS;
	var.ran_y = (rand() % 3 - 1) * PIXELS;
	var.index_x = *var.x + var.ran_x;
	var.index_y = *var.y + var.ran_y;
	if (var.index_x != 0)
		var.index_x /= PIXELS;
	if (var.index_y != 0)
		var.index_y /= PIXELS;
	if (game->grid[var.index_y][var.index_x] != '1'
		&& game->grid[var.index_y][var.index_x] != 'E')
	{
			*var.x += var.ran_x;
			*var.y += var.ran_y;
	}
}

void	enemy_patrol(void *temp)
{
	const t_map			*game = temp;
	size_t				count;
	static int			i;

	count = 0;
	check_status(game);
	if (i++ < EMOVE)
		return ;
	while (count < game->images->enemy->count)
	{
		move_all (game, count);
		count++;
	}
	i = 0;
}
