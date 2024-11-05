# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 08:25:50 by malves-b          #+#    #+#              #
#    Updated: 2024/08/12 16:35:27 by malves-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = pipex

FILES = pipex.c pipex_utils.c \
		libft/ft_bzero.c libft/ft_calloc.c \
		libft/ft_strlen.c libft/ft_split.c \
		libft/ft_strcmp.c libft/ft_strjoin.c \
		libft/ft_strdup.c libft/ft_strnstr.c \
		libft/ft_strcpy.c \

OBJS = $(FILES:.c=.o)

CC		= cc -g
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

LIBRARY	= pipex.a

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBRARY)

$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBRARY) $(TARGET)

re: fclean all

.PHONY: all, clean, fclean, re
