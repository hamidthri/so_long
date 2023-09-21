/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:02:40 by htaheri           #+#    #+#             */
/*   Updated: 2023/09/20 12:14:43 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	*collectible_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*collectible;

	collectible = mlx_load_png("images/Rupee.png");
	if (!collectible)
		error_message("Problem with loading png");
	img->collectible = mlx_texture_to_image(mlx, collectible);
	if (!img->collectible)
		error_message("Problem with texture to image");
	mlx_delete_texture(collectible);
	return (img);
}

t_image	*enemy_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*enemy;

	enemy = mlx_load_png("images/enemy.png");
	if (!enemy)
		error_message("Problem with loading png");
	img->enemy = mlx_texture_to_image(mlx, enemy);
	if (!img->enemy)
		error_message("Problem with texture to image");
	mlx_delete_texture(enemy);
	return (img);
}

t_image	*initialize_img_struct(mlx_t *mlx)
{
	t_image	*elems;

	elems = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!elems)
		return (NULL);
	elems = link_texture(mlx, elems);
	elems = grass_texture(mlx, elems);
	elems = collectible_texture(mlx, elems);
	elems = bush_texture(mlx, elems);
	elems = enemy_texture(mlx, elems);
	elems = exit_open_texture(mlx, elems);
	elems = exit_closed_texture(mlx, elems);
	return (elems);
}
