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
	while ((line = get_next_line(fd)) != NULL)
	{
		aux = map_content;
		map_content = ft_strjoin(aux, line);
		free(aux);
		free(line);
	}
	close(fd);
	if (!map_content)
		exit_game(game, "Error: Map is empty!");
	game->map.data = ft_split(map_content, '\n');
	free(map_content);
	if (!game->map.data)
		exit_game(game, "Error: Failed to parse map!");
}


