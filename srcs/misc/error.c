/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:21:13 by llebugle          #+#    #+#             */
/*   Updated: 2025/03/24 23:39:52 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_matrix(int **matrix, int i)
{
	if (!matrix || !*matrix)
		return ;
	if (!i)
	{
		free(matrix);
		return ;
	}
	while (i--)
		if (matrix[i])
			free(matrix[i]);
	free(matrix);
}

void	cleanup_map(t_map *map)
{
	free_matrix(map->matrix, map->height);
	free(map);
}

void	cleanup_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEX_COUNT)
	{
		if (data->tex[i])
		{
			if (data->tex[i]->data)
				free(data->tex[i]->data);
			free(data->tex[i]);
			data->tex[i] = NULL;
		}
	}
}

void	clean_up(t_data *data)
{
	if (!data)
		return ;
	if (data->s_mlx.win && data->img.img)
		mlx_destroy_window(data->s_mlx.mlx, data->s_mlx.win);
	if (data->s_mlx.win)
		mlx_destroy_image(data->s_mlx.mlx, data->img.img);
	cleanup_textures(data);
	cleanup_map(data->map);
	mlx_destroy_display(data->s_mlx.mlx);
	free(data->s_mlx.mlx);
}

void print_err(char *msg)
{
	ft_printf_fd(STDERR_FILENO, YELLOW);
	ft_printf_fd(STDERR_FILENO, "Error\n");
	if (errno == ENOMEM)
		perror(strerror(errno));
	else if (msg)
		ft_printf_fd(2, "%s", msg, RESET);
	ft_printf_fd(2, RESET);
}

void	exit_with_error(const char *msg, t_data *data)
{
	ft_printf_fd(2, YELLOW);
	ft_printf_fd(2, "Error\n");
	if (errno == ENOMEM)
		perror(strerror(errno));
	else if (msg)
		ft_printf_fd(2, "%s", msg, RESET);
	ft_printf_fd(2, RESET);
	clean_up(data);
	exit(EXIT_FAILURE);
}
