/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:55:58 by llebugle          #+#    #+#             */
/*   Updated: 2025/03/14 17:55:59 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_map_info(t_map *map)
{
	ft_printf(BLUE);
	ft_printf("\n=== Map Info ===\n");
	ft_printf("Map width: %d\n", map->width);
	ft_printf("Map height: %d\n", map->height);
	// ft_printf("\n=============Matrix==========\n\n");
	// print_matrix(data->map->matrix, data);
	ft_printf(RESET);
}

void	print_tex_info(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEX_COUNT)
	{
		if (data->textures[i])
		{
			if (data->textures[i]->data)
				ft_printf("Tex[%d] -> size[%d:%d]\n", i, data->textures[i]->width, data->textures[i]->height);
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
	ft_printf("MLX Pointer: %p\n", data->mlx);
	ft_printf("Window Pointer: %p\n", data->win);
	print_tex_info(data);
	ft_printf("==============================\n\n");
	ft_printf(RESET);
	
	if (data->map)
		print_map_info(data->map);
	
	ft_printf("%s==============================\n\n%s", YELLOW, RESET);
	
}