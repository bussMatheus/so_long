/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:37:04 by mely-pan          #+#    #+#             */
/*   Updated: 2025/01/27 19:30:20 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//it frees the 2d array map
void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free(map);
	}
}

void	game_won(t_game *game)
{
	game->player.moves++;
	display_moves(game);
	ft_putstr_fd("You won!", 1);
	exit_game(game, NULL);
}

static void	destroy_imgs(t_game *game)
{
	if (game->p_right.img)
		mlx_destroy_image(game->mlx, game->p_right.img);
	if (game->p_left.img)
		mlx_destroy_image(game->mlx, game->p_left.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->c.img)
		mlx_destroy_image(game->mlx, game->c.img);
	if (game->bg.img)
		mlx_destroy_image(game->mlx, game->bg.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
}

void	exit_game(t_game *game, char *str)
{
	free_map(game->map.data);
	destroy_imgs(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (str)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd(str, 1);
		exit (1);
	}
	exit (0);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit(1);
}
