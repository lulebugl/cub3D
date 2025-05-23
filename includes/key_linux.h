/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_linux.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxweert <maxweert@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:58:07 by maxweert          #+#    #+#             */
/*   Updated: 2025/03/29 21:58:08 by maxweert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_LINUX_H
# define KEY_LINUX_H

/*
** Keyboard LETTERS
*/

# ifdef __APPLE__
/* macOS key codes */
#  define K_ESC 53
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define K_AR_L 123
#  define K_AR_R 124
#  define K_SHIFT 56
#  define K_M 46
#  define K_E 14
#  define K_TAB 48
# else
/* Linux key codes */
#  define K_W 119
#  define K_TAB 65289
#  define K_A 97
#  define K_S 115
#  define K_E 101
#  define K_M 109
#  define K_D 100
#  define K_AR_L 65361
#  define K_AR_R 65363
#  define K_SHIFT 65505
#  define K_ESC 65307

# endif

# define K_B 98
# define K_C 99
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_T 116
# define K_U 117
# define K_V 118
# define K_X 120
# define K_Y 121
# define K_Z 122

/*
** Keyboard ARROWS
*/

# define K_AR_U 65362
# define K_AR_D 65364

/*
** Keyboard NUMPAD
*/

# define K_NP_DIV 65455
# define K_NP_MUL 65450
# define K_NP_MIN 65453
# define K_NP_PLU 65451

/*
** Keyboard MISC
*/

# define K_SP 32

/*
** Mouse
*/

# define M_CLK_L 1
# define M_CLK_R 3
# define M_CLK_M 2
# define M_SCR_U 4
# define M_SCR_D 5

#endif
