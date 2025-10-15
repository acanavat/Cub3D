/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isibio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:31:10 by isibio            #+#    #+#             */
/*   Updated: 2024/04/11 18:38:39 by acanavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>          
# include <stdlib.h>
# include <math.h>

# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/minilibx-linux/mlx_int.h"

# define MAP_WALL				'1'
# define MAP_EMPTY				'0'
# define MAP_PLAYER_NORTH		'N'
# define MAP_PLAYER_SOUTH		'S'
# define MAP_PLAYER_WEST		'W'
# define MAP_PLAYER_EAST		'E'
# define MAP_DOOR_OPEN			'+'
# define MAP_DOOR_CLOSED		'-'
# define MAP_VOID				'x'
# define MAP_TEXTURE_NORTH		"NO"
# define MAP_TEXTURE_SOUTH		"SO"
# define MAP_TEXTURE_WEST		"WE"
# define MAP_TEXTURE_EAST		"EA"
# define MAP_COLOUR_FLOOR		"F"
# define MAP_COLOUR_CEILING		"C"

# define KEY_EXIT				65307
# define KEY_CROSSAIR			65471

# define KEY_RENDER_WALLS		65474
# define KEY_RENDER_BACKGROUND	65475
# define KEY_RENDER_SPRITES		65476

# define KEY_DEBUG				65472
# define KEY_KEY_DEBUG			65473
# define KEY_SPRINT				65509
# define KEY_SNEAK				65505
# define KEY_RESPAWN			114
# define KEY_MOVE_FORWARD		119
# define KEY_MOVE_BACKWARD		115
# define KEY_MOVE_LEFT			97
# define KEY_MOVE_RIGHT			100
# define KEY_ROTATE_LEFT		65361
# define KEY_ROTATE_RIGHT		65363
# define KEY_ROTATE_UP			105
# define KEY_ROTATE_DOWN		111
# define KEY_INTERACT			102
# define KEY_PAUSE				116
# define KEY_JUMP				32

# define DEFAULT_TEXTURE_WIDTH		64
# define DEFAULT_TEXTURE_HEIGHT		64
# define DEFAULT_WINDOW_WIDTH		1280
# define DEFAULT_WINDOW_HEIGHT		720
# define DEFAULT_WINDOW_TITLE		"g envie de crever"
# define DEFAULT_PLAYER_MOVE_SPEED	0.085
# define DEFAULT_PLAYER_ROT_SPEED	0.04
# define DEFAULT_PLAYER_MOUSE_SPEED	0.0012

// * s_image struct :
// * 	brightness -> could be better with a multipiclator
// * 		(loop the brightness x times to get a darker texture)
typedef struct s_image
{
	unsigned int	brightness;
	unsigned int	image_width;
	unsigned int	image_height;
	void			*mlx_instance;
	void			*mlx_window;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_image;

// * s_sprite struct :
// *	animation_speed -> nb frames between each animation step
// * 	pos_z -> isn't used in any calculs, this vriable can be removed
// * 
// * 	can be more permissive if position of the sprite is stored in an
// * 	array, so we can use a sprite at multiple positions
typedef struct s_sprite
{
	unsigned long long	frame;
	t_image				*image;
	int					animation_step;
	int					animation_speed;
	int					animation_frames;

	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				u_div;
	double				v_div;
	double				v_move;
}	t_sprite;

typedef struct s_map
{
	char	**tab_map;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
////////////////
	int		stop;	//quand on rentre dans map par le bas
	int		last_line; //position de la derniere ligne de map
	int		first_line;
	int		line_size;
	int		player_y;
	int		player_x;
	char	player_dir;
///////////////	
	char	*ceiling_path;
	char	*floor_path;
	int		floor;
	int		ceiling;
}	t_map;

// * player struct
// * 	-> gravity_phase : [-1:fall | 0:ground | 1:jump]
// * 	-> range : used to define min distance to interact with environment
typedef struct s_player
{
	double	default_pos_x;
	double	default_pos_y;
	double	default_pos_z;
	double	default_dir_x;
	double	default_dir_y;
	double	default_pitch;
	double	default_plane_x;
	double	default_plane_y;
	double	default_rot_speed;
	double	default_move_speed;
	double	default_mouse_speed;

	int		gravity_phase;

	double	pos_x;
	double	pos_y;
	double	pos_z;
	double	dir_x;
	double	dir_y;
	double	pitch;
	double	plane_x;
	double	plane_y;

	double	rot_speed;
	double	move_speed;
	double	mouse_speed;

	double	range;
	char	pointed_wall_dir;
	char	pointed_wall_id;
	double	pointed_wall_dist;
	int		pointed_map_x;
	int		pointed_map_y;

	int		crossair_x;
}	t_player;

typedef struct s_key
{
	char	rotate_up;
	char	rotate_down;
	char	rotate_left;
	char	rotate_right;
	char	move_forward;
	char	move_backward;
	char	move_left;
	char	move_right;
	char	respawn;
	char	sprint;
	char	sneak;
	char	jump;
	char	exit;
}	t_key;

typedef struct s_raycasting
{
	double			*z_buffer;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				textured_ceiling;
	int				textured_floor;
	int				line_length;
	int				draw_start;
	int				line_end;
}	t_raycasting;

typedef struct s_data
{
	int				fd;

	char			toggle_debug_menu;
	char			toggle_key_debug_menu;
	char			toggle_pause;
	char			toggle_render_walls;
	char			toggle_render_background;
	char			toggle_render_crossair;
	char			toggle_render_sprites;
	int				last_pressed_key;
	int				last_released_key;

	t_image			door_open;
	t_image			door_closed;
	t_image			wall_north;
	t_image			wall_south;
	t_image			wall_west;
	t_image			wall_east;
	t_image			ceiling_texture;
	unsigned int	ceiling_color;
	t_image			floor_texture;
	unsigned int	floor_color;

	t_image			render;
	char			*window_title;

	t_sprite		*sprite;

	t_map			map;
	t_key			key;
	t_player		player;
	t_raycasting	raycasting;
}	t_data;

// * Parsing
void		parse(int argc, char **argv);
char		**create_map(char *path_to_map, t_data *data);
void		free_tab_tab(char **str);
int			parameter_in_file(char **str_file, t_data *data, int x, int y);
int			skip_space_tab(char *str, int y);
void		exit_close(int fd, char *str);
void		free_exit(char **str, char **map, char *error_msg);
void		exit_for_texture(char **str, char *path, int fd);
int			is_texture(char *str, int y);
void		path_texture(t_data *data, char **str, int x, int y);
void		open_texture(char **str, char *path, int fd);
void		stock_texture(char *str, char *path, t_data *data);
int			color_path(t_data *data, char *str);
void		ft_color(t_data *data, char **str, int x, int y);
int			parse_color(char *str, int x);
int			exit_floor_ceilling(char *str_file, int y);
void		stock_trgb(t_data *data, char str, char **rgb);
int			skip(char *str, int x);
void		copy(t_data *data, char *str, char c, int x);
int			parse_floor_ceilling(char *str_file, int y, int z);
char		**ret_str(char *str_file);
char		*ret(char *str_file, int c, int z);
int			last_wall(char *map);
void		parse_map_2(t_data *data, char **str, int x, int y);
int			extremity(char *map);
void		parse_map_1(t_data *data, char **str, int x, int y);
char		**ft_map(t_data *data, char **str, int y);
char		**creation_map(t_data *data, char **str, int x, int y);
void		parse_map_3(char **str, char **map, int x, int y);
void		pos_player(t_data *data, char **str, int x, int y);
void		line_size(char **str, t_data *data);
char		**empty_case(t_data *data, char **map, int z, int y);
int			line_too_long(t_data *data);
void		copy(t_data *data, char *str, char c, int x);
int			check(char map);

// cub3d_raycaster_dda.c
void		dda_init(t_data *data, int x);
void		dda_perform(t_data *data, int x);

// cub3d_utils_condition.c
int			is_foreground_object(char c);
int			is_invalid_printable_map_char(char c);
int			is_door(char c);
int			is_solid_wall(char c);

// cub3d_pixel_manip.c
int			pixel_get(t_image image, int x, int y);
void		pixel_put(t_image image, int x, int y, int color);
void		draw_square(t_image image, int x, int y, int color);

// cub3d_minimap.c
void		get_minimap(t_image render, char **map,
				double player_x, double player_y);

// cub3d_image_manip.c
t_image		open_image(void *mlx_instance, char *path, int width, int height);
int			get_image_color(t_image image, void *mlx_instance,
				unsigned int x, unsigned int y);
t_image		*clone_image_arr(t_image *array, int nb_images, int malloc_size);
void		get_image_resolution(int *width, int *height, t_image image);

// cub3d_player_pos_setters.c
void		set_player_position(t_player *player, double x, double y, double z);
void		set_default_player_direction(t_player *player, char direction);
void		reset_player_to_default(t_player *player);
void		respawn(t_data *data);

// cub3d_player_dir_setters.c
void		set_player_direction(t_player *player, char direction);
void		set_default_player_position(t_player *player,
				double x, double y, double z);

// cub3d_player_pos_move.c
void		move_forward(t_data *data);
void		move_backward(t_data *data);
void		move_right(t_data *data);
void		move_left(t_data *data);

// cub3d_player_dir_rotate.c
void		rotate_right(t_data *data, double rot_speed);
void		rotate_left(t_data *data, double rot_speed);

// cub3d_player_gravity.c
void		jump(t_player *player, double jump_height,
				double jump_speed, double speed_boost);
void		handle_gravity(t_player *player,
				double origin_z, double fall_speed);

// cub3d_render_line.c
void		render_line(t_data *data, int x);

// cub3d_render_background.c
void		render_background(t_data *data);

// cub3d_render_sprite.c
void		render_sprite(t_data *data, t_sprite *sprite);

// cub3d_menu_debug.c
void		print_debug_menu(t_data *data);

// cub3d_menu_debug_utils.c
void		string_put_free(t_data *data, int x, int y, char *message);

// cub3d_menu_key_debug.c
void		print_debug_key_menu(t_data *data);

// cub3d_player_interaction.c
void		interact(t_player *player, char **map);
void		interact_with_doors(t_player *player, char **map);

// cub3d_sprite_manip.c
t_sprite	*new_sprite(double pos_x, double pos_y,
				double pos_z, int animation_speed);
void		destroy_sprite(t_sprite *sprite, void *mlx_instance);
void		set_sprite_position(t_sprite *sprite,
				double x, double y, double z);
void		set_sprite_size(t_sprite *sprite, double width, double height);
void		add_sprite_frame(t_sprite *sprite, t_image new_frame);

// cub3d_utils_misc.c
double		ft_dabs(double x);
void		toggle(char *var);
int			is_xpm_extension(char *filename);

// cub3d_render.c
void		print_render(t_data *data);
void		set_background_renderer(t_raycasting *raycasting,
				int ceiling, int floor);

// cub3d_hook_single.c
int			single_pressed_key_hook(int keycode, t_data *data);

// cub3d_hook_mouse.c
int			mouse_hook(void *mlx_instance, void *mlx_window, t_data *data);

// cub3d_execute_keys.c
void		execute_keys(t_data *data);

// cub3d_hook_released_key.c
int			released_key_hook(int keycode, t_data *data);

// cub3d_hook_pressed_key.c
int			pressed_key_hook(int keycode, t_data *data);

// cub3d_hook.c
void		hooks_init(void *mlx_instance, void *mlx_window, t_data *data);

// cub3d_init.c
t_data		*data_init(char **argv);
void		reset_keys(t_key *key);
void		reset_debug_functions(t_data *data);

// cub3d_destroy.c
void		program_end(t_data *data);

// * cub3d_colors.c
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

// * cub3d_execution.c
void		exec(t_data *data);

// * ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣦⣾⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣿⡇⠀⠈⠛⠛⠻⠷⠶⠶⣶⣦⣤⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⡿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠙⠻⠷⣶⣤⣤⣴⣶⢾⣏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣯⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠹⠿⠀⠀⠘⢿⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⣠⣶⣦⣀⠀⠀⣠⣾⠏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢼⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⢰⣿⡛⠛⠛⠻⣿⡏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⢸⡇⠀⠀⠀⠀⠘⠃⠀⠀⠀⢰⣿⣿⡆⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣴⣶⢶⣦⣤⡀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⢸⣷⠂⠀⠀⠀⠀⠀⠀⠀⠀⠈⠛⠛⠉⠻⠿⢿⣧⣴⣶⠀⠀⠀⣴⣶⣤⣿⠋⠀⠀⠈⠙⢿⣶⡄⢀⣼⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⢀⣿⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠀⠀⠀⠀⠻⠿⠇⣿⠀⠀⠀⠀⠀⠀⢿⡇⠀⠘⣿⣧⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠈⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣤⠀⠀⠀⠀⠀⠈⠉⠀⠀⠸⣿⡆⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠛⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⡄⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⢰⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣧⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠸⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣹⡏⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⡄⠀⠀⠀⠀
// * ⠀⠀⠀⠀⢠⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡟⠁⠀⠀⠀⠀
// * ⠀⢀⣠⣴⡿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⠋⠀⣀⣤⣤⣶
// * ⠀⣼⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣶⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣶⣿⠿⣿⣿⣿
// * ⢐⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠋⠀⣴⣿⠟⢻
// * ⠀⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡿⢃⣰⣿⠟⠁⠀⠀
// * ⠀⠈⠻⣶⣦⣤⣴⣾⣷⣶⣤⣤⣄⣀⣀⣀⠀⠀⠀⠀⠀⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⣿⢿⠟⠋⠁⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠙⠛⠛⠛⢿⣿⠟⠛⠿⣷⣦⣴⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀
// * ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

#endif // CUB3D_BONUS_H
