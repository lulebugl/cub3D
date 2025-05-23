/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:51:24 by maxweert          #+#    #+#             */
/*   Updated: 2025/03/29 20:14:39 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

//	DEBUG

void			print_data(t_data *data);
void			print_matrix(int **matrix, int height, int width);

// ERROR

void			print_err(char *msg);
void			exit_with_error(const char *msg, t_data *data);

// CLEAN

void			clean_up(t_data *data);
void			free_matrix(int **matrix, int i);

// UTILS

int				get_current_time(void);
void			count_fps(t_data *data);
int				ft_usleep(size_t ms);
int				is_portal(t_data *data, int x, int y, int portal_i);
unsigned char	*get_texture_pixel(t_texture *tex, int x, int y);

#endif