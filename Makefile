# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaach <amaach@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 15:38:30 by amaach            #+#    #+#              #
#    Updated: 2021/06/08 16:41:55 by amaach           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =  -Wall -Wextra -Werror
NAME = client
SRC =  client.c
LIB = libft/libft.a
INCLUDES = libft
OBJ = *.o

all:	$(NAME)

$(NAME) : $(SRC)
	make -C libft
	gcc $(FLAGS) $(LIB) -I $(INCLUDES) $(SRC) -o $(NAME)

bonus : $(SRC)

clean:
	rm -f $(OBJ) $(NAME)

fclean:	clean
	rm -f $(EXEC)

re:		fclean all