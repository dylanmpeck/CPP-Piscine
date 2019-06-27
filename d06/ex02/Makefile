NAME = identify
SOURCE = main.cpp \
		 Base.cpp \
		 A.cpp \
		 B.cpp \
		 C.cpp
OBJ = main.o \
	  Base.o \
	  A.o \
	  B.o \
	  C.o

all: $(NAME)

$(NAME):
	clang++ -c -Wall -Wextra -Werror -std=c++98 $(SOURCE)
	clang++ -o $(NAME) -Wall -Wextra -Werror -std=c++98 $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm $(NAME)

re: fclean all

