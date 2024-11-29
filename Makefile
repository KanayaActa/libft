# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 08:24:02 by miwasa            #+#    #+#              #
#    Updated: 2024/11/14 16:30:00 by miwasa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

DIR				= .
SRCS_DIR		= $(DIR)
OBJS_DIR		= $(DIR)/obj
CC				= cc
PRINTF_DIR		= $(DIR)/ft_printf
PRINTF_SRCS_DIR = $(PRINTF_DIR)/srcs
PRINTF_INCS_DIR	= $(PRINTF_DIR)/includes
GNL_INCS_DIR	= $(DIR)/get_next_line
TEST_DIR		= $(DIR)/_test

SRCS			= \
	$(addprefix $(SRCS_DIR)/ft_ctype/, ft_isalnum.c ft_isalpha.c ft_iscntrl.c ft_isdigit.c ft_isgraph.c \
	ft_islower.c ft_isprint.c ft_ispunct.c ft_isspace.c ft_isupper.c \
	ft_isxdigit.c ft_isascii.c ft_isblank.c ft_toupper.c ft_tolower.c) \
	$(addprefix $(SRCS_DIR)/ft_lst/, ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c) \
	$(addprefix $(SRCS_DIR)/ft_put_fd/, ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c) \
	$(addprefix $(SRCS_DIR)/ft_stdlib/, ft_abs.c ft_atoi.c ft_calloc.c ft_itoa.c \
	ft_strtol.c ft_qsort.c ft_atol.c) \
	$(addprefix $(SRCS_DIR)/ft_string/, ft_strlen.c ft_strcat.c ft_strcmp.c ft_strchr.c ft_strcpy.c \
	ft_strdup.c ft_strrchr.c ft_strstr.c ft_strncmp.c ft_strncat.c \
	ft_strnchr.c ft_strncpy.c ft_strndup.c ft_strnlen.c ft_strnset.c \
	ft_memcpy.c ft_memdup.c ft_memfrob.c ft_memmove.c ft_memchr.c \
	ft_memset.c ft_memcmp.c ft_bzero.c ft_strlcat.c ft_strlcpy.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
	ft_striteri.c ) \
	$(addprefix $(SRCS_DIR)/ft_strings/, ft_strcasecmp.c ft_strncasecmp.c) \
	$(addprefix $(SRCS_DIR)/ft_utils/, ft_max.c ft_min.c ft_swap.c q_rsqrt.c) \
	$(addprefix $(PRINTF_SRCS_DIR)/, ft_printf.c print_format.c print_type.c \
	put_char.c put_decimal.c put_decimal_helper.c \
	put_hex.c put_hex_helper.c put_integer.c put_percent.c \
	put_pointer.c put_string.c put_unsigned.c \
	put_unsigned_helper.c add_padding.c get_type.c) \
	$(addprefix $(SRCS_DIR)/get_next_line/, get_next_line.c)

TEST_SRC = $(TEST_DIR)/test.c


OBJS			= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CFLAGS			= -Wall -Wextra -Werror
IDFLAGS			= -I.
IDFLAGS			+= -I$(PRINTF_INCS_DIR)
IDFLAGS			+= -I$(GNL_INCS_DIR)

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test:
	gcc $(TEST_SRC) $(NAME) -g -o test $(IDFLAGS)
	lldb ./test
	rm test
