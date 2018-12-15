# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarnett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 22:40:12 by abarnett          #+#    #+#              #
#    Updated: 2018/12/14 18:25:22 by alan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			libftprintf.a

SRC_DIR :=		srcs
INCLUDE_DIR :=	./includes
C_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./$(SRC_DIR)/*.c))
L_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./libft/$(SRC_DIR)/*.c))

CFLAGS +=		-g -Wall -Wextra -Werror -I$(INCLUDE_DIR)
LDFLAGS +=		-L./ -lftprintf

.PHONY:			all clean fclean re

all: $(NAME)

$(NAME): $(C_OBJS) $(L_OBJS)
	ar rc $(NAME) $(C_OBJS) $(L_OBJS)
	ranlib $(NAME)

test: all main.o
	@ctags -R
	$(CC) $(CFLAGS) main.o -o test $(LDFLAGS)

clean:
	@- $(RM) $(C_OBJS) $(L_OBJS) main.o

fclean: clean
	@- $(RM) $(NAME) test

re: fclean all
