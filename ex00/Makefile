# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Project name
NAME = ex00

all: $(NAME)

$(NAME): main.o Fixed.o
	$(CC) $(CFLAGS) -o $(NAME) main.o Fixed.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

Fixed.o: Fixed.cpp Fixed.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) *.o

fclean: clean

re: fclean all

.PHONY: all clean fclean re
