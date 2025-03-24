/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:05:14 by llebugle          #+#    #+#             */
/*   Updated: 2025/03/24 01:15:15 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "key_linux.h"
# include "mlx.h"
# include "parser.h"
# include "structures.h"
# include "game.h"
# include "key_linux.h"
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Constants */
# define SUCCESS 0
# define ERROR 1
# define MSG_ERR_MALLOC "No space left on device.\n"
# define WIDTH 1920
# define HEIGHT 1080
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.02
<<<<<<< HEAD

/* Colors */
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define RESET "\033[0;37m"

void	exit_with_error(const char *msg, t_data *data);
void	clean_up(t_data *data);
void	data_init(t_data *data);

//	debug	//
void	print_data(t_data *data);

// error
void	print_err(char *msg);
void	free_matrix(int **matrix, int i);
void	print_matrix(int **matrix, int height, int width);


#endif
=======
>>>>>>> draw

