# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 19:24:37 by agutierr          #+#    #+#              #
#    Updated: 2021/06/17 17:05:46 by agutierr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
SRCS			=	main.c srcs/check_args.c srcs/msg_err1.c\
					srcs/child_process.c srcs/split.c
OBJS 			=	$(SRCS:.c=.o)

GCC 			=	gcc
FLAGS			=	-Wall -Wall -Werror

#############################
RED 			= \033[0;31m
PURPLE			= \033[0;35m
GREEN			= \033[1;32m
RESET			= \033[0m
#############################

all: compile

%.o: %.c
	$(GCC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

compile: $(OBJS)
	@echo "${PURPLE}  Iniciando Compilacion ...${RESET}"
	$(GCC) $(OBJS) -o $(NAME)
	@echo "${GREEN}[.oOo.oOo.oOo.oOo.]"
	@echo "[ C O M P I L A O ]"
	@echo "[.oOo.oOo.oOo.oOo.]${RESET}"

norminette:
	norminette main.c srcs/* headers/*

fclean: clean
	@echo "${RED}  Limpiando ejecutable ... ${RESET}"
	rm -f $(NAME)

clean:
	@echo "${RED}  Limpiando OBJs ... ${RESET}"
	$(RM) $(OBJS)

re: fclean all

.PHONY: clean all
