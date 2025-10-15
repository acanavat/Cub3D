# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:22:13 by isibio            #+#    #+#              #
#    Updated: 2023/02/09 15:23:42 by isibio           ###   ########.fr        #
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
	SRCS_SHELL 				= $(shell ls -d1 srcs/*/** | grep -F .c)
	TOTAL_C_FILES			= $(shell ls -d1 srcs/*/** | grep -F .c | wc -l)
	TOTAL_O_FILES			= $(shell ls -d1 srcs/*/** | grep -F .o | wc -l)
	TOTAL_A_FILES			= $(shell ls bin/ | grep -F .a | wc -l)
	TOTAL_CLEAN_FILES_ECHO	= $(shell echo ${TOTAL_O_FILES})
	TOTAL_FCLEAN_FILES_ECHO	= $(shell echo ${TOTAL_O_FILES} +${TOTAL_A_FILES})
	TOTAL_PERCENT_ECHO		= $(shell echo ${TOTAL_O_FILES} /${TOTAL_C_FILES})
	TOTAL_NORM_ERR			= $(shell norminette | grep -F "Error:" | wc -l)
	TOTAL_NORM_ERR_DOC		= $(shell norminette | grep -F Error\! | wc -l)


	# Project variables
	PROJECT_NAME				=improved libft
	PROJECT_NAME_DISPLAY		=${CLEAN}${WHITE}[${ORANGE}${PROJECT_NAME}${WHITE}]${CLEAN}
	PROJECT_NAME_DISPLAY_UNDONE	=${CLEAN}${WHITE}[${BOLD}${GRAY}${TOTAL_PERCENT_ECHO} files${CLEAN}${WHITE}]${CLEAN}
	PROJECT_NAME_DISPLAY_DONE	=${CLEAN}${WHITE}[${ORANGE}${PROJECT_NAME}${WHITE}]${CLEAN}

# Compilation commands
	SRCS 		= ${SRCS_SHELL}
	OBJS		= ${SRCS:.c=.o}
	GCC			= cc
	FLAGS		= -Wall -Wextra -Werror
	HEADER		= -I includes/libft.h 
	NAME		= ./bin/libft.a

# Make actions
.c.o :
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) $(CLEAN)${WHITE}Compiling >> %s ${CLEAN}" ${notdir $<}
	@${GCC} ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Compiling >> ${BOLD}${GREEN}%s  ✓ \n${CLEAN}" ${notdir $<}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}

all : ${NAME}

clean :
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) ${RED}${BOLD}${GRAY}cleaning ${TOTAL_CLEAN_FILES_ECHO} files ${CLEAN}"
	@rm -f ${OBJS}
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Cleaning : ${BOLD}${GREEN}deleted ${TOTAL_CLEAN_FILES_ECHO} files ✓\n${CLEAN}"

fclean :
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) ${RED}${BOLD}${GRAY}cleaning ${TOTAL_FCLEAN_FILES_ECHO} files ${CLEAN}"
	@rm -f ${OBJS}
	@rm -f ${NAME}
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Cleaning : ${BOLD}${GREEN}deleted ${TOTAL_FCLEAN_FILES_ECHO} files ✓\n${CLEAN}"

update : fclean
	@clear
	@bash update.sh

re : fclean all
	
rmds :
	@rm -rf .DS_STORE
	@rm -rf bin/.DS_STORE
	@rm -rf includes/.DS_STORE
	@rm -rf srcs/*/.DS_STORE

norm :
	@printf "${WHITE}>>> ${ORANGE}${TOTAL_NORM_ERR} ${WHITE}norm error \n>>> ${ORANGE}${TOTAL_NORM_ERR_DOC} ${WHITE}documemts with norm errors\n"

git : fclean norm rmds
	@printf "\n"
	@git status

gitall : fclean norm rmds
	@printf "${WHITE}\n"
	@git status
	@printf "${WHITE}\n"
	@git add .
	@printf "${WHITE}\n"
	@git commit .
	@printf "${WHITE}\n"
	@git push origin master
	@printf "\n"

help :
	@printf ".c.o all clean fclean update re rmds norm git gitall\n"

.PHONY : all clean fclean re