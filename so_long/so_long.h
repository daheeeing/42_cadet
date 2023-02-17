/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:52:02 by dapark            #+#    #+#             */
/*   Updated: 2023/01/22 22:49:47 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"
# define BOLDRED	"\033[31m"
# define KEY_W	13
# define KEY_S	1
# define KEY_A	0
# define KEY_D	2
# define KEY_ESC	53
# define X_EVENT_KEY_EXIT	17

# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		collect;
}	t_player;

typedef struct s_image
{
	void	*img_tile;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_image;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		*map;
	int			coincheck;
	int			playercheck;
	int			exitcheck;
	int			moving;
	int			height;
	int			width;
	int			dfs_coin;
	int			dfs_exit;
	t_player	player;
	t_image		image;
}	t_game;

char	*read_map(t_game	*game, int fd);
int		key_press(int key_value, t_game	*game);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	xpm_to_image_init(t_game	*game);
void	draw_image_map(t_game *game);
char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
void	move(t_game *game, int x, int y);
void	player_init(t_game	*game);
int		exit_game(t_game *game, int flag);
int		check_map_contents(t_game *game);
int		check_wall(char **map, t_game *game);
char	**make_map_for_dfs(t_game *game);
int		check_whole(t_game *game);
void	ft_free(char ***str);
int		dfs(char **map, int x, int y, t_game *game);
void	put_image(t_game *game, int width, int height, char image);
void	move_print_count_collect(t_game *game, int x, int y);

#endif