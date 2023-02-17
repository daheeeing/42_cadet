/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapark <dapark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:15:41 by dapark            #+#    #+#             */
/*   Updated: 2023/01/22 23:11:27 by dapark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**make_map_for_dfs(t_game *game)
{
	char	**str;
	int		count;
	int		i;
	int		j;

	count = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (game->height + 1));
	while (count < game->height)
	{
		i = 0;
		str[count] = (char *)malloc(sizeof(char) * (game->width + 1));
		while (game->map[j] != '\0' && game->map[j] != '\n')
			str[count][i++] = game->map[j++];
		str[count++][i] = '\0';
		j++;
	}
	str[game->height] = NULL;
	return (str);
}

int	dfs(char **map, int x, int y, t_game *game)
{
	if (game->dfs_exit == 0 && game->dfs_coin == 0)
		return (1);
	if (map[y][x] == 'C')
		game->dfs_coin--;
	if (map[y][x] == 'E')
		game->dfs_exit--;
	map[y][x] = '1';
	if (x + 1 < game->width && map[y][x + 1] != '1')
		if (dfs(map, x + 1, y, game))
			return (1);
	if (x - 1 >= 0 && map[y][x - 1] != '1')
		if (dfs(map, x - 1, y, game))
			return (1);
	if (y + 1 < game->height && map[y + 1][x] != '1')
		if (dfs(map, x, y + 1, game))
			return (1);
	if (y - 1 >= 0 && map[y - 1][x] != '1')
		if (dfs(map, x, y - 1, game))
			return (1);
	map[y][x] = '0';
	return (0);
}

int	check_map_contents(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] == 'P')
			game->playercheck++;
		else if (game->map[i] == 'C')
			game->coincheck++;
		else if (game->map[i] == 'E')
			game->exitcheck++;
		else if (game->map[i] != '0' && game->map[i] != '1' \
				&& game->map[i] != '\n')
			return (0);
		i++;
	}
	if (game->playercheck != 1 || game->exitcheck != 1)
		return (0);
	if (game->coincheck < 1)
		return (0);
	game->dfs_coin = game->coincheck;
	game->dfs_exit = game->exitcheck;
	return (1);
}

int	check_wall(char **map, t_game *game)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if ((i == 0 || j == 0 || i == game->height - 1 \
				|| j == game->width - 1) && map[i][j] != '1')
				return (0);
			j++;
		}
		if (i == 0)
			check = j;
		if (check != j)
			return (0);
		if (i != 0)
			check = j;
		i++;
	}
	return (1);
}

int	check_whole(t_game *game)
{
	char	**str;

	str = make_map_for_dfs(game);
	if (!check_map_contents(game))
	{
		ft_printf("%s", "!!!!! ERROR : MAP CONTENTS !!!!! \n");
		ft_free(&str);
		return (0);
	}
	if (!check_wall(str, game))
	{
		ft_printf("%s", "!!!!! ERROR : MAP WALL !!!!! \n");
		ft_free(&str);
		return (0);
	}
	if (!dfs(str, game->player.x, game->player.y, game))
	{
		ft_printf("%s", "!!!!! ERROR : MAP DFS !!!!! \n");
		ft_free(&str);
		return (0);
	}
	ft_free(&str);
	return (1);
}
