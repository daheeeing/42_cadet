/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:29:07 by dapark            #+#    #+#             */
/*   Updated: 2023/01/22 22:51:32 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(t_game	*game, int fd)
{
	int		size;
	int		line;
	char	*store;
	char	*buf;
	char	*map;

	size = 0;
	line = 0;
	buf = malloc(sizeof(char) * 1);
	buf[0] = '\0';
	store = get_next_line(fd);
	while (store)
	{
		while (store[size] != '\0' && line == 0)
			size++;
		map = ft_strjoin(buf, store);
		free(buf);
		free(store);
		store = get_next_line(fd);
		line++;
		buf = map;
	}
	game->width = --size;
	game->height = line;
	return (map);
}

void	draw_image_map(t_game *game)
{
	int	height;
	int	width;
	int	i;

	height = -1;
	while (++height < game->height)
	{
		width = -1;
		i = (game->width + 1) * height;
		while (++width < game->width)
		{
			put_image(game, width, height, 'T');
			if (game->map[i] == 'P')
				put_image(game, width, height, 'P');
			else if (game->map[i] == '1')
				put_image(game, width, height, '1');
			else if (game->map[i] == 'C')
				put_image(game, width, height, 'C');
			else if (game->map[i] == 'E')
				put_image(game, width, height, 'E');
			i++;
		}
	}
}

void	move(t_game *game, int x, int y)
{
	if (game->map[(game->player.x + x) + (game->width + 1) * \
		(game->player.y + y)] == 'E')
	{
		if (game->coincheck != game->player.collect)
		{
			move_print_count_collect(game, x, y);
			draw_image_map(game);
			put_image(game, game->player.x + x, game->player.y + y, 'P');
			game->player.x = game->player.x + x;
			game->player.y = game->player.y + y;
		}
		else
			exit_game(game, 1);
	}
	else if (game->map[(game->player.x + x) + (game->width + 1) * \
	(game->player.y + y)] != '1')
	{
		move_print_count_collect(game, x, y);
		game->map[(game->player.x + x) + (game->width + 1) \
		* (game->player.y + y)] = 'P';
		draw_image_map(game);
		game->player.x = game->player.x + x;
		game->player.y = game->player.y + y;
	}
}

int	key_press(int key_value, t_game *game)
{
	if (key_value == KEY_W)
		move(game, 0, -1);
	else if (key_value == KEY_S)
		move(game, 0, 1);
	else if (key_value == KEY_A)
		move(game, -1, 0);
	else if (key_value == KEY_D)
		move(game, 1, 0);
	else if (key_value == KEY_ESC)
		exit_game(game, 0);
	return (0);
}

void	ft_free(char ***str)
{
	int	i;												

	i = 0;
	while ((*str)[i] != NULL)
		free((*str)[i++]);
	free(*str);
}
