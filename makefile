NAME	=	getnextline.a
SRC		=	get_next_line.c \
			get_next_line_utils.c

OBJ		= $(SRC:%.c=%.o)
CFLAGS	= -Wall -Werror -Wextra -D BUFFER_SIZE=150
CC		= gcc
INC		= get_next_line.h

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) -o $@

.PHONY : clean
clean:
	rm -f *.o

.PHONY : fclean
fclean: clean
	rm -f $(NAME)

.PHONY : all
all: $(NAME)

.PHONY : re
re: fclean all