/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:36:36 by mely-pan          #+#    #+#             */
/*   Updated: 2025/01/27 21:22:10 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangular(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int	is_enclosed(char **map)
{
	int	len;
	int	i;
	int	height;

	height = 0;
	while (map[height])
		height++;
	i = 0;
	len = ft_strlen(map[0]);
	while (i < len)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	count_element(char **map, int c)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map [i][j] == c)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

static int	is_not_missing_components(t_game *game)
{
	int	player;
	int	collectible;
	int	exit;

	player = count_element(game->map.data, 'P');
	collectible = count_element(game->map.data, 'C');
	exit = count_element(game->map.data, 'E');
	if (player != 1 || exit != 1 || collectible < 1)
		return (0);
	game->map.c = collectible;
	return (1);
}

void	validate_map(t_game *game)
{
	if (!is_rectangular(game->map.data))
		exit_game(game, "Map is Not rectangular!");
	if (!is_enclosed(game->map.data))
		exit_game(game, "Map is not enclosed by walls!");
	if (!is_not_missing_components(game))
		exit_game(game, "Map does not have required components!");
	if (!is_winnable(game))
		exit_game(game, "Game is not winnable!");
}
