NAME = libft.a
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC_NAME = libft.h
SRC_NAME = get_next_line.c\
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
	ft_memmove.c ft_memchr.c ft_memcmp.c\
	ft_strdup.c ft_strlen.c ft_strcpy.c ft_strncpy.c\
	ft_strcat.c ft_strncat.c ft_strlcat.c\
	ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c\
	ft_strcmp.c ft_strncmp.c ft_atoi.c\
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_toupper.c ft_tolower.c\
	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c\
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c\
	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c\
	ft_lstiter.c ft_lstmap.c\
	ft_strrev.c ft_strcapitalize.c ft_str_is_lowercase.c\
	ft_str_is_uppercase.c ft_swap.c ft_print_words_tables.c\
	ft_is_space.c ft_count_words.c ft_count_char.c\
	ft_print_numbers_tables.c ft_free_chartab.c ft_idx.c\
	ft_atoi_base.c ft_tsl_to_rvb.c
OBJ_NAME = $(SRC_NAME:.c=.o)

line = @echo "\033[31m*****************************************************\033[0m"
complete = @echo "\033[36mComplete:\033[0m"
	cleaning = @echo "\033[33mCleaning complete\033[0m"
	ok = [\033[0;32mOK\033[0m]

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
HED = $(addprefix ./includes/, $(INC_NAME)) 


.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(HED)
	$(line)
	@ar rc $(NAME) $(OBJ)
	@echo "$(ok) ar rc"
	@ranlib $(NAME)
	@echo "$(ok) ranlib"
	@echo "$(ok) libft made"
	$(line)

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir objs

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@echo "[\033[92m..\033[0m] Compiling $< into object file.."
	@tput cuu1;tput el;
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "$(ok)  Compiling $< into object file.."

.PHONY: clean
clean:
	@rm -rf $(OBJ_PATH)

.PHONY: fclean
fclean: clean
	@echo "Cleaning library..."
	@rm -f $(NAME)
	$(cleaning)
	$(line)

.PHONY: re
re: fclean all
