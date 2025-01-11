#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		ft_putstr_fd("Must have one argument!\n", 2);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	parse_map(&game, argv[1]);
	validate_map(&game);
	init_game(&game);
	mlx_loop(&game);
	return (0);
}