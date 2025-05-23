/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:51:21 by llebugle          #+#    #+#             */
/*   Updated: 2025/03/28 19:09:49 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	fill_matrix(t_map *map, int **matrix, char **line, int y)
{
	int	x;

	x = 0;
	matrix[y] = malloc(sizeof(int) * map->width);
	if (!matrix[y])
		return (print_err(MSG_ERR_MALLOC), ERROR);
	while (line[y][x])
	{
		if (line[y][x] == ' ' || line[y][x] == '\t')
			matrix[y][x] = 0;
		else if (ft_is_charset((line[y][x]), "EWNS") == true)
			matrix[y][x] = 0;
		else if (line[y][x] == 'C')
		{
			map->nb_cores++;
			matrix[y][x] = 2;
		}
		else
			matrix[y][x] = line[y][x] - 48;
		x++;
	}
	while (x < map->width)
		matrix[y][x++] = 0;
	return (0);
}

int	create_matrix(t_map *map, char **line)
{
	int	i;
	int	**matrix;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * (map->height));
	if (!matrix)
		return (print_err(MSG_ERR_MALLOC), ERROR);
	while (i < map->height)
	{
		if (fill_matrix(map, matrix, line, i) == ERROR)
			return (ERROR);
		i++;
	}
	map->matrix = matrix;
	return (0);
}

int	validate_map(t_map *map, char **line)
{
	int		i;
	int		j;
	char	*valid_chars;

	i = -1;
	valid_chars = "01EWNS \t";
	if (BONUS)
		valid_chars = "01EWNSC \t";
	while (line[++i])
	{
		j = -1;
		while (line[i][++j])
		{
			if (check_orientation(map, line[i][j], (t_coord){j, i}) == ERROR)
				return (ERROR);
			if (ft_is_charset(line[i][j], valid_chars) == false)
				return (print_err(MSG_INVALID_CHAR), ERROR);
		}
		if (j > map->width)
			map->width = j;
	}
	if (!map->orientation_start)
		return (print_err(MSG_NO_PLAYER), ERROR);
	return (map->height = i, 0);
}

int	is_map_closed(t_map *map)
{
	int	**cpy;
	int	i;
	int	j;

	cpy = (int **)ft_calloc((map->height + 1), sizeof(int *));
	if (!cpy)
		return (print_err(MSG_ERR_MALLOC), ERROR);
	i = -1;
	while (++i < map->height)
	{
		cpy[i] = (int *)ft_calloc(map->width, sizeof(int));
		if (!cpy[i])
			return (free_matrix(cpy, i), print_err(MSG_ERR_MALLOC), ERROR);
		j = -1;
		while (++j < map->width)
			cpy[i][j] = map->matrix[i][j];
	}
	if (flood_fill(map, cpy, map->player_start.y, map->player_start.x) == ERROR)
		return (free_matrix(cpy, map->height), print_err(MSG_MAP_NOT_CLOSED),
			ERROR);
	free_matrix(cpy, map->height);
	return (0);
}
