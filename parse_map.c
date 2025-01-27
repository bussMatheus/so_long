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
	line = get_next_line(fd);
	while (line != NULL)
	{
		aux = map_content;
		map_content = ft_strjoin_gnl(aux, line);
		free(line);
		if (!map_content)
			exit_game(game, "Failed reading the map");
		line = get_next_line(fd);
	}
	close(fd);
	if (!map_content)
		exit_game(game, "Map is empty!");
	game->map.data = ft_split(map_content, '\n');
	free(map_content);
}
