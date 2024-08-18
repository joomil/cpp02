# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Object files
MAIN_OBJ = main.o
FIXED_OBJ = Fixed.o
POINT_OBJ = Point.o
BSPOBJ = bsp.o

# Executable
NAME = ex03

all: $(NAME)

$(NAME): $(MAIN_OBJ) $(FIXED_OBJ) $(POINT_OBJ) $(BSPOBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN_OBJ) $(FIXED_OBJ) $(POINT_OBJ) $(BSPOBJ)

main.o: main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

Fixed.o: Fixed.cpp Fixed.hpp
	$(CC) $(CFLAGS) -c $< -o $@

Point.o: Point.cpp Point.hpp
	$(CC) $(CFLAGS) -c $< -o $@

bsp.o: bsp.cpp Point.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(MAIN_OBJ) $(FIXED_OBJ) $(POINT_OBJ) $(BSPOBJ)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
