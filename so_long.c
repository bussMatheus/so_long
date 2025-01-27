#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		ft_error("Must have one argument!\n");
	if (!is_correct_file_format(argv[1]))
		ft_error("Argument must be a '.ber' file");
	ft_bzero(&game, sizeof(t_game));
	parse_map(&game, argv[1]);
	validate_map(&game);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}