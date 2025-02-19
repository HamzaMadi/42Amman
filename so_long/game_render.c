/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:15:09 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/19 20:15:16 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image(int x, int y, t_game *game)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->wall,
			x * 64, y * 64);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->floor, x * 64, y * 64);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->player, x * 64, y * 64);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->collectible, x * 64, y * 64);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->exit,
			x * 64, y * 64);
}

void	player_postion(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	load_images(t_game *game)
{
	int	img_width;
	int	img_height;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&img_width, &img_height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&img_width, &img_height);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&img_width, &img_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm",
			&img_width, &img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&img_width, &img_height);
	if (!game->wall || !game->floor || !game->player || !game->collectible
		|| !game->exit)
	{
		ft_printf("Error: Failed to load one or more images.\n");
		exit(1);
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				render_image(x, y, game);
			else if (game->map[y][x] == '0')
				render_image(x, y, game);
			else if (game->map[y][x] == 'P')
				render_image(x, y, game);
			else if (game->map[y][x] == 'C')
				render_image(x, y, game);
			else if (game->map[y][x] == 'E')
				render_image(x, y, game);
			x++;
		}
		y++;
	}
}

int	logic_and_movement(int new_x, int new_y, t_game *game)
{
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'C')
		game->collectable_cont--;
	if (game->map[new_y][new_x] == 'E' && game->collectable_cont == 0)
	{
		free_game(game, "Congratulations! You collected all items and won!\n");
		exit(0);
	}
	if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
		game->count_movement++;
		ft_printf("Number of movements: %d\n", game->count_movement);
	}
	return (0);
}
