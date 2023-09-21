/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaheri <htaheri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:00:27 by htaheri           #+#    #+#             */
/*   Updated: 2023/09/21 18:31:22 by htaheri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdint.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# define PIXELS 64
# define EMOVE 30

typedef struct s_image
{
	mlx_image_t			*bush;
	mlx_image_t			*grass;
	mlx_image_t			*collectible;
	mlx_image_t			*link;
	mlx_image_t			*enemy;
	mlx_image_t			*exit_closed;
	mlx_image_t			*exit_open;
	mlx_image_t			*moves_print;
	mlx_image_t			*moves_nbr;
	mlx_image_t			*rupee_nbr;
}	t_image;

typedef struct s_map
{
	size_t			width;
	size_t			height;
	size_t			p_x;
	size_t			p_y;
	size_t			e_x;
	size_t			e_y;
	size_t			rupees;
	size_t			collected;
	size_t			steps;
	char			**grid;
	mlx_texture_t	*link_up;
	mlx_texture_t	*link_down;
	mlx_texture_t	*link_left;
	mlx_texture_t	*link_right;
	mlx_t			*mlx;
	t_image			*images;
}	t_map;

typedef struct s_pos
{
	size_t			x_pos;
	size_t			y_pos;
}	t_pos;

typedef struct s_var {
	int				ran_x;
	int				ran_y;
	int				*x;
	int				*y;
	int				index_x;
	int				index_y;
}	t_var;

typedef struct s_point
{
	size_t		x;
	size_t		y;
	int			n_rupees;
	int			exit;
	char		**grid;
}	t_point;

// validating map
t_map		*read_map(char *map);
void		map_content(char *map);
void		error_message(char	*msg);
char		*map_as_string(int fd);
void		is_empty(char *map);
void		is_rec_map(char **map);
void		is_empty_line(char *map);
void		map_extention_check(char *map, char *ber);
void		valid_rout(t_map *map);
void		wall_check(t_map *map_struct);
t_pos		player_pos(t_map *map_details);
t_pos		exit_pos(t_map *map_details);
t_map		*read_map(char *map);
size_t		count_height(char **col);
size_t		count_rupees(t_map *game);
t_map		*initialize_map(char **array_map);

void		fill_background(t_map *map);
void		render_map(t_map *map);
// Moving funcions
void		remove_collectible(t_map *game, int y, int x);
void		check_game_status(t_map *game);
void		move_map(mlx_key_data_t keydata, void *data);
void		move_left(t_map *map);
void		move_right(t_map *map);
void		move_down(t_map *map);
void		move_up(t_map *map);
// void	move_map();
t_image		*initialize_img_struct(mlx_t *mlx);

// texture
t_image		*enemy_texture(mlx_t *mlx, t_image *img);
t_image		*collectible_texture(mlx_t *mlx, t_image *img);
t_image		*bush_texture(mlx_t *mlx, t_image *img);
t_image		*exit_open_texture(mlx_t *mlx, t_image *img);
t_image		*exit_closed_texture(mlx_t *mlx, t_image *img);
t_image		*grass_texture(mlx_t *mlx, t_image *img);
t_image		*link_texture(mlx_t *mlx, t_image *img);

// enemy
void		enemy_patrol(void *temp);

void		map_status(t_map *map);
void		load_link(t_map *map, char dir);

// printing
void		string_to_screen(t_map *game);
void		print_moves(t_map *game);
void		print_rupees(t_map *game);
#endif