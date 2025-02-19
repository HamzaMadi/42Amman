/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:16:37 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/19 20:16:38 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_game(game, "Closed normaly");
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 65361 || keycode == 'a')
		new_x--;
	if (keycode == 65362 || keycode == 'w')
		new_y--;
	if (keycode == 65363 || keycode == 'd')
		new_x++;
	if (keycode == 65364 || keycode == 's')
		new_y++;
	if (keycode == 65307)
	{
		free_game(game, "Closed normaly");
		exit(0);
	}
	logic_and_movement(new_x, new_y, game);
	render_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long map.ber\n");
		return (1);
	}
	game.map = parse_map(argv[1], &game);
	player_postion(&game);
	check_valid_path(game.map, game.rows, (game.cols - 1), &game);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx,
			game.cols * 64, game.rows * 64, "So Long");
	load_images(&game);
	render_map(&game);
	mlx_key_hook(game.mlx_window, key_hook, &game);
	mlx_hook(game.mlx_window, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
