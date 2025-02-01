/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:37:01 by mely-pan          #+#    #+#             */
/*   Updated: 2025/01/27 21:06:09 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_pos(t_game *game, int new_x, int new_y)
{
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.moves++;
	if (game->player.c_taken == game->map.c)
		game->map.data[game->map.exit_y][game->map.exit_x] = 'E';
}

static void	move_player(t_game *game, int move_x, int move_y)
{
	int	new_y;
	int	new_x;

	new_x = game->player.x + move_x;
	new_y = game->player.y + move_y;
	if (new_x < 0 || new_x >= game->map.width || new_y < 0
		|| new_y >= game->map.height)
		return ;
	if (game->map.data[new_y][new_x] != '1')
	{
		if (game->map.data[new_y][new_x] == 'C')
			game->player.c_taken++;
		else if (game->map.data[new_y][new_x] == 'E'
			&& game->player.c_taken == game->map.c)
			game_won(game);
		game->map.data[game->player.y][game->player.x] = '0';
		game->map.data[new_y][new_x] = 'P';
		update_pos(game, new_x, new_y);
		render_map(game);
		display_moves(game);
	}
}

int	ft_close(t_game *game)
{
	exit_game(game, NULL);
	return (0);
}

int	ft_keypress_handler(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 0, -1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player.mv_right = false;
		move_player(game, -1, 0);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player.mv_right = true;
		move_player(game, 1, 0);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 0, 1);
	else if (keycode == KEY_ESC)
		ft_close(game);
	return (0);
}

void	define_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 0, ft_close, game);
	mlx_hook(game->win, 2, (1L << 0), ft_keypress_handler, game);
}
