/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:50:47 by maxweert          #+#    #+#             */
/*   Updated: 2025/03/24 01:16:36 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	leave(t_data *data)
{
	(void)data;
	exit(0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		leave(data);
	if (keycode == K_W)
		data->player.mv_forward += 1;
	if (keycode == K_S)
		data->player.mv_forward += -1;
	if (keycode == K_A)
		data->player.mv_lateral += -1;
	if (keycode == K_D)
		data->player.mv_lateral += 1;
	if (keycode == K_AR_L)
		data->player.mv_rotate += -1;
	if (keycode == K_AR_R)
		data->player.mv_rotate += 1;
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == K_W)
		data->player.mv_forward += -1;
	if (keycode == K_S)
		data->player.mv_forward += 1;
	if (keycode == K_A)
		data->player.mv_lateral += 1;
	if (keycode == K_D)
		data->player.mv_lateral += -1;
	if (keycode == K_AR_L)
		data->player.mv_rotate += 1;
	if (keycode == K_AR_R)
		data->player.mv_rotate += -1;
	return (0);
}

int	mouse_handler(int x, int y, t_data *data)
{
	static int	old_x = WIDTH / 2;

	(void)y;
	if (x == old_x)
		return (0);
	else if (x < old_x)
		rotate_mouse(data, -1);
	else if (x > old_x)
		rotate_mouse(data, 1);
	old_x = x;
	return (0);
}
