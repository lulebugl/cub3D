/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:58 by llebugle          #+#    #+#             */
/*   Updated: 2025/03/28 20:36:02 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_matrix(int **matrix, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			ft_printf("%d", matrix[i][j]);
		ft_printf("\n");
	}
}

void	print_map_info(t_map *map)
{
	if (!map)
		return ;
	ft_printf(BLUE);
	ft_printf("\n=== Map Info ===\n");
	ft_printf("Map height: %d\n", map->height);
	ft_printf("Map width: %d\n", map->width);
	ft_printf("Floor color: %d\n", map->floor_color);
	ft_printf("Ceiling color: %d\n", map->ceiling_color);
	ft_printf("Orientation start: %c\n", map->orientation_start);
	ft_printf("Nb cores: %d\n", map->nb_cores);
	printf("Player start: [%f,%f]\n", map->player_start.x,
		map->player_start.y);
	if (map->matrix)
	{
		ft_printf("\n======== Matrix ========\n\n");
		print_matrix(map->matrix, map->height, map->width);
	}
	ft_printf(RESET);
}

void	print_tex_info(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEX_COUNT)
	{
		if (data->tex[i])
		{
			if (data->tex[i]->data)
				ft_printf("Tex[%d] -> size[%d:%d]\n", i, data->tex[i]->width,
					data->tex[i]->height);
		}
	}
}

void	print_data(t_data *data)
{
	if (!data)
		return ;
	ft_printf(YELLOW);
	ft_printf("\n========== DATA INFO ==========\n");
	ft_printf("\n=== Window Info ===\n");
	ft_printf("Max Row: %d\n", data->max_row);
	ft_printf("Max Col: %d\n", data->max_col);
	ft_printf("MLX Pointer: %p\n", data->s_mlx.mlx);
	ft_printf("Window Pointer: %p\n", data->s_mlx.win);
	print_tex_info(data);
	ft_printf("==============================\n\n");
	ft_printf(RESET);
	print_map_info(data->map);
	ft_printf("%s==============================\n\n%s", YELLOW, RESET);
}
