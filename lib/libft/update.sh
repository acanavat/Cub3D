# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    update.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 14:44:12 by isibio            #+#    #+#              #
#    Updated: 2023/06/27 16:46:54 by isibio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Style and colors
	CLEAN="\033[0m"
	BOLD="\033[1m"
	CLEAR="\r\033[K"
	ITALIC="\e[3m"
	BLUE="\033[38;5;27m"
	GITHUB_OUTPUTS="${ITALIC}\033[38;5;209m"
	YELLOW="\033[38;5;226m"
	GRAY="\033[38;5;8m"
	GREEN="\033[38;5;46m"
	ORANGE="\033[38;5;214m"
	WHITE="\033[38;5;231m"
	RED="\033[38;5;9m"

# Global Variables
	PROJECT_NAME=$(cat config | grep PROJECT_NAME | awk '{print $2 $3 $4 $5}')
	PROJECT_VERSION=$(cat config | grep VERSION | awk '{print $2}')
	PROJECT_NAME_DISPLAY="${CLEAN}${WHITE}[${ORANGE}${PROJECT_NAME} v${PROJECT_VERSION}${WHITE}]${CLEAN}"
	PROJECT_NAME_DISPLAY_UNDONE="${CLEAN}${GRAY}[${ORANGE}${PROJECT_NAME}${WHITE}]${CLEAN}"
	PROJECT_NAME_DISPLAY_DONE="${CLEAN}${WHITE}[${ORANGE}${PROJECT_NAME}${WHITE}]${CLEAN}"

# WELCOME
	printf "${CLEAN}${BOLD}${WHITE}[${RED}WARNING${WHITE}] ${RED}THIS REPO IS NOT SUPPOSED TO BE MODIFIED !!!\n${GRAY}"
	printf "creating ghub dir\n"
	mkdir ghub
	printf "creating bin dir\n"
	mkdir bin

#	---------------------------------- LIBFT ---------------------------------------------------
	# libft variables
	libft_github="git@github.com:isibio/libft.libft.git"
	libft_github_branch="master"
	libft_display="libft"
	libft_path="./ghub/libft"
	libft_path_clone_srcs="./srcs/libft"
	libft_path_clone_includes="./includes"

	printf "\n${PROJECT_NAME_DISPLAY} ${WHITE}${BOLD}Clone ${YELLOW}${libft_display} ${CLEAN}${WHITE} >> \n\tlink : ${CLEAN}${ORANGE}${libft_github}${CLEAN} \n\t${WHITE}dir  : ${CLEAN}${ORANGE}${libft_path}${CLEAN} \n\n${CLEAN}${GITHUB_OUTPUTS}"

	# remove old clones if exists or remove old ft_libft files
	rm -rf ${libft_path}
	rm -rf ${libft_path_clone_srcs}/ft_libft*.c
	rm -rf ${libft_path_clone_includes}/libft*.h
	mkdir ${libft_path}
	mkdir ${libft_path_clone_srcs}
	mkdir ${libft_path_clone_includes}

	# git clone from ${libft_github} (branch ${libft_github_branch}) to ${libft_path}
	git clone --branch ${libft_github_branch} 	${libft_github} ${libft_path}

	# files to copy (ft_libft*.c)
	#  from ${libft_path}/srcs/ -> ${libft_path_clone_srcs}
	cp ${libft_path}/srcs/libft/ft_libft*.c 	${libft_path_clone_srcs}

	# files to copy (*.h) 
	#  from ${libft_path}/includes/ -> ${libft_path_clone_includes}
	cp ${libft_path}/includes/libft*.h 			${libft_path_clone_includes}

#	---------------------------------- FT_PRINTF -----------------------------------------------
	# printf variables
	ft_printf_github="git@github.com:isibio/libft.ft_printf.git"
	ft_printf_github_branch="master"
	ft_printf_display="ft_printf"
	ft_printf_path="./ghub/ft_printf"
	ft_printf_path_clone_srcs="./srcs/ft_printf"
	ft_printf_path_clone_includes="./includes"

	printf "\n${PROJECT_NAME_DISPLAY} ${WHITE}${BOLD}Clone ${YELLOW}${ft_printf_display} ${CLEAN}${WHITE} >> \n\tlink : ${CLEAN}${ORANGE}${ft_printf_github}${CLEAN} \n\t${WHITE}dir  : ${CLEAN}${ORANGE}${ft_printf_path}${CLEAN} \n\n${CLEAN}${GITHUB_OUTPUTS}"

	# remove old clones if exists or remove old ft_printf files
	rm -rf ${ft_printf_path}
	rm -rf ${ft_printf_path_clone_srcs}/ft_printf*.c
	rm -rf ${ft_printf_path_clone_includes}/ft_printf*.h
	mkdir ${ft_printf_path}
	mkdir ${ft_printf_path_clone_srcs}
	mkdir ${ft_printf_path_clone_includes}

	# git clone from ${ft_printf_github} (branch ${ft_printf_github_branch}) to ${ft_printf_path}
	git clone --branch ${ft_printf_github_branch} ${ft_printf_github} ${ft_printf_path}

	# files to copy (ft_printf*.c)
	#  from ${ft_printf_path}/srcs/ -> ${ft_printf_path_clone_srcs}
	cp ${ft_printf_path}/srcs/ft_printf/ft_printf*.c 	${ft_printf_path_clone_srcs}

	# files to copy (*.h) 
	#  from ${ft_printf_path}/includes/ -> ${ft_printf_path_clone_includes}
	cp ${ft_printf_path}/includes/ft_printf.h 	${ft_printf_path_clone_includes}

#	---------------------------------- GET_NEXT_LINE (=gnl) ------------------------------------
	# gnl variables
	gnl_github="git@github.com:isibio/libft.get_next_line.git"
	gnl_github_branch="master"
	gnl_display="get_next_line"
	gnl_path="./ghub/get_next_line"
	gnl_path_clone_srcs="./srcs/get_next_line"
	gnl_path_clone_includes="./includes"

	printf "\n${PROJECT_NAME_DISPLAY} ${WHITE}${BOLD}Clone ${YELLOW}${gnl_display} ${CLEAN}${WHITE} >> \n\tlink : ${CLEAN}${ORANGE}${gnl_github}${CLEAN} \n\t${WHITE}dir  : ${CLEAN}${ORANGE}${gnl_path}${CLEAN} \n\n${CLEAN}${GITHUB_OUTPUTS}"


	# remove old clones if exists
	rm -rf ${gnl_path}
	rm -rf ${gnl_path_clone_srcs}/get_next_line*.c
	rm -rf ${gnl_path_clone_includes}/get_next_line*.h
	mkdir ${gnl_path}
	mkdir ${gnl_path_clone_srcs}
	mkdir ${gnl_path_clone_includes}

	# git clone from ${get_next_line_github} (branch ${get_next_line_github_branch}) to ${get_next_line_path}
	git clone --branch ${gnl_github_branch} ${gnl_github} ${gnl_path}

	# files to copy (get_next_line*.c)
	#  from ${get_next_line_path}/srcs/ -> ${get_next_line_path_clone_srcs}
	cp ${gnl_path}/srcs/get_next_line/get_next_line*.c 	${gnl_path_clone_srcs}

	# files to copy (*.h) 
	#  from ${get_next_line_path}/includes/ -> ${get_next_line_path_clone_includes}
	cp ${gnl_path}/includes/get_next_line.h 	${gnl_path_clone_includes}

#	---------------------------------- FT_FPRINTF ------------------------------------
	# ft_fprintf variables
	ft_fprintf_github="git@github.com:isibio/libft.ft_fprintf.git"
	ft_fprintf_github_branch="master"
	ft_fprintf_display="ft_fprintf"
	ft_fprintf_path="./ghub/ft_fprintf"
	ft_fprintf_path_clone_srcs="./srcs/ft_fprintf"
	ft_fprintf_path_clone_includes="./includes"

	printf "\n${PROJECT_NAME_DISPLAY} ${WHITE}${BOLD}Clone ${YELLOW}${ft_fprintf_display} ${CLEAN}${WHITE} >> \n\tlink : ${CLEAN}${ORANGE}${ft_fprintf_github}${CLEAN} \n\t${WHITE}dir  : ${CLEAN}${ORANGE}${ft_fprintf_path}${CLEAN} \n\n${CLEAN}${GITHUB_OUTPUTS}"


	# remove old clones if exists
	rm -rf ${ft_fprintf_path}
	rm -rf ${ft_fprintf_path_clone_srcs}/ft_fprintf*.c
	rm -rf ${ft_fprintf_path_clone_includes}/ft_fprintf*.h
	mkdir ${ft_fprintf_path}
	mkdir ${ft_fprintf_path_clone_srcs}
	mkdir ${ft_fprintf_path_clone_includes}

	# git clone from ${get_next_line_github} (branch ${get_next_line_github_branch}) to ${get_next_line_path}
	git clone --branch ${ft_fprintf_github_branch} ${ft_fprintf_github} ${ft_fprintf_path}

	# files to copy (get_next_line*.c)
	#  from ${get_next_line_path}/srcs/ -> ${get_next_line_path_clone_srcs}
	cp ${ft_fprintf_path}/srcs/ft_fprintf/ft_fprintf*.c 	${ft_fprintf_path_clone_srcs}

	# files to copy (*.h) 
	#  from ${get_next_line_path}/includes/ -> ${get_next_line_path_clone_includes}
	cp ${ft_fprintf_path}/includes/ft_fprintf.h 	${ft_fprintf_path_clone_includes}

# ------------------------------ END OF PROGRAM ------------------------------

#	---------------------------------- FT_SPRINTF ------------------------------------
	# ft_sprintf variables
	ft_sprintf_github="git@github.com:isibio/libft.ft_sprintf.git"
	ft_sprintf_github_branch="master"
	ft_sprintf_display="ft_sprintf"
	ft_sprintf_path="./ghub/ft_sprintf"
	ft_sprintf_path_clone_srcs="./srcs/ft_sprintf"
	ft_sprintf_path_clone_includes="./includes"

	printf "\n${PROJECT_NAME_DISPLAY} ${WHITE}${BOLD}Clone ${YELLOW}${ft_sprintf_display} ${CLEAN}${WHITE} >> \n\tlink : ${CLEAN}${ORANGE}${ft_sprintf_github}${CLEAN} \n\t${WHITE}dir  : ${CLEAN}${ORANGE}${ft_sprintf_path}${CLEAN} \n\n${CLEAN}${GITHUB_OUTPUTS}"


	# remove old clones if exists
	rm -rf ${ft_sprintf_path}
	rm -rf ${ft_sprintf_path_clone_srcs}/ft_sprintf*.c
	rm -rf ${ft_sprintf_path_clone_includes}/ft_sprintf*.h
	mkdir ${ft_sprintf_path}
	mkdir ${ft_sprintf_path_clone_srcs}
	mkdir ${ft_sprintf_path_clone_includes}

	# git clone from ${get_next_line_github} (branch ${get_next_line_github_branch}) to ${get_next_line_path}
	git clone --branch ${ft_sprintf_github_branch} ${ft_sprintf_github} ${ft_sprintf_path}

	# files to copy (get_next_line*.c)
	#  from ${get_next_line_path}/srcs/ -> ${get_next_line_path_clone_srcs}
	cp ${ft_sprintf_path}/srcs/ft_sprintf/ft_sprintf*.c 	${ft_sprintf_path_clone_srcs}

	# files to copy (*.h) 
	#  from ${get_next_line_path}/includes/ -> ${get_next_line_path_clone_includes}
	cp ${ft_sprintf_path}/includes/ft_sprintf.h 	${ft_sprintf_path_clone_includes}

# ------------------------------ END OF PROGRAM ------------------------------

# Remove git clone's dir
	rm -rf ghub
printf "\n"
