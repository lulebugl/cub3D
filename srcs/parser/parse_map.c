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

static int	fill_matrix(t_map *map, int **matrix, char **line)
{
	int	j;

	j = 0;
	*matrix = malloc(sizeof(int) * map->width);
	if (!*matrix)
		return (ERROR);
	while ((*line)[j])
	{
		if ((*line)[j] == ' ' || (*line)[j] == '\t')
			(*matrix)[j] = 0;
		else if ((*line)[j] == 'E' || (*line)[j] == 'S' || (*line)[j] == 'N'
			|| (*line)[j] == 'W')
			(*matrix)[j] = 0;
		else if ((*line)[j] == PORTAL)
			(*matrix)[j] = 2;
		else if ((*line)[j] == CONTROLLER)
			(*matrix)[j] = 3;
		else
			(*matrix)[j] = (*line)[j] - 48;
		j++;
	}
	while (j < map->width)
		(*matrix)[j++] = 0;
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
		if (fill_matrix(map, matrix + i, line + i) == ERROR)
			return (print_err(MSG_ERR_MALLOC), ERROR);
		i++;
	}
	map->matrix = matrix;
	return (0);
}

int	get_map_size(t_map *map, char **line)
{
	int	i;
	int	j;
	
	i = -1;
	while (line[++i])
	{
		j = -1;
		while (line[i][++j])
		{
			if (ft_is_charset(line[i][j], "EWNS") == true)
			{
				if (map->orientation_start)
					return (print_err(MSG_TOO_MANY_PLAYER), ERROR);
				map->orientation_start = line[i][j];
				map->player_start = (t_coord){j, i};
			}
			if (ft_is_charset(line[i][j], VALID_CHARS) == false)
				return (print_err(MSG_INVALID_CHAR), ERROR);
		}
		if (j > map->width)
			map->width = j;
	}
	if (!map->orientation_start)
		return (print_err(MSG_NO_PLAYER), ERROR);
	return (map->height = i, 0);
}

int	flood_fill(t_map *map, int **matrix, int x, int y)
{
	int	result;

	if (x < 0 || y < 0 || x >= map->height || y >= map->width)
		return (ERROR);
	if (matrix[x][y] == OBSTACLE || matrix[x][y] == VISITED)
		return (SUCCESS);
	matrix[x][y] = VISITED;
	result = SUCCESS;
	if (flood_fill(map, matrix, x + 1, y) == ERROR)
		result = ERROR;
	if (flood_fill(map, matrix, x, y + 1) == ERROR)
		result = ERROR;
	if (flood_fill(map, matrix, x - 1, y) == ERROR)
		result = ERROR;
	if (flood_fill(map, matrix, x, y - 1) == ERROR)
		result = ERROR;
	return (result);
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
