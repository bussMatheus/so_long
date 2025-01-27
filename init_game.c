#include "so_long.h"

static void	define_assets(t_game *game)
{
	int	width;
	int heigth;

	width = IMAGES_SIZE;
	heigth = IMAGES_SIZE;
	game->player_img.img = mlx_xpm_file_to_image(game->mlx, "./assets/Playerr.xpm", &width, &heigth);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx, "./assets/token.xpm", &width, &heigth);
	game->background.img = mlx_xpm_file_to_image(game->mlx, "./assets/bg.xpm", &width, &heigth);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./assets/exit.xpm", &width, &heigth);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/Wall.xpm", &width, &heigth);
	if (!game->player_img.img)
		exit_game(game, "Error: Failed to load player image");
	if (!game->collectible.img)
		exit_game(game, "Error: Failed to load collectible image");
	if (!game->background.img)
		exit_game(game, "Error: Failed to load background image");
	if (!game->exit.img)
		exit_game(game, "Error: Failed to load exit image");
	if (!game->wall.img)
		exit_game(game, "Error: Failed to load wall image");
}

void	init_game(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, "Failed to Initialize minilibx");
	game->map.height = get_map_height(game->map.data);
	game->map.width = get_map_width(game->map.data);
	height = game->map.height * IMAGES_SIZE;
	width = game->map.width * IMAGES_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		exit_game(game, "Error: Failed to open window");
	game->player.moves = 0;
	game->player.c_taken = 0;
	get_player_pos(game);
	get_exit_pos(game);
	define_assets(game);
	define_hooks(game);
	render_map(game);
	display_moves(game);
	printf("Created window %dx%d, Moves: %d\n", height, width, game->player.moves);
}
