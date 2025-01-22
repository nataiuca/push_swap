# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 13:42:51 by natferna          #+#    #+#              #
#    Updated: 2025/01/22 16:21:54 by natferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = push_swap

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes

# Archivos fuente y objeto
SRC = src/main.c src/functions1.c src/functions2.c src/operations1.c src/check.c src/order1.c src/order2.c \
      src/size.c src/sorting.c src/stack.c src/operations2.c src/aux.c
OBJ = $(SRC:.c=.o)

# Colores para hacer más vistoso el output
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

# Regla principal
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✅ Compilación completada: $(NAME)$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)🔨 Compilando: $<$(RESET)"

# Limpieza de objetos
clean:
	@rm -f $(OBJ)
	@echo "$(YELLOW)🧹 Archivos objeto eliminados.$(RESET)"

# Limpieza completa
fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)🧹 Binario eliminado.$(RESET)"

# Recompilar desde cero
re: fclean all

# No considera estos nombres como archivos
.PHONY: all clean fclean re