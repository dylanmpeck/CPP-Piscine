NAME = convert
SOURCE = main.cpp \
		 Converter.cpp
OBJ = main.o \
	  Converter.o

all: $(NAME)

$(NAME):
	clang++ -c -Wall -Wextra -Werror $(SOURCE)
	clang++ -o $(NAME) -Wall -Wextra -Werror $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm $(NAME)

re: fclean all
