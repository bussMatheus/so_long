#include "so_long.h"

void	display_moves(t_game *game)
{
	char *str;

	str = ft_itoa(game->player.moves);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, str);
	free(str);
}

static void	*get_image_from_pos(char c, t_game *game)
{
	void *aux;

	if (c == '1')
			aux = game->wall.img;
	else if (c == '0')
		aux = game->background.img;
	else if (c == 'P')
		aux = game->player_img.img;
	else if (c == 'C')
		aux = game->collectible.img;
	if (c == 'E')
	{
		if (game->map.c == game->player.c_taken)
			aux = game->exit.img;
		else
			aux = game->background.img;
	}
	return ((void *)aux);
}

void	render_map(t_game *game)
{
	int		i;
	int		j;
	void	*aux;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			aux = get_image_from_pos(game->map.data[i][j], game);
			mlx_put_image_to_window(game->mlx, game->win, aux, (j * IMAGES_SIZE), (i * IMAGES_SIZE));
			j++;
		}
		i++;
	}
}
