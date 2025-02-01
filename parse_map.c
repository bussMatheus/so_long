/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:36:51 by mely-pan          #+#    #+#             */
/*   Updated: 2025/01/27 19:44:41 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	has_valid_components(t_game *game, char *line, char *map_content)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
	{
		free(line);
		if (map_content)
			free(map_content);
		exit_game(game, "Map is invalid! check for unnecessary newline");
	}
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != '\n' && line[i] != 'E' && line[i] != 'C' && line[i] != '\0')
		{
			free(line);
			if (map_content)
				free(map_content);
			exit_game(game, "Map has invalid Characters!");
		}
		i++;
	}
}

void	parse_map(t_game *game, char *map_path)
{
	int		fd;
	char	*aux;
	char	*line;
	char	*map_content;

	map_content = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		exit_game(game, "Failed to open the map file");
	while ((line = get_next_line(fd)) != NULL)
	{
		aux = map_content;
		map_content = ft_strjoin_gnl(aux, line);
		has_valid_components(game, line, map_content);
		free(line);
		if (!map_content)
			exit_game(game, "Error while reading the map");
	}
	close(fd);
	if (!map_content)
		exit_game(game, "Error: Map is empty!");
	game->map.data = ft_split(map_content, '\n');
	free(map_content);
	if (!game->map.data)
		exit_game(game, "Error: Failed to parse map!");
}
