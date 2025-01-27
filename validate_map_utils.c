/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:36:32 by mely-pan          #+#    #+#             */
/*   Updated: 2025/01/27 21:33:56 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_correct_file_format(char *map_path)
{
	ssize_t	len;

	len = ft_strlen(map_path);
	if (len < 4 || ft_strncmp(map_path + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	has_valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != 'E' && map[i][j] != '\n'
				&& map[i][j] != '\0')
				return (0);
			if (map[i][j] == '1' && map[i][j] != 'P')
			j++;
		}
		i++;
	}
	return (1);
}

static char	**copy_map(char **map)
{
	char	**new_map;
	int		i;
	int		height;

	i = 0;
	height = get_map_height(map);
	new_map = malloc(sizeof(char *) * (height + 1));
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
	new_map[i] = 0;
	return (new_map);
}

int	is_winnable(t_game *game)
{
	char	**aux;
	int		can_exit;
	int		collectibles;
	int		pos[2];

	get_player_pos(game);
	pos[0] = game->player.x;
	pos[1] = game->player.y;
	collectibles = game->map.c;
	can_exit = 0;
	aux = copy_map(game->map.data);
	if (!aux)
		exit_game(game, "Failed checking the map");
	ft_flood_fill(aux, pos, &collectibles, &can_exit);
	free_map(aux);
	if (collectibles == 0 && can_exit == 1)
		return (1);
	return (0);
}

void	ft_flood_fill(char **map, int pos[2], int *collectibles, int *can_exit)
{
	int	x;
	int	y;
	int	new_pos[2];

	x = pos[0];
	y = pos[1];
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		(*collectibles)--;
	if (map[y][x] == 'E')
		*can_exit = 1;
	map[y][x] = 'F';
	new_pos[0] = x + 1;
	new_pos[1] = y;
	ft_flood_fill(map, new_pos, collectibles, can_exit);
	new_pos[0] = x - 1;
	new_pos[1] = y;
	ft_flood_fill(map, new_pos, collectibles, can_exit);
	new_pos[0] = x;
	new_pos[1] = y + 1;
	ft_flood_fill(map, new_pos, collectibles, can_exit);
	new_pos[0] = x;
	new_pos[1] = y - 1;
	ft_flood_fill(map, new_pos, collectibles, can_exit);
}
