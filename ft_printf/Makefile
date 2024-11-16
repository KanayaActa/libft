# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 22:36:55 by miwasa            #+#    #+#              #
#    Updated: 2024/11/14 22:37:00 by miwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

DIR				= .
FT				= ..
INCS_DIR		= $(DIR)/includes
SRCS_DIR		= $(DIR)/srcs
OBJS_DIR		= $(DIR)/objs
CC 				= cc

SRCS			= \
	$(SRCS_DIR)/ft_printf.c \
	$(SRCS_DIR)/print_format.c \
	$(SRCS_DIR)/print_type.c \
	$(SRCS_DIR)/put_char.c \
	$(SRCS_DIR)/put_decimal.c \
	$(SRCS_DIR)/put_decimal_helper.c \
	$(SRCS_DIR)/put_hex.c \
	$(SRCS_DIR)/put_hex_helper.c \
	$(SRCS_DIR)/put_integer.c \
	$(SRCS_DIR)/put_percent.c \
	$(SRCS_DIR)/put_pointer.c \
	$(SRCS_DIR)/put_string.c \
	$(SRCS_DIR)/put_unsigned.c \
	$(SRCS_DIR)/put_unsigned_helper.c \
	$(SRCS_DIR)/add_padding.c \
	$(SRCS_DIR)/get_type.c \
	$(FT)/ft_string/ft_strchr.c \
	$(FT)/ft_string/ft_strlen.c \
	$(FT)/ft_stdlib/ft_atoi.c \
	$(FT)/ft_ctype/ft_isdigit.c \
	$(FT)/ft_stdlib/ft_abs.c \
	$(FT)/ft_string/ft_bzero.c \
	$(FT)/ft_string/ft_memset.c

OBJS = $(patsubst $(DIR)/%.c, $(OBJS_DIR)/%.o, $(filter $(DIR)/%, $(SRCS))) \
       $(patsubst $(FT)/%.c, $(OBJS_DIR)/%.o, $(filter $(FT)/%, $(SRCS)))


CFLAGS			= -Wall -Wextra -Werror
IDFLAGS			+= -I$(FT)
IDFLAGS			+= -I$(INCS_DIR)

.PHONY: all clean fclean re test norm

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $(OBJS)

$(OBJS_DIR)/%.o: $(DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

$(OBJS_DIR)/%.o: $(FT)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: test.c $(NAME)
	@make
	$(CC) -g $(CFLAGS) -L./ -I./ $< -o $@ -lftprintf

norm: $(SRCS_DIR) $(INCS_DIR)
	@norminette $^

