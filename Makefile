SRCS = ft_nbrtohex.c	\
		ft_printf_format.c	\
		ft_printf_utils.c	\
		ft_printf.c		\
		ft_putnbr.c		\
		ft_putptr.c		\
		ft_putunbr.c

NAME = libftprintf.a

INCLUDE = ft_printf.h

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c Makefile $(INCLUDE)
		@mkdir -p $(OBJS_DIR)
		@echo "Compiling: $<"
		@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
		@ar rcs $(NAME) $(INCLUDE) $(OBJECTS_PREFIXED)
		@echo "libprintf Done!"

all: $(NAME)

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all
