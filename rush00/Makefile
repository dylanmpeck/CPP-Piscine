CC=clang++
CFLAGS=-Wall -Werror -Wextra
LFLAGS=-lcurses 
NAME=ft_retro
SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

VPATH = obj

$(NAME): $(OBJ)
	$(CC) obj/* -o $(NAME) $(LFLAGS)

all: $(NAME)

%.o: %.cpp
	@mkdir -p obj
	$(CC) $(CFLAGS) -o obj/$@ -c $<

clean:
	@rm -rf obj/

fclean: clean
	@rm -f $(NAME)

re: fclean all
