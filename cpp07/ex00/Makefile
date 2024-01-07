NAME = converter
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC =  main.cpp ScalarConverter.cpp
HEADER = ScalarConverter.hpp
OBJ = $(SRC:.cpp=.o)

%.o : %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all