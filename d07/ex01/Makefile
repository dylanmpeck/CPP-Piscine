NAME = iter
SOURCE = iter.cpp
OBJ = iter.o

all : $(NAME)

$(NAME):
	clang++ -c -Wall -Wextra -Werror -std=c++98 $(SOURCE)
	clang++ -o $(NAME) -Wall -Wextra -Werror -std=c++98 $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm $(NAME)

re: fclean all
