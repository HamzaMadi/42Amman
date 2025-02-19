/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:18:34 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/19 20:18:35 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, int rows)
{
	char	**map_copy;
	int		i;

	map_copy = malloc((rows + 1) * sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[rows] = NULL;
	return (map_copy);
}

void	flood_fill(t_game *map_copy, int x, int y)
{
	if (x < 0 || y < 0 || x >= map_copy->rows || y >= map_copy->cols
		|| map_copy->map[x][y] == '1' || map_copy->map[x][y] == 'V')
		return ;
	map_copy->map[x][y] = 'V';
	flood_fill(map_copy, x + 1, y);
	flood_fill(map_copy, x - 1, y);
	flood_fill(map_copy, x, y + 1);
	flood_fill(map_copy, x, y - 1);
}

int	check_valid_path(char **map, int rows, int cols, t_game *game)
{
	int		i;
	int		j;
	t_game	map_copy;

	map_copy.map = copy_map(map, rows);
	map_copy.cols = cols;
	map_copy.rows = rows;
	if (!map_copy.map)
		return (0);
	flood_fill(&map_copy, game->player_y, game->player_x);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map_copy.map[i][j] == 'C' || map_copy.map[i][j] == 'E')
				free_two_maps(map, map_copy.map, "Error: no valid path\n");
			j++;
		}
		i++;
	}
	free_map(map_copy.map);
	return (1);
}
