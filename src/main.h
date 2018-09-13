/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:41:05 by dromanic          #+#    #+#             */
/*   Updated: 2018/09/13 20:31:53 by dromanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define DEF_OFFSET_Y 200
# define DEF_OFFSET_X 100
# define DEF_SCALE 1
# define WIN_NAME "FDF by dromanic (@Dentair)"
# define DEF_COLOR 0x0f9100FF
# define PI 3.14159265359
# define WIDTH_ERR_SKIP 0

# include <stdio.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <string.h>
# include <errno.h>

typedef struct	s_px
{
	float	x;
	float	y;
	float	z;
	float	z_orig;
	int		color;
}				t_px;

typedef struct	s_line
{
	int	color;
	int	end_x;
	int	end_y;
	int	len_y;
	int	len_x;
	int	len;
	int	dy;
	int	dx;
	int	d;
}				t_line;

typedef struct	s_param
{
	size_t	rows;
	size_t	cols;
	int		width;
	int		height;
	int		frame_cnt;
	int		offset_y;
	int		offset_x;
	int		sc_x;
	int		sc_y;
	int		sc_z;
	float	centr_x;
	float	centr_y;
}				t_param;

typedef struct	s_flags
{
	int		con_on;
	int		ver_on;
	int		sla_on;
	int		hor_on;
	int		bsl_on;
	int		fdf_on;
	int		dot_on;
	int		interface_on;
	int		error_code;
}				t_flags;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_win
{
	t_px	**map;
	t_param	*param;
	t_flags	*flags;
	t_img	*img;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_win;

enum			e_keys
{
	NUM_1 = 83, ONE = 18,
	NUM_2 = 84, TWO = 19,
	NUM_3 = 85, THREE = 20,
	NUM_4 = 86, FOUR = 21,
	NUM_5 = 87, FIVE = 23,
	NUM_6 = 88, SIX = 22,
	NUM_7 = 89, SEVEN = 26,
	NUM_8 = 91, EIGHT = 28,
	NUM_MINUS = 78, NINE = 25,
	NUM_PLUS = 69, ZERO = 29,
	Q = 12, W = 13, E = 14,
	A = 0, S = 1, D = 2,
	R = 15, ENTER = 36, ESC = 53,
	ARROW_UP = 126, ARROW_DOWN = 125,
	ARROW_LEFT = 123, ARROW_RIGHT = 124,
	MOUSE_SCROLL_UP = 4, MINUS = 27,
	MOUSE_SCROLL_DOWN = 5, PLUS = 24,
};

enum			e_errors
{
	MAP_INVALID = 404,
	WIDTH_ERR = 405,
	READ_ERR = 406,
	COLOR_ERR = 407,
	ITS_A_DIRECTORY = 21
};

t_line			*init_line(void);
t_win			*init_win(void);
t_img			*init_img(void *mlx_ptr, int width, int height);

int				is_valid_row(t_win *win, void *cont, size_t max_i);
t_win			*parse_map(char *file_name, t_win *win);
int				get_col(t_win *win, char *hex, size_t *i, size_t max_i);

void			draw_line(t_win *win, t_line *line, int x, int y);
void			draw_map(t_win *win);
void			draw_map_dots(t_win *win);

void			draw_map_vertical(t_win *win, t_param *p, int con);
void			draw_map_backslash(t_win *win, t_param *p, int con);
void			draw_map_horizontal(t_win *win, t_param *p, int con);
void			draw_map_slash(t_win *win, t_param *p, int con);
void			draw_map_fdf(t_win *win, t_param *p, int con);

int				deal_keyboard(int key, t_win *win);
int				deal_mouse(int key, int x, int y, t_win *win);
int				exit_x(t_win *par);

void			map_offset(t_win *win, int offset_x, int offset_y);
void			zoom_offset(t_win *win, int zoom_offset, int only_z);
void			toggles(t_win *win, int key);
void			animate(t_win *win);

void			show_interface(t_win *win);

int				toggle_param(int *param);
int				set_vec(t_win *win, long long x, long long y, long long z);
size_t			ft_cnt_words(char *str, size_t max_i, char ch);
void			redraw_img(t_win *win);

void			rotate_map(t_win *win, char axis, int new_angle);
void			reset(t_win *win);

void			free_map(t_win *win);
int				free_win(t_win *win);
t_win			*clear_img(t_win *win);

#endif
