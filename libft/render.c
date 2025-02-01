/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:36:48 by mely-pan          #+#    #+#             */
/*   Updated: 2025/01/27 19:45:04 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.moves);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, str);
	free(str);
}

static void	*get_image_from_pos(char c, t_game *game)
{
	void	*aux;

	if (c == '1')
		aux = game->wall.img;
	else if (c == '0')
		aux = game->bg.img;
	else if (c == 'P' && game->player.mv_right)
		aux = game->p_right.img;
	else if (c == 'P' && !(game->player.mv_right))
		aux = game->p_left.img;
	else if (c == 'C')
		aux = game->c.img;
	if (c == 'E')
	{
		if (game->map.c == game->player.c_taken)
			aux = game->exit.img;
		else
			aux = game->bg.img;
	}
	return ((void *)aux);
}

void	render_map(t_game *game)
{
	int		i;
	int		j;
	void	*aux;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			aux = get_image_from_pos(game->map.data[i][j], game);
			mlx_put_image_to_window(game->mlx, game->win, aux, (j
					* IMAGES_SIZE), (i * IMAGES_SIZE));
			j++;
		}
		i++;
	}
}
