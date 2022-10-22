NAME = prog

CC = g++
CFLAGS= -Wall -Wextra -Werror

SRC = a.cpp

OBJ:=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	@clear

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

info: 
	@echo "obj = $(OBJ)\nsrc = $(SRC)"

.PHONY: all clean info