/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:38:02 by maxweert          #+#    #+#             */
/*   Updated: 2025/03/28 20:44:02 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move_forward(t_data *data)
{
	double	step_x;
	double	step_y;
	double	tmp;

	if (data->player.mv_forward != 0)
	{
		step_x = data->player.dir_x * MOVE_SPEED * data->player.run
			* data->player.mv_forward;
		step_y = data->player.dir_y * MOVE_SPEED * data->player.run
			* data->player.mv_forward;
		tmp = data->player.pos_x + step_x;
		if (tmp > 1.0 && tmp < data->map->width - 1)
			if (data->map->matrix[(int)data->player.pos_y][(int)tmp] <= 0)
				data->player.pos_x += step_x;
		tmp = data->player.pos_y + step_y;
		if (tmp > 1.0 && tmp < data->map->height - 1)
			if (data->map->matrix[(int)tmp][(int)data->player.pos_x] <= 0)
				data->player.pos_y += step_y;
	}
}

static void	move_lateral(t_data *data)
{
	double	step_x;
	double	step_y;
	double	tmp;

	if (data->player.mv_lateral != 0)
	{
		step_x = data->player.plane_x * MOVE_SPEED * data->player.run
			* data->player.mv_lateral;
		step_y = data->player.plane_y * MOVE_SPEED * data->player.run
			* data->player.mv_lateral;
		tmp = data->player.pos_x + step_x;
		if (tmp > 1.0 && tmp < data->map->width - 1)
			if (data->map->matrix[(int)data->player.pos_y][(int)tmp] <= 0)
				data->player.pos_x += step_x;
		tmp = data->player.pos_y + step_y;
		if (tmp > 1.0 && tmp < data->map->width - 1)
			if (data->map->matrix[(int)tmp][(int)(data->player.pos_x)] <= 0)
				data->player.pos_y += step_y;
	}
}

static void	move_rotate(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	if (data->player.mv_rotate != 0)
	{
		rot = ROT_SPEED * data->player.mv_rotate;
		old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(rot) - data->player.dir_y
			* sin(rot);
		data->player.dir_y = old_dir_x * sin(rot) + data->player.dir_y
			* cos(rot);
		old_plane_x = data->player.plane_y;
		data->player.plane_y = data->player.plane_y * cos(-rot)
			- data->player.plane_x * sin(-rot);
		data->player.plane_x = old_plane_x * sin(-rot) + data->player.plane_x
			* cos(-rot);
	}
}

void	compute_player_pos(t_data *data)
{
	double	old_x;
	double	old_y;

	old_x = data->player.pos_x;
	old_y = data->player.pos_y;
	move_forward(data);
	move_lateral(data);
	move_rotate(data);
	if (data->map->matrix[(int)data->player.pos_y][(int)data->player.pos_x] ==
		-2)
		teleport(data, old_x, old_y);
}

void	rotate_mouse(t_data *data, int mouse_x)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;

	rot = ((double)mouse_x - (double)WIDTH / 2) * MOUSE_SENSIBILITY;
	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rot) - data->player.dir_y
		* sin(rot);
	data->player.dir_y = old_dir_x * sin(rot) + data->player.dir_y * cos(rot);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot)
		- data->player.plane_y * sin(rot);
	data->player.plane_y = old_plane_x * sin(rot) + data->player.plane_y
		* cos(rot);
}
