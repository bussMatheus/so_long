#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./minilibx-linux/mlx.h"

# define IMAGES_SIZE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_ESC 65307

/*            	STRUCTURES	              */
typedef	struct s_player
{
	int	x;
	int	y;
	int	moves;
	int	c_taken;
}	t_player;

typedef	struct s_images
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef	struct s_map
{
	char 	**data;
	int		width;
	int		height;
	int		c;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef	struct s_game
{
	void		*mlx; //Mlx instance
	void		*win; //Game Window
	t_map		map;
	t_player	player;
	t_img		wall;
	t_img		player_img;
	t_img		collectible;
	t_img		background;
	t_img		exit;
}	t_game;

/*              Exit && Clean FUNCTIONS            */
void	ft_error(char *str);
void	free_map(char **map);
void	exit_game(t_game *game, char *str);


/*              	HOOKS	            */
int 	ft_close(t_game *game);
int		ft_keypress_handler(int	keycode, t_game *game);
void	define_hooks(t_game *game);
void	display_moves(t_game *game);

/*              CHECK FUNCTIONS            */
int		is_correct_file_format(char *map_path);
int		is_winnable(t_game *game);

/*             		 UTILS   	         	*/
int		get_map_width(char **map);
int		get_map_height(char **map);
void	get_player_pos(t_game *game);
void	get_exit_pos(t_game *game);

/*              GAME PROCESS FUNCTIONS            */
void	init_game(t_game *game);
void	render_map(t_game *game);
void	validate_map(t_game *game);
void	parse_map(t_game *game, char *map_path);
void	ft_flood_fill(char **map, int x, int y, int *collectibles, int *can_exit);


#endif
