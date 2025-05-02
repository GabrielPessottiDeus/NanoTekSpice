# Variables
CC = g++
CFLAGS = -std=c++20 -Wall -Wextra -Werror
NAME = nanotekspice
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(SRC) 

# Compile object files
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean object files and library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all