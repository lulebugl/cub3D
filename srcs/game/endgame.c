/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:09:52 by maxweert          #+#    #+#             */
/*   Updated: 2025/03/30 20:09:55 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	interact_interruptor(t_data *data)
{
	int				curr_x;
	int				curr_y;
	t_raycasting	ray;

	if (data->game_end == LOOSE)
		return ;
	curr_x = (int)data->player.pos_x;
	curr_y = (int)data->player.pos_y;
	init_ray(data, &ray, WIDTH / 2);
	dda(data, &ray);
	if (abs(curr_x - ray.ray_x) <= 2 && abs(curr_y - ray.ray_y) <= 2)
	{
		if (data->map->matrix[ray.ray_y][ray.ray_x] == 2)
		{
			data->map->nb_cores--;
			data->map->matrix[ray.ray_y][ray.ray_x] = 3;
		}
	}
	if (data->map->nb_cores == 0)
		data->game_end = WIN;
}

void	render_mission_failed(t_data *data)
{
	int	x_pos;
	int	y_pos;
	int	y;
	int	x;
	int	color;

	x_pos = (WIDTH - data->tex[TEX_MISSION_FAILED]->width) / 2;
	y_pos = (HEIGHT - data->tex[TEX_MISSION_FAILED]->height) / 2;
	if (!data->started)
		draw_texture(data, data->tex[TEX_MISSION_FAILED],
			(t_coord){(double)(WIDTH - data->tex[TEX_MISSION_FAILED]->width)
			/ 2, (double)(HEIGHT - data->tex[TEX_MISSION_FAILED]->height) / 2},
			0);
}

void	render_mission_complete(t_data *data)
{
	int	x_pos;
	int	y_pos;
	int	y;
	int	x;
	int	color;

	x_pos = (WIDTH - data->tex[TEX_MISSION_FAILED]->width) / 2;
	y_pos = (HEIGHT - data->tex[TEX_MISSION_FAILED]->height) / 2;
	if (!data->started)
		draw_texture(data, data->tex[TEX_MISSION_FAILED],
			(t_coord){(double)(WIDTH - data->tex[TEX_MISSION_FAILED]->width)
			/ 2, (double)(HEIGHT - data->tex[TEX_MISSION_FAILED]->height) / 2},
			0);
}