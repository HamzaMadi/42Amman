/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:16:37 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/19 20:56:05 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		if (str1[i] == '\0' && str2[i] == '\0')
			return (0);
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	is_valid_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error: Invalid file extension. Use a .ber file\n");
		return(0);
	}
	return (1);
}

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
		ft_printf("Error: include map file");
		return (1);
	}
	if (!is_valid_extension(argv[1]))
		return (1);
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
