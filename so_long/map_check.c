/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:17:07 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/19 20:17:08 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_row(char *row, char **map)
{
	int	i;

	if (!row)
		free_map_error(map, "Invalid map row\n");
	i = 0;
	while (row[i] && row[i] != '\n')
	{
		if (row[i] != '1')
			free_map_error(map, "Map is not enclosed with walls\n");
		i++;
	}
}

int	is_rectangular(char **map)
{
	size_t	first_len;
	int		i;

	if (!map || !map[0])
		return (0);
	first_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_len)
			return (0);
		i++;
	}
	return (1);
}

void	check_walls(char **map, int rows)
{
	int	i;
	int	len;

	if (!map || !map[0])
		free_map_error(map, "Empty map\n");
	len = ft_strlen(map[0]);
	check_row(map[0], map);
	check_row(map[rows - 1], map);
	i = 1;
	while (i < rows - 1)
	{
		if (map[i][0] != '1' || map[i][len - 2] != '1')
			free_map_error(map, "Map is not enclosed with walls\n");
		i++;
	}
}

void	check_elements(char **map, t_game *game)
{
	int	e;
	int	p;
	int	c;

	initialize_elements(&e, &p, &c, map);
	game->collectable_cont = c;
	if (e != 1)
		free_map_error(map, "Invalid exit count (should be 1)\n");
	if (p != 1)
		free_map_error(map, "Invalid player count (should be 1)\n");
	if (c < 1)
		free_map_error(map, "No collectibles found\n");
}

char	**parse_map(const char *map_file, t_game *game)
{
	int		rows;
	char	**map;

	map = read_map(map_file, &rows);
	if (!map)
		exit(1);
	game->rows = rows;
	game->cols = ft_strlen(map[0]) - 1;
	if (!is_rectangular(map))
		free_map_error(map, "Map is not rectangular\n");
	check_walls(map, rows);
	check_elements(map, game);
	return (map);
}
