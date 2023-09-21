/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_texture2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:02:19 by htaheri           #+#    #+#             */
/*   Updated: 2023/09/20 12:19:51 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_image	*link_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*link;

	link = mlx_load_png("images/Link.png");
	if (!link)
		error_message("Problem with loading png");
	img->link = mlx_texture_to_image(mlx, link);
	if (!img->link)
		error_message("Problem with texture to image");
	mlx_delete_texture(link);
	return (img);
}

t_image	*grass_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*grass;

	grass = mlx_load_png("images/Grass.png");
	if (!grass)
		error_message("Problem with loading png");
	img->grass = mlx_texture_to_image(mlx, grass);
	if (!img->grass)
		error_message("Problem with texture to image");
	mlx_delete_texture(grass);
	return (img);
}

t_image	*exit_closed_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*exit_closed;

	exit_closed = mlx_load_png("images/Exit_Closed.png");
	if (!exit_closed)
		error_message("Problem with loading png");
	img->exit_closed = mlx_texture_to_image(mlx, exit_closed);
	if (!img->exit_closed)
		error_message("Problem with texture to image");
	mlx_delete_texture(exit_closed);
	return (img);
}

t_image	*exit_open_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*exit_open;

	exit_open = mlx_load_png("images/Exit_Open.png");
	if (!exit_open)
		error_message("Problem with loading png");
	img->exit_open = mlx_texture_to_image(mlx, exit_open);
	if (!img->exit_open)
		error_message("Problem with texture to image");
	mlx_delete_texture(exit_open);
	return (img);
}

t_image	*bush_texture(mlx_t *mlx, t_image *img)
{
	mlx_texture_t	*bush;

	bush = mlx_load_png("images/Bush.png");
	if (!bush)
		error_message("Problem with loading png");
	img->bush = mlx_texture_to_image(mlx, bush);
	if (!img->bush)
		error_message("Problem with texture to image");
	mlx_delete_texture(bush);
	return (img);
}
