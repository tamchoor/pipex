# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamchoor <tamchoor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 14:19:17 by tamchoor          #+#    #+#              #
#    Updated: 2021/12/27 14:19:44 by tamchoor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= pipex.a

NAME_B 			= pipex_b.a

SOURCES	=		ft_calloc.c\
				ft_split.c\
				ft_strjoin.c\
				exec_cmd.c\
				ft_utils.c\
				pipex.c
 
SOURCES_B=		ft_calloc_bonus.c\
				ft_split_bonus.c\
				ft_strjoin_bonus.c\
				exec_cmd_bonus.c\
				ft_utils_bonus.c\
				gnl_bonus.c\
				pipex_bonus.c

HEADER 			= pipex.h

HEADER_B 		= pipex_bonus.h

PR 				= pipex

OBJECTS 		= $(SOURCES:%.c=%.o)

OBJECTS_B 		= $(SOURCES_B:%.c=%.o)

CC 				= cc

CFLAGS 			= -Wall -Wextra -Werror

.PHONY			: all clean fclean re bonus

all				: $(NAME)

$(NAME) 		: $(OBJECTS) $(HEADER)
					ar rcs $(NAME) $?
					@rm -rf $(NAME_B)
					$(CC) $(CFLAGS) $(NAME) -o $(PR)

$(OBJECTS)		:	%.o : %.c $(HEADER)
					$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(OBJECTS_B)	: %.o : %.c $(HEADER_B)
					$(CC) $(CFLAGS) -I $(HEADER_B) -c $< -o $@

bonus			: $(NAME_B)

$(NAME_B) 		: $(OBJECTS_B) $(HEADER)
					ar rcs $(NAME_B) $?
					@rm -rf $(NAME)
					$(CC) $(CFLAGS) $(NAME_B) -o $(PR)

clean			: 
					@rm -rf $(OBJECTS) $(OBJECTS_B)

fclean			: clean
					rm -rf $(NAME) $(NAME_B) $(PR)

re				: fclean all
