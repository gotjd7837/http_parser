GCC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = http_parser
SRC_DIR = ./sources
INC_DIR = ./includes

SRCS = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:%.c=%.o)
INC = -I$(INC_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(GCC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
