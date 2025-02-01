/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mely-pan <mely-pan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:35:28 by mely-pan          #+#    #+#             */
/*   Updated: 2025/01/27 19:45:51 by mely-pan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error("Must have one argument!");
	if (!is_correct_file_format(argv[1]))
		ft_error("Argument must be a '.ber' file");
	ft_bzero(&game, sizeof(t_game));
	parse_map(&game, argv[1]);
	if (!game.map.data)
		exit_game(&game, "Failed to parse map!");
	validate_map(&game);
	init_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
