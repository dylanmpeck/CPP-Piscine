NAME = megaphone
SOURCE = megaphone.cpp
OBJ = megaphone.o

all: $(NAME)

$(NAME):
	clang++ -c -Wall -Wextra -Werror $(SOURCE)
	clang++ -o $(NAME) -Wall -Wextra -Werror $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm $(NAME)

re: fclean all
