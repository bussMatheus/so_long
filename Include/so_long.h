#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"

typedef	struct s_player
{
	int	x;
	int	y;
	int	moves;
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
	int		n_collectables;
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
	t_img		player;
	t_img		collectible;
	t_img		background;
	t_img		exit;
}	t_game;


#endif