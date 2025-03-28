/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:10:07 by maxweert          #+#    #+#             */
/*   Updated: 2025/03/28 20:58:37 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

// INIT

void	init_ray(t_data *data, t_raycasting *ray, int x);
int		init_img(t_mlx *s_mlx, t_img *s_img);

// DRAW

void	set_background(t_data *data);
int		draw_game(t_data *data);
void	draw_transparent_pixel(t_data *data, t_coord coord, int color,
			float alpha);

// RAYCASTING

int		raycasting(t_data *data);
void	dda(t_data *data, t_raycasting *ray);

// TEXTURE

void	compute_tex(t_data *data, t_raycasting *ray, int x);

// HUD

void	draw_fps(t_data *data);
void	set_cross(t_data *data);

// BACKGROUND

void	set_textured_background(t_data *data);
int		init_portal(t_data *data);
void	interact_portals(t_data *data);

// minimap
int		render_hud(t_data *data);
void	init_minimap(t_minimap *minimap);
void	draw_line(t_data *data, t_coord start, t_coord end, int color);

#endif
