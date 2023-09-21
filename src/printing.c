/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:20:37 by htaheri           #+#    #+#             */
/*   Updated: 2023/09/20 12:25:01 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	string_to_screen(t_map *game)
{
	game->images->moves_print = mlx_put_string(game->mlx, "MOVES:",
			16, game->height * 64 - 44);
	mlx_image_to_window(game->mlx, game->images->collectible,
		140, game->height * 64 - 50);
	mlx_put_string(game->mlx, ":", 160, game->height * 64 - 44);
}

void	print_moves(t_map *game)
{
	char	*string;

	string = ft_itoa(game->steps + 1);
	mlx_delete_image(game->mlx, game->images->moves_nbr);
	game->images->moves_nbr = mlx_put_string(game->mlx, string,
			80, game->height * 64 - 44);
	free(string);
}

void	print_rupees(t_map *game)
{
	char	*string;

	string = ft_itoa(game->collected + 1);
	mlx_delete_image(game->mlx, game->images->rupee_nbr);
	game->images->rupee_nbr = mlx_put_string(game->mlx, string,
			175, game->height * 64 - 44);
	free(string);
}
