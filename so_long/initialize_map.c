/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:15:45 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/19 20:32:51 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_map_rows(const char *map_file)
{
	int		fd;
	int		rows;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: Cannot open map file\n"), -1);
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		rows++;
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

char	**read_map(const char *map_file, int *rows)
{
	int		fd;
	int		i;
	char	**map;
	char	*line;

	*rows = count_map_rows(map_file);
	if (*rows < 0)
		return (NULL);
	map = malloc((*rows + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	initialize_elements(int *e, int *p, int *c, char **map)
{
	int	i;
	int	j;

	*e = 0;
	*p = 0;
	*c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				(*e)++;
			else if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}
