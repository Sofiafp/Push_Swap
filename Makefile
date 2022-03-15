# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 20:00:00 by salegre-          #+#    #+#              #
#    Updated: 2022/03/15 11:07:28 by salegre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
LIB1	= ar -rcs

RM		= /bin/rm -f

NAME	= libps.a

INCLUDE	= libps.h

SRCS	= libft/ft_isascii.c libft/ft_isprint.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c \
			libft/ft_tolower.c libft/ft_toupper.c libft/ft_strlen.c libft/ft_strlcpy.c libft/ft_strlcat.c \
			libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strnstr.c libft/ft_strncmp.c libft/ft_atoi.c \
			 libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memmove.c \
			libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strdup.c libft/ft_calloc.c libft/ft_itoa.c \
			libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
			libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_strmapi.c \
			main.c push_swap.c struct_funcs.c checks.c operations.c two_three_algs.c big_algs.c \
			big_alg_aux.c put_in_place.c put_in_place_aux.c chose_what_to_do.c do_it_on_purpose.c

OBJS	= $(SRCS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)
			gcc $(CFLAGS) push_swap.c -L. -lps -o push_swap

.c.o:
			$(CC) -g $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
