/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:58:03 by dapark            #+#    #+#             */
/*   Updated: 2023/01/22 22:50:54 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, int width, int height, char image)
{
	if (image == 'T')
		mlx_put_image_to_window(game->mlx, game->window, \
			game->image.img_tile, width * 64, height * 64);
	else if (image == 'P')
		mlx_put_image_to_window(game->mlx, game->window, \
			game->image.img_player, width * 64, height * 64);
	else if (image == '1')
		mlx_put_image_to_window(game->mlx, game->window, \
			game->image.img_wall, width * 64, height * 64);
	else if (image == 'C')
		mlx_put_image_to_window(game->mlx, game->window, \
			game->image.img_collect, width * 64, height * 64);
	else if (image == 'E')
		mlx_put_image_to_window(game->mlx, game->window, \
			game->image.img_exit, width * 64, height * 64);
}

void	move_print_count_collect(t_game *game, int x, int y)
{
	game->moving++;
	ft_printf("number of movements : %d \n", game->moving);
	if (game->map[(game->player.x) + (game->width + 1) \
		* (game->player.y)] != 'E')
		game->map[(game->player.x) + (game->width + 1) \
		* (game->player.y)] = '0';
	if (game->map[(game->player.x + x) + (game->width + 1) \
		* (game->player.y + y)] == 'C')
		game->player.collect++;
}
