#include "so_long.h"

int	get_map_width(char	**map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

int	get_map_height(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	get_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.data[i])
	{
		j = 0;
		while (game->map.data[i][j])
		{
			if (game->map.data[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			j++;
		}
		i++;
	}
}

void	get_exit_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.data[i])
	{
		j = 0;
		while (game->map.data[i][j])
		{
			if (game->map.data[i][j] == 'E')
			{
				game->map.exit_x = j;
				game->map.exit_y = i;
			}
			j++;
		}
		i++;
	}
}
