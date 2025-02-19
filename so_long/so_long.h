/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadi <hmadi@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:17:47 by hmadi             #+#    #+#             */
/*   Updated: 2025/02/19 20:18:02 by hmadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include "inc/Libft/libft.h"
# include "inc/ft_printf/ft_printf.h"
# include "inc/get_next_line/get_next_line.h"

typedef struct game
{
	void	*mlx;
	void	*mlx_window;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		collectable_cont;
	int		count_movement;
}			t_game;
char		**parse_map(const char *map, t_game *game);
void		load_images(t_game *game);
void		render_map(t_game *game);
int			logic_and_movement(int new_x, int new_y, t_game *game);
void		player_postion(t_game *game);
void		free_game(t_game *game, char *message);
void		free_map(char **map);
void		free_map_error(char **map, char *message);
void		free_two_maps(char **map, char **map_two, char *message);
int			check_valid_path(char **map, int rows, int cols, t_game *game);
char		**read_map(const char *map_file, int *rows);
void		initialize_elements(int *e, int *p, int *c, char **map);
#endif
