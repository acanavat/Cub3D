# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isibio <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 12:32:51 by isibio            #+#    #+#              #
#    Updated: 2024/03/08 12:32:52 by isibio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors and styles variables
	CLEAN	= \033[0m
	BOLD	= \033[1m
	CLEAR	= \r\033[K
	BLUE	= \033[38;5;27m
	YELLOW	= \033[38;5;226m
	GRAY	= \033[38;5;8m
	GREEN	= \033[38;5;46m
	ORANGE	= \033[38;5;214m
	WHITE	= \033[38;5;231m
	BK_		= \033[48;5;0m

# Global variables


	# Variables fron Shell command
	LIST_C_FILES_MANDATORY 	= $(shell ls -d1 srcs/mandatory/*/** | grep -F .c)
	LIST_C_FILES_BONUS 		= $(shell ls -d1 srcs/bonus/*/** | grep -F .c)
	TOTAL_C_FILES			= $(shell ls -d1 srcs/*/*/** | grep -F .c | wc -l)
	TOTAL_O_FILES			= $(shell ls -d1 srcs/*/*/** | grep -F .o | wc -l)
	TOTAL_BIN_FILES			= $(shell ls bin/ | wc -l)
	TOTAL_CLEAN_FILES_ECHO	= $(shell echo ${TOTAL_O_FILES})
	TOTAL_FCLEAN_FILES_ECHO	= $(shell echo ${TOTAL_O_FILES} + ${TOTAL_BIN_FILES})
	TOTAL_PERCENT_ECHO		= $(shell echo ${TOTAL_O_FILES} / ${TOTAL_C_FILES})
	# 'include' folder not included in calcul /!\
	TOTAL_NORM_ERR			= $(shell norminette srcs | grep -F "Error:" | wc -l)
	TOTAL_NORM_ERR_DOC		= $(shell norminette srcs | grep -F Error\! | wc -l)


	# Project variables
	PROJECT_NAME				=cub3d
	PROJECT_EXECUTABLE_NAME		=cub3D
	PROJECT_NAME_DISPLAY		=${CLEAN}${WHITE}[${ORANGE}${PROJECT_NAME}${WHITE}]${CLEAN}
	PROJECT_NAME_DISPLAY_UNDONE	=${CLEAN}${WHITE}[${BOLD}${GRAY}${TOTAL_PERCENT_ECHO} files${CLEAN}${WHITE}]${CLEAN}
	PROJECT_NAME_DISPLAY_DONE	=${CLEAN}${WHITE}[${ORANGE}${PROJECT_NAME}${WHITE}]${CLEAN}

NAME		=	bin/$(PROJECT_EXECUTABLE_NAME)
SRCS		=	srcs/mandatory/execution/cub3d_colors.c \
				srcs/mandatory/execution/cub3d_destroy.c \
				srcs/mandatory/execution/cub3d_execution.c \
				srcs/mandatory/execution/cub3d_execution_keys.c \
				srcs/mandatory/execution/cub3d_hook.c \
				srcs/mandatory/execution/cub3d_hook_pressed_key.c \
				srcs/mandatory/execution/cub3d_hook_released_key.c \
				srcs/mandatory/execution/cub3d_hook_single_pressed.c \
				srcs/mandatory/execution/cub3d_image_manip.c \
				srcs/mandatory/execution/cub3d_init.c \
				srcs/mandatory/execution/cub3d_menu_debug.c \
				srcs/mandatory/execution/cub3d_menu_debug_utils.c \
				srcs/mandatory/execution/cub3d_menu_key_debug.c \
				srcs/mandatory/execution/cub3d_pixel_manip.c \
				srcs/mandatory/execution/cub3d_player_dir_rotate.c \
				srcs/mandatory/execution/cub3d_player_dir_setters.c \
				srcs/mandatory/execution/cub3d_player_gravity.c \
				srcs/mandatory/execution/cub3d_player_pos_move.c \
				srcs/mandatory/execution/cub3d_player_pos_setters.c \
				srcs/mandatory/execution/cub3d_raycaster_dda.c \
				srcs/mandatory/execution/cub3d_render_background.c \
				srcs/mandatory/execution/cub3d_render_background_static.c \
				srcs/mandatory/execution/cub3d_render.c \
				srcs/mandatory/execution/cub3d_render_line.c \
				srcs/mandatory/execution/cub3d_render_line_static_draw.c \
				srcs/mandatory/execution/cub3d_render_line_static_getters.c \
				srcs/mandatory/execution/cub3d_utils_condition.c \
				srcs/mandatory/execution/cub3d_utils_misc.c \
				srcs/mandatory/execution/main.c \
				srcs/mandatory/parsing/colors1.c \
				srcs/mandatory/parsing/colors2.c \
				srcs/mandatory/parsing/map1.c \
				srcs/mandatory/parsing/map2.c \
				srcs/mandatory/parsing/misc.c \
				srcs/mandatory/parsing/parsing1.c \
				srcs/mandatory/parsing/parsing2.c \
				srcs/mandatory/parsing/texture.c \
				srcs/mandatory/parsing/utils.c

OBJS		=	${SRCS:.c=.o}

NAME_BONUS	=	bin/$(PROJECT_EXECUTABLE_NAME)
SRCS_BONUS	=	srcs/bonus/execution/cub3d_colors_bonus.c \
				srcs/bonus/execution/cub3d_destroy_bonus.c \
				srcs/bonus/execution/cub3d_execution_bonus.c \
				srcs/bonus/execution/cub3d_execution_keys_bonus.c \
				srcs/bonus/execution/cub3d_hook_bonus.c \
				srcs/bonus/execution/cub3d_hook_mouse_bonus.c \
				srcs/bonus/execution/cub3d_hook_pressed_key_bonus.c \
				srcs/bonus/execution/cub3d_hook_released_key_bonus.c \
				srcs/bonus/execution/cub3d_hook_single_pressed_bonus.c \
				srcs/bonus/execution/cub3d_image_manip_bonus.c \
				srcs/bonus/execution/cub3d_init_bonus.c \
				srcs/bonus/execution/cub3d_menu_debug_bonus.c \
				srcs/bonus/execution/cub3d_menu_debug_utils_bonus.c \
				srcs/bonus/execution/cub3d_menu_key_debug_bonus.c \
				srcs/bonus/execution/cub3d_minimap_bonus.c \
				srcs/bonus/execution/cub3d_pixel_manip_bonus.c \
				srcs/bonus/execution/cub3d_player_dir_rotate_bonus.c \
				srcs/bonus/execution/cub3d_player_dir_setters_bonus.c \
				srcs/bonus/execution/cub3d_player_gravity_bonus.c \
				srcs/bonus/execution/cub3d_player_interaction_bonus.c \
				srcs/bonus/execution/cub3d_player_pos_move_bonus.c \
				srcs/bonus/execution/cub3d_player_pos_setters_bonus.c \
				srcs/bonus/execution/cub3d_raycaster_dda_bonus.c \
				srcs/bonus/execution/cub3d_render_background_bonus.c \
				srcs/bonus/execution/cub3d_render_background_static_bonus.c \
				srcs/bonus/execution/cub3d_render_bonus.c \
				srcs/bonus/execution/cub3d_render_line_bonus.c \
				srcs/bonus/execution/cub3d_render_line_static_draw_bonus.c \
				srcs/bonus/execution/cub3d_render_line_static_getters_bonus.c \
				srcs/bonus/execution/cub3d_render_sprite_bonus.c \
				srcs/bonus/execution/cub3d_render_sprite_static_bonus.c \
				srcs/bonus/execution/cub3d_sprite_manip_bonus.c \
				srcs/bonus/execution/cub3d_utils_condition_bonus.c \
				srcs/bonus/execution/cub3d_utils_misc_bonus.c \
				srcs/bonus/execution/main_bonus.c \
				srcs/bonus/parsing/colors1_bonus.c \
				srcs/bonus/parsing/colors2_bonus.c \
				srcs/bonus/parsing/map1_bonus.c \
				srcs/bonus/parsing/map2_bonus.c \
				srcs/bonus/parsing/misc_bonus.c \
				srcs/bonus/parsing/parsing1_bonus.c \
				srcs/bonus/parsing/parsing2_bonus.c \
				srcs/bonus/parsing/texture_bonus.c \
				srcs/bonus/parsing/utils_bonus.c

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

GCC					=	cc
OPTIMIZATION_FLAGS	=	-Ofast -march=native -flto -fno-signed-zeros -fno-trapping-math -D_GLIBCXX_PARALLEL -funroll-loops
FLAGS				=	-Ilib/minilix-linux -Wall -Wextra -Werror -g -ferror-limit=256 ${OPTIMIZATION_FLAGS}

# Lib files
	LIB_LIBFT_DIR			= lib/libft/
	LIB_LIBFT_A_FILE		= lib/libft/bin/libft.a
	LIB_MLX_LINUX_DIR		= lib/minilibx-linux/
	LIB_MLX_LINUX_A_FILE	= lib/minilibx-linux/libmlx.a

# Variables modifications
	ifdef DEBUG
		FLAGS += -fsanitize=address -g
	endif

	ifdef BONUS
		SRCS = ${SRCS_BONUS}
		OBJS = ${OBJS_BONUS}
		NAME = ${NAME_BONUS}
	endif


all : ${NAME}
bonus :
	@${MAKE} BONUS=1

.c.o : 
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) $(CLEAN)${WHITE}Compiling >> %s ${CLEAN}" ${notdir $<}
	@${GCC} ${FLAGS} -c $< -o ${<:.c=.o}
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Compiling >> ${BOLD}${GREEN}%s  ✓ \n${CLEAN}" ${notdir $<}

# Lib compilation
${LIB_LIBFT_A_FILE} :
	@${MAKE} -C ${LIB_LIBFT_DIR}
${LIB_MLX_LINUX_A_FILE} :
	@${MAKE} -C ${LIB_MLX_LINUX_DIR}

${NAME}: ${LIB_LIBFT_A_FILE} ${LIB_MLX_LINUX_A_FILE} ${OBJS}
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) $(CLEAN)${WHITE}Compiling >> %s ${CLEAN}" ${notdir $<}
	@${GCC} ${FLAGS} ${OBJS} -Llib/minilibx-linux -lmlx -lXext -lX11 -lm -lz -o ${NAME} ${LIB_LIBFT_A_FILE}
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Compiling >> ${BOLD}${GREEN}%s  ✓ \n${CLEAN}" ${notdir $<}

clean :
	@${MAKE} clean -C ${LIB_LIBFT_DIR} ${LIB_MLX_LINUX_DIR}
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) ${RED}${BOLD}${GRAY}cleaning ${TOTAL_CLEAN_FILES_ECHO} files ${CLEAN}"
	@rm -f ${OBJS}
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Cleaning : ${BOLD}${GREEN}deleted ${TOTAL_CLEAN_FILES_ECHO} files ✓\n${CLEAN}"

fclean :
	@${MAKE} fclean -C ${LIB_LIBFT_DIR}
	@${MAKE} clean -C ${LIB_MLX_LINUX_DIR}
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) ${RED}${BOLD}${GRAY}cleaning ${TOTAL_FCLEAN_FILES_ECHO} files ${CLEAN}"
	@rm -f ${OBJS}
	@rm -f ${NAME}
	@rm -f ${OBJS_BONUS}
	@rm -f ${NAME_BONUS}
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Cleaning : ${BOLD}${GREEN}deleted ${TOTAL_FCLEAN_FILES_ECHO} files ✓\n${CLEAN}"

re : fclean all

debug:
	@make DEBUG=1 re


# norm only the srcs
norm :
	@printf "${WHITE}>>> ${ORANGE}${TOTAL_NORM_ERR} ${WHITE}norm error(s) \n>>> ${ORANGE}${TOTAL_NORM_ERR_DOC} ${WHITE}documemts with norm errors\n"

git : fclean norm rmds
	@printf "\n"
	@git status

#- old or broken -#

# gitallb : fclean norm rmds
# 	@vi branch
# 	@printf "${WHITE}\n"
# 	@git status
# 	@printf "${WHITE}\n"
# 	@git add .
# 	@printf "${WHITE}\n"
# 	@git commit .
# 	@printf "${WHITE}\n"
# 	@git push origin $(cat branch)
# 	@printf "\n"
# 	@rm -rf branch

# gitall : fclean norm rmds
# 	@printf "${WHITE}\n"
# 	@git status
# 	@printf "${WHITE}\n"
# 	@git add .
# 	@printf "${WHITE}\n"
# 	@git commit .
# 	@printf "${WHITE}\n"
# 	@git push origin master
# 	@printf "\n"

.PHONY : all clean fclean re