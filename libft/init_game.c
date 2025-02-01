/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:36:58 by mely-pan          #+#    #+#             */
/*   Updated: 2025/01/27 20:33:28 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	define_assets(t_game *game)
{
	int	w;
	int	h;

	w = IMAGES_SIZE;
	h = IMAGES_SIZE;
	game->p_right.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/p_right.xpm", &w, &h);
	game->p_left.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/p_left.xpm", &w, &h);
	game->c.img = mlx_xpm_file_to_image(game->mlx, "./assets/c.xpm", &w, &h);
	game->bg.img = mlx_xpm_file_to_image(game->mlx, "./assets/bg.xpm", &w, &h);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./assets/E.xpm", &w, &h);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/W.xpm", &w, &h);
	if (!game->p_left.img)
		exit_game(game, "Failed to load player image");
	if (!game->p_right.img)
		exit_game(game, "Failed to load player image");
	if (!game->c.img)
		exit_game(game, "Failed to load collectible image");
	if (!game->bg.img)
		exit_game(game, "Failed to load background image");
	if (!game->exit.img)
		exit_game(game, "Failed to load exit image");
	if (!game->wall.img)
		exit_game(game, "Failed to load wall image");
}

static int	is_valid_screen_size(t_game *game, int width, int height)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(game->mlx, &screen_width, &screen_height);
	if (screen_width < width || screen_height < height)
		return (0);
	return (1);
}

void	init_game(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, "Failed to Initialize minilibx");
	game->map.height = get_map_height(game->map.data);
	game->map.width = get_map_width(game->map.data);
	height = game->map.height * IMAGES_SIZE;
	width = game->map.width * IMAGES_SIZE;
	if (!is_valid_screen_size(game, width, height))
		exit_game(game, "Map surpass screen size");
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		exit_game(game, "Error: Failed to open window");
	game->player.moves = 0;
	game->player.c_taken = 0;
	game->player.mv_right = true;
	get_player_pos(game);
	get_exit_pos(game);
	define_assets(game);
	define_hooks(game);
	render_map(game);
	display_moves(game);
}
