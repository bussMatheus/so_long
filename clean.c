#include "so_long.h"

//it frees the 2d array map
void	free_map(char **map)
{
	int i;

	i = 0;
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free(map);
	}
}

static void	destroy_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

static void	destroy_imgs(t_game *game)
{
	if (game->player_img.img)
		mlx_destroy_image(game->mlx, game->player_img.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->background.img)
		mlx_destroy_image(game->mlx, game->background.img);
	if (game->exit.img)
			mlx_destroy_image(game->mlx, game->exit.img);
}

void	exit_game(t_game *game, char *str)
{
	free_map(game->map.data);
	destroy_imgs(game);
	destroy_window(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (str)
	{
		ft_putstr_fd(str, 2);
		exit (1);
	}
	exit (0);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}