# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaach <amaach@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 15:38:30 by amaach            #+#    #+#              #
#    Updated: 2021/06/10 14:38:46 by amaach           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =  -Wall -Wextra -Werror
NAME1 = client
NAME2 = server
SRC1 =  client.c
SRC2 = server.c
LIB = libft/libft.a
INCLUDES = libft
OBJ =libft/*.o

all:	$(NAME1) $(NAME2)

$(NAME1) : $(SRC1)
	make -C libft
	gcc $(FLAGS) $(LIB) -I $(INCLUDES) $(SRC1) -o $(NAME1)
$(NAME2) : $(SRC2)
	make -C libft
	gcc $(FLAGS) $(LIB) -I $(INCLUDES) $(SRC2) -o $(NAME2)

bonus : $(SRC)

clean:
	rm -f $(OBJ) $(NAME)

fclean:	clean
	rm -f $(EXEC)

re:		fclean all