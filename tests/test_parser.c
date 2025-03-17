/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebugle <llebugle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:30:15 by llebugle          #+#    #+#             */
/*   Updated: 2025/03/13 19:30:16 by llebugle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void data_init(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_with_error(NULL, data);
	errno = 0;
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		exit_with_error(NULL, data);
	ft_memset(data->map, 0, sizeof(t_map));
	data->map->ceiling_color = -1;
	data->map->floor_color = -1;
}

int main(int ac, char **argv)
{
	t_data data;
	(void)ac;
	
	data_init(&data);
	if (parse_arguments(&data, ac, argv))
		exit_with_error(NULL, &data);
	clean_up(&data);
	return (0);
}