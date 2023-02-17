/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:40:08 by dapark            #+#    #+#             */
/*   Updated: 2023/01/20 18:15:46 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game	*game)
{
	game->coincheck = 0;
	game->exitcheck = 0;
	game->playercheck = 0;
	game->player.collect = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->moving = 0;
	game->dfs_exit = 0;
	game->dfs_coin = 0;
	return ;
}

void	xpm_to_image_init(t_game	*game)
{
	int	img_width;
	int	img_height;

	img_height = 64;
	img_width = 64;
	game->image.img_tile = mlx_xpm_file_to_image(game->mlx, \
		"textures/tile.xpm", &img_width, &img_height);
	game->image.img_wall = mlx_xpm_file_to_image(game->mlx, \
		"textures/wall.xpm", &img_width, &img_height);
	game->image.img_player = mlx_xpm_file_to_image(game->mlx, \
		"textures/player.xpm", &img_width, &img_height);
	game->image.img_collect = mlx_xpm_file_to_image(game->mlx, \
		"textures/collect.xpm", &img_width, &img_height);
	game->image.img_exit = mlx_xpm_file_to_image(game->mlx, \
		"textures/exit.xpm", &img_width, &img_height);
	return ;
}

void	player_init(t_game	*game)
{
	int	height;
	int	width;
	int	i;

	i = 0;
	height = -1;
	while (++height < game->height)
	{
		width = -1;
		while (++width < game->width)
		{
			if (game->map[i] == '\n')
				width--;
			if (game->map[i] == 'P')
			{
				game->player.x = width;
				game->player.y = height;
				return ;
			}
			i++;
		}
	}
}

int	exit_game(t_game *game, int flag)
{
	if (flag == 1)
		ft_printf("%s\n", "!!! GAME CLEAR !!!");
	mlx_destroy_window(game->mlx, game->window);
	free(game->map);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game		game;
	int			fd;

	if (argc != 2)
		return (0);
	game_init(&game);
	game.mlx = mlx_init();
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (0);
	game.map = read_map(&game, fd);
	player_init(&game);
	if (!check_whole(&game))
		return (0);
	game.window = mlx_new_window(game.mlx, game.width * 64, \
		game.height * 64, "dapark's_game");
	if (!game.window)
		return (0);
	xpm_to_image_init(&game);
	draw_image_map(&game);
	mlx_key_hook(game.window, &key_press, &game);
	mlx_hook(game.window, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx);
	close(fd);
	return (0);
}
