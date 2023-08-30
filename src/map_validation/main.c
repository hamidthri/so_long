/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:57:41 by htaheri           #+#    #+#             */
/*   Updated: 2023/08/26 18:28:19 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../MLX42/include/MLX42/MLX42.h"
#include <MLX42/MLX42.h>

void	load_link_textures(t_map *map)
{
	map->link_up = mlx_load_png("images/Link_Up.png");
	if (!map->link_up)
		error_message("Problem with loading png");
	map->link_down = mlx_load_png("images/Link_Down.png");
	if (!map->link_down)
		error_message("Problem with loading png");
	map->link_left = mlx_load_png("images/Link_Left.png");
	if (!map->link_left)
		error_message("Problem with loading png");
	map->link_right = mlx_load_png("images/Link_Right.png");
	if (!map->link_right)
		error_message("Problem with loading png");
}

void	map_extention_check(char *map, char *ber)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(map);
	j = 0;
	while (j < 4)
	{
		if (ber[j] != map[i - 4 + j])
		{
			error_message ("Error");
			return ;
		}
		j++;
	}
}

t_map	*initialize_map(char **array_map)
{
	t_map		*map_details;
	t_pos		pos;

	map_details = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map_details)
		error_message("allocation failed");
	map_details->width = ft_strlen(array_map[0]);
	map_details->height = count_height(array_map);
	map_details->grid = array_map;
	map_details->steps = 0;
	pos = player_pos(map_details);
	map_details->p_x = pos.x_pos;
	map_details->p_y = pos.y_pos;
	pos = exit_pos(map_details);
	map_details->e_x = pos.x_pos;
	map_details->e_y = pos.y_pos;
	map_details->rupees = count_rupees(map_details);
	load_link_textures(map_details);
	return (map_details);
}

t_map	*read_map(char *map)
{
	char	*string_map;
	char	**array_map;
	t_map	*map_struct;

	string_map = map_as_string(map);
	is_empty(string_map);
	is_empty_line(string_map);
	map_content(string_map);
	array_map = ft_split(string_map, '\n');
	is_rec_map(array_map);
	map_struct = initialize_map(array_map);
	wall_check(map_struct);
	valid_rout(map_struct);
	free (string_map);
	return (map_struct);
}

int32_t	main(int32_t argc, char *argv[])
{
	t_map		*map;
	t_image		*images;

	if (argc != 2)
		error_message("Please add a map as argument");
	map = read_map(argv[1]);
	map->mlx = mlx_init(map->width * PIXELS, \
				map->height * PIXELS, "so_long", false);
	if (!map->mlx)
		return (EXIT_FAILURE);
	images = initialize_img_struct(map->mlx);
	map->images = images;
	fill_background(map);
	render_map(map);
	mlx_key_hook(map->mlx, move_map, map);
	mlx_loop_hook(map->mlx, enemy_patrol, map);
	mlx_loop(map->mlx);
	mlx_terminate(map->mlx);
	return (EXIT_SUCCESS);
}
