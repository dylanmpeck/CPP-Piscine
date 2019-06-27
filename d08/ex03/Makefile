NAME = mindopen

SRC_PATH = src/
OBJ_PATH = obj/

SOURCE = main.cpp \
		 ClosedBrackets.cpp \
		 DecrementByteAtPointer.cpp \
		 DecrementPointer.cpp \
		 IncrementByteAtPointer.cpp \
		 IncrementPointer.cpp \
		 Input.cpp \
		 Instruction.cpp \
		 Interpreter.cpp \
		 MOContainer.cpp \
		 OpenBrackets.cpp \
		 Output.cpp \

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ_NAME = $(subst .cpp,.o, $(SOURCE))

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -Wall -Wextra -Werror -o $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(OBJ_PATH)
	clang++ -Wall -Wextra -Werror -o $@ -c $<

test: $(OBJ)
	clang++ -o $(NAME) $(OBJ)

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
