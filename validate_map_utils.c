#include "so_long.h"

int	is_correct_file_format(char *map_path)
{
	ssize_t	len;

	len = ft_strlen(map_path);
	if (len < 4 || ft_strncmp(map_path + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

static char	**copy_map(char **map)
{
	char	**new_map;
	int		i;
	int		height;

	i = 0;
	height = get_map_height(map);
	new_map = malloc(sizeof(char *) * height + 1);
	if (!new_map)
		return (NULL);
	while (i < height)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = '\0';
	return (new_map);
}

int	is_winnable(t_game *game)
{
	char	**aux;
	int		can_exit;
	int		collectibles;
	int		x;
	int		y;

	get_player_pos(game);
	x = game->player.x;
	y = game->player.y;
	collectibles = game->map.c;
	can_exit = 0;
	aux = copy_map(game->map.data);
	ft_flood_fill(aux, x, y, &collectibles, &can_exit);
	free_map(aux);
	if (collectibles == 0 && can_exit == 1)
		return (1);
	return (0);
}

void	ft_flood_fill(char **map, int x, int y, int *collectibles, int *can_exit)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		(*collectibles)--;
	if (map[y][x] == 'E')
		*can_exit = 1;
	map[y][x] = 'F';
	ft_flood_fill (map, x + 1, y, collectibles, can_exit);
	ft_flood_fill (map, x - 1, y, collectibles, can_exit);
	ft_flood_fill (map, x, y + 1, collectibles, can_exit);
	ft_flood_fill (map, x, y - 1, collectibles, can_exit);
}
